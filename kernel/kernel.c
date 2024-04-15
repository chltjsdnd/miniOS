#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input,"exit") == 0) {
            break;
        }

        else if (strcmp(input,"minisystem") == 0){
            minisystem();
        }
        else if (strcmp(input, "calc") == 0){
        	calculator();
        }
        else if (strcmp(input, "custom_fork") == 0){
        	custom_fork();
        }
        else if (strcmp(input, "ipc_pipe") == 0){
        	ipc_pipe();
        }
        else system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return(1);
}

void print_minios(char* str) {
        printf("%s\n",str);
}

void calculator(){
	float a,b;
	char operation[10];
	
	printf("select operator(+,-,*,/) : ");
	scanf("%s", operation);
	printf("input two numbers : ");
	scanf("%f %f", &a, &b);
	
	if(strcmp(operation, "+") == 0){
		printf("result : %.1f\n", add(a,b));
	}
	else if(strcmp(operation, "-") == 0){
		printf("result : %.1f\n", subtract(a,b));
	}
	else if(strcmp(operation, "*") == 0){
		printf("result : %.1f\n", multiply(a,b));
	}
	else if(strcmp(operation, "/") == 0){
		printf("result : %.1f\n", divide(a,b));
	}
	else{
		printf("unknown operation!\n");
	}
}
