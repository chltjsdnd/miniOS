#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int custom_fork(){
	pid_t pid;
	
	pid = fork();
	
	if(pid < 0) {
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if(pid == 0){
		printf("Child process : pid is %d\n", getpid());
		execlp("/bin/ls", "ls", NULL);
	}
	else{
		printf("Parent process : pid is %d\n", getpid());
		wait(NULL);
		printf("Parent prcess : child's pid is %d\n", pid);
	}
	return 0;
}
