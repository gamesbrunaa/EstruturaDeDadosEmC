#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[80];
    float preco;
} PROD;

PROD * cadastro(int i){
    int tamanho = 20;
    PROD *p;
    p = (PROD *) malloc(tamanho * sizeof(PROD));
    printf("Digite o nome: ");
    scanf("%s", p[i].nome);
    printf("Digite o preco: ");
    scanf("%f", p[i].preco);

    return p;
}

PROD * ordenar(PROD *vet){

}

PROD * inflacionar(PROD *vet, int tamanho){
    int i, inflacao;
    for (i = 0; i < tamanho; i++){
        if(vet[i].preco > 100){
            inflacao = vet[i].preco * 0.05;
            vet[i].preco = vet[i].preco + inflacao;
        }
    }

    return vet;
}

void imprimir(PROD *vet, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("NOME = %s \n", vet[i].nome);
        printf("PREÇO = %.2f \n", vet[i].preco);
        printf("\n");
    }

}

int main(){
    PROD *p;
    int cont = 0, tamanho = 20;
    do{
        p = cadastro(cont);
        cont = cont + 1;
    } while (cont <= tamanho);

    p = ordenar(p);
    p = inflacionar(p, tamanho);
    imprimir(p, tamanho);

    return 0;
}