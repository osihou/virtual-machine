#include "../instructions.h"
uint8_t *ins_sub(uint8_t *ip, STACK *s)
			{
	INSTANCE i;
	i.type = 1;
	i.i8 = stack_pop(s).i8 - stack_pop(s).i8;
	
	stack_push(s, i);
	return ip-1;
		
}
	
uint8_t *ins_add(uint8_t *ip, STACK *s)
//add two numbers from the stack
{
	INSTANCE i;
	i.type = 1;
	i.i8 = stack_pop(s).i8 + stack_pop(s).i8;
	stack_push(s,i);
	return ip-1;
}
