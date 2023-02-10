typedef struct conta Conta;
typedef struct _pilha Pilha;

Pilha *criar();
Conta *criar_conta(int cont);
void inserir(Pilha *p, int cont);
void mostrarTodaPilha(Pilha *p);
int pilha_vazia(Pilha *p);
void mostrar_topo_pilha(Pilha *p);
Conta* remover(Pilha* p);
void pilha_libera(Pilha* p);


