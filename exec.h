#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>



// Macro and define
#define FILE_ERROR "Failed to open input file"
#define FUNCTION_ERROR "Failed to use the command"
#define PIPE_ERROR "Failed to create the pipe"
#define FORK_ERROR "Faile to create the fork"


#define MAX_FUN_SIZE 256



// Functions declaration
char** getFunction(char*, char**) ;
char** redirectionHandler(char*, char**) ;