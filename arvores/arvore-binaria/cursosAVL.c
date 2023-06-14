#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de uma disciplina
typedef struct {
    int codigo;
    char nome[50];
    int bloco;
    int cargaHoraria;
} Disciplina;

// Estrutura para a árvore de disciplinas
typedef struct {
    Disciplina disciplina;
    ArvoreDisciplinas *esquerda;
    ArvoreDisciplinas *direita;
    int altura;
} ArvoreDisciplinas;

// Estrutura para armazenar os dados de um curso
typedef struct {
    int codigo;
    char nome[50];
    int quantidadeBlocos;
    int semanasPorDisciplina;
    struct ArvoreDisciplinas *disciplinas; // Ponteiro para a árvore de disciplinas do curso
} Curso;

// Estrutura para a árvore de Cursos
typedef struct {
    Curso curso;
    ArvoreCurso *esquerda;
    ArvoreCurso *direita;
    int altura;
} ArvoreCurso;

// Função para criar um novo nó na árvore de disciplinas
ArvoreDisciplinas* criarNoDisciplina(Disciplina disciplina) {
    ArvoreDisciplinas* novoNo = (ArvoreDisciplinas*)malloc(sizeof(ArvoreDisciplinas));
    novoNo->disciplina = disciplina;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para criar uma nova disciplina
Disciplina* criarDisciplina(int codigo, char nome[], int bloco, int cargaHoraria) {
    Disciplina* novaDisciplina = (Disciplina*)malloc(sizeof(Disciplina));
    novaDisciplina->codigo = codigo;
    strcpy(novaDisciplina->nome, nome);
    novaDisciplina->bloco = bloco;
    novaDisciplina->cargaHoraria = cargaHoraria;
    return novaDisciplina;
}

// Função para criar um novo nó na árvore de cursos
ArvoreCurso* criarNoCurso(Curso curso) {
    ArvoreCurso* novoNo = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
    novoNo->curso = curso;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para criar um novo curso
Curso* criarCurso(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina, ArvoreDisciplinas *disciplinas) {
    Curso* novoCurso = (Curso*)malloc(sizeof(Curso));
    novoCurso->codigo = codigo;
    strcpy(novoCurso->nome, nome);
    novoCurso->quantidadeBlocos = quantidadeBlocos;
    novoCurso->semanasPorDisciplina = semanasPorDisciplina;
    novoCurso->disciplinas = NULL;
    return novoCurso;
}

// Função para calcular o fator de balanceamento da árvore de disciplinas
int fatorBalanceamentoDisciplinas(ArvoreDisciplinas *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (raiz->esquerda->altura - (raiz->direita->altura));
}

// Função para balancear a árvore de disciplinas (se necessário)
void balancearArvoreDisciplinas(ArvoreDisciplinas** raiz) {
    int fb = fatorBalanceamentoDisciplinas(*raiz);
    if (fb > 1) {
        if (fatorBalanceamentoDisciplinas((*raiz)->esquerda) < 0)
            rotacaoEsquerdaDisciplinas(&((*raiz)->esquerda));
        rotacaoDireitaDisciplinas(raiz);
    } else if (fb < -1) {
        if (fatorBalanceamentoDisciplinas((*raiz)->direita) > 0)
            rotacaoDireitaDisciplinas(&((*raiz)->direita));
        rotacaoEsquerdaDisciplinas(raiz);
    }
    atualizarAlturaDisciplinas(raiz);
}

// Função para realizar a rotação à direita na árvore de disciplinas
void rotacaoDireitaDisciplinas(ArvoreDisciplinas** raiz) {
    ArvoreDisciplinas* temp = (*raiz)->esquerda;
    (*raiz)->esquerda = temp->direita;
    temp->direita = *raiz;
    *raiz = temp;
    atualizarAlturaDisciplinas(raiz);
}

// Função para realizar a rotação à esquerda na árvore de disciplinas
void rotacaoEsquerdaDisciplinas(ArvoreDisciplinas** raiz) {
    ArvoreDisciplinas* temp = (*raiz)->direita;
    (*raiz)->direita = temp->esquerda;
    temp->esquerda = *raiz;
    *raiz = temp;
    atualizarAlturaDisciplinas(raiz);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Função para atualizar a altura da árvore de disciplinas
void atualizarAlturaDisciplinas(ArvoreDisciplinas** raiz) {
    int alturaEsquerda, alturaDireita;
    if (*raiz == NULL) {
        return;
    }
    
    atualizarAlturaDisciplinas(&((*raiz)->esquerda));
    atualizarAlturaDisciplinas(&((*raiz)->direita));
    
    int alturaEsquerda = 0;
    if ((*raiz)->esquerda != NULL) {
        alturaEsquerda = (*raiz)->esquerda->altura;
    }
    
    int alturaDireita = 0;
    if ((*raiz)->direita != NULL) {
        alturaDireita = (*raiz)->direita->altura;
    }
    
    (*raiz)->altura = 1 + max(alturaEsquerda, alturaDireita);
}

// Função para inserir uma disciplina na árvore de disciplinas
void inserirDisciplina(ArvoreDisciplinas** raiz, Disciplina *disciplina) {
    int fb;
    if (*raiz == NULL) {
        *raiz = criarNoDisciplina(*disciplina);
    } else if (disciplina->codigo < (*raiz)->disciplina.codigo) {
        inserirDisciplina(&((*raiz)->esquerda), disciplina);
    } else {
        inserirDisciplina(&((*raiz)->direita), disciplina);
    }

    balancearArvoreDisciplinas(raiz);

    *raiz = disciplina;
}


// Função para calcular o fator de balanceamento da arvore de cursos
int fatorBalanceamentoCurso(ArvoreCurso *raiz){
    if (raiz == NULL) {
        return 0;
    }
    return ((raiz->esquerda->altura) - (raiz->direita->altura));
}

// Função para balancear a árvore de cursos (se necessário)
void balancearArvoreCurso(ArvoreCurso** raiz) {
    int fb = fatorBalanceamentoCurso(*raiz);
    if (fb > 1) {
        if (fatorBalanceamentoCurso((*raiz)->esquerda) < 0)
            rotacaoEsquerdaCurso(&((*raiz)->esquerda));
        rotacaoDireitaCurso(raiz);
    } else if (fb < -1) {
        if (fatorBalanceamentoCurso((*raiz)->direita) > 0)
            rotacaoDireitaCurso(&((*raiz)->direita));
        rotacaoEsquerdaCurso(raiz);
    }
    atualizarAlturaCurso(raiz);
}

//Função para realizar o balanceamento da arvore de cursos (se necessário)
void rotacaoDireitaCurso(ArvoreCurso** raiz){
    ArvoreCurso* temp = (*raiz)->esquerda;
    (*raiz)->esquerda = temp->direita;
    temp->direita = *raiz;
    *raiz = temp;
    atualizarAlturaCurso(raiz);
}

//Função para realizar o balanceamento da arvore de cursos (se necessário)
void rotacaoEsquerdaCurso(ArvoreCurso** raiz){
    ArvoreCurso* temp = (*raiz)->direita;
    (*raiz)->direita = temp->esquerda;
    temp->esquerda = *raiz;
    *raiz = temp;
    atualizarAlturaCurso(raiz);
}

//Função para atualizar altura da arvore de cursos (se necessário)
void atualizarAlturaCurso(ArvoreCurso** raiz) {
    int alturaEsquerda, alturaDireita;
    if (*raiz == NULL) {
        return;
    }
    
    atualizarAlturaCurso(&((*raiz)->esquerda));
    atualizarAlturaCurso(&((*raiz)->direita));
    
    int alturaEsquerda = 0;
    if ((*raiz)->esquerda != NULL) {
        alturaEsquerda = (*raiz)->esquerda->altura;
    }
    
    int alturaDireita = 0;
    if ((*raiz)->direita != NULL) {
        alturaDireita = (*raiz)->direita->altura;
    }
    
    (*raiz)->altura = 1 + max(alturaEsquerda, alturaDireita);
}

void inserirCurso(ArvoreCurso** raiz, Curso* curso) {
    int fb;
    if (*raiz == NULL) {
        *raiz = curso;
    } else if (curso->codigo < (*raiz)->curso.codigo) {
        inserirCurso(&((*raiz)->esquerda), curso);
    } else {
        inserirCurso(&((*raiz)->direita), curso);
    }

    balancearArvoreCurso(raiz);
    
    *raiz = curso;
}

// Função para buscar uma disciplina na árvore de disciplinas
ArvoreDisciplinas* buscarDisciplina(ArvoreDisciplinas* raiz, int codigo) {
    if (raiz == NULL || raiz->disciplina.codigo == codigo) {
        return raiz;
    }

    if (codigo < raiz->disciplina.codigo) {
        return buscarDisciplina(raiz->esquerda, codigo);
    } else {
        return buscarDisciplina(raiz->direita, codigo);
    }
}

// Função para buscar um curso na árvore de cursos
ArvoreCurso* buscarCurso(ArvoreCurso* raiz, int codigo) {
    if (raiz == NULL || raiz->curso.codigo == codigo) {
        return raiz;
    }

    if (codigo < raiz->curso.codigo) {
        return buscarCurso(raiz->esquerda, codigo);
    } else {
        return buscarCurso(raiz->direita, codigo);
    }
}

// Função para exibir os dados de uma disciplina
void exibirDisciplina(Disciplina disciplina) {
    printf("Código: %d\n", disciplina.codigo);
    printf("Nome: %s\n", disciplina.nome);
    printf("Bloco: %d\n", disciplina.bloco);
    printf("Carga horária: %d\n", disciplina.cargaHoraria);
    printf("\n");
}

// Função para exibir a árvore de disciplinas em ordem
void exibirArvoreDisciplinas(ArvoreDisciplinas* raiz) {
    exibirArvoreDisciplinas(raiz->esquerda);
    exibirDisciplina(raiz->disciplina);
    exibirArvoreDisciplinas(raiz->direita);
}

// Função para exibir os dados de um curso
void exibirCurso(Curso curso) {
    printf("Código: %d\n", curso.codigo);
    printf("Nome: %s\n", curso.nome);
    printf("Quantidade de Blocos: %d\n", curso.quantidadeBlocos);
    printf("Semanas por Disciplinas: %d\n", curso.semanasPorDisciplina);
    printf("Disciplinas: \n");
    exibirArvoreDisciplinas(curso.disciplinas);
    printf("\n");
}

// Função para exibir a árvore de cursos em ordem
void exibirArvoreCurso(ArvoreCurso* raiz) {
    exibirArvoreCurso(raiz->esquerda);
    exibirCurso(raiz->curso);
    exibirArvoreCurso(raiz->direita);
}

//(1) Imprimir a árvore de cursos em ordem crescente pelo código do curso
void ImprimirCursos_OrdemCrescente(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCurso(raiz, codigo);
    if(aux != NULL){
        exibirArvoreCurso(raiz);
    } else{
        printf("Curso não encontrado.\n");
    }
}

//(2) Imprimir os dados de um curso dado o código do mesmo
void imprimirCursos_Dados(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCurso(raiz, codigo);
    if(aux != NULL){
        if(codigo == raiz->curso.codigo){
            exibirCurso(raiz->curso);
        }
    } else{
        printf("Curso não encontrado.\n");
    }
}

//(3) Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos
void imprimirCursos_QtdBlocos(ArvoreCurso* raiz, int quantidadeBlocos){
    if(raiz != NULL){
        if(raiz->curso.quantidadeBlocos == quantidadeBlocos){
            exibirCurso(raiz->curso);
        }
        imprimirCursos_QtdBlocos(raiz->esquerda, quantidadeBlocos);
        imprimirCursos_QtdBlocos(raiz->direita, quantidadeBlocos);
    }
}

//(4) Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
void ImprimirDisciplinas_OrdemCrescente(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCurso(raiz, codigo);
    if(aux != NULL){
        exibirArvoreDisciplinas(aux);
    } else {
        printf("Curso não encontrado.\n");
    }
}

//(5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
void ImprimirDisciplinas_Dados(ArvoreCurso* raiz, int codigo, int codigo2){
    ArvoreCurso *cursoEncontrado = buscarCurso(raiz, codigo2);
    if(cursoEncontrado != NULL){
        ArvoreDisciplinas *disciplinas = cursoEncontrado->curso.disciplinas;
        if(disciplinas != NULL){
            Disciplina *disciplinaEncontrada = buscarDisciplina(disciplinas, codigo);
            if(disciplinaEncontrada != NULL){
                exibirDisciplina(*disciplinaEncontrada);
            }
        } else{
            printf("O curso não possui disciplinas cadastradas!\n");
        }
    } else{
        printf("Curso não encontrado!\n");
    }
}

//(6) Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso
void imprimirDisciplinas_Bloco(ArvoreCurso* raiz, int bloco, int codigo){
    if(raiz != NULL){
        if(raiz->curso.codigo == codigo){
            ArvoreDisciplinas *aux = raiz->curso.disciplinas;
            if(aux->disciplina.bloco == bloco){
                exibirDisciplina(aux->disciplina);
            }
            aux = raiz->esquerda;
            if(aux->disciplina.bloco == bloco){
                exibirDisciplina(aux->disciplina);
            }
            aux = raiz->direita;
            if(aux->disciplina.bloco == bloco){
                exibirDisciplina(aux->disciplina);
            }
        }else if(codigo < raiz->curso.codigo){
            imprimirDisciplinas_CargaHoraria(raiz->esquerda, bloco, codigo);
        }else{
            imprimirDisciplinas_CargaHoraria(raiz->direita, bloco, codigo);
        }
    }
}

//(7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário
void imprimirDisciplinas_CargaHoraria(ArvoreCurso* raiz, int cargaH, int codigo){
    if(raiz != NULL){
        if(raiz->curso.codigo == codigo){
            ArvoreDisciplinas *aux = raiz->curso.disciplinas;
            if(aux->disciplina.cargaHoraria == cargaH){
                exibirDisciplina(aux->disciplina);
            }
            aux = raiz->esquerda;
            if(aux->disciplina.cargaHoraria == cargaH){
                exibirDisciplina(aux->disciplina);
            }
            aux = raiz->direita;
            if(aux->disciplina.cargaHoraria == cargaH){
                exibirDisciplina(aux->disciplina);
            }
        }else if(codigo < raiz->curso.codigo){
            imprimirDisciplinas_CargaHoraria(raiz->esquerda, cargaH, codigo);
        }else{
            imprimirDisciplinas_CargaHoraria(raiz->direita, cargaH, codigo);
        }
    }
}

//(8) Excluir uma disciplina dado o código da disciplina e o código do curso
void excluirDisciplina(ArvoreCurso** raiz, int codigoCurso, ArvoreDisciplinas** raiz2, int codigoDisciplina) {
    if (*raiz != NULL) {
        if (codigoCurso == (*raiz)->curso.codigo) {
            if (*raiz2 != NULL) {
                if ((*raiz2)->disciplina.codigo == codigoDisciplina) {
                    ArvoreDisciplinas* aux = *raiz2;
                    *raiz2 = removerNoDisciplina(*raiz2, codigoDisciplina);
                    free(aux);
                } else if (codigoDisciplina < (*raiz2)->disciplina.codigo) {
                    excluirDisciplina(raiz, codigoCurso, &(*raiz2)->esquerda, codigoDisciplina);
                } else {
                    excluirDisciplina(raiz, codigoCurso, &(*raiz2)->direita, codigoDisciplina);
                }
                atualizarAlturaDisciplinas(raiz2);
                balancearArvoreDisciplinas(raiz2);
            }
        } else if (codigoCurso < (*raiz)->curso.codigo) {
            excluirDisciplina(&(*raiz)->esquerda, codigoCurso, raiz2, codigoDisciplina);
            atualizarAlturaCurso(raiz);
            balancearArvoreCurso(raiz);
        } else {
            excluirDisciplina(&(*raiz)->direita, codigoCurso, raiz2, codigoDisciplina);
            atualizarAlturaCurso(raiz);
            balancearArvoreCurso(raiz);
        }
    }
}

//(9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void excluirCurso(ArvoreCurso** raiz, int codigoCurso) {
     if (*raiz != NULL) {
        if (codigoCurso == (*raiz)->curso.codigo) {
            if ((*raiz)->curso.disciplinas != NULL) {
                printf("Não é possível excluir o curso, pois possui disciplinas cadastradas!\n");
            } else {
                ArvoreCurso* aux = *raiz;
                *raiz = NULL;
                free(aux);
            }
        } else if (codigoCurso < (*raiz)->curso.codigo) {
            excluirCurso(&(*raiz)->esquerda, codigoCurso);
        } else {
            excluirCurso(&(*raiz)->direita, codigoCurso);
        }
        balancearArvoreCurso(raiz);
    }
}

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