#include <stdio.h>
#include <stdlib.h>

int **preencherMatriz(int lin, int col){
	int **mat;
	int i, j;
	mat = (int **) calloc(lin, sizeof(int*));
	for (i = 0; i < lin; ++i)
		{
			mat[i] = (int *) malloc(sizeof(int) * col);
		}	

	for (i = 0; i < lin; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			mat[i][j] = rand() % 256;
			//scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

int *menorMaiorMedia(int l, int c, int **mat){
	int *vet, i, j;
	vet = (int *) calloc(3, sizeof(int));
	vet[0] = mat[0][0];
	vet[1] = mat[1][1];
	int soma = 0;
	for (i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			if(vet[0] < mat[i][j])
				vet[0] = mat[i][j];
			if(vet[1] > mat[i][j])
				vet[1] = mat[i][j];
			soma = soma + mat[i][j];
		}
	}
	
	vet[2] = soma /(l * c);
	
	return vet;
}

void mostrarMenorMaiorMedia(int *vet, int t){
	int i;
	for (i = 0; i < t; i++){
		printf("%d \n", vet[i]);
	}
}

void mostrarDados(int lin, int col, int **m){
	int i, j;
	for (i = 0; i < lin; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf("%d    ", m[i][j]);
		}
		printf("\n");
	}
}
void liberarMemoria(int **m, int t){
	int i;
	for (i = 0; i < t; ++i)
	{
		free(m[i]);
	}
	free(m);
}
int main(){
	int **m, *v;
	int t = 3;
	m = preencherMatriz(5, 5);
	mostrarDados(5, 5, m);
	v = menorMaiorMedia(5, 5, m);
	printf("\n");
	mostrarMenorMaiorMedia(v, t);
	liberarMemoria(m, 10);
	return 0;
}
