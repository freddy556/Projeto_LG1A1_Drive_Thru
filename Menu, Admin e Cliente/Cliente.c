/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define  NOME_ESTABELECIMENTO       "DRIVE THRU DO MICKEY & DONALDS"

/* Struct */
typedef struct {   
    int    	Codprod;
    char   	Nomeprod[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
    float	Custoprod;
} registro_produto; 

typedef struct {
	registro_produto	Prodped;
	int					Qtd;
	float				Valoritem;
} registro_pedido;

typedef struct {
	int		Codpgto;
	char	Formapgto[20+1]; /* 20 úteis + o \0 = NULL TERMINATOR */
	float	Valorpgto;
} registro_pagamento;

/* Variaveis */
registro_produto reg; 

/* Funções */
int CalculaRegistrosArq (char *nomeArq) {
   FILE *Arq;
   registro_pagamento R;
   int numero_registros;
   
   Arq = fopen (nomeArq, "r");
   if (Arq==NULL) {
      numero_registros = 0; /* O arquivo não existe */
   } else {   /* Calcula o tamanho do arquivo */
		if ( fseek (Arq, 0, SEEK_END) ) {
           printf("\nERRO ao calcular o tamanho de arquivo!\n");
           getch();
           numero_registros = -1;
        }else{   
		    numero_registros =  ftell(Arq) / sizeof (R); 
  	    }
  	    fclose (Arq);
	}
	return (numero_registros); 
}

int  menu_produtos	(void) {  
   FILE *A;
   registro_produto R; 
   R.Codprod=0;
   A = fopen ("PRODUTOS.DAT", "r");
   if (A==NULL) {
   		printf("\n Erro ao abrir arquivo PRODUTOS.DAT!");
	  	getch();
	  	exit(0); 
   } else {    
   		printf ("\n\t     --------------------------------------");
        printf ("\n\t              PRODUTOS CADASTRADOS        ");
        printf ("\n\t     --------------------------------------");
   	    while ( !feof(A) ) { 
		    fread (&R, sizeof(R), 1, A);
            if ( ferror(A) ) {
            	printf("\n Erro ao ler arquivo PRODUTOS.DAT!");
	  		    getch();
	  		    exit(0);	
			}  
	        if ( !feof(A) ) {
	        	printf ("\n\t     %3d %-20s R$%5.2f", R.Codprod, R.Nomeprod, R.Custoprod);	
			}      
	   }
	   fclose(A);
   }
   printf ("\n\t     --------------------------------------\n");
   return (R.Codprod);
}

void PesquisaProduto (registro_produto * R) {  
	FILE *A;
	registro_produto Rler; 
	A = fopen ("PRODUTOS.DAT", "r");
   	if (A==NULL) {
    	printf("\n Erro ao abrir arquivo PRODUTOS.DAT!");
		getch();
		exit(0);  
	} else {   
    
   	    while ( !feof(A) ) { 
		    fread (&Rler, sizeof(Rler), 1, A);
            if ( ferror(A) ) {
            	printf("\n Erro ao ler arquivo PRODUTOS.DAT!");
	  			getch();
	  			exit(0);	
			}	 
	        if ( !feof(A) ) {
	        	if ( R->Codprod == Rler.Codprod ) {
	        		*R = Rler;
				}    	
			}	        	
		}
		fclose(A);
	}
}

void geraTicket(int nroPedido, int qtd, registro_pedido rped, float total, char flag) {   
	FILE * Ticket;
    if (qtd==1) {
    	Ticket = fopen ("TICKET.TXT", "w");
	} else {
		Ticket = fopen ("TICKET.TXT", "a");	
	} 
    if ( Ticket == NULL ) { 	
		printf ("\nErro ao gerar TICKET.TXT");
    	getch();
	} else {   
		if (qtd==1) {	
			fprintf (Ticket, "\n +-----------------------------------------------------------+");
		    fprintf (Ticket, "\n |                %s             |", NOME_ESTABELECIMENTO);
		    fprintf (Ticket, "\n +-----------------------------------------------------------+");
		    fprintf (Ticket, "\n | Nro do pedido: %03i                                        |", nroPedido);
		    fprintf (Ticket, "\n +-----------------------------------------------------------+");
	   		fprintf (Ticket, "\n |Cód | Produto              | Custo Unit | Qtd | Valor item |");
	   		fprintf (Ticket, "\n +-----------------------------------------------------------+");
    	}
		if ( flag == '1' ) {   
			fprintf (Ticket, "\n +-----------------------------------------------------------+");
		    fprintf (Ticket, "\n |                                        TOTAL | R$   %5.2f |", total);
		    fprintf (Ticket, "\n +-----------------------------------------------------------+");
		} else {
		   fprintf (Ticket, "\n | %2i | %-20s | R$ %7.2f | %3i | R$ %7.2f |", 
		   rped.Prodped.Codprod, rped.Prodped.Nomeprod, rped.Prodped.Custoprod, rped.Qtd, rped.Valoritem);
	 	}
		fclose (Ticket);
	}
}

void pagamento_bemsucedido (registro_pagamento Rpgto) {
   printf ("\n\n PAGAMENTO [%3d][%s][R$%5.2f]", Rpgto.Codpgto, Rpgto.Formapgto, Rpgto.Valorpgto);
   printf ("\n gravado com sucesso!\n\n");
   /*_sleep(200);*/	
}

void registraPgto (registro_pagamento Rpgto, char flag) {
	FILE * A;
	if ( flag == 't'){
		A = fopen ("ULTIMOPGTO.DAT", "w");
	} else {
		A = fopen ("PAGAMENTOS.DAT", "a");
	}	   
	if (A == NULL){
		printf("\n Erro ao abrir PAGAMENTOS.DAT!");
	  	getch();
	  	exit(0); 
	}
      	  	
	fwrite (&Rpgto, sizeof(Rpgto), 1, A );
	if (ferror(A)) {
		printf("\n Erro ao gravar no arquivo PAGAMENTOS.DAT! ");
	  	getch();
	  	exit(0); 
	} else {
		if ( flag != 't')
           pagamento_bemsucedido(Rpgto);
	}  
    fclose (A);
}

/* Corpo do Programa */
int main (){
	system("MODE con cols=63 lines=30");
	char  esc;
    registro_pedido     registroped;
    float               total=0;
    int quantidade_itens = 0;
    int codUltimoProduto = 0;
    registro_pagamento Rpgto;
    Rpgto.Codpgto = CalculaRegistrosArq("PAGAMENTOS.DAT")+1;
    
    setlocale (LC_ALL, "");
    do{ 	
		do{  
			system ("cls");
    		printf ("\n\t     --- %s ---", NOME_ESTABELECIMENTO);
	    	codUltimoProduto = menu_produtos();
	    	
	    	if (codUltimoProduto==0) {
	        	printf("\n Erro! Não há produtos cadastrados no arquivo PRODUTOS.DAT!");
	  			getch();
	  			exit(0); 
	        }
	          
	    	/* Solicita um produto cadastrado */
	    	printf ("\n\t     Qual produto deseja? "); 
			fflush(stdin); 
			scanf("%i", &registroped.Prodped.Codprod);    
	    	if ( registroped.Prodped.Codprod < 1 || registroped.Prodped.Codprod > codUltimoProduto ) {
				printf ("\n Código de produto inválido!");
	    		getch();
	    	}
		} while ( registroped.Prodped.Codprod < 1 || registroped.Prodped.Codprod > codUltimoProduto );
	   
		/* Contabiliza quantos itens foram pedidos */
		quantidade_itens++;
		/* Busca os dados do produto selecionado */
		PesquisaProduto(&registroped.Prodped);
		/* Solicita a quantidade de produto */
		do {   
	    	printf ("\n\t     Quantas unidades de %s deseja? ", registroped.Prodped.Nomeprod); 
			fflush(stdin); scanf("%i", &registroped.Qtd);
			if ( registroped.Qtd < 1 ) {
				printf ("\n Quantidade inválida!");
	        	getch();
	    	}
		} while ( registroped.Qtd < 1);
	   
		/* Calcula o valor do item do pedido */
		registroped.Valoritem = registroped.Qtd * registroped.Prodped.Custoprod;
	   
		/* Atualiza o total do pedido */
		total = total + registroped.Valoritem;
	   
		/* Mostra o que foi comprado até o momento */
		system("cls");
		geraTicket(Rpgto.Codpgto, quantidade_itens, registroped, total, '0');
		system ("TYPE TICKET.TXT");
		printf ("\n +-----------------------------------------------------------+");
		printf ("\n |\t\t\t        Total da compra | R$ %7.2f |", total);
		printf ("\n +-----------------------------------------------------------+");
	   
		/* Pergunta se deseja mais algum produto */
		printf ("\n\n Deseja mais algum produto [S=sim]");
		fflush (stdin); esc = getche();
	   
	} while ( esc == 'S' || esc == 's');
    
	/* Mostra o ticket completo com o total a pagar */
    geraTicket(Rpgto.Codpgto, ++quantidade_itens, registroped, total, '1');
    system ("NOTEPAD TICKET.TXT");
    
	/* Prepara o arquivo de pagamentos para receber a forma de pagamento */
    Rpgto.Valorpgto = total;
    
	/* 't' = guarda temporariamente esse registro para preservar o nro do pedido e o total*/
    registraPgto (Rpgto, 't');
	
	
    return (0);
}
