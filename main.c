#include "display.h"


int main() {

	char userInput[MAX_INPUT_SIZE];
	ssize_t byteRead;
    int status;

    welcomeShell();
	while (1) {

    	byteRead = read(0, userInput, sizeof(userInput));

        // Reading error
    	if (byteRead < 0) {

       	 writeError(READ_ERROR);
        
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

			pid_t pid = fork();

            if (pid == -1) {
            
          		writeError(SON_ERROR);
            
            }
            else if (pid != 0) { // The father code
            
            			wait(&status);
                        promptLine() ;
			
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