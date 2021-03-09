#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"
#include <string.h>

int busca_binaria(int cod, FILE *arq){
	
	int tam = tamanho_arquivo(arq)-1;
	return busca_recursiva(arq, cod, 0, tam);
	

}

int busca_recursiva(FILE *arq, int cod, int menor, int maior){
	
	TFunc * aux = (TFunc *)malloc(sizeof(TFunc));
	
	int media = floor(menor+maior)/2;
	
	aux = le(arq, media);
	
	int cod_media = atoi(aux->cod);
	
	aux = le(arq, media);
	
	if(menor>maior){
		return -1; //não encontrou o elemento
	} else if(cod == cod_media){
		return media;
	} else if(cod_media < cod){
		return busca_recursiva(arq, cod, ++media, maior);
	} else if(cod_media > cod){
		return busca_recursiva(arq, cod, menor, --media);
	}
	
}

void cadastra(FILE * arq){
	
	
	TFunc *funcionario = (TFunc *)malloc(sizeof(TFunc));
	int cont = 1;
	
	int aux_cod;
	
		
		
		fseek(arq, 0, SEEK_SET);
		
	char aux[50];
	
	if(tamanho_arquivo(arq) == 0){
		aux_cod = 0;
	} else {
		aux_cod = tamanho_arquivo(arq);
	}
		
	
	
	
	do{
    	printf("\n\n\tCadastro de usuário código: %d", aux_cod);
    	
    	
    	strncpy(funcionario->cod,itoa(aux_cod, aux, 10), 3);
    	
    	printf("\n\n\tNome: ");
    	fflush(stdin);
    	fgets(aux, 30, stdin);
    	
    	strncpy(funcionario->nome, aux, 30);
    	
    	printf("\n\n\tCPF: ");
    	fflush(stdin);
    	fgets(aux, 15, stdin);
    	
    	strncpy(funcionario->cpf, aux, 14);
    	
    	printf("\n\n\tData de nascimento: ");
    	fflush(stdin);
    	fgets(aux, 10, stdin);
    	
    	strncpy(funcionario->data_nascimento, aux, 10);
    	
    	printf("\n\n\tSalário: ");
    	fflush(stdin);
    	fgets(aux, 10, stdin);
    	
    	strncpy(funcionario->salario, aux, 10);
    	
    	salva(funcionario, arq);
    	printf("\n\n\tDeseja inserir outro funcionário ?");
    	printf("\n\t 1 = Sim  0 = Não\n\t");
		fflush(stdin);
    	scanf("%d", &cont);
    	printf("\n\n\n");
    	
    	if(cont == 1){
    		aux_cod++;
		}
    	
    	
    	
		
	}while(cont != 0);
	free(funcionario);
	return;
	
}




int tamanho_registro(){
	
	return 5 + sizeof(TFunc);
}


// Salva no arquivo out, na posição atual do cursor
void salva(TFunc *func, FILE *out) {
char bar[] = "|";


fwrite(func->cod, sizeof(char), sizeof(func->cod), out);

fwrite(bar, sizeof(char), 1, out);

fwrite(func->nome, sizeof(char),
sizeof(func->nome), out);

fwrite(bar, sizeof(char), 1, out);


fwrite(func->cpf, sizeof(char),
sizeof(func->cpf), out);

fwrite(bar, sizeof(char), 1, out);


fwrite(func->data_nascimento, sizeof(char),
sizeof(func->data_nascimento), out);

fwrite(bar, sizeof(char), 1, out);


fwrite(func->salario, sizeof(char), sizeof(func->salario), out);

fwrite(bar, sizeof(char), 1, out);
}



TFunc *le(FILE *in, int index) {

char codigo[3];
char salario[10];
char bar[1];

TFunc *func = (TFunc*) malloc(sizeof(TFunc));

fseek(in, (tamanho_registro()*index), SEEK_SET);

fread(func->cod, sizeof(char), sizeof(func->cod), in);
fread(bar, sizeof(char), 1, in);


fread(func->nome, sizeof(char), sizeof(func->nome), in);
fread(bar, sizeof(char), 1, in);


fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
fread(bar, sizeof(char), 1, in);

fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
fread(bar, sizeof(char), 1, in);

fread(func->salario, sizeof(char), sizeof(func->salario), in);
fread(bar, sizeof(char), 1, in);

return func;
free(func);

}

int tamanho_arquivo(FILE *arq) {
fseek(arq, 0, SEEK_END);
int tam = trunc(ftell(arq) / tamanho_registro());
return tam;
}

void imprime_func(TFunc *func){
	 
	
	printf("\n\n\n\n\t----------Código %d--------------------------------\n", atoi(func->cod));
	printf("\t|\t\t\t\t\t\t|");
	
	printf("\n\t \tNome: ");
	puts(func->nome);
	
	printf("\t \tCPF: ");
	puts(func->cpf);
	
	printf("\t \tData de nascimento: ");
	puts(func->data_nascimento);
	
	printf("\t \tSalário: ");
	puts(func->salario);
	
		
	printf("\t|\t\t\t\t\t\t|");
	printf("\n\t-------------------------------------------------\n");	
	
}
