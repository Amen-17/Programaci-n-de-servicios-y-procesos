#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

void main(){
  int  arc1,arc2,bytesleidos,p1,p2,num,num2;
  char buffer[10];
	arc1 = mkfifo("FIFO1", 0666);
	if(arc1 == 0){printf("Archivo creado correctamente\n");}
	p1 = open("FIFO1",1);
	
	srand(time(NULL));
	num =(rand() % 10)+1;
	sprintf(buffer,"%d",num);
	write(p1,buffer,strlen(buffer));
	close(p1);
	
	p2 = open("FIFO2",0);
	read(p2,buffer,4);
	num2 = atoi(buffer);
	printf("El factorial de %d es %d\n",num ,num2);
	close(p2);
	
	remove("FIFO1");
exit(0);
}
