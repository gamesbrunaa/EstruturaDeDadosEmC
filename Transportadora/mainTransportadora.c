#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "transportadora.h"

int main(){
	int op, op2, op3, op4, cont = 0, aux, codigo;
    Cliente *c;
    Entrega *e;
    Lista *l = criar_lista(); //lista responsavel pelos clientes
    Fila *f = criar_fila(); //fila responsavel pela rota de entrega
    Pilha *p = criar_pilha(); // pilha responsavel pelas entregas nao efetuadas
    Fila *f2 = criar_fila(); // fila da devolução de produtos

    do{
        printf("\n\t 0 - SAIR \n\t 1- INSERIR CLIENTE \n\t 2- REMOVER CLIENTE \n\t 3- MOSTRAR CLIENTES \n\t 4- BUSCAR CLIENTE \n\t 5- VERIFICAR LISTA VAZIA \n\t 6- LIBERAR LiSTA \n\t 7- MENU ENTREGAS \n\t 8- MENU ENTREGAS NÃO EFETUADAS \n\t 9- MENU DEVOLUÇÃO DE PRODUTOS \n\t");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                inserir_entrega(f, inserir_cliente(l, cont));
                cont = cont + 1;
                break;
            case 2:
                c = remover(l);
                e = remover_entrega(c);
                if(e != NULL){
                    printf("Cliente: %d removido!\n", c);
                } else{
                    printf("Esse conta nao existe! \n");
                }
                break;
            case 3:
                mostrarTodosClientes(l);
                break;
            case 4:
                print("Digite o codigo para buscar: \n");
                scanf("%d", &codigo);
                buscar_cliente(l, codigo);
                break;
            case 5:
                aux = lista_vazia(l);
                if(aux == 0){
                    printf("Lista nao esta vazia! \n");
                } else{
                    printf("Lista vazia!\n");
                }
                break;
            case 6:
                lista_libera(l);
                break;
            case 7:
                printf("\n\t 0 - SAIR \n\t 1- MOSTRAR ENTREGAS \n\t 2- REMOVER ENTREGA \n\t 3- LIBERAR FILA \n\t 4- VERIFICAR FILA VAZIA \n\t 5- ORDENAR ENTREGAS \n\t");
                printf("Digite a opção desejada: ");
                scanf("%d", &op2);
                switch (op2){
                case 1:
                    mostrarEntregas(f);
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    liberar_fila(f);
                    break;
                case 4:
                    fila_vazia(f);
                    break;
                case 5:
                    f = ordenar_entregas(f);
                    break;
                default:
                    break;
                }
                break;
            case 8:
                printf("\n\t 0 - VOLTAR \n\t 1- INSERIR ENTREGAS NÃO EFETUADAS \n\t 2- MOSTRAR ENTREGAS \n\t 3- REMOVER ENTREGA \n\t 4- VERIFICAR PILHA VAZIA \n\t 5- LIBERAR PILHA \n\t");
                printf("Digite a opção desejada: ");
                scanf("%d", &op3);
                switch (op3){
                case 1:
                    inserir_naoEfetuada(p, c);
                    break;
                case 2:
                    mostrar_naoEfetuadas(p);
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    pilha_vazia(p);
                    break;
                case 5:
                    liberar_pilha(p);
                    break;
                default:
                    break;
                }
                break;
            case 9:
                printf("\n\t 0 - SAIR \n\t 1- INSERIR DEVOLUÇÃO DE PRODUTOS \n\t 2- MOSTRAR DEVOLUÇÃO DE PRODUTOS \n\t");
                printf("Digite a opção desejada: ");
                scanf("%d", &op4);
                switch (op4){
                case 1:
                    inserir_entrega(f2, c);
                    break;
                case 2:
                    mostrarEntregas(f2);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
        }

    }while(op != 0);

	return 0;
}