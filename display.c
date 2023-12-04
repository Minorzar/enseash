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