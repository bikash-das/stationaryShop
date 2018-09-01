/* calculate.h*/
#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

extern int n,item_no[20];

double total[20];

double total_amt=0.0,dis=0.0,gta=0.0;


void calculate()
{
	int i;
	for(i=0;i<n;i++)
	{
		total[i] = (price[item_no[i] - 1] )* q[i];
		total_amt = total_amt + total[i];
	}
	dis=0.05 * total_amt;	
	gta=total_amt-dis;
	
}

#endif
