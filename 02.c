#include <stdio.h>
#include <stdlib.h>

int main(){
	int mat[200][100];
	int i, j, x, cont = 0, a;
	scanf("%d", &x);
	for(i = 0; i < 200; i++){
		for(j = 0; j < 100; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	int vet[x];
	for(a = 0; a < x; a++){
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				if(mat[i][j] == a){
					cont++;
				}
			}

		}
		vet[a] = cont;
		cont = 0;
	}
	for (a = 0; a <= x; a++){
		if(vet[a] == 1){
			printf("O numero %d ocorreu %d vez \n", a, vet[a]);
		}
		else if(vet[a] > 1){
			printf("O numero %d ocorreu %d vezes \n", a, vet[a]);
		}
	}
	
	return 0;
	
}
