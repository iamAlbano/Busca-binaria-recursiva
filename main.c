#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "func.c"
#include <locale.h>


int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int menu = 1;
	int i;
	int num;
	int resp;
	
	TFunc * func = (TFunc*) malloc(sizeof(TFunc));
	
	FILE * arquivo = fopen("binario.bin", "rb");
	
	int teste = tamanho_arquivo(arquivo);
	
	
	do{
		
	printf("\n\n\n\n\t----------MENU-----------------------------------\n");
	printf("\t|\t\t\t\t\t\t|");
	printf("\n\t|\tGerenciador de funcion�rios\t\t|\n");
	printf("\t|\t\t\t\t\t\t|");
	printf("\n\t-------------------------------------------------\n");
	
	printf("\n\n\t 1 - Cadastrar novo funcion�rio");
	printf("\n\t 2 - Apagar registro");
	printf("\n\t 3 - Busca bin�ria");
	printf("\n\t 4 - Sair\n\t");
	fflush(stdin);
	scanf("%d", &menu);

	
	switch(menu){
		case 1:
			fclose(arquivo);
			FILE * arquivo = fopen("binario.bin", "a+b");
			cadastra(arquivo);
			break;
		case 2:
			
			printf("\n\n\tEssa a��o exclu�ra todos os funcion�rios do registro atual");
			
			printf("\n\n\tTem certeza que deseja criar um novo registro ?");
			printf("\n\t1 - Sim  ou  0 - N�o: ");
			fflush(stdin);
			scanf("%d", &resp);
			
			if(resp == 1){
				fclose(arquivo);
			FILE * arquivo = fopen("binario.bin", "wb");
				printf("\n\n\tRegistro apagado com sucesso!");
			} else{
				continue;
			}
			
			
			break;
		case 3:
			fclose(arquivo);
			arquivo = fopen("binario.bin", "rb");
			printf("\n\n\tInsira o c�digo do funcion�rio: ");
			scanf("%d", &i);
			printf("\n\n\t");
			
			num = busca_binaria(i, arquivo);
			
			func = le(arquivo, num);
			
			if(num == -1){
				printf("\n\n\t Nenhum usu�rio foi encontrado ! verifique o c�digo e tente novamente");
			} else{
				imprime_func(func);
			}		
		
			break;
		case 4:
			printf("\n\n\n\n\n\tObrigado por utilizar o gerenciador de funcion�rios !");
			printf("\n\tFeito por Guilherme Albano.");
			menu = 0;
			break;
		default:
			break;
	}
	
	
	
	}while(menu != 0);
	
	
	
	free(func);
	fclose(arquivo);
	return 0;
}






