#include <stdio.h>
#include <stdlib.h>

int decimal_octal(int decimal){
  int octal = 0;
  int resto, i = 1;

  while(decimal != 0) {
        resto = decimal % 8;
        decimal = decimal / 8;
        octal = octal + (resto * i);
        i = i * 10;
  }

  return octal;
}

char decimal_hexa(int decimal){
    int sequencia = 0, valor;
    char *valor_hexa;
    while (decimal != 0){
        valor = decimal % 16;
        if (valor < 10)
            valor = valor + 48;
        else
            valor = valor + 55;
        valor_hexa[sequencia++] = valor;
        decimal = decimal / 16;
    }
    valor_hexa[sequencia+1] = '\0';
    return *valor_hexa;
}

int main (){
    int decimal, octal;
    char *hexa;
    printf("Digite o numero decimal: ");
    scanf("%d", &decimal);
    octal = decimal_octal(decimal);
    hexa = decimal_hexa(decimal);
    //printf("HEXA = %c \n", hexa);
    printf("OCTAL = %d \n", octal);

    return 0;
}