#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[80];
    int i, caracteres = 0, pontuacao = 0, letras = 0;

    printf("Digite a string: ");
    scanf("%s", &str);

    for(i = 0; i < 80; i++){
        if((str[i] != '\0') && (str[i] != ' ')){
            caracteres = caracteres + 1;
        }

        if(str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
            pontuacao = pontuacao + 1;
        }

        if((str[i] >= 'a') && (str[i] <= 'z')){
            letras = letras + 1;
        }
    }

    printf("Caracteres = %d \n", caracteres);
    printf("Pontuação = %d \n", pontuacao);
    printf("Letras = %d \n", letras);

    return 0;
}