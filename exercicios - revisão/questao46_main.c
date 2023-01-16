#include <stdio.h.>
#include <stdlib.h>

#include "questao46.h"

int main(){
    Pessoa *b;
    char nome[50], data[50];
    int cpf;
    
    printf("Digite o nome: \n");
    scanf("%s", nome);
    printf("Digite a data: \n");
    scanf("%s", data);
    printf("Digite o cpf: \n");
    scanf("%d", &cpf);

    b = criar(nome, data, cpf);
    imprimir(b);
    liberar(b);

    return 0;
}