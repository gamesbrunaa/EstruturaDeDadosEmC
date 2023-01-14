#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, result = 0;
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            result = i * j;
            printf("%d x %d = %d \n", i, j, result);
        }
        printf("\n");
    }

    return 0;
}