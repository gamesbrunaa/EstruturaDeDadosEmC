#include <stdlib.h>
#include <stdio.h>

typedef struct cliente{
    int identificador;
    char nome[100];
    int cpf;
    char endereco[100];
    struct cliente *prox;
} Cliente;

typedef struct lista{
    Cliente *inicio;
} Lista;


Lista *criar_lista(){
    Lista *L = (Lista *) calloc(1, sizeof(Lista));
    L->inicio = NULL;

    return L;
}

Cliente *criar_cliente(int cont){
    Cliente *novo = (Cliente *) calloc(1, sizeof(Cliente));
    novo->identificador = cont;
    printf("Digite o nome do cliente: \n");
    scanf("%s", novo->nome);
    printf("Digite o cpf: \n");
    scanf("%f", &novo->cpf);
    printf("Digite o endereco: \n");
    scanf("%s", novo->endereco);
    novo->prox = NULL;

    return novo;
}

Cliente *inserir_cliente(Lista *l, int cont){
    if(lista_vazia(l)){
        Cliente *n = criar_cliente(cont);
        l->inicio = n;
        return n;
    } else{
        Cliente *n = criar_cliente(cont);
        n->prox = l->inicio;
        l->inicio = n;
        return n;
    }
}

void mostrarTodosClientes(Lista *l){
    Cliente *n = l->inicio;
    while(n != NULL){
        printf("Código: %d \n", n->identificador);
        printf("Nome: %s \n", n->nome);
        printf("CPF: %d", n->cpf);
        printf("Endereço: %s \n", n->endereco);

        n = n->prox;
    }
}

Cliente *remover_cliente(Lista *l){
    if (lista_vazia(l)) return NULL;
    Cliente * removido = l->inicio;
    Cliente* segundo = l->inicio->prox;
    free(l->inicio);
    l->inicio = segundo;

    return removido;
}

Cliente *buscar_cliente(Lista *l, int cod){
    if(lista_vazia(l)) return NULL;
    while (l->inicio != NULL){
        if (l->inicio->identificador == cod){
            Cliente *buscado = l->inicio;
        } else{

        }
        
    }
    
}

void liberar_lista(Lista *l){
    Cliente *segundo = l->inicio->prox;
    free(l->inicio);
    l->inicio = segundo;
}

int lista_vazia(Lista *l){
    if(l->inicio == NULL)
        return 1;
    else
        return 0;
}

typedef struct rotaEntrega{
    int conseguiu_entregar;
    Cliente *c;
    struct rotaEntrega *prox;
    
}Entrega;

typedef struct fila{
    Entrega *begin;
    Entrega *end;
}Fila;

Fila *criar_fila(){
    Fila *F = (Fila *) calloc(1, sizeof(Fila));
    F->begin = NULL;
    F->end = NULL; 
    return F;
}

Entrega *criar_entrega(Cliente *cliente){
    Entrega *nova = (Entrega *) calloc(1, sizeof(Entrega));
    nova->c = cliente;
    nova->prox = NULL;
    nova->conseguiu_entregar = rand () % 10;

    return nova;
}

void inserir_entrega(Fila *f, Cliente *cliente){
    Entrega *n = criar_entrega(cliente);
    if(f->begin == NULL){
        f->begin = n;
        f->end = n;
    } else{
        f->begin->prox = n;
        f->end = f->end->prox;
    }
}

void mostrarEntregas(Fila *f){
    Entrega *n = f->begin;
    while(n != NULL){
        printf("Nome: %s \n", n->c->nome);
        printf("Codigo: %d \n", n->c->identificador);
        printf("CPF: %d \n", n->c->cpf);
        printf("Endereõ: %s \n", n->c->endereco);

        n = n->prox;
    }
}

Entrega *remover_entrega(Fila *f){
    if (fila_vazia(f)) return NULL;
    Entrega * removido = f->begin;
    Entrega* segundo = f->begin->prox;
    free(f->begin);
    f->begin = segundo;

    return removido;
}

void liberar_fila(Fila *f){
    Entrega *segundo = f->begin->prox;
    free(f->begin);
    f->begin = segundo;
}

int fila_vazia(Fila *f){
    if(f->begin == NULL)
        return 1;
    else
        return 0;
}

Fila ordenar_entregas(Fila *f){

}


typedef struct pilha{
    Entrega *primeiro;
} Pilha;

Pilha *criar_pilha(){
    Pilha *P = (Pilha *) calloc(1, sizeof(Pilha));
    P->primeiro = NULL;

    return P;
}

void inserir_naoEfetuada(Pilha *p, Entrega *c, Cliente *novo){
    if(c->conseguiu_entregar > 5){
        if(pilha_vazia(p)){
            p->primeiro = novo;
            printf("Entrega realizada!");
        } else{
            novo->prox = p->primeiro;
            p->primeiro = p;
            printf("Entrega realizada!");
        }
    }else{
        printf("Não foi possivel realizar entrega!");
    }
}

void mostrar_naoEfetuadas(Pilha *p){
    Entrega *n = p->primeiro;
    while(n != NULL){
        printf("Nome: %s \n", n->c->nome);
        printf("Codigo: %d \n", n->c->identificador);
        printf("CPF: %d \n", n->c->cpf);
        printf("Endereõ: %s \n", n->c->endereco);

        n = n->prox;
    }
}

Entrega *remover(Pilha *p){
    if (pilha_vazia(p)) return NULL;
    Entrega * removido = p->primeiro;
    Entrega* segundo = p->primeiro->prox;
    free(p->primeiro);
    p->primeiro = segundo;

    return removido;
}

void liberar_pilha(Pilha *p){
    Entrega *segundo = p->primeiro->prox;
    free(p->primeiro);
    p->primeiro = segundo;
}

int pilha_vazia(Pilha *p){
    if(p->primeiro == NULL)
        return 1;
    else
        return 0;
}