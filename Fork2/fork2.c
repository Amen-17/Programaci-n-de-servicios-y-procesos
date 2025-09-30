#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pidHijo, pidNieto, pidBisnieto;
	pidHijo = fork();
	waitpid(pidHijo,NULL,0);
	if (pidHijo == 0){
		pidNieto = fork(); 
		waitpid(pidNieto,NULL,0);
	}
	if (pidHijo == 0 && pidNieto == 0){ 
		pidBisnieto = fork();
		waitpid(pidBisnieto,NULL,0);
	}
	
	printf("Mi pid es %d, el de mi padre es %d y la suma de ellos es %d\n",getpid(),getppid(),(getpid()+getppid()));
	
exit(0);
}
