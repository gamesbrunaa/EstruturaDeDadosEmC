#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, i;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    if(a < b){
        for(i = a; i <= b; i++){
            printf("%d\n", i);
        }
    }else if (a > b){
        for(i = b; i <= a; i++){
            printf("%d\n", i);
        }
    }else{
        printf("Valores iguais!!!");
    }
    
    return 0;
}