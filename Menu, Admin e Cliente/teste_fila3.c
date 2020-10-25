#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 5

typedef struct T_FILA{
	int dados [N];
	int fim;
}T_FILA;

void inicializaFila(T_FILA *f){
	int i;
	for(i=0; i<N; i++){
		f->dados[i]=0;
	}
	f->fim=0;
}


void enfileira(int dado, T_FILA *f){
	if(f->fim == N){
		printf("Fila cheia!\n");
		return;
	}
	else{
		f->dados[f->fim] = dado;
		f->fim++;
	}
}

int desenfileira(T_FILA *f){
	int dado, i;
	if(f->fim == 0){
		printf("\nFila vazia");
		return;
	}
	else{
		dado = f->dados[0];
		for(i=0; i<f->fim; i++){
			f->dados[i] = f->dados[i+1];
		}
		f->fim--;
	}
	return dado;
}

void imprimeFila(T_FILA *f){
	int i;
	printf("\nImprimindo a fila\n");
	for(i=0; i<f->fim; i++){
		printf("%d ", f->dados[i]);
	}
}



int main(){
	T_FILA f1;
	
	inicializaFila(&f1);
	enfileira(10, &f1);
	enfileira(10, &f1);
	enfileira(10, &f1);
	enfileira(10, &f1);
	
	imprimeFila(&f1);
	
	desenfileira(&f1);
	
	imprimeFila(&f1);
}
