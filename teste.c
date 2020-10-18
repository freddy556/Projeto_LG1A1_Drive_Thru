#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <cstdlib>











int Menu_Principal()
{
int a_X,a_Y, result;
INPUT_RECORD ir_Evento;
DWORD dw_Saida;
BOOL bl_Finalizar = 0;
do{
gotoxy(24,5);printf("____________MENU____________");
gotoxy(23,6);printf("| Cadastrar |",178,178); // 33 ~ 42
gotoxy(23,8);printf("| Editar Cadastro |",176,176); // 30 ~ 44
gotoxy(23,10);printf("| Listar Cadastro |",178,178); // 30 ~ 44
gotoxy(23,12);printf("| Deletar Cadastro |",176,176); // 30 ~ 45
gotoxy(23,14);printf("| Importar BD |",178,178); // 32 ~ 42
gotoxy(23,16);printf("| Exportar BD |",176,176); // 32 ~ 42
gotoxy(23,18);printf("| relação |",178,178); // 34 ~ 40
gotoxy(23,20);printf("| Fechar Programa |",176,176); // 30 ~ 44
for(int a=7;a<20;a=a+2)
{
gotoxy(23,a);printf("| |");
}
for(int i=24;i<52;i++)
{
gotoxy(i,21);printf("%c", 238);
}
ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),&ir_Evento,1,&dw_Saida);
if(ir_Evento.EventType == MOUSE_EVENT) bl_Finalizar=0;
if(ir_Evento.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,2});
std::cout<<"x :"<<ir_Evento.Event.MouseEvent.dwMousePosition.X<<" \ny :"<<ir_Evento.Event.MouseEvent.dwMousePosition.Y<<" \n";
} if(ir_Evento.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
{

if(((ir_Evento.Event.MouseEvent.dwMousePosition.X >= 33) &&(ir_Evento.Event.MouseEvent.dwMousePosition.X <=42))
&&(ir_Evento.Event.MouseEvent.dwMousePosition.Y == 6))

{
result=1;
return result; // RETORNA CADASTRO
}

if(((ir_Evento.Event.MouseEvent.dwMousePosition.X >= 30)&&(ir_Evento.Event.MouseEvent.dwMousePosition.X <=44))
&&(ir_Evento.Event.MouseEvent.dwMousePosition.Y == 20))
{
result=0;
return result; //RETORNA SAIR
}

if((ir_Evento.Event.MouseEvent.dwMousePosition.X >= 30)&&(ir_Evento.Event.MouseEvent.dwMousePosition.X <=44)
&&(ir_Evento.Event.MouseEvent.dwMousePosition.Y == 8))
{
result=2;
return result; //RETORNA EDITAR
}

if((ir_Evento.Event.MouseEvent.dwMousePosition.X >= 30)&&(ir_Evento.Event.MouseEvent.dwMousePosition.X <=44)
&&(ir_Evento.Event.MouseEvent.dwMousePosition.Y == 10))
{
result=3;
return result; //RETORNA EDITAR
}

}


}while(bl_Finalizar ==0);
