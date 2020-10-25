/*----------------------------------------------------------
# Objetivo: Página de Pagamento, Registro de cartões em arquivo. 
----------------------------------------------------------*/

/*Autor: Lucas Mendes
Data: 16/10/2020*/

/*Libs*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define TAMCARTAO 16
#define  NOME_ESTABELECIMENTO       "DRIVE THRU DO MICKEY & DONALD"

/* Structs */
typedef struct
{
	int		Codpgto;
	char	Formapgto[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
	float	Valorpgto;
}
registro_pagamento;

typedef struct
{
    int		Codpgto;
    char	Numcartao[TAMCARTAO];
}
registro_cartao;

/* Funções */
int CalculaRegistrosArq (char *nomeArq) {
   	FILE *Arq;
   	registro_pagamento R;
   	int numero_registros;
   
   	Arq = fopen (nomeArq, "r");
   	if (Arq==NULL) {
      	numero_registros = 0; /* O arquivo não existe */
   	} else {   /* Calcula o tamanho do arquivo */
		if ( fseek (Arq, 0, SEEK_END) ) {
           printf("\n   ERRO ao calcular o tamanho de arquivo!\n");
           getch();
           numero_registros = -1;
        }else{   
		    numero_registros =  ftell(Arq) / sizeof (R); 
  	    }
  	    fclose (Arq);
	}
	return (numero_registros); 
}

void resgataTemp (registro_pagamento *Rpgto) {
	FILE * A;
    A = fopen ("ULTIMOPGTO.DAT", "r");
	if (A == NULL) {
		printf("\n Erro ao abrir arquivo ULTIMOPGTO.DAT!");
	  	getch();
	  	exit(0); 	
	}   
	fread(Rpgto, sizeof(registro_pagamento), 1, A );
	
	if (ferror(A))	{
		printf("\n Erro ao ler arquivo ULTIMOPGTO.DAT!");
	  	getch();
	  	exit(0); 
	}   
    fclose (A);
}

void registraPgto (registro_pagamento Rpgto, char flag) {
	FILE * A;
	if ( flag == 't'){
		A = fopen ("ULTIMOPGTO.DAT", "w");	
	} else {
		A = fopen ("PAGAMENTOS.DAT", "a");	
	}  
	if (A == NULL) {
		printf("\n Erro ao abrir arquivo .DAT!");
	  	getch();
	  	exit(0); 	
	} 
	fwrite (&Rpgto, sizeof(Rpgto), 1, A );
	if (ferror(A)) {
		printf("\n Erro ao gravar no arquivo .DAT!");
	  	getch();
	  	exit(0); 
	} else {
		if ( flag != 't') {
			/* Pagamento bem sucedido */
			printf ("\n\n   PAGAMENTO [%3d][%s][R$%5.2f]", Rpgto.Codpgto, Rpgto.Formapgto, Rpgto.Valorpgto);
   			printf ("\n   gravado com sucesso!\n\n");	
		}    	
	}       
    fclose (A);
}

void solicitaCartao(registro_cartao *Rcart) {   
	int i;
	printf ("\n   Digite o nro do cartão: "); 
	for (i=0; i<TAMCARTAO; i++)
	{   do
		{
		   fflush (stdin); Rcart->Numcartao[i] = getche();
	    }while ( Rcart->Numcartao[i] <'0' || Rcart->Numcartao[i] > '9');
	}
}

void mascaraCartao(registro_cartao *Rcart) {   
	int i;
	//1234 5678 9012 3456
	for (i=0; i<TAMCARTAO; i++)
	{   if ( i>3 && i<12 )
		   Rcart->Numcartao[i] = '*';
	}
	printf ("\n   Cartão a gravar:  %s", Rcart->Numcartao); getch();
}

void gravaCartao (registro_cartao R) {
   	FILE *A;
   	A = fopen ("CARTOES.DAT", "a");
   	if (A==NULL) {
   		system ("cls");
		printf (" FALHA AO ABRIR [%s]!", "CARTOES.DAT");
		getch();
		exit(0);
	} else {
      	fwrite (&R, sizeof(R), 1, A);
      	if ( ferror(A) ) {
      		system ("cls");
			printf (" FALHA AO GRAVAR [%s]!", "CARTOES.DAT");
			getch();
			exit(0);
		}   	
   	}
   	fclose(A);
   	printf ("\n\n   Cartão [%3d][%s]", R.Codpgto, R.Numcartao);
   	printf ("\n   gravado com sucesso!\n\n");
   	/*_sleep(200);*/	
}

/* Corpo do programa */
int   main (void) {	
	char  esc;
    registro_pagamento Rpgto, Rpgto_temp;
    registro_cartao    Rcart;
    Rpgto.Codpgto = CalculaRegistrosArq("PAGAMENTOS.DAT")+1;
    setlocale (LC_ALL, "");
    /* Captura forma de pagamento do pedido */
	do
    {
		system ("color b0");
    	system("MODE con cols=45 lines=30");
		system ("cls");
    	printf ("\n    --- %s ---", NOME_ESTABELECIMENTO);
    	printf ("\n   +-------------------------------------+");
    	printf ("\n   |   Formas de Pagamento - Pedido %3i  |", Rpgto.Codpgto);
    	printf ("\n   +-------------------------------------+");
    	printf ("\n   |         1. Dinheiro                 |");
    	printf ("\n   |         2. Cartão de Crédito        |");
    	printf ("\n   |         3. Cartão de Débito         |");
    	printf ("\n   |         4. Cheque                   |");
    	printf ("\n   |         0. Voltar                   |");
    	printf ("\n   +-------------------------------------+");
    	printf ("\n   Sua opção: ");
		fflush(stdin);
		esc = getche();
    	if ( esc < '0' || esc > '4')
    	{
    	   printf ("\n Forma de pagamento INVÁLIDA!");
    	   getch();
        }
    } while ( esc < '0' || esc > '4');
    /* Registra pagamento */
    switch ( esc )
    {
    	case '1':
			strcpy (Rpgto.Formapgto, "Dinheiro");
			break;
    	case '2':
			strcpy (Rpgto.Formapgto, "Cartão");
			break;
		case '3':
			strcpy (Rpgto.Formapgto, "Cartão");
			break;
		case '4':
			strcpy (Rpgto.Formapgto, "Cheque");
		break;
		case '0':
			system("cls");
			system("Cliente_menu");
			exit(0);
			break;
	}
	/* Atualiza o valor do último pedido */
    resgataTemp(&Rpgto_temp);	
    if ( Rpgto.Codpgto == Rpgto_temp.Codpgto )
    {
        Rpgto.Valorpgto = Rpgto_temp.Valorpgto;
        registraPgto (Rpgto, 'a'); 
        
        /* Caso o pagamento seja feito com cartão...*/
        if ( esc == '2' || esc == '3')
        {  Rcart.Codpgto = Rpgto.Codpgto; /*... atualiza o nro do pedido no registro de cartão */
           solicitaCartao(&Rcart); /* captura o nro do cartão */
           mascaraCartao (&Rcart); /* mascara o nro do cartão */
		   /* Grava o número do cartão */
           gravaCartao(Rcart);
        }
    }
    else
    {
    	printf ("\n Erro! Último pedido não localizado!");
    	getch();
    	system("Cliente_menu");
    	exit(0);
	}
	
	system("pause");
	system("Manda_Fila");
	
    return (0);
}

