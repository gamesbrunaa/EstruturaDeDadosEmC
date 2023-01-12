#include <stdio.h>
#include <stdlib.h>

#include "str.h"

int main(){

   char *str1;
   char *str2;
   int x;

   printf("palavra a: ");
   str1 = ler();
   printf("palavra b: ");
   str2 = ler();

  
   x = iguais(str1,str2);
   if(x == 1){
    printf("As strings sao diferentes");
   } else{
    printf("As strings sao iguais");
   }

   concatenar(str1,str2);
   printf("\nAs strings cancatenadas: %s\n", str1);

   printf("O tamanho da string eh: %d \n", tamanho(str1));
   
   liberar(str1);
   liberar(str2);
    return 0;
}