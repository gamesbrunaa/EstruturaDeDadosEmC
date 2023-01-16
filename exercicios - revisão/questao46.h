typedef struct pessoa Pessoa;

Pessoa *criar(char n[50], char data[50], int cpf);
void imprimir(Pessoa *a);
void liberar(Pessoa *a);