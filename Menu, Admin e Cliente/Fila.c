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
char str [128];
char buffer[128];
char buffer1[128];
char buffer2[128];
char buffer3[128];
char buffer4[128];
char buffer5[128];
int res, i, j, p0, p1, p2, p3, p4, p5, p6;

char opc;



void primeiroRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPedido Nro %d\n", p1);
		printf("\nPedido Nro %d\n", p2);
		printf("\nPedido Nro %d\n", p3);
		printf("\nPedido Nro %d\n", p4);
		printf("\nPedido Nro %d\n", p5);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void segundoRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPedido Nro %d\n", p1);
		printf("\nPedido Nro %d\n", p2);
		printf("\nPedido Nro %d\n", p3);
		printf("\nPedido Nro %d\n", p4);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void terceiroRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPedido Nro %d\n", p1);
		printf("\nPedido Nro %d\n", p2);
		printf("\nPedido Nro %d\n", p3);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void quartoRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPedido Nro %d\n", p1);
		printf("\nPedido Nro %d\n", p2);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void quintoRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPedido Nro %d\n", p1);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void sextoRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");
		printf("\nPedido Nro %d\n", p0);
		printf("\nPressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
		opc = getch();
		if((opc=='r') || (opc=='R')){
			removeFila();
		}else{
			system("Cliente_menu");
		}
}

void ultimoRemove(){
		system("cls");
		printf("\n---------------NOVA FILA-------------------");

		printf("\nFila Vazia! Pressione qualquer tecla para retornar ao menu cliente");
		opc = getch();
		remove("FILAF.TXT");
		system("Cliente_menu");
}

void removeFila(){
	/*char op;*/
	int temp6, temp5, temp4, temp3, temp2, temp1, temp0;
	/*int  p0, p1, p2, p3, p4, p5, p6;*/
	start: ;
	do{
		fflush(stdin);
		if(p6!=0){
			temp6 = p0;
			p0 = p1;
			p1 = p2;
			p2 = p3;
			p3 = p4;
			p4 = p5;
			p5 = p6;
			p6=0;
			system("cls");
			printf("\nPedido Nro %d\n", p0);
			printf("\nPedido Nro %d\n", p1);
			printf("\nPedido Nro %d\n", p2);
			printf("\nPedido Nro %d\n", p3);
			printf("\nPedido Nro %d\n", p4);
			printf("\nPedido Nro %d\n", p5);
			printf("\n\n\t-----------------------------------");
			printf("\n\t| Chamar pedido Nro %d no balcao! |", temp6);
			printf("\n\t-----------------------------------");
			getch();
			printf("\n\n Pedido Nro %d removido com sucesso!\n", temp6);
			getch();
			primeiroRemove();
		}
		else{
			if(p5!=0){
			temp5 = p0;
			p0 = p1;
			p1 = p2;
			p2 = p3;
			p3 = p4;
			p4 = p5;
			p5 = 0;
			p6 = 0;
			system("cls");
			printf("\nPedido Nro %d\n", p0);
			printf("\nPedido Nro %d\n", p1);
			printf("\nPedido Nro %d\n", p2);
			printf("\nPedido Nro %d\n", p3);
			printf("\nPedido Nro %d\n", p4);
			printf("\n\n\t-----------------------------------");
			printf("\n\t| Chamar pedido Nro %d no balcao! |", temp5);
			printf("\n\t-----------------------------------");
			getch();
			printf("\n\n Pedido Nro %d removido com sucesso!\n", temp5);
			getch();
			segundoRemove();
			
		}else{	
			if(p4!=0){
				temp4 = p0;
				p0 = p1;
				p1 = p2;
				p2 = p3;
				p3 = p4;
				p4 = 0;
				p5 = 0;
				p6 = 0;
				system("cls");
				printf("\nPedido Nro %d\n", p0);
				printf("\nPedido Nro %d\n", p1);
				printf("\nPedido Nro %d\n", p2);
				printf("\nPedido Nro %d\n", p3);
				printf("\n\n\t-----------------------------------");
				printf("\n\t| Chamar pedido Nro %d no balcao! |", temp4);
				printf("\n\t-----------------------------------");
				getch();
				printf("\n\n Pedido Nro %d removido com sucesso!\n", temp4);
				getch();
				terceiroRemove();
			}else{
				if(p3!=0){
					temp3 = p0;
					p0 = p1;
					p1 = p2;
					p2 = p3;
					p3 = 0;
					p4 = 0;
					p5 = 0;
					p6 = 0;
					system("cls");
					printf("\nPedido Nro %d\n", p0);
					printf("\nPedido Nro %d\n", p1);
					printf("\nPedido Nro %d\n", p2);
					printf("\n\n\t-----------------------------------");
					printf("\n\t| Chamar pedido Nro %d no balcao! |", temp3);
					printf("\n\t-----------------------------------");
					getch();
					printf("\n\n Pedido Nro %d removido com sucesso!\n", temp3);
					getch();
					quartoRemove();
				}else{	
					if(p2!=0){
						temp2 = p0;
						p0 = p1;
						p1 = p2;
						p2 = 0;
						p3 = 0;
						p4 = 0;
						p5 = 0;
						p6 = 0;
						system("cls");
						printf("\nPedido Nro %d\n", p0);
						printf("\nPedido Nro %d\n", p1);
						printf("\n\n\t-----------------------------------");
						printf("\n\t| Chamar pedido Nro %d no balcao! |", temp2);
						printf("\n\t-----------------------------------");
						getch();
						printf("\n\n Pedido Nro %d removido com sucesso!\n", temp2);
						getch();
						quintoRemove();
					}else{
						if(p1!=0){
							temp1 = p0;
							p0 = p1;
							p1 = 0;
							p2 = 0;
							p3 = 0;
							p4 = 0;
							p5 = 0;
							p6 = 0;
							system("cls");
							printf("\nPedido Nro %d\n", p0);
							printf("\n\n\t-----------------------------------");
							printf("\n\t| Chamar pedido Nro %d no balcao! |", temp1);
							printf("\n\t-----------------------------------");
							getch();
							printf("\n\n Pedido Nro %d removido com sucesso!\n", temp1);
							getch();
							sextoRemove();					
						}else{
							if(p0!=0){
								temp0 = p0;
								p0 = 0;
								p1 = 0;
								p2 = 0;
								p3 = 0;
								p4 = 0;
								p5 = 0;
								p6 = 0;
								system("cls");
								printf("\n\n\t-----------------------------------");
								printf("\n\t| Chamar pedido Nro %d no balcao! |", temp0);
								printf("\n\t-----------------------------------");
								getch();
								printf("\n\n Pedido Nro %d removido com sucesso!\n", temp0);
								getch();
								ultimoRemove();
							}
							}			
						}
					}
				}
			}
		}
	}
	while(opc=='r');
	
}



void iniciaFila(){
	FILE * Fila;
	/*int res, i, j, p0, p1, p2, p3, p4, p5, p6;
	/*char str [128];*/
	/*char buffer[128];*/
	Fila = fopen("FILAF.TXT", "r");
	if(Fila==NULL){
		printf("\n A fila está vazia!");
		return;
	}
		if(fgets(str, 30, Fila)!=NULL){
			/*puts(str);*/
			p0 = atoi(str);
			printf("\nPedido Nro %d\n", p0);
		}
		if(fgets(buffer, 30, Fila)!=NULL){
			/*puts(buffer);*/
			p1 = atoi(buffer);
			printf("\nPedido Nro %d\n", p1);
		}
			if(fgets(buffer1, 30, Fila)!=NULL){
			/*puts(buffer1);*/
			p2 = atoi(buffer1);
			printf("\nPedido Nro %d\n", p2);
		}
		if(fgets(buffer2, 30, Fila)!=NULL){
			/*puts(buffer2);*/
			p3 = atoi(buffer2);
			printf("\nPedido Nro %d\n", p3);
		}
		if(fgets(buffer3, 30, Fila)!=NULL){
			/*puts(buffer3);*/
			p4 = atoi(buffer3);
			printf("\nPedido Nro %d\n", p4);
		}
		if(fgets(buffer4, 30, Fila)!=NULL){
			/*puts(buffer4);*/
			p5 = atoi(buffer4);
			printf("\nPedido Nro %d\n", p5);
		}
		if(fgets(buffer5, 30, Fila)!=NULL){
			/*puts(buffer4);*/
			p6 = atoi(buffer5);
			printf("\nPedido Nro %d\n", p6);
		}		
	fclose(Fila);
}


main(){
	setlocale(LC_ALL, "");
	system("cls");
	system("MODE con cols=50 lines=30");
	char opc;
	printf("\n --------------------FILA----------------------");
	printf("\n Pressione qualquer tecla");
	getch();
	iniciaFila();
	printf("\n Pressione qualquer tecla para retornar ao menu cliente ou r para remover o primeiro elemento da fila");
	opc = getch();
	if((opc=='r') || (opc=='R')){
		removeFila();
	}
	else{
		system("cls");
		system("MODE con cols=45 lines=30");
		system("Cliente_menu");
	}
	
}
