#include <stdio.h>
#include <stdlib.h>

int soma (int k){

	if (k == 0)
		return 0;
	return k + soma(k - 1);
}

int main(){
	int k;
	printf("Digite o valor de K: ");
	scanf("%d", &k);
	printf("%d", soma(k));
}
