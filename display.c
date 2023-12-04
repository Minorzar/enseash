#include "display.h"

void welcomeShell(){
	write(1, WELCOME, strlen(WELCOME) - 1) ;
}

void promptLine(){
	write(1, PROMPT, strlen(PROMPT) - 1) ;
}

void writeError(char* error){
	write(2, error, strlen(error) - 1) ;
}

void exitLine(){
	write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE) - 1) ;
}

void prompWithStatus(int type, int status, long time){

	char message[MAX_INPUT_SIZE] ;

	snprintf(message, sizeof(message), "enseash [%s:%d|%ldms] %% ",SIGNAL_OR_CODE(type), status,time);
	write(1, message, strlen(message)) ;

}

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
