/*-------------------------------------------------------------------------------------
# Objetivo: Página inicial do programa. Fornecer opção de acesso como admin ou cliente.
-------------------------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/* Variaveis */

/* Corpo do Programa */
int main (void) {
	setlocale(LC_ALL, "");
	op:;
	system("MODE con cols=45 lines=30");
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
			fflush(stdin);
			system("login");
			exit(0);
			break;
		case '2':
			fflush(stdin);
			printf("\n cliente");	
			break;
		case '0':
			fflush(stdin);
			printf("\n Saiu");
			return 0;
			break;
		default:
			system("erroradmin");
			/*printf("\n Opcao invalida!");
			getch();
			goto op;*/
	}
	return (0);
}
