#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct conta{
    int num_conta;
    char titular[100];
    float saldo;
    struct conta *prox;
}Conta;

typedef struct _fila{
    Conta *inicio;
    Conta *fim;
}Fila;

Fila *criar(){
    Fila *F = (Fila *) calloc(1, sizeof(Fila));
    F->inicio = NULL;
    F->fim = NULL; 
    return F;
}

Conta *criar_conta(int cont){
    Conta *novo = (Conta *) calloc(1, sizeof(Conta));
    printf("Digite o nome do titular: ");
    scanf("%s", novo->titular);
    printf("Digite o saldo da conta: ");
    scanf("%f", &novo->saldo);
    novo->num_conta = cont;
    novo->prox = NULL;

    return novo;
}

void inserir(Fila *f, int cont){
    Conta *n = criar_conta(cont);
    if(f->inicio == NULL){
        f->inicio = n;
        f->fim = n;
    } else{
        f->fim->prox = n;
        f->fim = f->fim->prox;
    }
}

void mostrarTodaFila(Fila *f){
    Conta *n = f->inicio;
    while(n != NULL){
        printf("Nome: %s \n", n->titular);
        printf("Numero Conta: %d \n", n->num_conta);
        printf("Saldo: %.2f \n", n->saldo);

        n = n->prox;
    }
}

int fila_vazia(Fila *f){
    if(f->inicio == NULL)
        return 1;
    else
        return 0;
}

void mostrar_topo_fila(Fila *f){
    if(fila_vazia(f)){
        printf("Fila vazia!");
    } else{
        printf("O topo da fila eh: \n");
        printf("Nome: %s \n", f->inicio->titular);
        printf("Numero Conta: %d \n", f->inicio->num_conta);
        printf("Saldo: %.2f \n", f->inicio->saldo);
    }
}

void mostrar_fim_fila(Fila *f){
    if(fila_vazia(f)){
        printf("Fila vazia!");
    } else{
        printf("O fim da fila eh: \n");
        printf("Nome: %s \n", f->fim->titular);
        printf("Numero Conta: %d \n", f->fim->num_conta);
        printf("Saldo: %.2f \n", f->fim->saldo);
    }
}

Conta* remover(Fila* f){
    if (fila_vazia(f)) return NULL;
    Conta * removido = f->inicio;
    Conta* segundo = f->inicio->prox;
    free(f->inicio);
    f->inicio = segundo;
    return removido;
}

void fila_libera(Fila* f){
    Conta *segundo = f->inicio->prox;
    free(f->inicio);
    f->inicio = segundo;
}