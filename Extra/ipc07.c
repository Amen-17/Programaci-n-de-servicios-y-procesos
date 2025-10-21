#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdbool.h>

// Traduce la operación y devuelve el resultado.
int operacion(int num1,int num2,int num3){
	switch(num1){
		case 1: 
		return num2 + num3;
		break;
		case 2: 
		return num2 - num3;
		break;
		case 3: 
		return num2 * num3;
		break;
		case 4: 
		return num2 / num3;
		break;
	}
}

void main(){

	int array[2],array2[2],num[3],resultado;
	char buffer[50];
	pipe(array);
	pipe(array2);
	pid_t p1, p2,p3;
	p1 = getpid();
	p2 = fork();
	if (p2 == 0){
		p3 = fork();
	}
	if(getpid() == p1){
		close(array[0]);
		close(array2[1]);
		close(array2[0]);
		printf("Proceso P1 pid = %d\n",p1);
		printf("**CALCULADORA**\n");
		printf("1. Sumar\n");
		printf("2. Restar\n");
		printf("3. Multiplicar\n");
		printf("4. División\n");
		printf("Seleccione la opción deseada: ");
		scanf("%d",&num[0]);
		sprintf(buffer,"%d",num[0]);
		write(array[1],buffer,4);
		
		printf("Introduce el primer número: ");
		scanf("%d",&num[1]);
		sprintf(buffer,"%d",num[1]);
		write(array[1],buffer,4);
		
		printf("Introduce el segundo número: ");
		scanf("%d",&num[2]);
		sprintf(buffer,"%d",num[2]);
		write(array[1],buffer,4);
		wait(NULL);
		printf("Termina proceso P1\n");
	}else if(p2 == 0 && p3 !=0){
		close(array[1]);
		close(array2[0]);
		
		read(array[0],buffer,4);
		num[0] = atoi(buffer);
		read(array[0],buffer,4);
		num[1] = atoi(buffer);
		read(array[0],buffer,4);
		num[2] = atoi(buffer);
		resultado = operacion(num[0],num[1],num[2]);
		printf("Proceso P2 pid = %d - Proceso padre pid = %d\n",p2,getppid());
		printf("Este es el resultado: %d\n",resultado);
		sprintf(buffer,"%d",resultado);
		write(array2[1],buffer,4);
		wait(NULL);
		printf("Termina proceso P2\n");
	}else{
		close(array[0]);
		close(array[1]);
		close(array2[1]);
		read(array2[0],buffer,4);
		num[0] = atoi(buffer);
		printf("Proceso P3 pid = %d - Proceso padre pid = %d\n",p3,getppid());
		if(num[0] % 2 == 0){printf("El resultado de la operación %d es par\n",num[0]);}
		else{printf("El resultado de la operación %d es impar\n",num[0]);}
		printf("Termina proceso P3\n");
	}
exit(0);
}
