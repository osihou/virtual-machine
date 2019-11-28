#include "instructions.h"



uint8_t *ins_nop(uint8_t *ip, STACK *s)
//do nothing
{
	return ip-1;
}

uint8_t *ins_push_char(uint8_t *ip, STACK *s)
//insert char onto the stack
{
	INSTANCE i;
	i.type = 'c';
	i.u8 = *(ip-1);
	stack_push(s,i);
	return ip-2;
}

uint8_t *ins_echo_char(uint8_t *ip, STACK *s)
//echo the char from the stack
{
	INSTANCE i = stack_pop(s);
	putchar(i.u8);
	return ip-1;
}

uint8_t *ins_echo_int(uint8_t *ip, STACK *s)
//echo the int from the stack
{
	INSTANCE i = stack_pop(s);
	printf("%d", i.i8);
	return ip-1;
}


uint8_t *ins_echo_stack(uint8_t *ip, STACK *s)
//echo chars till &
{
	INSTANCE i;
	while((i = stack_pop(s)).u8 != ']')
		putchar(i.u8);
	
	return ip-1;
}
uint8_t *ins_push_int(uint8_t *ip, STACK *s)
//insert int onto the stack
{
	INSTANCE i;
	i.type = 1;
	i.i8 = *(ip-1) - 48;
	stack_push(s,i);
	return ip-2;
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

uint8_t *ins_read_file(uint8_t *ip, STACK *s)
//read & eval file
{
	INSTANCE i;
	char filename[256];
	int ct = 0;
	while((i = stack_pop(s)).u8 != '%')
		filename[ct++] = i.u8;
		
	filename[ct] = '\0';
	
	i.iptr = ip-1;
	stack_push(s,i); 

	ip = load_file(filename);
	
	return ip;
}


uint8_t *ins_push_iptr(uint8_t *ip, STACK *s)
{
	INSTANCE i;
	i.iptr = ip;
	stack_push(s,i);
	return ip-1;

}

uint8_t *ins_je(uint8_t *ip, STACK *s)
//jump if equals
{
	INSTANCE i;
	if(( i = stack_pop(s)).i8 == 0)
		return stack_pop(s).iptr;

	else return ip - 1;

}

uint8_t *ins_sub(uint8_t *ip, STACK *s)
{
	INSTANCE i;
	i.type = 1;
	i.i8 = stack_pop(s).i8 - stack_pop(s).i8;

	stack_push(s, i);
	return ip-1;

}

uint8_t *ins_return(uint8_t *ip, STACK *s)
//return back to parent
//for now it cannot have returned anything
//leaves empty stack
{

	INSTANCE i;
	i = stack_pop(s);
	return i.iptr;

}

