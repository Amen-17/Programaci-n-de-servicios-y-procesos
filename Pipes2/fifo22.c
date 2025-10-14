#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void main(){
	int  pe, pl, bytesleidos;
	char buffer[10];
	pl = open("PIPE02",0);
	read(pl,buffer,4);
	printf("He leido %s\n",buffer);
	close(pl);
	pe = open("PIPE02",1);
	write(pe,"120",4);
	close(pe);
exit(0);
}
