typedef struct _no Conta;
typedef struct _fila Fila;

Fila *criar();
Conta *criar_conta(int cont);
void inserir(Fila *f, int cont);
void mostrarTodaFila(Fila *f);
int fila_vazia(Fila *f);
void mostrar_topo_fila(Fila *f);
void mostrar_fim_fila(Fila *f);
Conta* remover(Fila* f);
void fila_libera(Fila* f);