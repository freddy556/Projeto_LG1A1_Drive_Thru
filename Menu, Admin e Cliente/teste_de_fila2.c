 #include <stdio.h> 
 #include <string.h> 
 #include <stdlib.h> 



 void q_enter(void);
 void q_list(void);
 int q_store(char *ptr);
 int q_delete(void);

 int count = 0;    //contador
 int store = 0;    // proxima posi��o na fila
 int retrieve = 0; // recupera a posi��o da fila
 char *queue[100]; // vetor da fila



 int main()
 {
 int i = 0;
 for ( i = 0; i < 100; i++ )
 {
 queue[i] = NULL;
 }
 q_enter(); // entra os dados na fila
 printf("\n\nTodos os dados da fila (FIFO):\n");
 q_list();
 q_delete(); // Apaga a primeira entrada da fila
 printf("\n\nA fila depois delete(FIFO):\n");
 q_list();
 printf("\n\nNumero de elementos restantes na fila: %i \n", count);
 getchar(); // espera
 return 0;
 }
 

 void q_enter(void)
 {
  static char str[5], *ptr;
  puts("Pressione a tecla ENTER sem nome pra sair\n");
  do {
      printf("Entre o nome:");
      gets(str);
      ptr = (char *) malloc(strlen(str)); //alocar um espa�o na mem�ria
      strcpy(ptr,str);
      if (*str)
      {
      count++;
      q_store(ptr); // Guarda o endere�o da seq��ncia de caracteres
      }

    } while (*str); //Sair se n�o houver uma entrada
 }
 
 

 // listar a fila
 void q_list(void)
 {
  int k;
 
  for (k = retrieve; k < store; k++)
  {
  printf("Elemento %d : %s \n",k+1,queue[k]);
  }
}
 

 // Guarda os itens na fila
 int q_store(char *ptr)
 {
  if (store == 5) {
  printf("\nA lista esta cheia!\n");
  return 0 ;
  }
  queue[store] = ptr;
  store++; // pr�ximo �ndice da fila
 }
 
 // Apaga um item da fila
 int q_delete(void)
 {
  if (store == retrieve) {
  printf("\nA fila esta vazia!");
  return 0 ;
  }
 count--;
 retrieve++; 
 }
