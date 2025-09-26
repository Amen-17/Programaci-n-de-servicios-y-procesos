#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	pid_t pidHijo, pidNieto;
	pidHijo = fork();
	if(pidHijo == 0){
		pidNieto = fork();
	}
	
	if (pidHijo != 0){
		waitpid(pidHijo,NULL,0);
		printf("Soy P1 el padre mi pid es %d y el de mi hijo es %d\n",getpid(),pidHijo);
	}else{
		if(pidNieto != 0){
		wait(NULL);
		printf("Soy P2 el hijo mi pid es %d y el de padre es %d \n",getpid(),getppid());
		}else{
		printf("Soy P3 el nieto mi pid es %d y el de padre es %d \n",getpid(),getppid());
		}
	}

exit(0);
}

