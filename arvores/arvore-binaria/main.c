#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cursosABB.h"
#include "cursosAVL.h"

void embaralhar(int *array, int tamanho) {
    int i, j, temp;
    srand(time(NULL));
    for (i = tamanho - 1; i > 0; i--) {
        j = rand() % i;;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int tamanho = 50000;
    int numerosDisciplinas[tamanho];
    int numerosCursos[tamanho];
    int i;

    for (i = 0; i < tamanho; i++) {
        numerosDisciplinas[i] = i + 1;
        numerosCursos[i] = i + 1;
    }

    embaralhar(numerosDisciplinas, tamanho);
    embaralhar(numerosCursos, tamanho);

    FILE* arquivo = fopen("numeros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "NUMEROS DISCIPLINAS:\n");
    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d   ", numerosDisciplinas[i]);
        
    }
    fprintf(arquivo, "\n");

    fprintf(arquivo, "NUMEROS CURSOS\n");
    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d  ", numerosCursos[i]);
    }

    struct ArvoreCurso* arvoreCursos = NULL;
    struct ArvoreCurso* arvoreCursos2 = NULL;
    struct ArvoreDisciplinas* arvoreDisciplinasMat = NULL;
    struct ArvoreDisciplinas* arvoreDisciplinasMat2 = NULL;

    // Medir o tempo de inserção dos elementos na árvore de cursos
    clock_t inicioInsercaoCursos = clock();
    //Criar e inserir cursos
    for(i = 0; i < tamanho; i++){
        Curso* curso = criarCurso(numerosCursos[i], "matematica", 8, 12, arvoreDisciplinasMat);
        arvoreCursos = inserirCurso(&arvoreCursos, curso);
    }
    clock_t fimInsercaoCursos = clock();
    double tempoInsercaoCursos = (double)(fimInsercaoCursos - inicioInsercaoCursos) / CLOCKS_PER_SEC;

    clock_t inicioInsercaoCursosAVL = clock();
    //Criar e inserir cursos AVL
    for(i = 0; i < tamanho; i++){
        Curso* curso1 = criarCursoAVL(numerosCursos[i], "matematica", 8, 12, arvoreDisciplinasMat2);
        arvoreCursos2 = inserirCursoAVL(&arvoreCursos2, curso1);
    }
    clock_t fimInsercaoCursosAVL = clock();
    double tempoInsercaoCursosAVL = (double)(fimInsercaoCursosAVL - inicioInsercaoCursosAVL) / CLOCKS_PER_SEC;

    // Medir o tempo de inserção dos elementos na árvore de disciplinas ABB
    clock_t inicioInsercaoDisciplinas = clock();
    for(i = 0; i < tamanho; i++){
        Disciplina* disciplina = criarDisciplina(numerosDisciplinas[i], "Disciplina", 1, 60);
        arvoreDisciplinasMat = inserirDisciplina(&arvoreDisciplinasMat, disciplina);
    }
    clock_t fimInsercaoDisciplinas = clock();
    double tempoInsercaoDisciplinas = (double)(fimInsercaoDisciplinas - inicioInsercaoDisciplinas) / CLOCKS_PER_SEC;

    // Medir o tempo de inserção dos elementos na árvore de disciplinas AVL
    clock_t inicioInsercaoDisciplinasAVL = clock();
    for(i = 0; i < tamanho; i++){
        Disciplina* disciplina1 = criarDisciplinaAVL(numerosDisciplinas[i], "Disciplina", 1, 60);
        arvoreDisciplinasMat2 = inserirDisciplinaAVL(&arvoreDisciplinasMat2, disciplina1);
    }
    clock_t fimInsercaoDisciplinasAVL = clock();
    double tempoInsercaoDisciplinasAVL = (double)(fimInsercaoDisciplinasAVL - inicioInsercaoDisciplinasAVL) / CLOCKS_PER_SEC;

    // Medir o tempo de busca de um curso na árvore de cursos ABB
    int repeticoesBusca = tamanho;
    clock_t inicioBuscaCurso = clock();
    ArvoreCurso* resultado = buscarCurso(arvoreCursos, 100);
    clock_t fimBuscaCurso = clock();
    double tempoBuscaCurso = (double)(fimBuscaCurso - inicioBuscaCurso) / (repeticoesBusca * CLOCKS_PER_SEC);

    // Medir o tempo de busca de um curso na árvore de cursos ABB
    clock_t inicioBuscaCursoAVL = clock();
    ArvoreCurso* resultado2 = buscarCursoAVL(arvoreCursos, 100);
    clock_t fimBuscaCursoAVL = clock();
    double tempoBuscaCursoAVL = (double)(fimBuscaCursoAVL - inicioBuscaCursoAVL) / (repeticoesBusca * CLOCKS_PER_SEC);

    // Medir o tempo de busca de um curso na árvore de disciplina ABB
    clock_t inicioBuscaDisciplina = clock();
    Disciplina* resultado3 = buscarDisciplina(arvoreDisciplinasMat, 10);
    clock_t fimBuscaDisciplina = clock();
    double tempoBuscaDisciplina = (double)(fimBuscaDisciplina - inicioBuscaDisciplina) / (repeticoesBusca * CLOCKS_PER_SEC);

    // Medir o tempo de busca de um curso na árvore de disciplina AVL
    clock_t inicioBuscaDisciplinaAVL = clock();
    Disciplina* resultado4 = buscarDisciplinaAVL(arvoreDisciplinasMat2, 10);
    clock_t fimBuscaDisciplinaAVL = clock();
    double tempoBuscaDisciplinaAVL = (double)(fimBuscaDisciplinaAVL - inicioBuscaDisciplinaAVL) / (repeticoesBusca * CLOCKS_PER_SEC);

    // Imprimir os tempos de inserção e busca
    printf("Tempo de insercao Curso ABB: %.6f segundos\n", tempoInsercaoCursos);
    printf("Tempo de insercao Disciplinas ABB: %.6f segundos\n", tempoInsercaoDisciplinas);
    printf("Tempo de busca Curso ABB: %.6f segundos\n", tempoBuscaCurso);
    printf("Tempo de busca Disciplina AVL: %.6f segundos\n", tempoBuscaDisciplina);
    printf("======================================================= \n");
    printf("Tempo de insercao Curso AVL: %.6f segundos\n", tempoInsercaoCursosAVL);
    printf("Tempo de insercao Disciplinas AVL: %.6f segundos\n", tempoInsercaoDisciplinasAVL);
    printf("Tempo de busca Curso AVL: %.6f segundos\n", tempoBuscaCursoAVL);
    printf("Tempo de busca Disciplina AVL: %.6f segundos\n", tempoBuscaDisciplinaAVL);

    return 0;
}