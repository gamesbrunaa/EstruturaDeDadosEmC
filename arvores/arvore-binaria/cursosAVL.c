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

// Função para calcular o fator de balanceamento da arvore de disciplinas
int fatorBalancemantoDisciplinas(ArvoreDisciplinas *raiz);

//Função para realizar o balanceamento da arvore de disciplinas (se necessário)
void rotacaoDireitaDisciplinas(ArvoreDisciplinas** raiz);

//Função para realizar o balanceamento da arvore de disciplinas (se necessário)
void rotacaoEsquerdaDisciplinas(ArvoreDisciplinas** raiz);

//Função para atualizar altura da arvore de disciplinas (se necessário)
void atualizarAlturaDisciplinas(ArvoreDisciplinas** raiz);

// Função para inserir uma disciplina na árvore de disciplinas
ArvoreDisciplinas* inserirDisciplina(ArvoreDisciplinas** raiz, Disciplina *disciplina) {
    int fb;
    if(*raiz == NULL){
        *raiz = disciplina;
    }else if(disciplina->codigo < (*raiz)->disciplina.codigo){
        inserirDisciplina(&((*raiz)->esquerda), disciplina);
    }else{
        inserirDisciplina(&((*raiz)->direita), disciplina);
    }
    fb = fatorBalanceamentoDisciplinas(*raiz);
    if(fb == 2){
        if(fatorBalanceamentoDisciplinas((*raiz)->esquerda) < 0)
            rotacaoEsquerdaDisciplinas(&((*raiz)->esquerda));
        rotacaoDireitaDisciplinas(raiz);
    }else if(fb == -2){
        if(fatorBalanceamentoDisciplinas((*raiz)->direita) > 0)
            rotacaoDireitaDisciplinas(&((*raiz)->direita));
        rotacaoEsquerdaDisciplinas(raiz);
    }
    atualizarAlturaDisciplinas(raiz);
}

// Função para calcular o fator de balanceamento da arvore de cursos
int fatorBalancemantoCurso(ArvoreCurso *raiz);

//Função para realizar o balanceamento da arvore de cursos (se necessário)
void rotacaoDireitaCurso(ArvoreCurso** raiz);

//Função para realizar o balanceamento da arvore de cursos (se necessário)
void rotacaoEsquerdaCurso(ArvoreCurso** raiz);

//Função para atualizar altura da arvore de cursos (se necessário)
void atualizarAlturaCurso(ArvoreCurso** raiz);

// Função para inserir um curso na árvore de cursos
ArvoreCurso* inserirCurso(ArvoreCurso** raiz, Curso* curso) {
    int fb;
    if(*raiz == NULL){
        *raiz = curso;
    }else if(curso->codigo < (*raiz)->curso.codigo){
        inserirDisciplina(&((*raiz)->esquerda), curso);
    }else{
        inserirDisciplina(&((*raiz)->direita), curso);
    }
    fb = fatorBalanceamentoCurso(*raiz);
    if(fb == 2){
        if(fatorBalanceamentoCurso((*raiz)->esquerda) < 0)
            rotacaoEsquerdaCurso(&((*raiz)->esquerda));
        rotacaoDireitaCurso(raiz);
    }else if(fb == -2){
        if(fatorBalanceamentoCurso((*raiz)->direita) > 0)
            rotacaoDireitaCurso(&((*raiz)->direita));
        rotacaoEsquerdaCurso(raiz);
    }
    atualizarAlturaCurso(raiz);
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
    exibirArvoreDisciplina(curso.disciplinas);
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
    if(raiz != NULL){
        if(codigo == raiz->curso.codigo)
            exibirArvoreCurso(raiz);
    }
}

//(2) Imprimir os dados de um curso dado o código do mesmo
void imprimirCursos_Dados(ArvoreCurso* raiz, int codigo){
    if(raiz != NULL){
        if(codigo == raiz->curso.codigo){
            exibirCurso(raiz->curso);
        } else if(codigo < raiz->curso.codigo){
            imprimirCursos_Dados(raiz->esquerda, codigo);
        }else{
            imprimirCursos_Dados(raiz->direita, codigo);
        }
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
    ArvoreDisciplinas *aux;
    if(raiz != NULL){
        if(codigo == raiz->curso.codigo){
            aux = raiz->curso.disciplinas;
            exibirArvoreDisciplinas(aux);
        }
    }
}

//(5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
void ImprimirDisciplinas_Dados(ArvoreCurso* raiz, int codigo, int codigo2){
    ArvoreDisciplinas *aux;
    if(raiz != NULL){
        if(codigo == raiz->curso.codigo){
            aux = raiz->curso.disciplinas;
            if(codigo2 == aux->disciplina.codigo){
                exibirDisciplina(aux->disciplina);
            } else if(codigo2 < aux->disciplina.codigo){
                ImprimirDisciplinas_Dados(raiz->esquerda, codigo, codigo2);
            }else{
                imprimirDisciplinas_Dados(raiz->direita, codigo, codigo2);
            }
        }
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
void excluirDisciplina(ArvoreCurso* raiz, int codigo, ArvoreDisciplinas** raiz2, int codigo2){
    ArvoreDisciplinas *aux, *end;
    int fb;
    if(raiz != NULL){ //verifica se a arvore de curso é vazia
        if(codigo == raiz->curso.codigo){ // procura o curso com o codigo indicado
            if(*raiz2 != NULL){ //verifica se a arvore de disciplinas do curso é vazia
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
            excluirCurso(&(*raiz2)->esquerda, codigo);
        }else{
            excluirCurso(&(*raiz2)->direita, codigo);
        }

        fb = fatorBalanceamentoDisciplinas(*raiz2);
        if(fb == 2){
            if(fatorBalanceamentoDisciplinas((*raiz2)->esquerda) < 0)
                rotacaoEsquerdaDisciplinas(&((*raiz2)->esquerda));
            rotacaoDireitaDisciplinas(raiz2);
        }else if(fb == -2){
            if(fatorBalanceamentoDisciplinas((*raiz2)->direita) > 0)
                rotacaoDireitaDisciplinas(&((*raiz2)->direita));
            rotacaoEsquerdaDisciplinas(raiz2);
        }
        atualizarAlturaDisciplinas(raiz);
    }
}

//(9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void excluirCurso(ArvoreCurso** raiz, int codigo){
    ArvoreCurso *aux, *end;
    int fb;
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

        fb = fatorBalanceamentoCurso(*raiz);
        if(fb == 2){
            if(fatorBalanceamentoCurso((*raiz)->esquerda) < 0)
                rotacaoEsquerdaCurso(&((*raiz)->esquerda));
            rotacaoDireitaCurso(raiz);
        }else if(fb == -2){
            if(fatorBalanceamentoCurso((*raiz)->direita) > 0)
                rotacaoDireitaCurso(&((*raiz)->direita));
            rotacaoEsquerdaCurso(raiz);
        }
        atualizarAlturaCurso(raiz);
    }
}


