#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Fila.h"

int main(){
	int op, cont = 0, aux;
    Conta *c;
    Fila *f = criar();

    do{
        printf("\n\t 0 - SAIR \n\t 1- INSERIR \n\t 2- REMOVER \n\t 3- MOSTRAR FILA \n\t 4- MOSTRAR TOPO \n\t 5- VERIFICAR PILHA VAZIA \n\t 6- LIBERAR \n\t 7- MOSTRAR FIM");

        scanf("%d", &op);
        switch(op){
            case 1:
                inserir(f, cont);
                cont = cont + 1;
                break;
            case 2:
                c = remover(f);
                if(c != NULL){
                    printf("Conta: %d removida!\n", c);
                } else{
                    printf("Essa conta nao existe! \n");
                }
                break;
            case 3:
                mostrarTodaFila(f);
                break;
            case 4:
                mostrar_topo_fila(f);
                break;
            case 5:
                aux = fila_vazia(f);
                if(aux == 0){
                    printf("Fila nao esta vazia! \n");
                } else{
                    printf("Fila vazia!\n");
                }
                break;
            case 6:
                fila_libera(f);
                break;
            case 7:
                mostrar_fim_fila(f);
            default:
                break;
        }

    }while(op != 0);

	return 0;
}