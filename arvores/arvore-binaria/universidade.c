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
    struct ArvoreDisciplinas *esquerda;
    struct ArvoreDisciplinas *direita;
} ArvoreDisciplinas;

// Definição da estrutura de um curso
typedef struct {
    int codigo;
    char nome[50];
    int quantidadeBlocos;
    int semanasPorDisciplina;
    struct ArvoreDisciplinas *disciplinas; // Ponteiro para a árvore de disciplinas do curso
} Curso;

typedef struct {
    Curso curso;
    struct ArvoreCurso *esq;
    struct ArvoreCurso *dir;
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

// Função para inserir uma disciplina na árvore de disciplinas
ArvoreDisciplinas* inserirDisciplina(ArvoreDisciplinas* raiz, Disciplina disciplina) {
    if (raiz == NULL) {
        raiz = criarNoDisciplina(disciplina);
    } else {
        if (disciplina.codigo < raiz->disciplina.codigo) {
            raiz->esquerda = inserirDisciplina(raiz->esquerda, disciplina);
        } else if (disciplina.codigo > raiz->disciplina.codigo) {
            raiz->direita = inserirDisciplina(raiz->direita, disciplina);
        }
    }
    return raiz;
}

// Função para criar um novo nó na árvore de cursos
Curso* criarNoCurso(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina) {
    Curso* novoNo = (Curso*)malloc(sizeof(Curso));
    novoNo->codigo = codigo;
    strcpy(novoNo->nome, nome);
    novoNo->quantidadeBlocos = quantidadeBlocos;
    novoNo->semanasPorDisciplina = semanasPorDisciplina;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->disciplinas = NULL;
    return novoNo;
}

// Função para inserir um curso na árvore de cursos
Curso* inserirCurso(Curso* raiz, int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina) {
    if (raiz == NULL) {
        return criarNoCurso(codigo, nome, quantidadeBlocos, semanasPorDisciplina);
    }

    if (codigo < raiz->codigo) {
        raiz->esquerda = inserirCurso(raiz->esquerda, codigo, nome, quantidadeBlocos, semanasPorDisciplina);
    } else if (codigo > raiz->codigo) {
        raiz->direita = inserirCurso(raiz->direita, codigo, nome, quantidadeBlocos, semanasPorDisciplina);
    }

    return raiz;
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
Curso* buscarCurso(Curso* raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo) {
        return raiz;
    }

    if (codigo < raiz->codigo) {
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
    if (raiz != NULL) {
        exibirArvoreDisciplinas(raiz->esquerda);
        exibirDisciplina(raiz->disciplina);
        exibirArvoreDisciplinas(raiz->direita);
    }
}

// Função para liberar a memória alocada pela árvore de disciplinas
void liberarArvoreDisciplinas(ArvoreDisciplinas* raiz) {
    if (raiz != NULL) {
        liberarArvoreDisciplinas(raiz->esquerda);
        liberarArvoreDisciplinas(raiz->direita);
        free(raiz);
    }
}

// Função para liberar a memória alocada por uma árvore de cursos
void liberarArvoreCursos(Curso* raiz) {
    if (raiz != NULL) {
        liberarArvoreCursos(raiz->esquerda);
        liberarArvoreCursos(raiz->direita);
        Disciplina* disciplinaAtual = raiz->disciplinas;
        liberarArvoreDisciplinas(disciplinaAtual);
        free(raiz);
    }
}

void ImprimirCursos_OrdemCrescente(Curso* raiz, int codigo); //ok
void ImprimirCursos_Dados(Curso* raiz, int codigo); //ok
void ImprimirDisciplinas_OrdemCrescente(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2); //ok
void ImprimirDisciplinas_Dados(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2); //ok
void ImprimirCursos_QtdBlocos(Curso* raiz, int blocos); //ok
void ImprimirDisciplinas_Bloco(Curso* raiz, int bloco, int codigo); //ok
void ImprimirDisciplinas_CargaHoraria(Curso* raiz, int cargaH, int codigo); //ok
void ExcluirDisciplina(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2);
void ExcluirCurso(Curso* raiz, int codigo);