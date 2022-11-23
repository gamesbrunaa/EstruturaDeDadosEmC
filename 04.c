#include <stdio.h>
#include <stdlib.h>

int invertido(int x){
	if(x > 11){
		x = x / 10;
		return invertido(x);
	}
	else{
		return x;
	}
}

int main(){
	int valor, result;
	printf("Digite o número inteiro: \n");
	scanf("%d", &valor);
	result = invertido(valor);
	printf("O numero %d invertido = %d", valor, result);
}
