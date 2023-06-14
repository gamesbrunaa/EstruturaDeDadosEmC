#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ... (código anterior)

int main() {
    ArvoreCurso* raizCursos = NULL;

    // Códigos das disciplinas
    int codigosDisciplinas[] = {1, 2, 3, 4};

    // Embaralhar os códigos das disciplinas
    int numDisciplinas = sizeof(codigosDisciplinas) / sizeof(int);
    for (int i = numDisciplinas - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = codigosDisciplinas[i];
        codigosDisciplinas[i] = codigosDisciplinas[j];
        codigosDisciplinas[j] = temp;
    }

    // Criar e inserir as disciplinas
    ArvoreDisciplinas* arvoreDisciplinas = NULL;
    for (int i = 0; i < numDisciplinas; ++i) {
        int codigo = codigosDisciplinas[i];
        Disciplina* disciplina = criarDisciplina(codigo, "Disciplina", 1, 60);
        arvoreDisciplinas = inserirDisciplina(arvoreDisciplinas, *disciplina);
    }

    // Código do curso
    int codigoCurso = 1;

    // Criar o curso e inserir na árvore de cursos
    Curso* curso = criarCurso(codigoCurso, "Curso", 3, 16, arvoreDisciplinas);
    raizCursos = inserirCurso(raizCursos, *curso);

    // Medir o tempo de inserção dos elementos na árvore de cursos
    clock_t inicioInsercao = clock();

    // ... (inserir mais cursos e disciplinas, se necessário)

    clock_t fimInsercao = clock();
    double tempoInsercao = (double)(fimInsercao - inicioInsercao) / CLOCKS_PER_SEC;

    // Medir o tempo de busca de um curso na árvore de cursos (média de 30 repetições)
    int repeticoesBusca = 30;
    clock_t inicioBusca = clock();
    for (int i = 0; i < repeticoesBusca; ++i) {
        // ... (realizar a busca do curso desejado)
    }
    clock_t fimBusca = clock();
    double tempoBusca = (double)(fimBusca - inicioBusca) / (repeticoesBusca * CLOCKS_PER_SEC);

    // Imprimir os tempos de inserção e busca
    printf("Tempo de insercao: %.6f segundos\n", tempoInsercao);
    printf("Tempo de busca: %.6f segundos\n", tempoBusca);

    // ... (restante do código)

    return 0;
}