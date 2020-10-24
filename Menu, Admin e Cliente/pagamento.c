/*----------------------------------------------------------
# Objetivo: P�gina de Pagamento, Registro de cart�es em arquivo. 
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
#include "customLibPrj.h"


/* Corpo do programa */
int   main (void)
{	char  esc;
    registro_pagamento Rpgto, Rpgto_temp;
    registro_cartao    Rcart;
    Rpgto.Codpgto = CalculaRegistrosArq(ARQUIVO_DE_PAGAMENTOS)+1;
    setlocale (LC_ALL, "");
    /* Captura forma de pagamento do pedido */
	do
    {	system ("color 08");
    	system("MODE con cols=45 lines=30");
		system ("cls");
    	printf ("\n--- %s ---", NOME_ESTABELECIMENTO);
    	printf ("\n+-------------------------------------+");
    	printf ("\n|   Formas de Pagamento - Pedido %3i  |", Rpgto.Codpgto);
    	printf ("\n+-------------------------------------+");
    	printf ("\n|         1. Dinheiro                 |");
    	printf ("\n|         2. Cart�o de Cr�dito        |");
    	printf ("\n|         3. Cart�o de D�bito         |");
    	printf ("\n|         4. Cheque                   |");
    	printf ("\n|         0. Voltar                   |");
    	printf ("\n+-------------------------------------+");
    	printf ("\n   Sua op��o: ");
		fflush(stdin);
		esc = getche();
    	if ( esc < '0' || esc > '4')
    	{
    	   printf ("\nForma de pagamento INV�LIDA!");
    	   getch();
        }
    } while ( esc < '0' || esc > '4');
    /* Registra pagamento */
    switch ( esc )
    {
    	case '1':
			strcpy (Rpgto.Formapgto, "Dinheiro");
			system("Cliente");
			break;
    	case '2':
			strcpy (Rpgto.Formapgto, "Cart�o");
			break;
		case '3':
			strcpy (Rpgto.Formapgto, "Cart�o");
			break;
		case '4':
			strcpy (Rpgto.Formapgto, "Cheque");
		break;
		case '0':
			system("cls");
			system("Admin");
			/*exit (0);*/
			break;
	}
	/* Atualiza o valor do �ltimo pedido */
    resgataTemp (&Rpgto_temp);	
    if ( Rpgto.Codpgto == Rpgto_temp.Codpgto )
    {
        Rpgto.Valorpgto = Rpgto_temp.Valorpgto;
        registraPgto (Rpgto, 'a'); 
        
        /* Caso o pagamento seja feito com cart�o...*/
        if ( esc == '2' || esc == '3')
        {  Rcart.Codpgto = Rpgto.Codpgto; /*... atualiza o nro do pedido no registro de cart�o */
           solicitaCartao(&Rcart); /* captura o nro do cart�o */
           mascaraCartao (&Rcart); /* mascara o nro do cart�o */
		   /* Grava o n�mero do cart�o */
           gravaCartao(Rcart);
        }
    }
    else
    {
    	printf ("\nErro! �ltimo pedido n�o localizado!");
    	getch();
    	system("Cliente");
	}
    return (0);
}

