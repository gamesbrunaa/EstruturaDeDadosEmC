#include <stdio.h>
#include <stdlib.h>

int escolha(){
    int op;
    printf("1 - A vista com 10% de desconto \n");
    printf("2 - Em duas vezes (preço da etiqueta) \n");
    printf("3 - De 3 à 10 vezes com 3% de juros ao mês (para compras acima de R$100,00 \n");
    printf("Digite a opção desejada: ");
    scanf("%d", &op);

    return op;
}

void avista(float preco){
    float desconto, valorFinal;
    desconto = (preco * 0.10);
    valorFinal = preco - desconto;
    printf("Valor Total = R$%.2f", valorFinal);
}

void duasvezes(float preco){
    float prestacao;
    prestacao = preco / 2;
    printf("Primeira prestação = %.2f \n", prestacao);
    printf("Segunda prestação = %.2f \n", prestacao);
}

void tresAdez(float preco){
    int quantidade;
    float juros, prestacao;
    juros = preco * 0.03;
    printf("Em quantas prestações deseja dividir? \n");
    scanf("%d", &quantidade);
    juros = juros * quantidade;
    prestacao = juros + preco / quantidade ;

    printf("%d prestações de = %.2f", quantidade, prestacao);

    printf("Sua compra foi divida em %d prestações de %.2f", quantidade, prestacao);
    
}

int main(){
    float valorTotal;
    int opcao;

    printf("Digite o valor da compra: ");
    scanf("%f", &valorTotal);
    opcao = escolha();

    switch (opcao)
    {
    case 1:
        avista(valorTotal);
        break;
    case 2:
        duasvezes(valorTotal);
        break;
    case 3:
        if(valorTotal > 100){
            tresAdez(valorTotal);
        } else{
            printf("Essa opção só é válida para compras acima de R$100,00");
        }
        break;
    default:
        printf("Opção inválida!!");
        break;
    }

    return 0;
}