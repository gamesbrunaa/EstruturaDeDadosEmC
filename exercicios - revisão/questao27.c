#include <stdio.h>
#include <stdlib.h>

int main (){
    char *nome, *str, endereco[50];
    int telefone, idade;

    printf("Qual seu nome? ");
    scanf("%s", nome);

    printf("Qual seu endereco? ");
    scanf("%s", endereco);

    printf("Qual seu telefone? ");
    scanf("%d", &telefone);

    printf("Qual sua idade? ");
    scanf("%d", &idade);

    str = ("Seu nome eh " + nome + "voce tem" + idade + "anos");

    printf("%s \n", str);

    return 0
}