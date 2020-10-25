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

#define STRSIZE 128



int Fila[100];
int str [128];
int buffer[128];
int buffer1[128];
int buffer2[128];
int buffer3[128];
int buffer4[128];

void iniciaFila(){
	FILE * Fila;
	int res, i, j, p1, p2, p3, p4, p5, p0;
	char str [128];
	char buffer[128];
	Fila = fopen("FILAF.TXT", "r");
	if(Fila==NULL){
		printf("\nFalha ao abrir o arquivo FILAF.DAT!");
		return;
	}
	
		if(fgets(str, 30, Fila)!=NULL){
			/*puts(str);*/
			p0 = atoi(str);
			printf("\n%d\n", p0);
		}
		if(fgets(buffer, 30, Fila)!=NULL){
			/*puts(buffer);*/
			p1 = atoi(buffer);
			printf("\n%d\n", p1);
		}
			if(fgets(buffer1, 30, Fila)!=NULL){
			/*puts(buffer1);*/
			p2 = atoi(buffer1);
			printf("\n%d\n", p2);
		}
		if(fgets(buffer2, 30, Fila)!=NULL){
			/*puts(buffer2);*/
			p3 = atoi(buffer2);
			printf("\n%d\n", p3);
		}
		if(fgets(buffer3, 30, Fila)!=NULL){
			/*puts(buffer3);*/
			p4 = atoi(buffer3);
			printf("\n%d\n", p4);
		}
		if(fgets(buffer4, 30, Fila)!=NULL){
			/*puts(buffer4);*/
			p5 = atoi(buffer4);
			printf("\n%d\n", p5);
		}

	
	

	
	fclose(Fila);
}


main(){
	printf("\nTeste!");
	printf("\Pressione qualquer tecla");
	getch();
	iniciaFila();
}
