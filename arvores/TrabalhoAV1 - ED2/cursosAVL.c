#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar os dados de uma disciplina
typedef struct {
    int codigo;
    char nome[50];
    int bloco;
    int cargaHoraria;
} Disciplina;

// Estrutura para a árvore de disciplinas
typedef struct ArvoreDisciplinas{
    Disciplina disciplina;
    struct ArvoreDisciplinas *esquerda;
    struct ArvoreDisciplinas *direita;
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
typedef struct ArvoreCurso{
    Curso curso;
    struct ArvoreCurso *esquerda;
    struct ArvoreCurso *direita;
    int altura;
} ArvoreCurso;

// Função para criar um novo nó na árvore de disciplinas
ArvoreDisciplinas* criarNoDisciplinaAVL(Disciplina disciplina) {
    ArvoreDisciplinas* novoNo = (ArvoreDisciplinas*)malloc(sizeof(ArvoreDisciplinas));
    novoNo->disciplina = disciplina;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para criar uma nova disciplina
Disciplina* criarDisciplinaAVL(int codigo, char nome[], int bloco, int cargaHoraria) {
    Disciplina* novaDisciplina = (Disciplina*)malloc(sizeof(Disciplina));
    novaDisciplina->codigo = codigo;
    strcpy(novaDisciplina->nome, nome);
    novaDisciplina->bloco = bloco;
    novaDisciplina->cargaHoraria = cargaHoraria;
    return novaDisciplina;
}

// Função para criar um novo nó na árvore de cursos
ArvoreCurso* criarNoCursoAVL(Curso curso) {
    ArvoreCurso* novoNo = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
    novoNo->curso = curso;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para criar um novo curso
Curso* criarCursoAVL(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina, ArvoreDisciplinas *disciplinas) {
    Curso* novoCurso = (Curso*)malloc(sizeof(Curso));
    novoCurso->codigo = codigo;
    strcpy(novoCurso->nome, nome);
    novoCurso->quantidadeBlocos = quantidadeBlocos;
    novoCurso->semanasPorDisciplina = semanasPorDisciplina;
    novoCurso->disciplinas = disciplinas;
    return novoCurso;
}

// Função para calcular o fator de balanceamento da árvore de disciplinas
int fatorBalanceamentoDisciplinas(ArvoreDisciplinas *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (raiz->esquerda->altura - (raiz->direita->altura));
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
    
    alturaEsquerda = 0;
    if ((*raiz)->esquerda != NULL) {
        alturaEsquerda = (*raiz)->esquerda->altura;
    }
    
    alturaDireita = 0;
    if ((*raiz)->direita != NULL) {
        alturaDireita = (*raiz)->direita->altura;
    }
    
    (*raiz)->altura = 1 + max(alturaEsquerda, alturaDireita);
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

// Função para calcular o fator de balanceamento da arvore de cursos
int fatorBalanceamentoCurso(ArvoreCurso *raiz){
    if (raiz == NULL) {
        return 0;
    }
    return (raiz->esquerda->altura - (raiz->direita->altura));
}

//Função para atualizar altura da arvore de cursos (se necessário)
void atualizarAlturaCurso(ArvoreCurso** raiz) {
    int alturaEsquerda, alturaDireita;
    if (*raiz == NULL) {
        return;
    }
    atualizarAlturaCurso(&((*raiz)->esquerda));
    atualizarAlturaCurso(&((*raiz)->direita));
    alturaEsquerda = 0;
    if ((*raiz)->esquerda != NULL) {
        alturaEsquerda = (*raiz)->esquerda->altura;
    }
    alturaDireita = 0;
    if ((*raiz)->direita != NULL) {
        alturaDireita = (*raiz)->direita->altura;
    }
    (*raiz)->altura = 1 + max(alturaEsquerda, alturaDireita);
}

// Função para inserir uma disciplina na árvore de disciplinas
ArvoreDisciplinas* inserirDisciplinaAVL(ArvoreDisciplinas** raiz, Disciplina *disciplina) {
    if (*raiz == NULL) {
        ArvoreDisciplinas* novoNo = criarNoDisciplinaAVL(*disciplina);
        *raiz = novoNo;
        return novoNo;
    } else if (disciplina->codigo < (*raiz)->disciplina.codigo) {
        return inserirDisciplinaAVL(&((*raiz)->esquerda), disciplina);
    } else {
        return inserirDisciplinaAVL(&((*raiz)->direita), disciplina);
    }
    balancearArvoreDisciplinas(raiz);
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

ArvoreCurso* inserirCursoAVL(ArvoreCurso** raiz, Curso *curso) {
    if (*raiz == NULL) {
        ArvoreCurso* novoNo = criarNoCursoAVL(*curso);
        *raiz = novoNo;
        return novoNo;
    } else if (curso->codigo < (*raiz)->curso.codigo) {
        return inserirCursoAVL(&((*raiz)->esquerda), curso);
    } else {
        return inserirCursoAVL(&((*raiz)->direita), curso);
    }

    balancearArvoreCurso(raiz);
}

// Função para buscar uma disciplina na árvore de disciplinas
Disciplina* buscarDisciplinaAVL(ArvoreDisciplinas* raiz, int codigo) {
    while (raiz != NULL && raiz->disciplina.codigo != codigo) {
        if (codigo < raiz->disciplina.codigo) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }
    if (raiz == NULL) {
        return NULL;
    } else {
        return &(raiz->disciplina);
    }
}

// Função para buscar um curso na árvore de cursos
ArvoreCurso* buscarCursoAVL(ArvoreCurso* raiz, int codigo) {
    while (raiz != NULL && raiz->curso.codigo != codigo) {
        if (codigo < raiz->curso.codigo) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }
    return raiz;
}

// Função para exibir os dados de uma disciplina
void exibirDisciplinaAVL(Disciplina disciplina) {
    printf("Código: %d\n", disciplina.codigo);
    printf("Nome: %s\n", disciplina.nome);
    printf("Bloco: %d\n", disciplina.bloco);
    printf("Carga horária: %d\n", disciplina.cargaHoraria);
    printf("\n");
}

// Função para exibir a árvore de disciplinas em ordem
void exibirArvoreDisciplinasAVL(ArvoreDisciplinas* raiz) {
    exibirArvoreDisciplinasAVL(raiz->esquerda);
    exibirDisciplinaAVL(raiz->disciplina);
    exibirArvoreDisciplinasAVL(raiz->direita);
}

// Função para exibir os dados de um curso
void exibirCursoAVL(Curso curso) {
    printf("Código: %d\n", curso.codigo);
    printf("Nome: %s\n", curso.nome);
    printf("Quantidade de Blocos: %d\n", curso.quantidadeBlocos);
    printf("Semanas por Disciplinas: %d\n", curso.semanasPorDisciplina);
    printf("Disciplinas: \n");
    exibirArvoreDisciplinasAVL(curso.disciplinas);
    printf("\n");
}

// Função para exibir a árvore de cursos em ordem
void exibirArvoreCursoAVL(ArvoreCurso* raiz) {
    exibirArvoreCursoAVL(raiz->esquerda);
    exibirCursoAVL(raiz->curso);
    exibirArvoreCursoAVL(raiz->direita);
}

//(1) Imprimir a árvore de cursos em ordem crescente pelo código do curso
void ImprimirCursos_OrdemCrescenteAVL(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCursoAVL(raiz, codigo);
    if(aux != NULL){
        exibirArvoreCursoAVL(raiz);
    } else{
        printf("Curso não encontrado.\n");
    }
}

//(2) Imprimir os dados de um curso dado o código do mesmo
void imprimirCursos_DadosAVL(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCursoAVL(raiz, codigo);
    if(aux != NULL){
        if(codigo == raiz->curso.codigo){
            exibirCursoAVL(raiz->curso);
        }
    } else{
        printf("Curso não encontrado.\n");
    }
}

//(3) Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos
void imprimirCursos_QtdBlocosAVL(ArvoreCurso* raiz, int quantidadeBlocos){
    if(raiz != NULL){
        if(raiz->curso.quantidadeBlocos == quantidadeBlocos){
            exibirCursoAVL(raiz->curso);
        }
        imprimirCursos_QtdBlocosAVL(raiz->esquerda, quantidadeBlocos);
        imprimirCursos_QtdBlocosAVL(raiz->direita, quantidadeBlocos);
    }
}

//(4) Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
void ImprimirDisciplinas_OrdemCrescenteAVL(ArvoreCurso* raiz, int codigo){
    ArvoreCurso *aux = buscarCursoAVL(raiz, codigo);
    if(aux != NULL){
        exibirArvoreDisciplinasAVL(aux->curso.disciplinas);
    } else {
        printf("Curso não encontrado.\n");
    }
}

//(5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
void ImprimirDisciplinas_DadosAVL(ArvoreCurso* raiz, int codigo, int codigo2){
    ArvoreCurso *cursoEncontrado = buscarCursoAVL(raiz, codigo2);
    if(cursoEncontrado != NULL){
        ArvoreDisciplinas *disciplinas = cursoEncontrado->curso.disciplinas;
        if(disciplinas != NULL){
            Disciplina *disciplinaEncontrada = buscarDisciplinaAVL(disciplinas, codigo);
            if(disciplinaEncontrada != NULL){
                exibirDisciplinaAVL(*disciplinaEncontrada);
            }
        } else{
            printf("O curso não possui disciplinas cadastradas!\n");
        }
    } else{
        printf("Curso não encontrado!\n");
    }
}

//(6) Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso
void imprimirDisciplinas_BlocoAVL(ArvoreDisciplinas* raiz, int bloco) {
    if (raiz != NULL) {
        imprimirDisciplinas_BlocoAVL(raiz->esquerda, bloco);
        if (raiz->disciplina.bloco == bloco) {
            printf("Código: %d\n", raiz->disciplina.codigo);
            printf("Nome: %s\n", raiz->disciplina.nome);
            printf("Bloco: %d\n", raiz->disciplina.bloco);
            printf("Carga Horária: %d\n", raiz->disciplina.cargaHoraria);
            printf("--------------------\n");
        }
        imprimirDisciplinas_BlocoAVL(raiz->direita, bloco);
    }
}

//(7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário
void imprimirDisciplinas_CargaHorariaAVL(ArvoreDisciplinas* raiz, int cargaHoraria) {
    if (raiz != NULL) {
        imprimirDisciplinas_CargaHorariaAVL(raiz->esquerda, cargaHoraria);
        if (raiz->disciplina.cargaHoraria == cargaHoraria) {
            printf("Código: %d\n", raiz->disciplina.codigo);
            printf("Nome: %s\n", raiz->disciplina.nome);
            printf("Bloco: %d\n", raiz->disciplina.bloco);
            printf("Carga Horária: %d\n", raiz->disciplina.cargaHoraria);
            printf("--------------------\n");
        }
        imprimirDisciplinas_CargaHorariaAVL(raiz->direita, cargaHoraria);
    }
}

ArvoreDisciplinas* encontrarSucessorAVL(ArvoreDisciplinas* raiz) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->esquerda == NULL) {
        return raiz;
    } else {
        return encontrarSucessorAVL(raiz->esquerda);
    }
}

ArvoreDisciplinas* removerNoDisciplinaAVL(ArvoreDisciplinas* raiz, int codigo) {
    if (raiz == NULL) {
        return NULL;
    } else if (codigo < raiz->disciplina.codigo) {
        raiz->esquerda = removerNoDisciplinaAVL(raiz->esquerda, codigo);
    } else if (codigo > raiz->disciplina.codigo) {
        raiz->direita = removerNoDisciplinaAVL(raiz->direita, codigo);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->esquerda == NULL) {
            ArvoreDisciplinas* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            ArvoreDisciplinas* temp = raiz->esquerda;
            free(raiz);
            return temp;
        } else {
            ArvoreDisciplinas* sucessor = encontrarSucessorAVL(raiz->direita);
            raiz->disciplina = sucessor->disciplina;
            raiz->direita = removerNoDisciplinaAVL(raiz->direita, sucessor->disciplina.codigo);
        }
    }
    return raiz;
}

//(8) Excluir uma disciplina dado o código da disciplina e o código do curso
void excluirDisciplinaAVL(ArvoreCurso** raiz, int codigoCurso, ArvoreDisciplinas** raiz2, int codigoDisciplina) {
    if (*raiz != NULL) {
        if (codigoCurso == (*raiz)->curso.codigo) {
            if (*raiz2 != NULL) {
                if ((*raiz2)->disciplina.codigo == codigoDisciplina) {
                    ArvoreDisciplinas* aux = *raiz2;
                    *raiz2 = removerNoDisciplinaAVL(*raiz2, codigoDisciplina);
                    free(aux);
                } else if (codigoDisciplina < (*raiz2)->disciplina.codigo) {
                    excluirDisciplinaAVL(raiz, codigoCurso, &(*raiz2)->esquerda, codigoDisciplina);
                } else {
                    excluirDisciplinaAVL(raiz, codigoCurso, &(*raiz2)->direita, codigoDisciplina);
                }
                atualizarAlturaDisciplinas(raiz2);
                balancearArvoreDisciplinas(raiz2);
            }
        } else if (codigoCurso < (*raiz)->curso.codigo) {
            excluirDisciplinaAVL(&(*raiz)->esquerda, codigoCurso, raiz2, codigoDisciplina);
            atualizarAlturaCurso(raiz);
            balancearArvoreCurso(raiz);
        } else {
            excluirDisciplinaAVL(&(*raiz)->direita, codigoCurso, raiz2, codigoDisciplina);
            atualizarAlturaCurso(raiz);
            balancearArvoreCurso(raiz);
        }
    }
}

ArvoreCurso* maiorEsquerdaAVL(ArvoreCurso* raiz) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->direita == NULL) {
        return raiz;
    } else {
        return maiorEsquerdaAVL(raiz->direita);
    }
}

ArvoreCurso** enderecoFilhoAVL(ArvoreCurso* pai, ArvoreCurso* filho) {
    if (pai == NULL) {
        return NULL;
    } else if (pai->esquerda == filho) {
        return &(pai->esquerda);
    } else if (pai->direita == filho) {
        return &(pai->direita);
    } else {
        return NULL;
    }
}

//(9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void excluirCursoAVL(ArvoreCurso** raiz, int codigoCurso) {
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
            excluirCursoAVL(&(*raiz)->esquerda, codigoCurso);
        } else {
            excluirCursoAVL(&(*raiz)->direita, codigoCurso);
        }
        balancearArvoreCurso(raiz);
    }
}