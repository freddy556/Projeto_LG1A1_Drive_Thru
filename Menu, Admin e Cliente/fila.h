#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{   
	int   CodVenda;
    int   removido;
} filas;

FILE * arqFila;

filas listaFila[500];

void ListarFila()
{
	arqFila = fopen ("fila.dat", "r");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
		
	filas fila;
	while(fread(&fila, sizeof(fila), 1, arqFila)) 
	{
		listaFila[contagemFila] = fila;
		contagemFila++;		
	}
		
	fclose(arqFila);
}

void AdicionarPedidoAFila(int codVenda)
{
	filas fila;
	fila.CodVenda = codVenda;
	fila.removido = 0;
	listaFila[contagemFila] = fila;
			
	arqFila = fopen ("fila.dat", "a");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
			
	fwrite(&fila, sizeof(fila), 1, arqFila); 
			
	fclose(arqFila);
}

void SalvarFila()
{
	arqFila = fopen ("fila.dat", "w");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	
	filas fila;	
	int i;	
	for(i=0;i<=contagemFila;i++)
	{
		fwrite(&listaFila[i], sizeof(fila), 1, arqFila); 
	}
		
	fclose(arqFila);
}
