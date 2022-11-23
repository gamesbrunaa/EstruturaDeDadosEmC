#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, soma = 0;
	float media = 0;
	int menor, maior, n, cont = 0;
	printf("Digite um valor inteiro: \n");
	scanf("%d", &x);
	n = x;
	menor = x;
	maior = x;
	soma = soma + n;
	while(x != -1){
		scanf("%d", &x);
		n = x;
		
		if(x == -1){
			break;
		}
		soma = soma + n;
		cont++;
		
		if(n < menor && n != -1){
			menor = n;
		}
		
		if(n > maior){
			maior = n;
		}
	}
	media = (soma/cont);
	printf("Soma = %d \n", soma);
	printf("Media = %f \n", media);
	printf("Menor = %d \n", menor);
	printf("Maior = %d \n", maior);
	
	return 0;
}
