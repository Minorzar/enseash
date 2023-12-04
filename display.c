#include "display.h"



void welcomeShell(){
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME) - 1) ;
}

void promptLine(){
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT) - 1) ;
}

void writeError(char* error){
	write(STDERR_FILENO, error, strlen(error) - 1) ;
}

void exitLine(){
	write(STDOUT_FILENO, EXIT_MESSAGE, strlen(EXIT_MESSAGE) - 1) ;
}

void prompWithStatus(int type, int status, long time){

	char message[MAX_INPUT_SIZE] ;

	snprintf(message, sizeof(message), "enseash [%s:%d|%ldms] %% ",SIGNAL_OR_CODE(type), status,time);
	write(STDOUT_FILENO, message, strlen(message)) ;

}
