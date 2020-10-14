/*---------------------------------------------------------------------
# Objetivo: Calcular a quantidade de registros no arquivo PRODUTOS.DAT.
---------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Struct */
typedef struct {   
    int    	Codprod;
    char   	Nomeprod[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
    float	Custoprod;
} registro; 

/* Variaveis */
FILE * Arq;
int numero_de_registros;

/* Corpo do programa */
int main() {
	
	Arq = fopen ("PRODUTOS.DAT", "r"); /* Abrir como leitura */
	if ( Arq == NULL ) { /* O arquivo não existe */
	   numero_de_registros = 0;
	} else {   
	
		/* Calcula o tamanho do arquivo */
		if ( fseek (Arq, SEEK_SET, SEEK_END) != 0 ) { /* Aqui fseek tenta se posicionar no final do arquivo...[0 = SUCESSO]*/
           printf("\n ERRO ao calcular o tamanho de arquivo!\n");
           getch();
           numero_de_registros = -1;
        } else {   
		    /* Dividindo-se o total de bytes do arquivo pelo tamanho de cada registro */
		    /* tem-se o número de registros do arquivo. */
		    numero_de_registros =  ftell(Arq) / sizeof (registro); 
  	    }
  	    fclose (Arq);
	}
    
    printf ("\n O arquivo PRODUTOS.DAT tem [%i] registros.", numero_de_registros);
    getch();
    
	return (numero_de_registros); /* Retorna a quantidade de registros */
}
