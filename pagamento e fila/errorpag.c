/*Popup generico para error*/
/* Autor: Lucas Mendes
	Data: 16/10/2020*/

/*Libs*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Variáveis*/


/*Corpo da função de erro*/
	int main(){
		system("cls");
		system("MODE con cols=30 lines=4");
		setlocale(LC_ALL, "");		
		printf("\nOpção inválida!\nPressione qualquer tecla para retornar");
		getch();
		system("pagamento.exe");
	return 0;
}
