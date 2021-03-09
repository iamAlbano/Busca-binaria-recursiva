#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct Funcionario {
char cod[3];
char nome[31];
char cpf[16];
char data_nascimento[13];
char salario[11];

} TFunc;

int tamanho_registro();

int tamanho_arquivo(FILE *arq);

int busca_binaria(int cod, FILE *arq);

int busca_recursiva(FILE *arq, int cod, int menor, int maior);

void salva(TFunc *func, FILE *out);

TFunc *le(FILE *in, int index);


void cadastra(FILE * arq);

void gravar(TFunc *func, FILE *out);

void imprime_func(TFunc *func);


#endif
