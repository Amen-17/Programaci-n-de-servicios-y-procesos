#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <time.h>
#include <fcntl.h>
#include <string.h>

int fichero;
char texto[100];
time_t tiempo;
struct tm *tm_info;

void gestionarSenal(int num){
	fichero = open("archivo.txt",O_WRONLY | O_APPEND,0644);
	tiempo = time(NULL);
	tm_info = localtime(&tiempo);
 	snprintf(texto, sizeof(texto),"Señal SIGINT recibida a las %02d:%02d:%02d\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
	write(fichero,texto,strlen(texto));
	close(fichero);
}

void main(){
int cont = 1;
	while(1){
	if(cont > 20){signal(SIGINT,SIG_DFL);}
	signal(SIGINT,gestionarSenal);
	cont = cont +1;
	}
exit(0);
}
