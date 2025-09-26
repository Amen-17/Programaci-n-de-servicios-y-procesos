#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	 pid_t pidHij;
	 printf("CCC \n");
	 pidHij = fork();
	 if (pidHij != 0){
	 	wait(NULL);
	 	printf("AAA \n");
	 } else{ 
	 printf("BBB \n");
	}
 exit(0);
}

