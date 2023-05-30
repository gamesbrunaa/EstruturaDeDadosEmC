#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main() {
    // Criando uma árvore de cursos vazia
    struct Curso* arvoreCursos = NULL;

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
        
        switch (op){
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            case 9:
                /* code */
                break;
            default:
                printf("Opção Inválida! \n");
                break;
        }
    }
    
    // Inserindo cursos na árvore
    arvoreCursos = inserirCurso(arvoreCursos, 15, "Ciencia da Computacao", 18, 20);
    arvoreCursos = inserirCurso(arvoreCursos, 20, "Engenharia Civil", 16, 18);
    arvoreCursos = inserirCurso(arvoreCursos, 10, "Administracao", 12, 15);

    // Buscando um curso pelo código
    int codigoBusca = 15;
    struct Curso* cursoEncontrado = buscarCurso(arvoreCursos, codigoBusca);
    if (cursoEncontrado != NULL) {
        printf("Curso encontrado:\n");
        printf("Código: %d\n", cursoEncontrado.codigo);
        printf("Nome: %s\n", cursoEncontrado->nome);
        printf("Quantidade de blocos: %d\n", cursoEncontrado->quantidadeBlocos);
        printf("Semanas por disciplina: %d\n", cursoEncontrado->semanasPorDisciplina);
        printf("\n");

        // Inserindo disciplinas no curso encontrado
        inserirDisciplina(cursoEncontrado, 1, "Matematica", 1, 400);
        inserirDisciplina(cursoEncontrado, 2, "Algoritmos", 2, 600);
        inserirDisciplina(cursoEncontrado, 3, "Banco de Dados", 3, 500);

        // Exibindo as disciplinas do curso
        printf("Disciplinas do curso:\n");
        exibirDisciplinas(cursoEncontrado);
    } else {
        printf("Curso nao encontrado.\n");
    }

    // Liberando a memória alocada pela árvore de cursos
    liberarArvoreCursos(arvoreCursos);

    return 0;
}