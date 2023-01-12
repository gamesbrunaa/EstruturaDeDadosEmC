#include <stdio.h>
#include <stdlib.h>

#include "str.h"

char *ler(){
    char *str;
    str = malloc (sizeof(char));
    scanf("%s", str);
    return str;
}

void concatenar(char *str1, char *str2){

   int i, j;
   for(i=0; str1[i] != '\0'; ++i);
   for(j=0; str2[j] != '\0'; ++j, ++i){
    str1[i] = str2[j];
   }
   str1[i] = '\0';
}

int tamanho(char *str){
    int tam = 0, i;
    for(i = 0; str[i] != '\0'; i++){
        tam = tam + 1;
    }
    return tam;
}

int iguais(char *str1, char *str2){
    int tam1 = 0, tam2 = 0, i, cont = 0;
    if(tam1 != tam2){
        return 0;
    } else{
        for(i = 0; i <= tam1; i++){
            if(str1[i] == str2[i]){
                cont = cont + 1;
            }
        }
        if(cont == tam1){
            return 1;
        } else{
            return 0;
        }
    }

}

void liberar(char *str){
    free(str);
}