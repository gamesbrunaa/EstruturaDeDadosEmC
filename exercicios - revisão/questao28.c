#include <stdio.h>
#include <stdlib.h>

int main (){
    char str[10];

    printf("Digite a string: ");
    scanf("%s", str);

    if((str == 'SIM') || (str == 'sim')){
        return 1;
    } else if ((str == 'NAO') || (str == 'nao')){
        return 0;
    } else{
        system("PAUSE");
    }

}