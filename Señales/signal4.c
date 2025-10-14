#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void gestionaSenal(int num){
	time_t tiempo = time(NULL);
	struct tm *tm_info = localtime(&tiempo);
printf("Señal de alarma recibida a las %02d:%02d:%02d");
}
void main(){
	int num1, num2;
	printf("¿Cuántas veces sonará a alarma?");
	scanf("%d",num1);
	printf("¿Cada cuántos seugnod se repetirá la alarma?");
	scanf("%d",num2);
	for(int i = 0; i < num1; i++){
		signal(SIGUSR1,gestionaSenal);
		kill(getpid(),SIGUSR1);
		sleep(num2);
	}
}
