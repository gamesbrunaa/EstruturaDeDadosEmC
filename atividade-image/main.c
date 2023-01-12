#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

int main(){
	Imagem *img;

	img = criarImagem(5,5);
	preencherImagem(img);
	imprimirImagem(img);
	setPixelValue(img, 3, 2, 255);
	printf("\n");
	imprimirImagem(img);
	printf("Valor da posicao (3,2): %d\n", getPixelValue(img, 3,2));

	/*
	1 - Comente o que acontece com as linhas 15 e 16
	img->pixels[10].valor = 255;
	print("%d ", img->pixels[10].valor);
	*/
	/*
	2 - Comente o que acontece com as linhas 20 e 21
	setPixelValue(img, 3,2, 255);
	A função set troca o número informado pelo que está dentro da matriz na posição indicada.
	printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3,2));
	A função get retorna o número que está denro da matriz na posição indicada.
	*/
	liberarImagem(img);

	return 0;
}