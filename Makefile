CC = gcc
CFLAGS= -c -Wall
TARGET= vm
INST = instructions
MATH = $(INST)/math
INC= include
HEADERS= $(INC)/stack.h $(INC)/filectl.h  $(INST)/instructions.h
OBJECTS= $(TARGET).o $(INC)/stack.o $(INST)/$(INST).o $(INC)/filectl.o $(MATH)/math.o

$(TARGET): $(OBJECTS)
	@echo compiling project
	$(CC) -o $(TARGET) $(OBJECTS)

$(TARGET).o: $(TARGET).c $(HEADERS)
	@echo creating target object
	$(CC) $(CFLAGS) $(TARGET).c
	
stack.o: stack.c stack.h
	@echo creating stack objcet
	$(CC) $(CFLAGS) $(INC)/stack.c

instructions.o: $(INST)/$(INST).c $(HEADERS)
	@echo creating instructins object
	$(CC) $(CFLAGS) $(INST)/$(INST).c

filectl.o: filectl.c filectl.h
	@echo creating filectl object
	$(CC) $(CFLAGS) $(INC)/filectl.c

math.o: $(MATH)/math.c $(HEADERS)
	@echo math
	$(CC) $(CFLAGS) $(MATH)/math.c

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET) 


clnobj: 
	rm -f $(OBJECTS)
