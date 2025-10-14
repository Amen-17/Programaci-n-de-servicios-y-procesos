#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void main(){
	int  arc1,bytesleidos,p1,p2,num;
	char buffer[10];
	arc1 = mkfifo("FIFO2", 0666);
	p1 = open("FIFO1",0);
	if(arc1 == 0){printf("Archivo creado correctamente\n");}
	bytesleidos=read(p1,buffer,4); 
	close(p1); 
	
	num = atoi(buffer);
	for (int i = num-1;i>0;i--){
		num = num * i;
	}
	
	p2 = open("FIFO2",1);
	sprintf(buffer,"%d",num);
	write(p2,buffer,strlen(buffer));
	close(p2);

	remove("FIFO2");
exit(0);
}
