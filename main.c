/* main.c */
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h> /* to use exit() function */
#include<time.h> /*to use time function */
/* user defined header files */
#include "data_items.h"
#include "calculate.h"
#include "billing.h"
#include "round_off.h"
#include "display_items.h"
//#include "cust_details.h"

const char *items[20]; /* array of 20 strings via pointer source - StackOverflow */
int main()
{
	int i;
	
	items[0]="Pen                    ";
	items[1]="Pencil                 ";
	items[2]="Scale (15cm)           ";
	items[3]="Scale (30cm)           ";
	items[4]="Excercise Book (Small) ";
	items[5]="Excercise Book (Large) ";
	items[6]="Eraser                 ";
	items[7]="Blank CD -R            ";
	items[8]="Blank CD -RW           ";
	items[9]="Blank DVD -R           ";
	items[10]="Blank DVD -RW         ";
	items[11]="A4 Paper (packet)     ";
	items[12]="A3 Paper (packet)     ";
	items[13]="Paper Clip            ";
	items[14]="Scissor               ";
	items[15]="Gum                   ";
	items[16]="Stapler               ";
	items[17]="Color Pencil          ";
	items[18]="Sharpener             ";
	items[19]="Envelope              ";
	printf("\n\n\t\t\t\t W  E  L  C  O  M  E \n\n\t\t\t\t\tT O \n\n\t\t C H A C H A J I   P E N - P E N C I L    S T O R E S\n\n");
	
	printf("\n\t\t   T H E S E  A R E  T H E  I T E M S  A V A I L A B L E\n\n");
	for(i=0;i<17;i=i+3)
	{
		printf("\t\t%s\t%s\t%s\n",items[i],items[i+1],items[i+2]);
	}
	printf("\t\t%s\t\t\t\t%s\n",items[18],items[19]);
	printf("\n\n\t\tA l r i g h t  L e t ' s  A d d  S o m e  I t e m s'\n");
	printf("\n\t\tP r e s s    A    K e y\n\t\t");
	getch();
	system("cls");
	data_items();
	calculate();
	convert(); /*round off function */
	
	billing();	
	getch();
	return 0;
}
