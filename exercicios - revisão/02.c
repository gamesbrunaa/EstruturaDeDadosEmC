#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *vet_alocado;
	int i, j;
	
	vet_alocado = (int *) malloc(n1 * n2 * sizeof(int));
	if(vet_alocado == NULL){
		printf("\n Impossivel alocar memória. \n");
	}
	
	for(i = 0; i < n1; i++)
		vet_alocado[i] = v1[i];
		
	for(j = 0; j < n2; j++)
		vet_alocado[(j + n1)] = n2[j];
		
	return vet_alocado;
}

int main(){
	int *v1, *v2, n1, n2, *v3;
	int i;
	
	printf("Digite o tamanho do vetor 1: \n");
	scanf("%d", &n1);
	printf("Digite o tamanho do vetor 2: \n");
	scanf("%d", &n2);
	
	for(i = 0; i < n1; i++){
		v1[i] = rand () % 10;
	}
	
	for(i = 0; i < n2; i++){
		v2[i] = rand () % 10;
	}
	
	v3 = uniao(v1, n1, v2, n2);
	
	for(i = 0; j < (n1 + n2); j++)
		printf("%d ", v3[i]);
}
