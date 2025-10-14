#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int segundos = 0;

void gestionarSenal(int num){
	segundos = segundos + 5;
	printf("Han transcurrido %d segundos.\n",segundos);
}

void main(){
	while(1){
		sleep(5);
		signal(SIGUSR1,gestionarSenal);
		kill(getpid(),SIGUSR1);
		
	};
exit(0);
}
