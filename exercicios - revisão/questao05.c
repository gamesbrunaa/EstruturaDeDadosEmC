#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float soma(float a, float b){
    float soma;
    soma = a + b;

    return soma;
}

float produto(float a, float b){
    float prod;
    prod = a * b;

    return prod;
}

float quadrado(float a, float b){
    float quad;
    quad = pow(a, b);

    return quad;
}

float raiz(float a, float b){
    float raiz, quada, quadb, soma2;
    quada = quadrado(a, 2);
    quadb = quadrado(b, 2);
    soma2 = soma(quada, quadb);
    raiz = sqrt(soma2);

    return(raiz);
}

float seno(float a, float b){
    float seno;
    return seno;
}

float modulo(float a){
    float mod;
    mod = a * (-1);
    return mod;
}

int main(){
    float x, y, s, p, q, r, se, m;

    printf("Digite o primeiro numero: \n");
    scanf("%f", &x);
    printf("Digite o segundo numero: ");
    scanf("%f", &y);

    s = soma(x, y);
    p = produto(x, y);
    q = quadrado(x, y);
    r = raiz(x, y);
    se = seno(x, y);
    m = modulo(x);

    printf("SOMA = %.2f \n", s);
    printf("PRODUTO = %.2f \n", p);
    printf("QUADRADO = %.2f \n", q);
    printf("RAIZ = %.2f \n", r);
    printf("SENO = %.2f \n", se);
    printf("MODULO = %.2f \n", m);

    return 0;
}