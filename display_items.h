/*display_items.h*/
/* IF NOT DEFINED OR INCLUDED IN MAIN OR CALLING FUNCTION
IT WILL BE DEFINED 
IF ALREADY DEFINED THEN IT WILL IGNORE
OTHERWISE 
error will come, redefinition of data type "bla" 
*/
#ifndef DISPLAY_ITEMS_H_INCLUDED
#define DISPLAY_ITEMS_H_INCLUDED
extern const char *items[20];
extern const int price[20];

void display_item()
{
	int i;
	
	printf("\t\t---------------------------------------------------------");
	printf("\n\t\t\t\tI T E M S  A V A I L A B L E\n");	
	printf("\t\t---------------------------------------------------------\n\n");
	printf("\t\tItem No.\tItem Name\t\t Rate/Piece (in Rs.)\n");
	printf("\t\t--------\t---------\t\t -------------------\n");
	for(i=0;i<20;i++)
	{
		printf("\t\t%d.\t\t%s\t\t%d\n",(i+1),items[i],price[i]);
	}	
}
#endif   	
