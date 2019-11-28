#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/stack.h"
#include "../include/filectl.h"

typedef uint8_t* (*instruction)(uint8_t*, STACK *);
#define NUM_INS 256


#define HALT '!'

#define PUSH_CHAR ','
uint8_t *ins_push_char(uint8_t *ip, STACK *s);
#define PUSH_INT '*'
uint8_t *ins_push_int(uint8_t *ip, STACK *s);
#define PUSH_IPTR '&'
uint8_t *ins_push_iptr(uint8_t *ip, STACK *s);


#define ECHO_CHAR '#'
uint8_t *ins_echo_char(uint8_t *ip, STACK *s);
#define ECHO_STACK '['
uint8_t *ins_echo_stack(uint8_t *ip, STACK *s);
#define ECHO_INT '@'
uint8_t *ins_echo_int(uint8_t *ip, STACK *s);

#define STACK_ADD '+'
uint8_t *ins_add(uint8_t *ip, STACK *s);
#define STACK_SUB '-'
uint8_t *ins_sub(uint8_t *ip, STACK *s);

#define READ_FILE '%'
uint8_t *ins_read_file(uint8_t *ip, STACK *s);

#define RETURN '$'
uint8_t *ins_return(uint8_t *ip, STACK *s);

#define JE '~'
uint8_t *ins_je(uint8_t *ip, STACK *s);


uint8_t *ins_nop(uint8_t *ip, STACK *s);

#endif
