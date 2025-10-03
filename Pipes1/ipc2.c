#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdbool.h>
void main(){
	// la posición 1 escribe y la 0 lee
	int array[2];
	char buffer[50];
	pipe(array);
	pid_t p2;
	p2 = fork();
	int suma, i=1;
	bool bandera = false;
	
		if(p2 == 0){
			close(array[1]);
		do{
			printf("Vuelta numero %d\n",i);
			read(array[0],buffer,sizeof(buffer));
			printf("Numero a sumar: %s\n",buffer);
			suma = suma + atoi(buffer);
			if(atoi(buffer) == '+'){bandera = true;}
			i++;
		}while(!bandera);
			close(array[0]);
		}else{
			close(array[0]);
			write(array[1],"25",4);
			write(array[1],"25",4);
			write(array[1],"20",4);
			write(array[1],"20",4);
			write(array[1],"+",4);
			close(array[1]);
			wait(NULL);
		}

exit(0);
}
