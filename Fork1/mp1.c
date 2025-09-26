#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t pidHijo;
	pidHijo = fork();
	
	if (pidHijo == 0){
		printf("Mohamed Amen el Boudakhani Ballafkih\n");
	}else{
		wait(NULL);
		printf("Mi pid es %d y el de mi hijo es %d \n",getpid(),pidHijo);
	}

exit(0);
}

