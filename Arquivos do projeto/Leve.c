/*----------------------------------------------------------
# Objetivo: Página do Admin. Cadastrar e consultar produtos.
----------------------------------------------------------*/

/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

/* Funções */
typedef struct {
	int		Codpgto;
	char	Formapgto[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
	float	Valorpgto;
} registro_pagamento;

int CalculaRegistrosArq(char *nomeArq) {
	FILE *Arq;
   	registro_pagamento R;
	int numero_registros;
   
	Arq = fopen (nomeArq, "r");
	if (Arq==NULL) {
    	numero_registros = 0; /* O arquivo não existe */
	} else {   
   	/* Calcula o tamanho do arquivo */
		if ( fseek (Arq, 0, SEEK_END) ) {
        	printf("\n ERRO ao calcular o tamanho de arquivo!\n");
        	getch();
        	numero_registros = -1;
        } else {  
			numero_registros =  ftell(Arq) / sizeof (R); 
  	    }
  	    fclose (Arq);
	}
	return (numero_registros); 
}

void PesquisaPagamento( registro_pagamento * R ) {
	FILE *A;
	registro_pagamento Rler; 
	A = fopen ("PAGAMENTOS.DAT", "r");
	if (A==NULL) {
		printf("\n Erro ao abrir arquivo PAGAMENTOS.DAT!");
	  	getch();
	  	exit(0); 
	} else {    
	
   	    while ( !feof(A) ) { 
		    fread (&Rler, sizeof(Rler), 1, A);
            if ( ferror(A) ) {
            	printf("\n Erro ao ler arquivo PAGAMENTOS.DAT!");
	  			getch();
	  			exit(0);
			}
	    
	        if ( !feof(A) ) {
	        	if ( R->Codpgto == Rler.Codpgto ) {
	            	*R = Rler;
	            	break;
	           	}
			}       
	   	}
	   	fclose(A);
   	}
}

/* Corpo do programa */
int main (void) {	
	system("MODE con cols=45 lines=30");
	registro_pagamento Rpgto;
    setlocale (LC_ALL, "");    
	Rpgto.Codpgto = CalculaRegistrosArq("PAGAMENTOS.DAT");  /* Retorna o numero de registros em PAGAMENTOS.DAT */
	PesquisaPagamento(&Rpgto); 
    if ( strcmp(Rpgto.Formapgto, "Dinheiro") == 0 ) {
    	system ("color 72");	
	} else {
		if ( strcmp(Rpgto.Formapgto, "Cheque") == 0 ) {
			system ("color 71");	
		} else {
			system ("color 7d");	
		}	
	}
	system ("cls");
    printf ("\n\tPEDIDO [%3i] PAGO COM %s", Rpgto.Codpgto, Rpgto.Formapgto);
    printf ("\n\n Aperte qualquer tecla para voltar ao menu cliente.");
    getch();
    system("Cliente_menu");
    
	return (0);
}
