#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	pid_t pidHijo1, pidHijo2;
	pidHijo1 = fork();
	if (pidHijo1 != 0){
	pidHijo2 = fork();
	}
	if(pidHijo1 != 0 && pidHijo2 != 0){
	wait(NULL);
	wait(NULL);
	}else if(pidHijo1 == 0){
	sleep(10);
	printf("Despierto\n");
	}else{
	printf("Soy el proceso P3 y mi pid es %d y el de mi padre es %d \n",getpid(),getppid());
	}
exit(0);
}
