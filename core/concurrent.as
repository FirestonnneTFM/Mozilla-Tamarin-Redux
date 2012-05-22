package flash.concurrent 
{

include "api-versions.as"

[API(CONFIG::SWF_17)]
[native(cls="MutexClass",instance="MutexObject",gc="exact")]
public final class Mutex
{
    public function Mutex()
    {
        ctor();
    }
    private native function ctor():void;
    public native function lock(): void;
    public native function unlock():void;
    public native function tryLock():Boolean;
}

[API(CONFIG::SWF_17)]
[native(cls="ConditionClass",instance="ConditionObject",gc="exact")]
public final class Condition 
{
    public native function wait(mutex: Mutex):void;
    public native function broadcast():void;
    public native function signal():void;
}
}