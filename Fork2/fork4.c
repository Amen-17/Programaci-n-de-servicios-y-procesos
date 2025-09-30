#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t p2,p3,p4,p5;
	int i = (int)getpid();
	p2 = fork();
	if(p2 != 0){
		p3 = fork();
		wait(NULL);
		wait(NULL);
	}
	if(p2 == 0 || p3 == 0){
		i = i + (int)getpid();
		if(p3 == 0){
			p4 = fork();
			wait(NULL);
		}else{
			p5 = fork();
			wait(NULL);
		}
		if(p5 == 0 || p4 == 0){
			i = i + (int)getpid();
		}
	}
	if((int)getpid() % 2 == 0){
		printf("%d\n",(i+10));
	}else{
		printf("%d\n",(i-100));
	}
exit(0);
}
