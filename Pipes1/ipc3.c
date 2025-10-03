#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdbool.h>
#include <time.h>

void main(){
	// la posición 1 escribe y la 0 lee
	int array[2];
	pipe(array);
	pid_t p2;
	p2 = fork();
	int num1, num2;
	if(p2 != 0){
		close(array[1]);
		read(array[0],&num1,sizeof(num1));
		read(array[0],&num2,sizeof(num2));
		printf("%d y %d = %d \n",num1,num2);
		wait(NULL);
	}else{
		close(array[0]);
		srand(time(NULL));  // Semilla
   		num1 = rand() % 50 + 1;
   		num2 = rand() % 50 + 1;
		write(array[1],&num1,4);
		write(array[1],&num2,4);
	}
 
exit(0);
}
