/*Compile on Windows: run command prompt and use gcc
Compile on linux:
 - On Windows: Use wsl
 - run "make"
The "make" command will activate the "Makefile" file and the app is compiled using Clang
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "headers/color.h"

#define err_code_01 "Insufficient Memory"
#define MAX 18400000000000000000

void getBin(unsigned long long a){
	int *list;
	int *ptr = &list;
	int i;
	int length;

	list = (int*)malloc(sizeof(int));

	printf("\nMemory Address: %p\n", ptr);

	if (list == NULL){
		printf("\n%sError: %s (Code 01)", RED, err_code_01);
		exit(1);
	}
	else{
		for (i = 0; i > -1; i++){
			list = realloc(list, (i+1)*sizeof(int)); //increase the size of array to add more remainders

			list[i] = a%2;
		
			a = floor(a/2);

			if (a<1){
				break;
			}
		}
		
		length = i;

		printf("%s\nBinary: ", GREEN);

		for (int k = length; k>=0; k--){
			printf("%d", list[k]);
		}
		free(list); //prevent memory leak
	}
}

int main(void){

	#ifdef _WIN32
	//Enabling color processing in Command Prompt
	WinEnableColor();
	#endif

	unsigned long long a;
	char b; //placeholder only
	int i;

	//The code from line 60-64 will take effect when clear the screen suring start
	
	for (i = 0; i>-1; i++){
		printf("%sNote: Max number is 18,400,000,000,000,000,000.\n\n", CYAN);

		printf("%sEnter an interger to get the binary value: ", NORM);
		scanf("%llu", &a);
			
		if (a>MAX){
			printf("\nMax number exceeded. Converting 18,400,000,000,000,000,000 to binary.");
			getBin(MAX);
		}
		else{
			getBin(a);
		}

		printf("\n\n%sEnter anything to clear: ", NORM);
		scanf("%s", &b);
		printf("\n");
		
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif
	}
  return 0;
}