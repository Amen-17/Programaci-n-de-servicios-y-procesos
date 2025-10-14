#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void main(){
	int  arc1, pe, pl, bytesleidos;
	char buffer[10];
	arc1 = mkfifo("PIPE02",0666);
	pe = open("PIPE02",1);
	write(pe,"5",4);
	close(pe);
	pl = open("PIPE02",0);
	read(pl,buffer,4);
	printf("He leido %s\n",buffer);
	close(pl);
exit(0);
}
