/*-----------------------------------------------------------------
# Objetivo: Consultar os produtos cadastrados pela p�gina do Admin.
-----------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* Struct */
typedef struct {   
    int    	Codprod;
    char   	Nomeprod[20+1]; /* 20 �teis + o \0 = NULL TERMINATOR */
    float	Custoprod;
} registro; 

/* Variaveis */
registro reg; 

/* Fun��es */
void consulta_todos_produtos (void) {
    FILE  *  A; /* A vari�vel 'A' se refere ao arquivo que vai ser manipuldo [PRODUTOS.DAT]*/
    A  =  fopen ("PRODUTOS.DAT" , "r"); /* Abrir como leitura */		
    if ( A == NULL ){
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT! ARQUIVO NULO!");
    	getch();
    	exit(0); 
	}
	system ("cls");
	printf ("\n ================================================");
	printf ("\n                LISTA DE PRODUTOS                ");
	printf ("\n ================================================");
    printf ("\n    CODPROD   NOME                  VALOR (R$)   ");	
	printf ("\n ================================================");

    while ( !feof(A) ){ 
       /* L� um produto*/
       fread ( &reg,  sizeof(reg), 1, A );
       /* Para n�o mostrar o �ltimo 2 vezes: testa se j� leu o EOF (end of file) */
       if ( !feof(A) ){  
	   		/* Exibe o registro lido na tela */
	       printf ("\n      %i\t     %-24s%.2f" , reg.Codprod, reg.Nomeprod, reg.Custoprod ) ; 
       }
    }
    fclose (A);
	printf ("\n ================================================");	
}

/* Corpo do Programa */
int main (){
	system("MODE con cols=50 lines=30");
	system("cls");
	consulta_todos_produtos();
	printf("\n\n     Pressione qualquer tecla para voltar\t\t");
	getch();
	system("Admin");
    return (0);
}
