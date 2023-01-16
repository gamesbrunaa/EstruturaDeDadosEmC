#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[50];
    char data_nasc[50];
    int CPF;
};

typedef struct pessoa Pessoa;

Pessoa *criar(char n[50], char data[50], int cpf){
    Pessoa *a;
    a = (Pessoa *) malloc(sizeof(Pessoa));
    *a->nome = *n;
    *a->data_nasc = *data;
    a->CPF = cpf;

    return a;
}

void imprimir(Pessoa *a){
    printf("NOME = %s \n", a->nome);
    printf("DATA = %s \n", a->data_nasc);
    printf("CPF = %d \n", a->CPF);
}

void liberar(Pessoa *a){
    free(a);
}
