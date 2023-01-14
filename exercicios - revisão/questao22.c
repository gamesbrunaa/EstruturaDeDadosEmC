#include <stdio.h>
#include <stdlib.h>

int main (){
    int i, vet[10], soma = 0, media, cont = 0;

    printf("Digite os valores: ");
    for (i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
        soma = soma + vet[i];
    }

    media = soma / 10;

    for (i = 0; i < 10; i ++){
        if (vet[i] == media){
            cont = cont + 1;
        }
    }

    if (cont == 0){
        printf("Nenhum valor é igual a media(%d)!", media);
    } else if(cont == 1){
        printf("Existe um valor igual a média(%d)!", media);
    }else{
        printf("Existem %d valores iguais a média(%d)!", cont, media);
    }    

    return 0;
}