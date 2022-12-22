#include <stdio.h>
#include <stdlib.h>

int numeros (int k){
	printf("%d\n", k);
	if (k == 0)
		return 0;
	return numeros(k - 1);
}

void main(){
	int k;
	printf("Digite o valor de K: ");
	scanf("%d", &k);
	numeros(k);
}
