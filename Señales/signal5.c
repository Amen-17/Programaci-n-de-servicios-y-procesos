#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>

int num, pe;
char buffer[10];

void gestionarsenal(int numsen){
	
	switch(numsen){
		case 10:
			read(pe,buffer,4);
			num = atoi(buffer);
			printf("Numero par recibido %d recibido por el proceso P2 con pid %d\n",num,getpid());
		break;
		case 12:
			read(pe,buffer,4);
			num = atoi(buffer);
			printf("Numero impar recibido %d recibido por el proceso P3 con pid %d\n",num,getpid());
		break;
	}
}

void main(){
	//signal(SIGINT,gestionarsenal);
	signal(SIGUSR1,gestionarsenal);
	signal(SIGUSR2,gestionarsenal);
	int arc1;
	pid_t p1,p2,p3;
	arc1 = mkfifo("PIPE1",0666);
	p1 = getpid();
	bool par = false;
	p2 = fork();
	if (p2 != 0){
		p3 = fork();
	}
	do{
		if(p2 == 0 || p3 == 0){
		pe = open("PIPE1",0);
		pause();
		}
		if(p2 != 0 && p3 != 0){
			pe = open("PIPE1",1);
			printf("Introduce un número: ");
			scanf("%d",&num);
			sprintf(buffer,"%d",num);
			write(pe,buffer,strlen(buffer));
			if(num == 0){
			}else{
				if(num % 2 == 0){
					kill(p2,SIGUSR1);
				}else{
					kill(p3,SIGUSR2);
				}
				sleep(1);
			}
		}
	}while(num != 0);
	if (p1 = getpid()){
		printf("Mandando señal de terminación al proceso hijo p2 con pid %d\n",p2);
		kill(p2,9);
		printf("Mandando señal de terminación al proceso hijo p3 con pid %d\n",p3);
		kill(p3,9);
		printf("Fin del proceso padre con pid %d\n",p1);
	}
exit(0);
}
