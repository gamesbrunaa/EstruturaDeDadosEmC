#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtdalunos;
    float n1, n2, media;

    printf("Digite a quantidade de alunos da turma: ");
    scanf("%d", &qtdalunos);

    while (qtdalunos != 0){
        printf("Digite a primeira nota: ");
        scanf("%f", &n1);
        if ((n1 >= 0) && (n1 <= 10)){
            printf("Digite a seguna nota: ");
            scanf("%f", &n2);
            media = (n1 + n2)/2;
            printf("MEDIA = %.2f", media);
        }else{
            break;
        }

        qtdalunos = qtdalunos - 1;
    }
    
    return 0;
}