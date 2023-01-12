#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "imagem.h"

struct pixel{
	int valor, x, y;
};

struct imagem{
	Pixel *pixels;
	int largura, altura;
};

Imagem *criarImagem(int largura, int altura){
	Imagem *mat;
	mat = (Imagem *) malloc(sizeof(Imagem));
	mat->altura = altura;
	mat->largura = largura;
	mat->pixels = (Pixel *) malloc(altura * largura * sizeof(Pixel));
	return mat;
}

void preencherImagem(Imagem *img){
	int i, j, k;
	for(i = 0; i < img->altura; i++){
		for(j = 0; j < img->largura; j++){
			k = i * img->largura + j;
			img->pixels[k].valor = 100;
			img->pixels[k].x = i;
			img->pixels[k].y = j;
		}
	}

}

void imprimirImagem(Imagem *img){
	int i, j, k;
	for(i = 0; i < img->altura; i++){
		for(j = 0; j < img->largura; j++){
			k = i * img->largura + j;
			printf("%d ", img->pixels[k].valor);
		}
		printf("\n");
	}
}

void setPixelValue(Imagem *img, int y, int x, int valor){
	int i, j, k;
	for(i = 0; i < img->altura; i++){
		for(j = 0; j < img->largura; j++){
			if (x == i && y == j ){
				k = i * img->largura + j;
				img->pixels[k].valor = valor;
			}
		}
	}
}

int getPixelValue(Imagem *img, int y, int x){
	int i, j, k, valor;
	for(i = 0; i < img->altura; i++){
		for(j = 0; j < img->largura; j++){
			if (x == i && y == j ){
				k = i * img->largura + j;
				valor = img->pixels[k].valor;
			}
		}
	}
	return valor;
}

void liberarImagem(Imagem *img){
	free(img->pixels);
	free(img);
}
