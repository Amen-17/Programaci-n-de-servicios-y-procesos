#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <time.h>

time_t tiempo;
struct tm *tm_info;

void gestionSenal(int num){
	tiempo = time(NULL);
	tm_info = localtime(&tiempo);
printf("Fin del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",
           getpid(), tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
signal(SIGINT,SIG_DFL);
kill (getpid(),3);
}
void main(){
	signal(SIGINT,gestionSenal);
	tiempo = time(NULL);
	tm_info = localtime(&tiempo);
	 printf("Inicio del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",
           getpid(), tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
	while(1){};
exit(0);
}
