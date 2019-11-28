#include "filectl.h"

void usage()
{
	printf("Usage:\n./vm [FILE]\n");
	exit(1);
}

uint8_t *load_file(char *filename)
//load the file
{
	FILE *file;

	//int size;
	uint8_t *code = NULL;
	struct stat st;

	if ((file = fopen(filename, "r"))){
		fseek(file,0,SEEK_END);
		fstat(fileno(file), &st);
		code = (uint8_t *) malloc (st.st_size);
		fread((void *) code, 1, st.st_size, file);
		return code;

	} else {
		printf("ERROR: cannot open file %s\n", filename);
		usage();
	}

	return NULL;
}


