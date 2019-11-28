#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "stack.h"
#include "instructions/instructions.h"
#include "filectl.h"

//instruction type functions
void init_ins(instruction *instructions)
{
	for (int i = 0; i < NUM_INS ; i++) 
	//set instructions to no operation
	{
		instructions[i] = ins_nop;
	}

	instructions[PUSH_CHAR] = ins_push_char;
	instructions[PUSH_INT] = ins_push_int;
	instructions[PUSH_IPTR] = ins_push_iptr;

	instructions[ECHO_CHAR]= ins_echo_char;
	instructions[ECHO_STACK]= ins_echo_stack;
	instructions[ECHO_INT] = ins_echo_int;

	instructions[STACK_ADD] = ins_add;
	instructions[STACK_SUB] = ins_sub;
	
	instructions[READ_FILE] = ins_read_file;

	instructions[RETURN] = ins_return;

	instructions[JE] = ins_je;
}



int main (int argc, char *argv[])
//main function
{
	uint8_t *code;
	uint8_t *ip;
	instruction instructions[NUM_INS];

	STACK data;
	
	if (argc != 2) 
	//print usage menu if ther is no file
	{
		usage();
	}

	init_ins(instructions);

	code = load_file(argv[1]);
	
	data = stack_init(MAX_STACK);
	
	ip = code;

	while (*ip != HALT)
	//execute functions from code while program does not hit the bang mark
	{
			ip = instructions[*ip](ip, &data);
	}

	return 0;

}
