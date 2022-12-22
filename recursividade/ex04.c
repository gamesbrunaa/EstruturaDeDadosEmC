#include <stdio.h>
#include <stdlib.h>

int soma (int a, int b){
	if (a == b)
		return a;
	return a + soma(a - 1, b);
}

int main(){
	int a, b;
	printf("Digite o valor de A e B: ");
	scanf("%d%d", &a, &b);
	printf("%d", soma(a, b));
}
