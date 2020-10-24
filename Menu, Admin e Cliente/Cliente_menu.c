/*-------------------------------------------------------------------------------------
# Objetivo: Sub menu da seção cliente. Opção de realizar pedido e escolher forma de pagamento.
-------------------------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Variaveis */

/* Corpo do Programa */
int main (void) {
	op: ;
	system("MODE con cols=45 lines=30");
	system("cls");
	printf("\n\n   =======================================");
	printf("\n   |               CLIENTE               |");
	printf("\n   =======================================");
	printf("\n   |                                     |");
	printf("\n   |          1. REALIZAR PEDIDO         |");
	printf("\n   |                                     |");
	printf("\n   |          2.    PAGAMENTO            |");
	printf("\n   |                                     |");
	printf("\n   |          0.     SAIR                |");
	printf("\n   |                                     |");
	printf("\n   =======================================");
	
	printf("\n             ");
	char op = getch();
	switch (op) {
		case '1':
			system("Cliente");
			
			exit(0);
			break;
		case '2':
			system("pagamento");
				
			break;
		case '0':
			printf("\n Saiu");
			exit(0);
			break;
		default:
			printf("\n Opcao invalida!");
			getch();
			goto op;
	}
	return (0);
}
