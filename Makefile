CC = gcc
CFLAGS= -c -Wall
TARGET= vm
HEADERS= include/stack.h instructions/instructions.h include/filectl.h
OBJECTS= $(TARGET).o include/stack.o instructions/instructions.o include/filectl.o

$(TARGET): $(OBJECTS)
	@echo compiling project
	$(CC) -o $(TARGET) $(OBJECTS)

$(TARGET).o: $(TARGET).c $(HEADERS)
	@echo creating target object
	$(CC) $(CFLAGS) $(TARGET).c
	
stack.o: stack.c stack.h
	@echo creating stack objcet
	$(CC) $(CFLAGS) include/stack.c

instructions.o: instructions/instructions.c $(HEADERS)
	@echo creating instructins object
	$(CC) $(CFLAGS) instructions/instructions.c

filectl.o: filectl.c filectl.h
	@echo creating filectl object
	$(CC) $(CFLAGS) include/filectl.c

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET) 


clnobj: 
	rm -f $(OBJECTS)
