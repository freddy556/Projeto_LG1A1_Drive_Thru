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



#define STRSIZE 128
#define N 5


/*Vari�veis globais*/
int num;
int CodPed;




/*Fun��o de verifica��o*/
ler_file(){
	FILE * Fila;
	int result;
	char str [128];
	char buffer[128];
	Fila = fopen("FILA.TXT", "r");
	if(Fila==NULL){
		printf("\nFalha ao abrir o arquivo FILA.TXT!");
		return 1;
	}
	if(fgets(str, 30, Fila)!=NULL){
		/*puts(str);*/
		CodPed = atoi(str);
	}
	if(fgets(buffer, 30, Fila)!=NULL){
		/*puts(buffer);*/
		num = atoi(buffer);
	}
	
	fclose(Fila);
	/*printf("\nO numero obtido foi %d", num);*/
	if(num>3){
		printf("\nO pedido Nro %d ser� enviado para a fila de espera por conter muitos itens (%d no total)!", CodPed, num);
		printf("\nPressione qualquer tecla para gerar o arquivo da fila");
		getch();
		
		FILE*File;
		File = fopen ("FILAF.TXT", "a");
			if(File == NULL){
			printf("\nErro ao gerar FILAF.DAT");
			getch();
			}
			else{
				/*result = fwrite(&CodPed, sizeof(File), 1, File);*/
		    	fprintf (File, "%d\n", CodPed);
		    	printf("Elemento gravado: Pedido Nro %d", CodPed);
		    	fclose(File);	
			}
		fclose (File);
		
		printf("\nSucesso!\n");
		printf("\nPressione qualquer tecla para retornar ao menu Cliente!");
		getch();
		system("Cliente_menu");
		return;
	}
	else{
		printf("\nChamar fun��o de levar");
		getch();
		system("Cliente_menu");
	}
}


int main(){
	setlocale(LC_ALL, "");
	system("cls");
	system("MODE con cols=120 lines=30");
	/*printf("\nUNDER CONSTRUCTION");*/
	ler_file();
	
	/*func_fila(num);*/
	
	return (0);
}

