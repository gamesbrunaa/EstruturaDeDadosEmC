typedef struct Disciplina Disciplina;
typedef struct Curso Curso;
typedef struct ArvoreDisciplinas ArvoreDisciplinas;
typedef struct ArvoreCurso ArvoreCurso;

ArvoreDisciplinas* criarNoDisciplinaAVL(Disciplina disciplina);
Disciplina* criarDisciplinaAVL(int codigo, char nome[], int bloco, int cargaHoraria);
ArvoreDisciplinas* inserirDisciplinaAVL(ArvoreDisciplinas** raiz, Disciplina *disciplina);
Disciplina* buscarDisciplinaAVL(ArvoreDisciplinas* raiz, int codigo);

ArvoreCurso* criarNoCursoAVL(Curso curso);
Curso* criarCursoAVL(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina, ArvoreDisciplinas *disciplinas);
ArvoreCurso* inserirCursoAVL(ArvoreCurso** raiz, Curso *curso);
ArvoreCurso* buscarCursoAVL(ArvoreCurso* raiz, int codigo);

void exibirCursoAVL(Curso curso);
void exibirArvoreCursoAVL(ArvoreCurso* raiz);
void exibirDisciplinaAVL(Disciplina disciplina);
void exibirArvoreDisciplinasAVL(ArvoreDisciplinas* raiz);

//Funções Auxiliares
int fatorBalanceamentoDisciplinas(ArvoreDisciplinas *raiz);
int max(int a, int b);
void atualizarAlturaDisciplinas(ArvoreDisciplinas** raiz);
void rotacaoDireitaDisciplinas(ArvoreDisciplinas** raiz);
void rotacaoEsquerdaDisciplinas(ArvoreDisciplinas** raiz);
void balancearArvoreDisciplinas(ArvoreDisciplinas** raiz);
int fatorBalanceamentoCurso(ArvoreCurso *raiz);
void atualizarAlturaCurso(ArvoreCurso** raiz);
void rotacaoDireitaCurso(ArvoreCurso** raiz);
void rotacaoEsquerdaCurso(ArvoreCurso** raiz);
void balancearArvoreCurso(ArvoreCurso** raiz);
ArvoreDisciplinas* encontrarSucessorAVL(ArvoreDisciplinas* raiz);
ArvoreDisciplinas* removerNoDisciplinaAVL(ArvoreDisciplinas* raiz, int codigo);
ArvoreCurso* maiorEsquerdaAVL(ArvoreCurso* raiz);
ArvoreCurso** enderecoFilhoAVL(ArvoreCurso* pai, ArvoreCurso* filho);

//Funções fornecidas para o usuario
void ImprimirCursos_OrdemCrescenteAVL(ArvoreCurso* raiz, int codigo);
void imprimirCursos_DadosAVL(ArvoreCurso* raiz, int codigo);void imprimirCursos_QtdBlocosAVL(ArvoreCurso* raiz, int quantidadeBlocos);
void ImprimirDisciplinas_OrdemCrescenteAVL(ArvoreCurso* raiz, int codigo);
void ImprimirDisciplinas_DadosAVL(ArvoreCurso* raiz, int codigo, int codigo2);
void imprimirDisciplinas_BlocoAVL(ArvoreDisciplinas* raiz, int bloco);
void ImprimirDisciplinas_CargaHorariaAVL(Curso* raiz, int cargaH, int codigo);
void excluirDisciplinaAVL(ArvoreCurso** raiz, int codigoCurso, ArvoreDisciplinas** raiz2, int codigoDisciplina);
void excluirCursoAVL(ArvoreCurso** raiz, int codigoCurso); //desde que não tenha nenhuma disciplina cadastrada para aquele curso
