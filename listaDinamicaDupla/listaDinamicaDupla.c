#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox, *ant;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) calloc(sizeof(Conta),1);
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->ant = NULL;
	new->prox = lista;
	if (lista)
		lista->ant = new;
	return new;
}

void *inserirFim(Conta *lista){
	Conta *aux, *novo = (Conta*) calloc(sizeof(Conta),1);
	if (novo){
		novo->num_conta = rand() % 100 + 10;
		printf("Nome - ");
		scanf("%s", novo->titular);
		printf("Saldo - ");
		scanf("%f", &novo->saldo);
		novo->prox = NULL;

		if(*lista == NULL){
			*lista = novo;
			novo->ant = NULL;

		} else{
			aux = *lista;
			while(aux->prox)
				aux = aux->prox;
			aux->prox = novo;
			novo->ant = aux;
		}

	} else{
		printf("Erro ao alocar memoria!\n");
	}

}

void *inserirOrdenado(Conta *lista){
	Conta *aux, *novo = (Conta*) calloc(sizeof(Conta),1);
	if (novo){
		novo->num_conta = rand() % 100 + 10;
		printf("Nome - ");
		scanf("%s", novo->titular);
		printf("Saldo - ");
		scanf("%f", &novo->saldo);

		if(*lista == NULL){
			novo->prox = NULL;
			novo->ant = NULL;
			*lista = novo;
		}
		else if(novo->num_conta < (*lista)->num_conta){
			novo->prox = *lista;
			(*lista)->ant = novo;
			*lista = novo;
		}
		else{
			aux = *lista;
			while(aux->prox && novo->num_conta > aux->prox->num_conta)
				aux = aux->prox;
			novo->prox = aux->prox;

			if(aux->prox)
				aux->prox->ant = novo;
			novo->ant = aux;
			aux->prox = novo;
		}
	} else{
		printf("Erro ao alocar memoria!\n");
	}
}

Conta *remover(Conta *lista, int valor){
	Conta *aux, *remover = NULL;
	if (*lista){
		if((*lista)->num_conta == valor){
			remover *lista;
			*lista = remover->prox;
			if(*lista)
				(*lista)->ant = NULL;
		} else{
			aux = *lista;
			while(aux->prox && aux->prox->num_conta != valor)
				aux = aux->prox;
			if(aux->prox){
				remover = aux->prox;
				aux->prox = remover->prox;
				if(aux->prox)
					aux->prox->ant = aux;
			}
		}
	}

	return remover;
}

Conta *buscar(Conta *lista, int valor){
	Conta *aux, *achou = NULL;

	aux = *lista;
	while(aux && aux->num_conta != valor)
		aux = aux->prox;
	if(aux)
		achou = aux;

	return achou;
}

Conta *alterar(Conta *lista, int oldValue, int newValue){

}

int listaVazia(Conta *lista){
    if(lista){
        return 1;
    } else{
        return NULL;
    }
}

void mostrarLista(Conta *lista){
	printf("Lista: \n");
	while(lista){
		printf("Numero conta: %d\n", lista->num_conta);
		printf("Titular: %s\n", lista->titular);
		printf("Saldo: %.2f\n", lista->saldo);
		printf("\n");
		lista = lista->prox;
	}
	printf("\n");
}

void liberarLista(){
    int aux = 0;
	while(lista){
        free(lista[aux]);
        aux = aux + 1;
    }
}