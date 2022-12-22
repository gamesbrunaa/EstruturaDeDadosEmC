#include<stdio.h>
#include<stdlib.h>

double juroscompostos(double valor, double taxa, int meses){
   double total;
	if (meses==0)
       return valor;
	else{
		valor = valor  + (valor * (taxa / 100));
        meses --;
        total = juroscompostos(valor,taxa,meses);
 		return total;
    }
}

int main(){
	double c,j;
	int t;
	printf("Digite o valor e a taxa de juros: ");
	scanf("%lf%lf",&c, &j);
	printf("Digite o tempo: ");
	scanf("%d", &t);
	
	printf("\nM = %2.lf\n",juroscompostos(c,j,t));	
	return 0;
}
