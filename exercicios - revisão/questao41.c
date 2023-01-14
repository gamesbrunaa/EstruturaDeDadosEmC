#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    char endereco[100];
    char fone[10];
    long int CEP;
} Pessoa;

Pessoa * cadastro(int indice){
    int tamanho = 100;
    Pessoa *p;
    p = (Pessoa *) malloc(tamanho * sizeof(Pessoa));
    printf("Digite o nome: ");
    scanf("%s", p[indice].nome);
    printf("Digite o endereco: ");
    scanf("%s", p[indice].endereco);
    printf("Digite o telefone: ");
    scanf("%s", p[indice].fone);
    printf("Digite o CEP: ");
    scanf("%d", &p[indice].CEP);

    return p;
}


int main(){
    Pessoa *p;
    int i, tam = 100, op, cont = 0, busca;
    char busca2[1];
    do{
        printf("1. Entrar um novo nome na agenda; \n");
        printf("2. Procurar pessoa na agenda; \n");
        printf("3. Imprimir lista de nomes que comecem por uma letra. \n");
        printf("4. SAIR \n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            p = cadastro(cont);
            printf("Cadastro realizado com sucesso!");
            cont = cont + 1;
            break;
        case 2:
            printf("Digite o indice da pessoa procurada: ");
            scanf("%d", &busca);
            for(i = 0; i < tam; i++){
                if(i == busca){
                    printf("NOME = %s\n", p[i].nome);
                    printf("ENDERECO = %s\n", p[i].endereco);
                    printf("TELEFONE = %s\n", p[i].fone);
                    printf("CEP = %d\n", p[i].CEP);
                }
            }
            break;
        case 3:
            printf("Digite a letra da pessoa procurada: ");
            scanf("%s", busca2);
            for(i = 0; i < tam; i++){
                if(p[i].nome[0] == busca2[0]){
                    printf("NOME = %s\n", p[i].nome);
                    printf("ENDERECO = %s\n", p[i].endereco);
                    printf("TELEFONE = %s\n", p[i].fone);
                    printf("CEP = %d\n", p[i].CEP);
                }
            }
            break;
        case 4:
            break;
        default:
            printf("Opção inválida!");
            break;
        }

    } while (op != 4);

    return 0;
}