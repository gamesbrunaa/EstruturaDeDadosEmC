#include <stdio.h>
#include <stdlib.h>

#include "listaDinamicaDupla.h"

int main(int argc, char const *argv[]){
	int op, valor, anterior;
    Conta *removido, *lista;

    lista = criarLista();

    do{
        printf("\n\t 0 - SAIR \n\t 1- INSERIR INICIO\n\t 2- INSERIR FIM \n\t 3- INSERIR ORDENADO \n\t 4- REMOVER \n\t 5- BUSCAR \n\t 6- ALTERAR \n\t 7- VERIFICAR LISTA VAZIA \n\t 8- MOSTRAR \n\t 9- LIBERAR \n");

        scanf("%d", &op);
        switch(op){
            case 1:
                lista = inserirInicio(lista);
                break;
            case 2:
                inserirFim(lista);
                break;
            case 3:
                inserirOrdenado(lista);
                break;
            case 4:
                printf("Digite o numero da conta para remover: \n");
                scanf("%d", &valor);
                removido = remover(lista, valor);
                if(removido){
                    printf("Conta: %d removida!\n", removido->num_conta);
                    free(removido);
                } else{
                    printf("Essa conta nao existe! \n");
                }
                break;
            case 5:
                printf("Digite o numero da conta para ser buscado: \n");
                scanf("%d", &valor);
                removido = buscar(lista, valor);
                if(removido){
                    printf("Conta encontrada: \n");
                    printf("Nome = %s \n", removido->titular);
                    printf("Numero = %d \n", removido->num_conta);
                    printf("Saldo= %.2f \n", removido->saldo);
                }
                break;
            case 6:
                break;
            case 7:
                int aux;
                aux = listaVazia;
                if(aux){
                    printf("Lista nao esta vazia! \n");
                } else{
                    printf("Lista vazia!\n");
                }
                break;
            case 8:
                mostrarLista(lista);
                break;
            case 9:
                liberarLista(lista);
                break; 
        }

    }while(op != 0);

	return 0;
}