#include <stdio.h>
#include <stdlib.h>

int expo (int b, int p){
	if (p == 0)
		return 1;
	return b * expo(b, p - 1);
}

int main(){
	int b, p;
	printf("Digite o valor de b e p: ");
	scanf("%d%d", &b, &p);
	
	printf("%d elevado a %d = %d\n", b, p, expo(b, p));
}
