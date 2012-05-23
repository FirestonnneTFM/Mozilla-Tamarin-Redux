package flash.concurrent 
{

include "api-versions.as"

[API(CONFIG::SWF_17)]
[native(cls="MutexClass",instance="MutexObject",gc="exact")]
final public class Mutex
{
    public function Mutex()
    {
        ctor();
    }
    private native function ctor() :void;
    public native function lock() :void;
    public native function unlock() :void;
    public native function tryLock() :Boolean;
}

[API(CONFIG::SWF_17)]
[native(cls="ConditionClass",instance="ConditionObject",gc="exact")]
final public class Condition 
{
    public function Condition(mutex:Mutex)
    {
        if (mutex == null)
           throw new ArgumentError("mutex is null");
        ctor(mutex);
    }
    private native function ctor(mutex:Mutex) :void;
     public native function wait(timeout:Number = -1) :Boolean;
    public native function notify() :void;
    public native function notifyAll() :void;

}
}