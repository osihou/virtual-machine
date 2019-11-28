#ifndef _FILECTL_H_
#define _FILECTL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



#define MAX_FILENAME 256

uint8_t *load_file(char *filename);

void usage();

#endif
