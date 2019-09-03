#include<assert.h>
#include "stack.h"
#include "stack.c"
void test_capacity_one_stack()
{

Stack stk= stack_new(1);

//Stack *stk=&stk_instance;

StackResult result;

assert(stack_empty(stk));
assert(!stack_full(stk));


stack_peek(stk,&result);
assert(result.status==STACK_EMPTY);



stk=stack_push(stk,100,&result);
assert(result.status==STACK_OK);

stk=stack_push(stk,101,&result);
assert(result.status==STACK_FULL);

stk=stack_peek(stk,&result);
assert(result.data==100&&result.status==STACK_OK);


stk=stack_pop(stk,&result);
assert(result.data==100 && result.status==STACK_OK);

assert(stack_empty(stk));

}







void test_arbitrary_stack()
{


Stack stk2= stack_new(0);

//Stack stk2=&stk_instance2;

StackResult result2={0,RESULT_INVALID};
int i;
for(i=0;i<MAX_DEPTH;i++)
{
stk2=stack_push(stk2,i,&result2);
assert(result2.status==STACK_OK);
result2.status=RESULT_INVALID;


}

stk2=stack_push(stk2,i,&result2);
assert(result2.status==STACK_FULL);


for(i=0;i<MAX_DEPTH;i++)
{
result2.status=0;
stk2=stack_peek(stk2,&result2);
assert(result2.data==MAX_DEPTH-i-1 );
result2.status=RESULT_INVALID;
stk2=stack_pop(stk2,&result2);
assert(result2.status==STACK_OK);


}

assert(stack_empty(stk2));


}




int main()
{

test_capacity_one_stack();
test_arbitrary_stack();

printf("\n executed successfully\n");
return 0;


}
