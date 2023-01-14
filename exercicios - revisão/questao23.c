#include <stdio.h>
#include <stdlib.h>

int main(){
    float mat[5][3];
    int i, j, contC = 0, contL = 0;
    float mediaC, mediaL, somaC = 0, somaL = 0;

    printf("Digite os valores da matriz: ");
    for (i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            scanf("%f", &mat[i][j]);
        }
    }

    for (i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            if(i % 2 == 0){
                somaC = somaC + mat[i][j];
                contC = contC + 1;
            }
            if(j % 2 == 1){
                somaL = somaL + mat[i][j];
                contL = contL + 1;
            }
        }
    }

    mediaC = somaC / contC;
    mediaL = somaL / contL;

    printf("Media Colunas Pares = %.2f\n", mediaC);
    printf("Media Linhas Impares = %.2f\n", mediaL);

    return 0;
}