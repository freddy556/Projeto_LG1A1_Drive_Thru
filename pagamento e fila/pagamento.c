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

/*Inicio struct de pagamentos*/
typedef struct{
	int codpgto;
	float valorpgto;
	char formapgto [20+1];
}pagamento;

/*Inicio da struct de cartões*/
typedef struct{
	int codpgtocard;
	char numcard [20+1];
}cartao;

/*Variáveis globais*/
FILE * Arq;
pagamento pgto;
cartao card;

/*Corpo do prgrama*/
int main(){
	start:;
	system("cls");
	setlocale(LC_ALL, "");
	system("MODE con cols=50 lines=30");
	system("cls");
	printf("\n\n    ========================================");
	printf("\n   |              MENU PAGAMENTO             |");
	printf("\n     =======================================");
	printf("\n   |                                         |");
	printf("\n   |         1. DINHEIRO                     |");
	printf("\n   |                                         |");
	printf("\n   |         2. CARTÃO DE CRÉDITO/DÉBITO     |");
	printf("\n   |                                         |");
	printf("\n   |         3. CHEQUE                       |");
	printf("\n   |                                         |");	
	printf("\n   |         0. VOLTAR                       |");
	printf("\n   |                                         |");
	printf("\n    ==========================================");

	char op = getch();
	switch(op){
		case '1':
			system("cls");
			pgto_dinheiro();
			break;
		case '2':
			system ("cls");
			pgto_card();
			break;
		case '3':
			system("cls");
			pgto_cheque();
			break;
		case '0':
			system("CLIENTE.EXE");
			break;
		default:
			system("errorpag.exe");				
	}
}

/*Função*/

void pgto_dinheiro(){
	
}

void pgto_card(){
	
}

void pgto_cheque(){
	
}


/*Função para gravar pagamento*/

void grava_pgto(void){
	FILE * pgt;
	pgt = fopen("PAGAMENTOS.DAT", "a");
	if(pgt == NULL){  /*Verificação para garantir que o arquivo foi aberto corretamente*/
		printf("\nFalha ao abrir o arquivo!");
		getch();
		exit(0);
	}
	
	/*Guardando os dados no arquivo PAGAMENTOS.DAT*/
	fwrite(&pgto, sizeof(pgto), 1, pgt);
	if(ferror (pgt) ){
		printf("\nErro ao gravar dados no arquivo PAGAMENTOS.DAT");
		getch();
		exit(0);
	}
}
