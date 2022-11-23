#include <stdio.h>
#include <stdlib.h>

int receba(int x, int y){
	if (y == 1){
		return x;
	}
	
	if (y == 0){
		return 1;
	}
	
	return x * receba(x, y-1);
}

int main(){
	int x, y, a;
	printf("Digite um numero inteiro x: \n");
	scanf("%d", &x);
	printf("Digite um numero inteiro y: \n");
	scanf("%d", &y);
	a = receba(x, y);
	printf("%d elevado a %d = %d", x, y, a);
	
	return 0;
}
