#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

int main(int argc, char const *argv[]){
	int op, cont = 0, aux;
    Conta *c;
    Pilha *p = criar();

    do{
        printf("\n\t 0 - SAIR \n\t 1- INSERIR \n\t 2- REMOVER \n\t 3- MOSTRAR PILHA \n\t 4- MOSTRAR TOPO \n\t 5- VERIFICAR PILHA VAZIA \n\t 6- LIBERAR \n");

        scanf("%d", &op);
        switch(op){
            case 1:
                inserir(p, cont);
                cont = cont + 1;
                break;
            case 2:
                c = remover(p);
                if(c != NULL){
                    printf("Conta: %d removida!\n", c);
                } else{
                    printf("Essa conta nao existe! \n");
                }
                break;
            case 3:
                mostrarTodaPilha(p);
                break;
            case 4:
                mostrar_topo_pilha(p);
                break;
            case 5:
                aux = pilha_vazia(p);
                if(aux){
                    printf("Lista nao esta vazia! \n");
                } else{
                    printf("Lista vazia!\n");
                }
                break;
            case 6:
                pilha_libera(p);
                break;
            default:
                break;
        }

    }while(op != 0);

	return 0;
}