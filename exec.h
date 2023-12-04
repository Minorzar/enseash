#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

// Macro and define
#define FILE_ERROR "Failed to open input file"


// Functions declaration
char** getFunction(char*, char**) ;
char** redirectionHandler(char*, char**) ;