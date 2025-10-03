#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdbool.h>
#include <time.h>

void main(){
	// la posición 1 escribe y la 0 lee
	int array1[2],array2[2];
	pipe(array1);
	pipe(array2);
	pid_t p2;
	int num;
	p2 = fork();
	if(p2 != 0){
		close(array1[0]);
		close(array2[1]);
		srand(time(NULL));  // Semilla
   		num = rand() % 10 + 1;
   		printf("El numero aleatorio es %d \n",num);
   		write(array1[1],&num,4);
   		read(array2[0],&num,sizeof(num));
   		printf("El factorial del numero es %d\n",num);
   		wait(NULL);
	}else{
		close(array2[0]);
		close(array1[1]);
		read(array1[0],&num,sizeof(num));
		for(int i = num-1; i > 0; --i){
			num = num * i;
		}
		write(array2[1],&num,4);	
	}
exit(0);
}
