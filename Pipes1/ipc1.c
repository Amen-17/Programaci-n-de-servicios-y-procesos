#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){
	// la posición 1 escribe y la 0 lee
	int array[2];
	pipe(array);
	char buffer[50];
	pid_t p2;
	p2 = fork();
	if(p2 != 0){
		close(array[0]);
		int i = sizeof("Martes 30 de septiembre, 30/9/2025");
		write(array[1],"\nMartes 30 de septiembre, 30/9/2025",i);
		close(array[1]);
	}else{
		close(array[1]);
		printf("\nSoy el proceso hijo con pid %d",getpid());
		read(array[0], buffer, sizeof(buffer));
                printf("\t %s \n", buffer);
                close(array[0]);
	}

exit(0);
}
