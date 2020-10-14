/*----------------------------------------------------------
# Objetivo: Página do Admin. Cadastrar e consultar produtos.
----------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* Struct */
typedef struct {   
    int    	Codprod;
    char   	Nomeprod[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
    float	Custoprod;
} registro; 

/* Variaveis */
registro reg; 

/* Funções */
void captura_produto(void) {
	
	system ("cls");
	reg.Codprod = system("Numero_de_registros"); /* -1 = erro ou 0 = arq PRODUTOS.DAT não existe */
	if ( reg.Codprod == -1 ){
	    printf("\n ERRO ao calcular o tamanho de arquivo com fseek no modulo Numero_de_registros");
	    getch();
	    exit(0);
	}	
	reg.Codprod++;  /* Código autonumérico */	
	printf("\n\n Codigo do produto: "); 
	printf("%i", reg.Codprod);
	
	printf("\n Digite o nome do produto: "); 
	fflush(stdin); 	
	gets(reg.Nomeprod); 
	
	printf("\n Digite o valor do produto R$: ");
	fflush(stdin);     
	scanf("%f", &reg.Custoprod);
}

void gravar_produto(void){
	
    FILE  *  A; /* A variável 'A' se refere ao arquivo que vai ser manipuldo [PRODUTOS.DAT]*/
    A  =  fopen ("PRODUTOS.DAT" , "a"); /* Abre o arquivo para adicionar dados ["a"] */		
    if ( A == NULL ){
    	printf("\n ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT! ARQUIVO NULO!");
    	getch();
    	exit(0);
	}
	
	/* Grava o registro em PRODUTOS.DAT */
	fwrite ( &reg,  sizeof(reg), 1, A );
	if ( ferror (A) ){
		printf ("\n ERRO AO GRAVAR NO ARQUIVO PRODUTOS.DAT!");
		getch();
		exit(0);
	}
	fclose (A);
}

/* Corpo do Programa */
int main (){
	op: ;
	system("MODE con cols=45 lines=30");
	system("cls");
	printf("\n\n   =======================================");
	printf("\n   |              MENU ADMIN             |");
	printf("\n   =======================================");
	printf("\n   |                                     |");
	printf("\n   |         1. CADASTRAR PRODUTO        |");
	printf("\n   |                                     |");
	printf("\n   |         2. CONSULTAR PRODUTOS       |");
	printf("\n   |                                     |");
	printf("\n   |         0.    VOLTAR                |");
	printf("\n   |                                     |");
	printf("\n   =======================================");
	
	printf("\n             ");
	char op = getch();
	switch (op) {
		case '1':
			captura_produto();
			gravar_produto();
			break;
		case '2':
			system("Consulta_registros");
			
			exit(0);
			break;
		case '0':
			system("Index");
			exit(0);
			break;
		default:
			printf("\n Opcao invalida!");
			getch();
			goto op;
	}
	goto op;
	
    return (0);
}
