#ifndef __IO_H__
#define __IO_H__

#define RST  "\x1B[0m"   // RESET
#define KRED  "\x1B[31m" // RED
#define KGRN  "\x1B[32m" // GREEN
#define KYEL  "\x1B[33m" // YELLOW
#define KBLU  "\x1B[34m" // BLUE
#define KMAG  "\x1B[35m" // MAGENTA
#define KCYN  "\x1B[36m" // CYAN
#define KWHT  "\x1B[37m" // WHITE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "interface.h"
#include "AVL.h"


#define Pagsize 10
#define buffsize 10


/**
 *	Função que 
 *	@param 
 */
void menu(SGV s);

#endif
