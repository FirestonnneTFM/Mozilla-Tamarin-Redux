/* -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil; tab-width: 2 -*- */
/* vi: set ts=2 sw=2 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "hm-main.h"
#ifdef VMCFG_HALFMOON

namespace halfmoon {

InstrKind tomodelPunt() {
  assert(false && "cant convert models");
  return HR_MAX;
}

InstrKind toModelAtom(const Type* t) {
  switch (model(t)) {
    default: assert(false && "bad model for toModelAtom");
    case kModelString:       return HR_string2atom;
    case kModelDouble:       return HR_double2atom;
    case kModelScriptObject: return HR_scriptobject2atom;
    case kModelNamespace:    return HR_ns2atom;
    case kModelInt:
      return isBoolean(t) ? HR_bool2atom :
             isInt(t) ? HR_int2atom :
             isUInt(t) ? HR_uint2atom : tomodelPunt();
  }
}

InstrKind toModelDouble(const Type* t) {
  switch (model(t)) {
    default: assert(false && "bad model for toModelDouble");
  case kModelAtom: return HR_atom2double;
    case kModelInt:
      return isInt(t) ? HR_i2d :
             isUInt(t) ? HR_u2d :
             HR_MAX;
  }
}

InstrKind toModelInt(const Type* t, const Type* use_type) {
  // todo: double->int
  switch (model(t)) {
    default: assert(false && "bad input model for toModelInt");
    case kModelAtom: {
      if (isBoolean(t)) {
        return HR_atom2bool;
      } else {
        /// This must be bad - example src: var x:uint = 10;
        /// The type is a uiNumber[a]. the use_type says x MUST be the uint type
        /// So we have to change the model from atom to uint
        /// but uint and int share the same model kModelInt, BUT are unique types
        /// and uint / int are not subtypes of each other
        /// so we have to be explicit in which int we choose based on the use_type
        assert (isInt(t) || isUInt(t));
        if (isUInt(use_type)) {
          assert (!isInt(use_type));
          return HR_atom2uint;
        } else {
          assert (isInt(use_type) && !isUInt(use_type));
          return HR_atom2int;
        }
      }
    }  // end case atom
    case kModelDouble:
      if (isInt(t))
        return HR_d2i;
      if (isUInt(t))
        return HR_d2u;
      assert(false && "nonsense -> int");
      break;
  } // end switch
  return HR_MAX;
}

InstrKind toModelScriptobject(const Type* t) {
  switch (model(t)) {
  default:
    assert(false && "bad input model for toModelScriptobject");
  case kModelAtom:
    return HR_atom2scriptobject;
  }
}

InstrKind toModelKind(const Type* val_type, const Type* use_type) {
  switch (model(use_type)) {
    default:
      printf("unknown conversion %s -> %s\n", typeName(val_type),
             typeName(use_type));
      assert(false && "bad model");
    case kModelAtom:
      return toModelAtom(val_type);
    case kModelScriptObject:
      return toModelScriptobject(val_type);
    case kModelString:
      return HR_atom2string;
    case kModelInt:
      return toModelInt(val_type, use_type);
    case kModelDouble:
      return toModelDouble(val_type);
  }
}

/// ModelFixer encapsulates state and helpers for inserting model-changing
/// instructions into the IR.
class ModelFixer {
public:
  ModelFixer(Context* cxt, InstrGraph* ir)
  : cxt_(cxt), ir_(ir), factory_(ir), analyzer_(ir) {
  }

  /** change opcodes when possible */
  void changeOps();

  /** insert conversions after defs */
  void fixDefs();

  /// Return the constraint for this use.  Instructions that have Any or
  /// Top in their signature get handled here.
  const Type* getConstraint(const Use& u);

private:
  Context* cxt_;
  InstrGraph* ir_;
  InstrFactory factory_;
  TypeAnalyzer analyzer_;
};

/**
 * Run a pass where we select alternative opcodes to reduce the number
 * of model conversions we'll have to insert.
 */
void ModelFixer::changeOps() {
  for (AllInstrRange i(ir_); !i.empty();) {
    Instr* instr = i.popFront();
    switch (kind(instr)) {
      case HR_cknull: {
        UnaryStmt* cknull = cast<UnaryStmt>(instr);
        const Type* ptr_type = type(cknull->value_in());
        if (model(ptr_type) == kModelScriptObject) {
          // cknull(ptr:ScriptObject) -> cknullobject(ptr)
          factory_.toUnaryStmt(HR_cknullobject, cknull);
          analyzer_.computeTypes(cknull);
        }
        break;
      }
    }
  }
}

/**
 * Insert model conversions after defs, where needed.  If multiple uses
 * need to use the same converted def, reuse the conversion instruction.
 */
void ModelFixer::fixDefs() {
  Def* converts[kModelMAX];  // space to memoize one conversion per ModelKind.
  for (PostorderBlockRange b(ir_); !b.empty();) {
    for (InstrRange i(b.popFront()); !i.empty();) {
      Instr* instr = i.popBack();
      SigRange sr = outputSigRange(instr);
      for (ArrayRange<Def> dr = defRange(instr); !dr.empty(); sr.popFront()) {
        Def* d = &dr.popFront();
        int have_mask = 0; // mask:  1 << ModelKind
        const Type* def_type = type(d);
        const Type* sig_type = sr.front();
        if (isBottom(def_type))
          def_type = sig_type;
        for (UseRange u(*d); !u.empty(); ) {
          Use& use = u.popFront();
          const Type* constraint = getConstraint(use);
          if (!submodelof(def_type, constraint)) {
            // need a conversion
            ModelKind need = model(constraint);
            if (!(have_mask & (1 << need))) {
              InstrKind convert_kind = toModelKind(def_type, constraint);
              UnaryExpr* expr = factory_.newUnaryExpr(convert_kind, d);
              ir_->addInstrAfter(instr, expr);
              converts[need] = expr->value_out();
              have_mask |= (1 << need);
            }
            use = converts[need];
          }
        }
      }
    }
  }
}

/// Return the constraint for this use.  Instructions that have Any or
/// Top in their signature get handled here.
const Type* ModelFixer::getConstraint(const Use& u) {
  Instr* instr = user(u);
  int use_pos = pos(u);
  InstrKind k = kind(instr);
  switch (k) {
    case HR_goto: {
      // constraint is the corresponding label's def type.
      GotoInstr* go = cast<GotoInstr>(instr);
      return type(go->target->params[use_pos]);
    }
    case HR_if:
    case HR_switch:
      if (use_pos > 0)
        return TOP;
      break;
    case HR_setslot:
      if (use_pos == 3) {
        CallStmt2* setslot = cast<CallStmt2>(instr);
        const Type* obj_type = type(setslot->object_in());
        int slot = ordinalVal(type(setslot->param_in()));
        return ir_->lattice.getSlotType(obj_type, slot);
      }
      break;
    case HR_callinterface:
    case HR_callmethod:
      if (use_pos >= 2) {
        CallStmt2* call = cast<CallStmt2>(instr);
        const Type* env_type = type(call->param_in());
        if (isEnv(env_type)) {
          MethodSignaturep sig = getMethod(type(call->param_in()))->getMethodSignature();
          return ir_->lattice.makeParamType(use_pos - 2, sig);
        }
      }
      break;
    case HR_callstatic:
      assert(false && "custom signature not implemented");
      break;
    case HR_return:
      if (use_pos == 1) {
        // return type is based on method signature
        MethodSignaturep sig = cxt_->method->getMethodSignature();
        return ir_->lattice.makeType(sig->returnTraits());
      }
      break;
  }
  const ShapeRep& rep = shape_reps[shape(instr)];
  if (rep.vararg == kVarIn && use_pos > rep.num_uses)
    use_pos = rep.num_uses;
  return inputSignature(instr)[use_pos];
}

ModelKind promoteModelKind(const Type* t) {
  if (isInt(t))
    return kModelInt;
  if (isUInt(t))
    return kModelInt;
  if (isNumber(t))
    return kModelDouble;
  if (isBoolean(t))
    return kModelInt;
  if (isString(t))
    return kModelString;
  if (isNamespace(t))
    return kModelNamespace;
  if (isScriptObject(t))
    return kModelScriptObject;
  return kModelAtom;
}

/// Run the model fixer once then clean up.
void fixModels(Context* cxt, InstrGraph* ir) {
  assert(checkTypes(ir, false));
  assert(checkPruned(ir) && checkSSA(ir));
  propagateTypes(ir);
  ModelFixer fixer(cxt, ir);
  fixer.changeOps();
  fixer.fixDefs();
  propagateTypes(ir);
  computeIdentities(ir);
  removeDeadCode(cxt, ir);
  assert(checkTypes(ir, true));
  assert(checkPruned(ir) && checkSSA(ir));
}

ModelKind defaultModelKind(Traits* traits) {
  switch (valueStorageType(builtinType(traits))) {
    default: assert(false && "bad SlotStorageType");
    case SST_atom: return kModelAtom;
    case SST_scriptobject: return kModelScriptObject;
    case SST_string: return kModelString;
    case SST_namespace: return kModelNamespace;
    case SST_int32: return kModelInt;
    case SST_uint32: return kModelInt;
    case SST_bool32: return kModelInt;
    case SST_double: return kModelDouble;
  }
}

SlotStorageType type2sst(const Type* t) {
  assert(isDataType(*t));
  switch (model(t)) {
    default: assert(false && "bad model");
    case kModelInt:
      return isInt(t) ? SST_int32 : isUInt(t) ? SST_uint32 : SST_bool32;
    case kModelDouble: return SST_double;
    case kModelString: return SST_string;
    case kModelScriptObject: return SST_scriptobject;
    case kModelAtom: return SST_atom;
    case kModelNamespace: return SST_namespace;
  }
}

}
#endif // VMCFG_HALFMOON
