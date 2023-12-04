#include "display.h"


int main() {

	char userInput[MAX_INPUT_SIZE];
	ssize_t byteRead;
    int status;
    struct timespec start_time, end_time;
    long time_elapsed;

    welcomeShell();
	while (1) {

    	byteRead = read(0, userInput, sizeof(userInput));

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
            
                    prompWithStatus(0, WEXITSTATUS(status), time_elapsed);
            
                } else if (WIFSIGNALED(status)) {   // Exit signal
            
                    prompWithStatus(1, WTERMSIG(status), time_elapsed);
            
                }
			
            }

			else { // The son code

                execlp(userInput, userInput, NULL);
                perror("Failed to use the command");
        		exit(EXIT_FAILURE);
                
        	}
		}

	}
	
    return EXIT_FAILURE;

}