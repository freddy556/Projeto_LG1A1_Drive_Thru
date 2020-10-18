/*Módulo de autenticação para acesso ao menu admin*/

/*Autor: Lucas Mendes	
	Data:17/10/2020*/
	
/*LIBS*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>	

/*Variaveis*/

char usuario[5]="admin"; /*Declaração do vetor contendo o usuário original. Esse vetor servirá de base de comparação para dizer se o usuário digitado é correto ou não*/
char user [5]; /*Declaração do vetor que irá guardar os caracteres do usuário com 4 posições (0, 1, 2, 3), e que será comparado com o vetor usuario original para permitir o acesso*/
char senha[5] = "admin"; /*Declaração do vetor contendo a senha original. Esse vetor servirá de base de comparação para dizer se a senha digitada é correta ou não*/
char pass [5]; /*Declaração do vetor que irá guardar os caracteres da senha com 4 posições (0, 1, 2, 3), e que será comparado com o vetor com a senha original para permitir o acesso*/

void main(){
	setlocale(LC_ALL, "");
	start:;
	int i, j;
	system("MODE con cols=48 lines=8");
	system("cls");
	printf("\n   ==========================================");
	printf("\n  |              LOGIN ADMIN                 |");
	printf("\n   ==========================================");
	printf("\n    Usuário: ");
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
