#include "display.h"
#include "exec.h"



int main() {

	char userInput[MAX_INPUT_SIZE];
	ssize_t byteRead;
    int status;
    struct timespec start_time, end_time;
    long time_elapsed;
	char *delim = " ";
    char *functionBuffer[MAX_INPUT_SIZE];

    welcomeShell();
	while (1) {

    	byteRead = read(STDIN_FILENO, userInput, sizeof(userInput));

        // Reading error
    	if (byteRead < 0) {

       	 writeError(READ_ERROR);
        
        }

        // Ctrl + d case
        if (byteRead == 0) {

            exitLine();
            return EXIT_SUCCESS;
        
        }

		// No input (just enter)
        if (byteRead == 1) {

       		promptLine();
        
   		}

		else {
            
            if (byteRead) {
    
            // Get rid of \n
    		userInput[byteRead - 1] = '\0';

            }

            // Exit case
            if (strcmp(userInput, EXIT) == 0) {
            
                exitLine();
                return EXIT_SUCCESS;
            
            }

            clock_gettime(CLOCK_MONOTONIC, &start_time);

			pid_t pid = fork();

            if (pid == -1) {
            
          		writeError(SON_ERROR);
            
            }
            
            else if (pid != 0) { // The father code
            
            	wait(&status);

                clock_gettime(CLOCK_MONOTONIC, &end_time);
                time_elapsed = ((end_time.tv_nsec - start_time.tv_nsec) / 1e6); // convert ns to ms

                if (WIFEXITED(status)) {    // Exit code
            
                    prompWithStatus(EXT, WEXITSTATUS(status), time_elapsed);
            
                }

                else if (WIFSIGNALED(status)) {   // Exit signal
            
                    prompWithStatus(SIGNAL, WTERMSIG(status), time_elapsed);
            
                }
			
            }
            
            else { // The son code 

                if (redirectionHandler(userInput, functionBuffer) != NULL){     // To prevent an unwanted re run (case of | encountered)

                    execvp(functionBuffer[0], functionBuffer);
                    perror(FUNCTION_ERROR);
                    exit(EXIT_FAILURE);

                }
                else{

                    return EXIT_SUCCESS;
                
                }
                
        	}
		
        }

	}
	
    return EXIT_FAILURE;

}