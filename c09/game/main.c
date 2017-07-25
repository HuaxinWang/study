#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"loginRegiste.h"
#include"gameRules.h"
#include"Menu.h"
#include"function.h"
#define NAME_LEN 200
#define LIVE 1
#define DEATH 0

int main()
{
	srand((unsigned)time(NULL));
	menu();
	return 0;
}
