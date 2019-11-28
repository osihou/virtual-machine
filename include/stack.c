#include "stack.h"


STACK stack_init (int size) 
//function to initialize the stack
{
	STACK s;
	s.top = 0;
	s.size = size;
	s.stack = (INSTANCE *) malloc (sizeof(INSTANCE) * size);
	return s;
}

int stack_push(STACK *s, INSTANCE i)
//function for the stack push
{
	s->stack[s->top++] = i;
	return s->top;
}

INSTANCE stack_pop(STACK *s)
//function for the stack pop
{
	return s->stack[--(s->top)];
}

INSTANCE stack_peek(STACK *s)
//function for the stack peek 
{
	return s->stack[s->top - 1];
}
