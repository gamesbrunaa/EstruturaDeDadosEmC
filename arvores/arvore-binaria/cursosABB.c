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
    struct ArvoreCurso *esquerda;
    struct ArvoreCurso *direita;
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

// Função para inserir um curso na árvore de cursos
ArvoreCurso* inserirCurso(ArvoreCurso* raiz, Curso curso) {
    if (raiz == NULL) {
        raiz = criarNoCurso(curso);
    } else {
        if (curso.codigo < raiz->curso.codigo) {
            raiz->esquerda = inserirCurso(raiz->esquerda, curso);
        } else if (curso.codigo > raiz->curso.codigo) {
            raiz->direita = inserirCurso(raiz->direita, curso);
        }
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
    if (raiz != NULL) {
        exibirArvoreDisciplinas(raiz->esquerda);
        exibirDisciplina(raiz->disciplina);
        exibirArvoreDisciplinas(raiz->direita);
    }
}

// Função para exibir os dados de um curso
void exibirCurso(Curso curso) {
    printf("Código: %d\n", curso.codigo);
    printf("Nome: %s\n", curso.nome);
    printf("Quantidade de Blocos: %d\n", curso.quantidadeBlocos);
    printf("Semanas por Disciplinas: %d\n", curso.semanasPorDisciplina);
    printf("Disciplinas: \n");
    exibirArvoreDisciplina(curso.disciplinas);
    printf("\n");
}

// Função para exibir a árvore de cursos em ordem
void exibirArvoreCurso(ArvoreCurso* raiz) {
    if (raiz != NULL) {
        exibirArvoreCurso(raiz->esquerda);
        exibirCurso(raiz->curso);
        exibirArvoreCurso(raiz->direita);
    }
}

//Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos
void imprimirCursos_QtdBlocos(ArvoreCurso* raiz, int quantidadeBlocos){
    if(raiz != NULL){
        if(raiz->curso.quantidadeBlocos == quantidadeBlocos){
            exibirCurso(raiz->curso);
        }
        imprimirCursos_QtdBlocos(raiz->esquerda, quantidadeBlocos);
        imprimirCursos_QtdBlocos(raiz->direita, quantidadeBlocos);
    }
}

//Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso
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

//Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário
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

//Excluir uma disciplina dado o código da disciplina e o código do curso
void excluirDisciplina(ArvoreCurso* raiz, int codigo, ArvoreDisciplinas** raiz2, int codigo2){
    ArvoreDisciplinas *aux, *end;
    if(raiz != NULL){ //verifica se a arvore de curso é vazia
        if(codigo == raiz->curso.codigo){ // procura o curso com o codigo indicado
            if(*raiz2 != NULL){ //verifica se a arvore de disciplinas é vazia
                if(((*raiz2)->esquerda == NULL) && ((*raiz2)->direita == NULL)){
                    aux = *raiz2;
                    *raiz2 = NULL;
                    free(aux);
                } else if(((*raiz2)->esquerda == NULL) || ((*raiz2)->direita ==NULL)){
                    end = enderecoFilho(*raiz2);
                    aux = *raiz2;
                    *raiz2 = end;
                    free(aux);
                } else{
                    end = maiorEsquerda((*raiz2)->esquerda);
                    aux = *raiz2;
                    filho->direita = (*raiz2)->esquerda;
                    *raiz2 = (*raiz2)->esquerda;
                    free(aux);
                }
            }
        }else if(codigo < raiz->curso.codigo){
            excluirCurso(&(*raiz)->esquerda, codigo);
        }else{
            excluirCurso(&(*raiz)->direita, codigo);
        }
    }
}

//Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void excluirCurso(ArvoreCurso** raiz, int codigo){
    ArvoreCurso *aux, *end;
    if(*raiz != NULL){
        if(codigo == (*raiz)->curso.codigo){ //procura o curso com o código indicado
            if((*raiz)->curso.disciplinas != NULL){ //verifica se existem disciplinas cadastradas
                printf("Não é possivel excluir curso, pois o mesmo possui disciplinas cadastradas! \n");
            } else{
                if(((*raiz)->esquerda == NULL) && ((*raiz)->direita == NULL)){
                    aux = *raiz;
                    *raiz = NULL;
                    free(aux);
                } else if(((*raiz)->esquerda == NULL) || ((*raiz)->direita ==NULL)){
                    end = enderecoFilho(*raiz);
                    aux = *raiz;
                    *raiz = end;
                    free(aux);
                } else{
                    end = maiorEsquerda((*raiz)->esquerda);
                    aux = *raiz;
                    filho->direita = (*raiz)->esquerda;
                    *raiz = (*raiz)->esquerda;
                    free(aux);
                }
            }
        }else if(codigo < (*raiz)->curso.codigo){
            excluirCurso(&(*raiz)->esquerda, codigo);
        }else{
            excluirCurso(&(*raiz)->direita, codigo);
        }
    }
}


