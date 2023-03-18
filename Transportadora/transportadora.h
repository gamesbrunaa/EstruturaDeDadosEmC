typedef struct cliente Cliente;
typedef struct lista Lista;

Lista *criar_lista();
Cliente *criar_cliente(int cont);
Cliente *inserir_cliente(Lista *l, int cont);
void mostrarTodosClientes(Lista *l);
Cliente *remover_cliente(Lista *l);
Cliente *buscar_cliente(Lista *l, int cod);
void liberar_lista(Lista *l);
int lista_vazia(Lista *l);

typedef struct rotaEntrega Entrega;
typedef struct fila Fila;

Fila *criar_fila();
Entrega *criar_entrega(Cliente *c);
void inserir_entrega(Fila *f, Cliente *c);
void mostrarEntregas(Fila *f);
Entrega *remover_entrega(Fila *f, Cliente *c);
void liberar_fila(Fila *f);
int fila_vazia(Fila *f);
Fila *ordenar_entregas(Fila *f);

typedef struct entregasNaoEfetuadas NaoEfetuadas;
typedef struct pilha Pilha;

Pilha *criar_pilha();
NaoEfetuadas *criar(Cliente *c);
void inserir_naoEfetuada(Pilha *p, Cliente *c);
void mostrar_naoEfetuadas(Pilha *p);
NaoEfetuadas *remover(Pilha *p);
void liberar_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
