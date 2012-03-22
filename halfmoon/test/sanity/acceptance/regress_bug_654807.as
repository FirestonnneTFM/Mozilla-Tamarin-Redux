
dynamic class DynamicArray extends Array {}
class SealedDynamicArray extends DynamicArray {}

function run_tests(b:Array, mode:String)
{
	b[0] = 44;
}
print(run_tests(new SealedDynamicArray, "semisealed")); 

