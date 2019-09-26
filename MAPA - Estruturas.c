#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define MAX 5

/*
Obsevações: Código feito no Dev++ como pedido, não podendo ser executado em kernel
linux pois existem comandos nativos do Windows como "system('color 0a')"
*/


typedef struct item{
  int PID;
  char name[60];
}Item;

typedef struct stack{
  int top;
  Item items[MAX];
}Stack;


int checkEmpty(Stack stack){
  if(stack.top == 0){
    return 1;
  }
  return 0;
}

Stack push(Stack stack, Item item){
  if(stack.top == MAX){
  	printf("===============================================\n");
    printf("\t\t!!!Pilha Cheia!!!\n");
    return stack;
  }
  
  stack.items[stack.top] = item;
  stack.top++;
  return stack;
}

void printProcess(Stack stack){

  printf("============ Conteúdo da Pilha ====================\n");

  if(checkEmpty(stack)){
    printf("\t\tPilha Vazia!!!\n");
  }else{
    int i = stack.top - 1;
	for(i; i >= 0; i--){
		if(i == 0){
		printf("\tTopo %d, PID: %d, Nome: %s \n", i, stack.items[i].PID, stack.items[i].name);
	}if(i > 0 && i < 4 ){	
		printf("\t%d\tPID: %d, Nome: %s \n",i, stack.items[i].PID, stack.items[i].name);
		}
		if(i == 4){
		printf("\tBase %d, PID: %d, Nome: %s \n", i, stack.items[i].PID, stack.items[i].name);

	}
	
	}
}

  printf("\n============ Contúdo do Fim da Fila ================\n");
}

Stack initStack(){

  Stack stack;
  stack.top = 0;
  return stack;
}

Stack pop(Stack stack){

  if(checkEmpty(stack)){
    printf("\t!!!Pilha vazia, Impossivél remover!!!\n");
    return stack;
  }

  stack.top--;
  return stack;
}

Stack emptyStack(){

  printf("\t\t!!!Pilha vazia!!!\n");
  return initStack();
}

void showMenu(){

//Menu de opções
  printf("\t     Opções:\n");
  printf("\t\t1) Empilhar\n");
  printf("\t\t2) Desempilhar\n");
  printf("\t\t3) Esvaziar\n");
  printf("\t\t0) Sair\n");
  
}

int generatePID(){
//Gerando Numeros aletórios
  int n = 1000;
  time_t t;
  srand((unsigned) time(&t));
  return rand() % n;
}

int executeOperation(int opt, Stack *stack){

  switch(opt){
    case 0: 
    return 0;
    case 1: 
      {
        Item process;
        char temp;
        process.PID = generatePID();
        printf("\nNome do Processo: ");
        scanf("%c", &temp);
        fgets(process.name,60,stdin);
        *stack = push(*stack, process);
      }
    return -1;
    case 2: 
      {
        *stack = pop(*stack);
      }
    return -1;
    case 3: 
      {
        *stack = emptyStack();
      }
    return -1;
  }
}

int main(){
	
	system("color 0a"); 
	
  setlocale(LC_ALL,"portuguese");
  
  int opt, loop = -1;
  Stack stack = initStack();
  
  do{
	
    printProcess(stack);
    showMenu();
    printf("\t\t?) Digite a Opção >>");
    scanf("%d", &opt);

    system("@cls||clear");
    loop = executeOperation(opt, &stack);

//tratamento de exceção, só é aceito o 0 para encerrar
  }while(loop !=0);

  return 0;
}
