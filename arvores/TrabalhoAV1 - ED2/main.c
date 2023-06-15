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
    clock_t inicioBuscaCurso = clock();
    Curso* resultado = buscarCurso(arvoreCursos, 100);
    //printf("%d \n", );
    clock_t fimBuscaCurso = clock();
    double tempoBuscaCurso = (double)(fimBuscaCurso - inicioBuscaCurso) / CLOCKS_PER_SEC;

    // Medir o tempo de busca de um curso na árvore de cursos ABB
    clock_t inicioBuscaCursoAVL = clock();
    ArvoreCurso* resultado2 = buscarCursoAVL(arvoreCursos, 100);
    //exibirCursoAVL(resultado2);
    clock_t fimBuscaCursoAVL = clock();
    double tempoBuscaCursoAVL = (double)(fimBuscaCursoAVL - inicioBuscaCursoAVL) / CLOCKS_PER_SEC;

    int valor;

    // Medir o tempo de busca de um curso na árvore de disciplina ABB
    clock_t inicioBuscaDisciplina = clock();
    Disciplina* resultado3 = buscarDisciplina(arvoreDisciplinasMat, valor);
    clock_t fimBuscaDisciplina = clock();
    double tempoBuscaDisciplina = (double)(fimBuscaDisciplina - inicioBuscaDisciplina) / CLOCKS_PER_SEC;

    // Medir o tempo de busca de um curso na árvore de disciplina AVL
    clock_t inicioBuscaDisciplinaAVL = clock();
    Disciplina* resultado4 = buscarDisciplinaAVL(arvoreDisciplinasMat2, 10);
    clock_t fimBuscaDisciplinaAVL = clock();
    double tempoBuscaDisciplinaAVL = (double)(fimBuscaDisciplinaAVL - inicioBuscaDisciplinaAVL) /  CLOCKS_PER_SEC;

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

    // FUNÇÕES PARA O USUÁRIO

    int codigoCurso, quantidadeBlocos, codigoDisciplina, numeroBloco, cargaHoraria, codigoDisciplinaExcluir, codigoCursoExcluir;

    int op = 0;
    while (op != -1){
        printf("MENU: \n");
        printf("(1) - Imprimir a árvore de cursos em ordem crescente pelo código do curso \n");
        printf("(2) - Imprimir os dados de um curso dado o código do mesmo \n");
        printf("(3) - Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos \n");
        printf("(4) - Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso \n");
        printf("(5) - Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence \n");
        printf("(6) - Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso\n");
        printf("(7) - Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário \n");
        printf("(8) - Excluir uma disciplina dado o código da disciplina e o código do curso \n");
        printf("(9) - Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso. \n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Árvore de cursos em ordem crescente pelo código do curso:\n");
                ImprimirCursos_OrdemCrescente(arvoreCursos, codigoCurso);
                break;
            case 2:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                imprimirCursos_Dados(arvoreCursos, codigoCurso);
                break;
            case 3:
                printf("Digite a quantidade de blocos: ");
                scanf("%d", &quantidadeBlocos);
                printf("Cursos com a mesma quantidade de blocos:\n");
                imprimirCursos_QtdBlocos(arvoreCursos, quantidadeBlocos);
                break;
            case 4:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                ImprimirDisciplinas_OrdemCrescente(arvoreCursos, codigoCurso);
                break;
            case 5:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o código da disciplina: ");
                scanf("%d", &codigoDisciplina);
                ImprimirDisciplinas_Dados(arvoreCursos, codigoDisciplina, codigoCurso);
                break;
            case 6:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o número do bloco: ");
                scanf("%d", &numeroBloco);
                imprimirDisciplinas_Bloco(arvoreCursos, numeroBloco, codigoCurso);
                break;
            case 7:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite a carga horária: ");
                scanf("%d", &cargaHoraria);
                imprimirDisciplinas_CargaHoraria(arvoreCursos, cargaHoraria, codigoCurso);
                break;
            case 8:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o código da disciplina: ");
                scanf("%d", &codigoDisciplinaExcluir);
                excluirDisciplina(&arvoreCursos, codigoCurso, codigoDisciplinaExcluir);
                break;
            case 9:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCursoExcluir);
                excluirCurso(&arvoreCursos, codigoCursoExcluir);
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }
    return 0;
}