//Домашнее задание №4
//Задание 2. Обратная польская запись
//Написать алгоритм перевода из инфиксной записи в обратную польскую. Для
//его реализации нужны данные по приоритетам операций. Реализовать
//алгоритм, используя побитовые операции (&, |, ^).
//Пример №1
//Данные на вход: ( 3 & 5 ) ^ 4 | 9
//Данные на выход: 3 5 & 4 ^ 9 |

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define STACK_SIZE 255
char oper[STACK_SIZE] = {0}; // стек для операций + - * / ( )
int oend=0; // заполненность стека

_Bool isOperator(char c)
{
 return (c=='&' || c=='|' || c=='^' || c=='+' || c=='-' || c=='*' || c=='/'); // (c==')' || c=='(' || 
}
void push(char v) 
{
 oper[oend++] = v;
}
char pop()
 {
 if(oend<=0 || (oend >=BUFFER_SIZE)) {
	fprintf(stderr,"Stack overflow\n");
	exit(1);
	}
 return oper[--oend];
}
_Bool emptyStack() {
 return oend==0;
}

int priority(char c)
{
 if(c=='(' || c==')')
 return 1;
 if(c=='+' || c=='-')
 return 2;
 if(c=='*' || c=='/')
 return 3;
 if(c=='&' || c=='^')
 return 4;
 if(c=='|')
 return 5;
 
 return 0;
}
char transform(char instr[])
{
char outstr[BUFFER_SIZE]={0};
	int flagdig=1;
	int flagop=1;
	int j=0;
	for(int i =0; instr[i]!='.';i++)
{
	//if(instr[i]>='0' && instr[i]<='9')
	//	{
			while(instr[i]>='0' && instr[i]<='9')
		{
		printf("%c", instr[i]);
		outstr[j]=instr[i];
		j++;
		i++;
		flagdig=0;
		
		}
	printf(" ");
	
	if(isOperator(instr[i]) || instr[i]=='(' || instr[i]==')')
	{ 
		if(instr[i]=='(' || instr[i]==')')
		{
		printf("()");
		//flagop=0;
		}
		else if(isOperator(instr[i]) && flagdig==0 && flagop==1 ) // была цифра не было оператора
		{
		push(instr[i]);// если первый оператор то пуш
		//printf("%c ", instr[i]);
		}
		else if(isOperator(instr[i]) && flagdig==1 && flagop==0 ) // нет цифр был оператор
		{
		//printf("dig 1 op 0");	
			if(pop()!=0) printf("%c", pop());//освобождаем стек 		//printf("%c ", instr[i]);
		//flagdig=1;
		//flagop=0;
		}
		//flagop=0;
		//else
		//flagop=0;}
		
	//{if (priority(instr[i])==3)
	//	if (priority(instr[i])==4)
	//	push(instr[i]);
		
		else if(isOperator(instr[i]) && flagdig==0 && flagop==0 ) // если 2-ой оператор и 2я цифра или их не было 
		{
			//if((instr[i]!='(' || instr[i]!=')'))
			printf("oper 2-2");
			printf("%c", pop());
			push(instr[i]);
			//flagop=1;
			//flagdig=1;
		}
	//flagdig=1;
	//flagop=0;
	}
	else if(instr[i]==' ')
	{i++;}
	else if(instr[i]=='.')
	 {break;}
}	
	return *outstr;
}

int main(void)
{
 char instr[BUFFER_SIZE]={"(1+2)*3"};
 //scanf("%[^\n]s", &instr);
 
//instr={"(1+2)*3"};
 //char answer[BUFFER_SIZE]={0};
// strcat(answer, string(transform(instr)));
 //printf("\nInput infix string: %s", instr);
 printf("\nOutput poland string: %c", transform(instr));



return 0;
}
