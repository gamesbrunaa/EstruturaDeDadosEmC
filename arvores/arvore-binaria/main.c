int main() {
    // Criando uma árvore de cursos vazia
    struct Curso* arvoreCursos = NULL;

    int codigoCurso;

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
                imprimirCursos_OrdemCrescente(arvoreCursos, codigoCurso);
                break;
            case 2:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                imprimirCurso_Dados(arvoreCursos, codigoCurso);
                break;
            case 3:
                int quantidadeBlocos;
                printf("Digite a quantidade de blocos: ");
                scanf("%d", &quantidadeBlocos);
                printf("Cursos com a mesma quantidade de blocos:\n");
                imprimirCursos_QtdBlocos(arvoreCursos, quantidadeBlocos);
                break;
            case 4:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                imprimirDisciplinas_OrdemCrescente(arvoreCursos, codigoCurso);
                break;
            case 5:
                int codigoDisciplina;
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o código da disciplina: ");
                scanf("%d", &codigoDisciplina);
                imprimirDisciplina_Dados(arvoreCursos, codigoDisciplina, codigoCurso);
                break;
            case 6:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o número do bloco: ");
                int numeroBloco;
                scanf("%d", &numeroBloco);
                imprimirDisciplinas_Bloco(arvoreCursos, numeroBloco, codigoCurso);
                break;
            case 7:
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite a carga horária: ");
                int cargaHoraria;
                scanf("%d", &cargaHoraria);
                imprimirDisciplinas_CargaHoraria(arvoreCursos, cargaHoraria, codigoCurso);
                break;
            case 8:
                int codigoDisciplinaExcluir, codigoCurso;
                printf("Digite o código do curso: ");
                scanf("%d", &codigoCurso);
                printf("Digite o código da disciplina: ");
                scanf("%d", &codigoDisciplinaExcluir);
                Curso* cursoExcluirDisciplina = buscarCurso(arvoreCursos, codigoCurso);
                if (cursoExcluirDisciplina != NULL){
                    excluirDisciplina(arvoreCursos, codigoCurso, cursoExcluirDisciplina->disciplinas, codigoDisciplinaExcluir);
                } else {
                    printf("Curso não encontrado.\n");
                }
                break;
            case 9:
                printf("Digite o código do curso: ");
                int codigoCursoExcluir;
                scanf("%d", &codigoCursoExcluir);
                excluirCurso(arvoreCursos, codigoCursoExcluir);
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }

    // Liberando a memória alocada pela árvore de cursos
    liberarArvoreCursos(arvoreCursos);

    return 0;
}