#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pidHijo1, pidHijo2, pidNieto2_2;
	
	pidHijo1 = fork();
	if (pidHijo1 != 0){
	pidHijo2 = fork();
		if(pidHijo2 == 0 && pidHijo1 != 0){
		pidNieto2_2 = fork();
		}
	}
	if(pidNieto2_2 != 0){
	wait(NULL);
	}
	if(pidHijo2 != 0 && pidHijo1 != 0){
	wait(NULL);
	wait(NULL);
	//printf("Soy el padre \n");
	}
	//if(pidHijo1 == 0){printf("Soy el hijo1\n");}
	//if(pidNieto2_2 == 0 && pidHijo2 == 0){printf("Soy el nieto\n");}
	//if (pidHijo2 == 0 && pidNieto2_2 != 0){printf("Soy el hijo 2\n");}

	if (getpid() % 2 == 0){
		printf("Mi identificador es %d y el de mi padre %d \n",getpid(),getppid());}else{
		printf("Mi identificador es el %d\n",getpid());
	}
exit(0);
}
