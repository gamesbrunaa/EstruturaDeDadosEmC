#include <stdbool.h>
#include <stdlib.h>

typedef struct conta{
    int num_conta;
    char titular[100];
    float saldo;
    struct conta *prox;
}Conta;

typedef struct _pilha{
    Conta *inicio;
}Pilha;

Pilha *criar(){
    Pilha *P = (Pilha *) calloc(1, sizeof(Pilha));
    P->inicio = NULL;
    return P;
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

void inserir(Pilha *p, int cont){
    if(pilha_vazia(p)){
        Conta *n = criar_conta(cont);
        p->inicio = n;
    } else{
        Conta *n = criar_conta(cont);
        n->prox = p->inicio;
        p->inicio = p;
    }
}

void mostrarTodaPilha(Pilha *p){
    Conta *n = p->inicio;
    while(n != NULL){
        printf("Nome: %s \n", n->titular);
        printf("Numero Conta: %d \n", n->num_conta);
        printf("Saldo: %.2f \n", n->saldo);

        n = n->prox;
    }
}

bool pilha_vazia(Pilha *p){
    if(p->inicio == NULL)
        return true;
    else
        return false;
}


Conta* remover(Pilha* p){
  if (pilha_vazia(p)) return NULL;
  Conta * removido = p->inicio;
  Conta* segundo = p->inicio->prox;
  free(p->inicio);
  p->inicio = segundo;
  return removido;
}

void pilha_libera (Pilha* p){
    Conta *segundo = p->inicio->prox;
    free(p->inicio);
    p->inicio = segundo;
}

void mostrar_topo_pilha(Pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia!");
    } else{
        printf("O topo da pilha eh: \n");
        printf("Nome: %s \n", p->inicio->titular);
        printf("Numero Conta: %d \n", p->inicio->num_conta);
        printf("Saldo: %.2f \n", p->inicio->saldo);
    }
}
