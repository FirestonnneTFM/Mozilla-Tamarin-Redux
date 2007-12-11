# These are tests for the IActiveScript related interfaces.  They are
# written in Python as the pywin32 package provides support for the vtable 
# based interfaces used - meaning the other (reasonable) alternative 
# would be C++.

# The intention is that whereever possible, we use the Windows Scripting
# Host to test as much as possible - but anything that can't be done that
# way, such as basic checks of the engine itself, are done here.

# taken from pywin32's win32comext/axscript/test/testHost.py
import sys
import unittest

# These modules come from the pywin32 package (sf.net/projects/pywin32)
try:
    import pythoncom
except ImportError:
    print >> sys.stderr, "This package requires the pywin32 extensions - http://sf.net/projects/pywin32"
    sys.exit(1)

from win32com.axscript import axscript
from win32com.server.util import wrap, Collection
from win32com.server.exception import COMException
import winerror

# Other misc stuff.
AXTAM_CLSID = "application/ecmascript;version=4"

# Known failures are a good indication of things todo :)
skip_known_failures = True #False

IActiveScriptSite_methods = """
    GetLCID GetItemInfo GetDocVersionString OnScriptTerminate OnStateChange
    OnScriptError OnEnterScript OnLeaveScript""".split()

class TestScriptCollection(Collection):
    """A 'collection', used to test enum semantics"""
    def _NewEnum(self):
      return Collection._NewEnum(self)

class TestScriptObject:
    """This object is added to the ScriptEngine with the name 'test'.  Script
       code can call reference the 'public' properties of this object.
    """
    _public_methods_ = [ 'call', 'fail' ]
    _public_attrs_ = ['value', 'collection']
    def __init__(self):
        self.collection = wrap( TestScriptCollection( [1,'Two',3] ))
        self.last = None
        self.fail_called = 0
        self.value = None

    def call(self, *args):
        self.last = args

    def fail(self, hresult=winerror.E_FAIL):
        raise COMException(hresult=hresult)

class AXTestSite:
    """An IActiveScriptSite implementation used for testing our engine."""
    _public_methods_ = IActiveScriptSite_methods
    _com_interfaces_ = [ axscript.IID_IActiveScriptSite ]

    def __init__(self, testcase):
        self.testcase = testcase
        self.terminate_result = None
        self.terminate_excepInfo = None
        self.last_error = None
        self.last_state = None
        self.num_enter_script = 0
        self.num_leave_script = 0

        engine = pythoncom.CoCreateInstance(AXTAM_CLSID, None, 
                                            pythoncom.CLSCTX_SERVER,
                                            pythoncom.IID_IUnknown)

        # We use 2 interfaces from the object - get them now.
        self.engine_script = engine.QueryInterface(axscript.IID_IActiveScript)
        self.engine_parse = engine.QueryInterface(axscript.IID_IActiveScriptParse)

    def init_engine(self):
        self.engine_script.SetScriptSite(wrap(self))
        self.engine_parse.InitNew()

    def close(self):
        # Should probably transition engine to the closed state too...
        if self.engine_script:
            self.engine_script.Close()
            self.engine_script = None
        self.engine_parse = None

    def _SetNamedItems(self, items):
        self.named_items = items
        for name, (dispatch, typeinfo, flags) in self.named_items.iteritems():
            self.engine_script.AddNamedItem(name, flags)

    # IActiveScriptSite methods
    def GetLCID(self):
        return 0

    def GetItemInfo(self, name, returnMask):
        disp, ti, flags = self.named_items[name]
        ret_disp = ret_ti = None
        if returnMask & axscript.SCRIPTINFO_IUNKNOWN:
            ret_disp = disp
        if returnMask & axscript.SCRIPTINFO_ITYPEINFO:
            ret_ti = ti
        return ret_disp, ret_ti

    def GetDocVersionString(self):
        return 'axtam test script host 1.0'

    def OnScriptTerminate(self, result, excepInfo):
        self.terminate_result = result
        self.terminate_excepInfo = excepInfo

    def OnStateChange(self, state):
        self.last_state = state

    def OnScriptError(self, errorInterface):
        self.last_error = errorInterface

    def OnEnterScript(self):
        self.num_enter_script += 1

    def OnLeaveScript(self):
        self.num_leave_script += 1

# The base classes for all our test cases.  Note that tests should generally
# *not* be added to these base classes, else they will be run once for each
# class that derives from us.

# This is the most basic, and it doesn't fully iniitialize the engine.
# You may want to derive your test case from a sub-class rather than 
# directly from this class.
class TestCase(unittest.TestCase):
    expecting_errors = False
    def setUp(self):
        self.site = AXTestSite(self)

    def tearDown(self):
        if self.site:
            try:
                if not self.expecting_errors and self.site.last_error is not None:
                    excep_info = self.site.last_error.GetExceptionInfo()
                    self.fail("Script Error Detected: %s" % (excep_info,))
            finally:
                self.site.close()

    def assertRaisesCOMError(self, func, *args, **kw):
        expected_hresult = kw.get('hresult')
        try:
            func(*args)
            raise AssertionError, "%s did not fail!" % (func,)
        except pythoncom.com_error, exc:
            if expected_hresult is None:
                return
            if exc[0] != expected_hresult:
                self.fail("Expected %s to return 0x%x - got 0x%x instead", func, expected_hresult, exc[0])

    def _prepareNamedItems(self):
        flags = axscript.SCRIPTITEM_ISVISIBLE | axscript.SCRIPTITEM_GLOBALMEMBERS
        self.test_script_ob = TestScriptObject()
        n = {'test': (wrap(self.test_script_ob), None, flags)}
        self.site._SetNamedItems(n)

    def parseScriptText(self, code, flags = 0, start_engine=True, expect_exc=False):
        try:
            self.site.engine_parse.ParseScriptText(code, None, None, None, 0, 0, flags)
            if start_engine:
                self.startEngine()
            self.failIf(expect_exc, "expected an exception - but things worked")
        except pythoncom.com_error:
            if not expect_exc:
                raise

    def startEngine(self):
        self.site.engine_script.SetScriptState(axscript.SCRIPTSTATE_CONNECTED)

# Fully initialized the engine and adds a 'test' script object.
class TestCaseInitialized(TestCase):
    def setUp(self):
        TestCase.setUp(self)
        self.site.init_engine()
        self._prepareNamedItems()

# The "real" test cases - these have the tests...
class TestSimple(TestCaseInitialized):
    def testSimple(self):
        # do nothing at all - just make sure we can setup and tear down.
        pass

class TestState(TestCase):
    def _setCheckState(self, new_state):
        self.site.engine_script.SetScriptState(new_state)
        # check engine says its in the new state
        self.failUnlessEqual(self.site.engine_script.GetScriptState(), new_state)
        # check the engine called back with the new state correctly.
        self.failUnlessEqual(self.site.engine_script.GetScriptState(), self.site.last_state)
        
    def testStateInitialized(self):
        get_state = self.site.engine_script.GetScriptState
        self.failUnlessEqual(get_state(), axscript.SCRIPTSTATE_UNINITIALIZED)
        self.failUnlessEqual(self.site.last_state, None) # never been set yet.
        # InitNew puts everything into the Initialized state.
        self.site.init_engine()
        self.failUnlessEqual(get_state(), axscript.SCRIPTSTATE_INITIALIZED)
        # the engine should have notified of the new state.
        self.failUnlessEqual(get_state(), self.site.last_state)

    def testStateInitializedEarly(self):
        # Check InitNew can be called before SetScriptSite, which is
        # what IE does.
        get_state = self.site.engine_script.GetScriptState
        self.failUnlessEqual(get_state(), axscript.SCRIPTSTATE_UNINITIALIZED)
        self.site.engine_parse.InitNew()
        #  should now be initialized.
        self.failUnlessEqual(get_state(), axscript.SCRIPTSTATE_INITIALIZED)
        # set the site so we cleanup without dumping debug messages.
        self.site.engine_script.SetScriptSite(wrap(self.site))

    def testStateTransitions(self):
        # InitNew puts everything into the Initialized state.
        self.site.init_engine()
        get_state = self.site.engine_script.GetScriptState
        self.failUnlessEqual(get_state(), axscript.SCRIPTSTATE_INITIALIZED)
        self.failUnlessEqual(get_state(), self.site.last_state)
        # Move to started
        self.site.engine_script.SetScriptState(axscript.SCRIPTSTATE_INITIALIZED)
        # It should be impossible to transition back to UNINITIALIZED
        self.assertRaises(pythoncom.com_error, self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_UNINITIALIZED)
        # But we should be able to move forward to STARTED then CONNECTED
        self._setCheckState(axscript.SCRIPTSTATE_STARTED)
        # to CONNECTED
        self._setCheckState(axscript.SCRIPTSTATE_CONNECTED)
        # It should be impossible to move back to STARTED
        self.assertRaises(pythoncom.com_error, self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_STARTED)
        # but we *can* move back to initialized.
        self._setCheckState(axscript.SCRIPTSTATE_INITIALIZED)
        # Lets jump all the way to CONNECTED
        self._setCheckState(axscript.SCRIPTSTATE_CONNECTED)
        # Then DISCONNECTED
        self._setCheckState(axscript.SCRIPTSTATE_DISCONNECTED)
        # can't move back to started or connected
        self.assertRaises(pythoncom.com_error, self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_STARTED)
        self.assertRaises(pythoncom.com_error, self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_CONNECTED)
        # and again back to initialized.
        self._setCheckState(axscript.SCRIPTSTATE_INITIALIZED)
        # close the engine - all state transitions are invalid.
        self._setCheckState(axscript.SCRIPTSTATE_CLOSED)
        self.assertRaisesCOMError(self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_INITIALIZED,
                                  hresult = winerror.E_FAIL)
        self.assertRaisesCOMError(self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_STARTED,
                                  hresult = winerror.E_FAIL)
        self.assertRaisesCOMError(self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_CONNECTED,
                                  hresult = winerror.E_FAIL)
        self.assertRaisesCOMError(self.site.engine_script.SetScriptState, axscript.SCRIPTSTATE_DISCONNECTED,
                                  hresult = winerror.E_FAIL)

    def testNothingExecutedUntilStarted(self):
        code = "test.value = 2"
        self.site.init_engine()
        self._prepareNamedItems()
        self.parseScriptText(code, start_engine=False)
        # code should not have been executed - so .value should remain None
        self.failUnlessEqual(self.test_script_ob.value, None)
        # now move to started.
        self.startEngine()
        # code was executed, so .value should be 2
        self.failUnlessEqual(self.test_script_ob.value, 2)

class TestNames(TestCaseInitialized):
    def testExplicitKnownProperty(self):
        code = "test.value = 2"
        self.parseScriptText(code)
        self.failUnlessEqual(self.test_script_ob.value, 2)

    def testImplicitKnownProperty(self):
        # Setting 'value' should set 'test.value', as the 'test' object was 
        # added with SCRIPTITEM_GLOBALMEMBERS
        code = "value = 2"
        self.parseScriptText(code)
        if not skip_known_failures:
            self.failUnlessEqual(self.test_script_ob.value, 2)

class TestExceptions(TestCaseInitialized):
    expecting_errors = True # stop base class from complaining about exceptions
    def testLineNumber(self):
        code = "// a comment line\nx = bad_name\n"
        self.parseScriptText(code, expect_exc=True)
        ctx, line, col = self.site.last_error.GetSourcePosition()
        if not skip_known_failures:
            self.failUnlessEqual(line, 2)

    def testCOMException(self):
        code = "test.fail()"
        self.parseScriptText(code, expect_exc=True)
        scode, hlp, desc, blah, blah, hresult = self.site.last_error.GetExceptionInfo()
        self.failUnless(desc.startswith("COM Error"), desc)

class TestDispatchConsumer(TestCaseInitialized):
    def testExpando(self):
        code = "test.expando = 'new value'"
        self.parseScriptText(code)
        # todo: check the new value - but how to do that (we don't have
        # SCRIPTTEXT_ISEXPRESSION working yet)

if __name__=='__main__':
    try:
        pythoncom.CoCreateInstance(AXTAM_CLSID, None, pythoncom.CLSCTX_SERVER,
                                   pythoncom.IID_IUnknown)
        # cool - no problem - we can continue
    except pythoncom.error, details:
        print >> sys.stderr, "The axtam engine has not been registered - cannot execute tests"
        sys.exit(1)

    unittest.main()
