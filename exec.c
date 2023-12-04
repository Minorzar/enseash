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

char** redirectionHandler(char* input, char** buffer) {

    int input_fd = -1;
    int output_fd = -1;
    int status;
    int pipe_fd[2];

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



        else if (strcmp(buffer[i], "|") == 0) {     // Check for pipe usage

            pid_t child1, child2;
            char* cmd1[MAX_FUN_SIZE] ;
            char* cmd2[MAX_FUN_SIZE] ;
            int count = 0 ;

            for(int j = 0 ; j < i ; j++){   // Get the first command

                cmd1[j] = buffer[j] ;

            }

            cmd1[i] = NULL ;

            for(int j = i+1 ; buffer[j] != NULL ; j++ ){    // Get the second command

                cmd2[count++] = buffer[j] ;

            }

            cmd2[count] = NULL ;


            if (pipe(pipe_fd) == -1){

                perror(PIPE_ERROR) ;
                exit(EXIT_FAILURE) ;

            }

            if ((child1 = fork()) == -1){

                perror(FORK_ERROR) ;
                exit(EXIT_FAILURE) ;

            }


            if(child1 == 0){        // Execute the first command

                close(pipe_fd[0]);
                dup2(pipe_fd[1], STDOUT_FILENO) ;
                close(pipe_fd[1]) ;

                execvp(cmd1[0], cmd1) ;
                perror(FUNCTION_ERROR) ;
                exit(EXIT_FAILURE) ;

            }
            else{

                if((child2 = fork()) == -1){

                    perror(FORK_ERROR) ;
                    exit(EXIT_FAILURE) ;

                }

                if(child2 == 0){        // Execute the second command

                    close(pipe_fd[1]) ;
                    dup2(pipe_fd[0], STDIN_FILENO) ;
                    close(pipe_fd[0]) ;

                    execvp(cmd2[0], cmd2) ;
                    perror(FUNCTION_ERROR) ;
                    exit(EXIT_FAILURE) ;

                }

                else{

                    close(pipe_fd[0]) ;
                    close(pipe_fd[1]) ;

                    waitpid(child1, NULL, 0);
                    waitpid(child2, NULL, 0);
                
                }
            
            }

            return NULL ;       // To prevent an unwanted re run of the function

        }

    }

    return buffer;

}

