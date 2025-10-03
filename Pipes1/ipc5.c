#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdbool.h>

void main(){
	int array1[2],array2[2];
	pipe(array1);
	pipe(array2);
	int dni;
	char letra;
	char letras_dni[23] =
{'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
	pid_t p2;
	p2 = fork();
	if(p2 != 0){
		close(array1[1]);
		close(array2[0]);
		read(array1[0],&dni,sizeof(dni));
		letra = letras_dni[dni%23];
		write(array2[1],&letra,sizeof(letra));
		wait(NULL);
	}else{
		close(array1[0]);
		close(array2[1]);
		printf("Introduce tu dni: "); 
		scanf("%d", &dni); 
		write(array1[1],&dni,sizeof(dni));
		read(array2[0],&letra,sizeof(letra));
		printf("La letra del NIF es %c \n",letra);
	}

exit(0);
}
