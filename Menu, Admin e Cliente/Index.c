/*-------------------------------------------------------------------------------------
# Objetivo: Página inicial do programa. Fornecer opção de acesso como admin ou cliente.
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
	system("color 08");
	system("cls");
	printf("\n\n   =======================================");
	printf("\n   |             ENTRAR COMO             |");
	printf("\n   =======================================");
	printf("\n   |                                     |");
	printf("\n   |          1. ADMINISTRADOR           |");
	printf("\n   |                                     |");
	printf("\n   |          2.    CLIENTE              |");
	printf("\n   |                                     |");
	printf("\n   |          0.     SAIR                |");
	printf("\n   |                                     |");
	printf("\n   =======================================");
	
	printf("\n             ");
	char op = getch();
	switch (op) {
		case '1':
			system("login");
			
			exit(0);
			break;
		case '2':
			system("Cliente_menu");
				
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
