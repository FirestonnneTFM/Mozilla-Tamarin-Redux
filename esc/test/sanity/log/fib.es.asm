
{ 'abc_class': 'AbcFile'
, 'minor_version': 16
, 'major_version': 46
, 'int_pool': [ 
              , '2'
              , '1'
              , '10' ]
, 'uint_pool': [  ]
, 'double_pool': [  ]
, 'utf8_pool': [ 
               , ''
               , 'Object'
               , 'Array'
               , 'RegExp'
               , 'Fib'
               , 'val'
               , 'n'
               , 'print' ]
, 'namespace_pool': [ 
                    , { 'kind': 'PackageNamespace'
                      , 'utf8': '1' }
                    , { 'kind': 'AnonymousNamespace'
                      , 'utf8': '1' } ]
, 'nsset_pool': [ 
                , [ '2' ] ]
, 'name_pool': [ 
               , { 'kind': 'QName'
                 , 'ns': '1'
                 , 'utf8': '2' }
               , { 'kind': 'QName'
                 , 'ns': '1'
                 , 'utf8': '3' }
               , { 'kind': 'QName'
                 , 'ns': '1'
                 , 'utf8': '4' }
               , { 'kind': 'QName'
                 , 'ns': '2'
                 , 'utf8': '5' }
               , { 'kind': 'QName'
                 , 'ns': '2'
                 , 'utf8': '2' }
               , { 'kind': 'QName'
                 , 'ns': '2'
                 , 'utf8': '6' }
               , { 'kind': 'QName'
                 , 'ns': '2'
                 , 'utf8': '7' }
               , { 'kind': 'Multiname'
                 , 'utf8': '7'
                 , 'nsset': '1' }
               , { 'kind': 'Multiname'
                 , 'utf8': '6'
                 , 'nsset': '1' }
               , { 'kind': 'Multiname'
                 , 'utf8': '5'
                 , 'nsset': '1' }
               , { 'kind': 'Multiname'
                 , 'utf8': '8'
                 , 'nsset': '1' } ]
, 'method_infos': [ { 'ret_type': 
                    , 'param_types': []
                    , 'name': 
                    , 'flags': 
                    , 'optional_count': 
                    , 'value_kind': [  ]
                    , 'param_names': [  ] }
                  , { 'ret_type': 
                    , 'param_types': []
                    , 'name': 
                    , 'flags': 
                    , 'optional_count': 
                    , 'value_kind': [  ]
                    , 'param_names': [  ] }
                  , { 'ret_type': 
                    , 'param_types': []
                    , 'name': 
                    , 'flags': 
                    , 'optional_count': 
                    , 'value_kind': [  ]
                    , 'param_names': [  ] }
                  ,  ]
, 'method_bodys': [ { 'method_info': 
                    , 'max_stack': 
                    , 'max_regs': 
                    , 'scope_depth': 
                    , 'max_scope': 
                    , 'code': [ getlocal0
                              , dup
                              , pushscope
                              , pushundefined
                              , pop
                              , popscope
                              , newactivation
                              , dup
                              , setlocal2
                              , dup
                              , pushwith
                              , findproperty 07
                              , getlocal1
                              , setproperty 07
                              , pushundefined
                              , pop
                              , getlocal0
                              , constructsuper 00
                              , popscope
                              , getlocal0
                              , pushscope
                              , pushscope
                              , findpropstrict 08
                              , getproperty 08
                              , pushint 01
                              , lessthan
                              , iffalse 00 00 00
                              , findproperty 09
                              , findpropstrict 08
                              , getproperty 08
                              , dup
                              , setlocal3
                              , setproperty 09
                              , getlocal3
                              , kill 03
                              , pop
                              , jump 00 00 00
                              , findproperty 09
                              , findpropstrict 0a
                              , getproperty 0a
                              , findpropstrict 08
                              , getproperty 08
                              , pushint 02
                              , subtract
                              , construct 01
                              , getproperty 09
                              , findpropstrict 0a
                              , getproperty 0a
                              , findpropstrict 08
                              , getproperty 08
                              , pushint 01
                              , subtract
                              , construct 01
                              , getproperty 09
                              , add
                              , dup
                              , setlocal3
                              , setproperty 09
                              , getlocal3
                              , kill 03
                              , pop
                              , kill 02
                              , returnvoid
                              ,  ]
                    , 'exceptions': [  ]
                    , 'fixtures': [  ] }
                  , { 'method_info': 
                    , 'max_stack': 
                    , 'max_regs': 
                    , 'scope_depth': 
                    , 'max_scope': 
                    , 'code': [ getlocal0
                              , pushscope
                              , returnvoid
                              ,  ]
                    , 'exceptions': [  ]
                    , 'fixtures': [  ] }
                  , { 'method_info': 
                    , 'max_stack': 
                    , 'max_regs': 
                    , 'scope_depth': 
                    , 'max_scope': 
                    , 'code': [ getlocal0
                              , pushscope
                              , findpropstrict 05
                              , getproperty 05
                              , dup
                              , pushscope
                              , newclass 00
                              , popscope
                              , getglobalscope
                              , swap
                              , initproperty 04
                              , findpropstrict 0b
                              , getproperty 0b
                              , pushnull
                              , findpropstrict 0a
                              , getproperty 0a
                              , pushint 03
                              , construct 01
                              , getproperty 09
                              , call 01
                              , pop
                              , returnvoid
                              ,  ]
                    , 'exceptions': [  ]
                    , 'fixtures': [  ] }
                  ,  ] }