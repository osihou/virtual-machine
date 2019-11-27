# virtual-machine
This is a basic stack machine implementation.

## Features 
For now it doesn't do anything extraordinary. It can do basic addition and substraciton.
It can echo words and open another file that it tries to execute.

## Usage

To make the binary simply type

``make``

To clean objects

``clnobj``

To clean all

``clean``

To run the the program use:

``./vm [FILENAME] ``

where insted of file name you have to put text file for interpretation.

## Language

INSTRUCTION | CODE | COMMENT
--- | --- | ---
HALT | ! | Stops the machine
PUSH_CHAR | , | Push char onto the stack
PUSH_INT | * | Push int onto the stack
PUSH_IPTR | & | Save current location by pushing the pointer onto the stack
ECHO_CHAR | # | Pop the stack and echo char
ECHO_STACK  | [ | Echos all chars from the stack until it hits the ]
ECHO_INT    | @ | Pop the stack and echo int
STACK_ADD  |+ | Add two integers from the stack and push resoult
STACK_SUB  |-  | Substract two integers from the stack and push result
READ_FILE  |% | Read another file and evaluate it (command endes with %)
RETURN   |$ | Retrun to the parent file
JE      |~ | Pop stack and if it return 0 then jump to saved location
