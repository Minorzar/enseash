#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Macro and define
#define WELCOME "Bienvenue dans le Shell ENSEA.\r\nPour quitter tapez 'exit'.\r\nenseash %  "
#define PROMPT "enseash %  "
#define NEW_LINE "\r\n"
#define MAX_INPUT_SIZE 256

// Functions declaration
void welcomeShell(void) ;
void promptLine(void) ;
void writeError(char*) ;




