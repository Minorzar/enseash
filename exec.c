#include "exec.h"

char** getFunction(char* input, char** buffer){
	char* delim = " " ;
	int len = strlen(input) ;
    char *token = strtok(input, delim);
    int index = 0;

    while (token != NULL) {
    
        buffer[index++] = token;
        token = strtok(NULL, delim);	// Get to next parameter
    
    }
    
    buffer[index] = NULL ;	// To indicate the end of the parameters for execvp

    return buffer ;
}

char** redirectionHandler(char* input, char** buffer){

    int input_fd = -1;
    int output_fd = -1;
    int status;

    // Get the function and its parameters
    getFunction(input, buffer);

    // Check for redirection
    for (int i = 0; buffer[i] != NULL; ++i) {

        if (strcmp(buffer[i], "<") == 0) {        // Check for < redirection
            
            input_fd = open(buffer[i + 1], O_RDONLY);
            if (input_fd == -1) {
                
                perror(FILE_ERROR);
                exit(EXIT_FAILURE);
            
            }
            
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
            buffer[i] = NULL;
            break;

        }
        else if (strcmp(buffer[i], ">") == 0) {    // Check for > redirection
            
            output_fd = open(buffer[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if (output_fd == -1) {
            
                perror(FILE_ERROR);
                exit(EXIT_FAILURE);
            
            }
            
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
            buffer[i] = NULL;
            break;

        }
    
    }

    return buffer;

}
