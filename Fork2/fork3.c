#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t p1Abu,p2Abu,p2,p3,p4,p5,p6;
	p1Abu = getpid();
	p2 = fork();
	waitpid(p2,NULL,0);
	if(p2 == 0){
	p2Abu = getpid();
	p3 = fork();
		if(p3 != 0){
		p4 = fork();
		wait(NULL);
		wait(NULL);
		}else{p5 = fork();wait(NULL);}
		if(p4 == 0){p6 = fork();wait(NULL);}
	}
	if(p3 == 0 || p4 == 0){
		if(p5 == 0 || p6 == 0){
		printf("Mi pid es %d, la de mi padre %d y la de mi abuelo es %d \n",getpid(),getppid(),p2Abu);
		}else{
		printf("Mi pid es %d, la de mi padre %d y la de mi abuelo es %d \n",getpid(),getppid(),p1Abu);
		}
	}else{printf("Mi pid es %d\n",getpid());}
exit(0);
}
