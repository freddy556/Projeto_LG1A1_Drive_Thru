/*M�dulo de autentica��o para acesso ao menu admin*/

/*Autor: Lucas Mendes	
	Data:17/10/2020*/
	
/*LIBS*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>	

/*Variaveis*/

char usuario[5]="admin"; /*Declara��o do vetor contendo o usu�rio original. Esse vetor servir� de base de compara��o para dizer se o usu�rio digitado � correto ou n�o*/
char user [5]; /*Declara��o do vetor que ir� guardar os caracteres do usu�rio com 4 posi��es (0, 1, 2, 3), e que ser� comparado com o vetor usuario original para permitir o acesso*/
char senha[5] = "admin"; /*Declara��o do vetor contendo a senha original. Esse vetor servir� de base de compara��o para dizer se a senha digitada � correta ou n�o*/
char pass [5]; /*Declara��o do vetor que ir� guardar os caracteres da senha com 4 posi��es (0, 1, 2, 3), e que ser� comparado com o vetor com a senha original para permitir o acesso*/

void main(){
	setlocale(LC_ALL, "");
	start:;
	int i, j;
	system("MODE con cols=48 lines=8");
	system("cls");
	printf("\n   ==========================================");
	printf("\n  |              LOGIN ADMIN                 |");
	printf("\n   ==========================================");
	printf("\n    Usu�rio: ");
		for(i=0; i<5; i++){
			user[i]=getche();
		}
	printf("\n                                          ");
	printf("\n    Senha: ");
		for(j=0; j<5; j++){
			pass[j]=getch();
			putchar('*');
		}

	if(strcmp(usuario, user)==0){
		if(strcmp(senha, pass)==0){
			printf("\npicles");
		}
	}
	else{
		printf("\nmecome");
	}
	/*if((strcmp(senha, pass)==0)){
		system("cls");
		printf("\nLogin bem sucedido!\nPressione qualquer tecla para prosseguir ao menu\nAdmin!");
		getch();
		system("Admin.exe");
	}
	else{
		system("cls");
		printf("\nFalha ao logar! Verifique os dados inseridos e tente novamente!");
		getch();
		goto start;
	}*/
	


}
