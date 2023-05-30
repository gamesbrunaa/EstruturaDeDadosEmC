typedef struct Disciplina disciplina;
typedef struct Curso curso;
typedef struct ArvoreDisciplinas;

ArvoreDisciplinas* criarNoDisciplina(Disciplina disciplina);
Disciplina* criarDisciplina(int codigo, char nome[], int bloco, int cargaHoraria);
ArvoreDisciplinas* inserirDisciplina(ArvoreDisciplinas* raiz, Disciplina disciplina);
ArvoreDisciplinas* buscarDisciplina(ArvoreDisciplinas* raiz, int codigo);

Curso* criarNoCurso(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina);
Curso* inserirCurso(Curso* raiz, int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina);
Curso* buscarCurso(Curso* raiz, int codigo);

void exibirDisciplina(Disciplina disciplina);
void exibirArvoreDisciplinas(ArvoreDisciplinas* raiz);
void liberarArvoreDisciplinas(ArvoreDisciplinas* raiz);
void liberarArvoreCursos(Curso* raiz);

//Funções fornecidas para o usuario
void ImprimirCursos_OrdemCrescente(Curso* raiz, int codigo);
void ImprimirCursos_Dados(Curso* raiz, int codigo);
void ImprimirCursos_QtdBlocos(Curso* raiz, int blocos);
void ImprimirDisciplinas_OrdemCrescente(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2);
void ImprimirDisciplinas_Dados(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2);
void ImprimirDisciplinas_Bloco(Curso* raiz, int bloco, int codigo);
void ImprimirDisciplinas_CargaHoraria(Curso* raiz, int cargaH, int codigo);
void ExcluirDisciplina(Curso* raiz, int codigo, ArvoreDisciplinas* raiz2, int codigo2);
void ExcluirCurso(Curso* raiz, int codigo); //desde que não tenha nenhuma disciplina cadastrada para aquele curso
