#include <stdio.h>
#include <stdlib.h>

#include "listaCircula.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserir(Conta *lista){
	
	Conta *new = (Conta*) malloc(sizeof(Conta)), *aux;
	
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	
	if (!lista)//se a lista for vazia o primeiro e o ultimo sao iguais
	{
		new->prox = new;
	}
	else{
		aux = lista;
		while(aux->prox != lista)
			aux = aux->prox;
		aux->prox = novo;
		novo->prox = lista;
	}
	return new;	
}

void mostrarLista(Conta *lista){
	Conta* p = lista; 
	if (p){ 
		do {
			printf("%d\n", p->info);
			p = p->prox; /* avança para o próximo elemento da lista*/
		} while (p != lista);
	}
}