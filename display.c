#include "display.h"

void welcomeShell(){
	write(1, WELCOME, strlen(WELCOME) - 1) ;
}
