#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define MAX_STACK 512

typedef struct INSTANCE_t {
	uint8_t type;
	union {
		uint8_t u8;
		uint8_t i8;
		void *ptr;
		uint8_t *iptr;
	};

} INSTANCE;

typedef struct STACK_t {
	int top;
	int size;
	INSTANCE *stack;
} STACK;


//function to initialize the stack
STACK stack_init (int size);

//function for the stack push
int stack_push(STACK *s, INSTANCE i);

//function for stack pop
INSTANCE stack_pop(STACK *s);

//function for stack peek
INSTANCE stack_peek(STACK *s);


#endif
