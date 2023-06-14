typedef struct Disciplina Disciplina;
typedef struct Curso Curso;
typedef struct ArvoreDisciplinas ArvoreDisciplinas;
typedef struct ArvoreCurso ArvoreCurso;

ArvoreDisciplinas* criarNoDisciplina(Disciplina disciplina);

// Função para criar uma nova disciplina
Disciplina* criarDisciplina(int codigo, char nome[], int bloco, int cargaHoraria);

// Função para inserir uma disciplina na árvore de disciplinas
ArvoreDisciplinas* inserirDisciplina(ArvoreDisciplinas** raiz, Disciplina *disciplina);
// Função para criar um novo nó na árvore de cursos
ArvoreCurso* criarNoCurso(Curso curso);

// Função para criar um novo curso
Curso* criarCurso(int codigo, char nome[], int quantidadeBlocos, int semanasPorDisciplina, ArvoreDisciplinas *disciplinas);

// Função para inserir um curso na árvore de cursos
ArvoreCurso* inserirCurso(ArvoreCurso** raiz, Curso *curso);

// Função para buscar uma disciplina na árvore de disciplinas
Disciplina* buscarDisciplina(ArvoreDisciplinas* raiz, int codigo);

// Função para buscar um curso na árvore de cursos
ArvoreCurso* buscarCurso(ArvoreCurso* raiz, int codigo);

// Função para exibir os dados de uma disciplina
void exibirDisciplina(Disciplina disciplina);

// Função para exibir a árvore de disciplinas em ordem
void exibirArvoreDisciplinas(ArvoreDisciplinas* raiz);
void exibirCurso(Curso curso);
// Função para exibir a árvore de cursos em ordem
void exibirArvoreCurso(ArvoreCurso* raiz);

//(1) Imprimir a árvore de cursos em ordem crescente pelo código do curso
void ImprimirCursos_OrdemCrescente(ArvoreCurso* raiz, int codigo);
//(2) Imprimir os dados de um curso dado o código do mesmo
void imprimirCursos_Dados(ArvoreCurso* raiz, int codigo);

//(3) Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos
void imprimirCursos_QtdBlocos(ArvoreCurso* raiz, int quantidadeBlocos);
//(4) Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
void ImprimirDisciplinas_OrdemCrescente(ArvoreCurso* raiz, int codigo);

//(5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
void ImprimirDisciplinas_Dados(ArvoreCurso* raiz, int codigo, int codigo2);

//(6) Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso
void imprimirDisciplinas_Bloco(ArvoreDisciplinas* raiz, int bloco);
//(7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário
void imprimirDisciplinas_CargaHoraria(ArvoreDisciplinas* raiz, int cargaHoraria);

ArvoreDisciplinas* encontrarSucessor(ArvoreDisciplinas* raiz);
ArvoreDisciplinas* removerNoDisciplina(ArvoreDisciplinas* raiz, int codigo);

//(8) Excluir uma disciplina dado o código da disciplina e o código do curso
void excluirDisciplina(ArvoreCurso** raiz, int codigoCurso, ArvoreDisciplinas** raiz2, int codigoDisciplina);

ArvoreCurso* maiorEsquerda(ArvoreCurso* raiz);

ArvoreCurso** enderecoFilho(ArvoreCurso* pai, ArvoreCurso* filho);

//(9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso
void excluirCurso(ArvoreCurso** raiz, int codigo);