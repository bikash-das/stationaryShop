/*billing.h*/

#ifndef BILLING_H_INCLUDED
#define BILLING_H_INCLUDED

extern int n,q[20],item_no[20];
extern const int price[20];
extern const char *items[20];
extern double total_amt,dis,total[20],gta;
extern int dec;
double roundFig=0.0;
extern int rdf;
/* this don't work */
//extern struct customer cust;
// declaring structure data type for customer info 


void billing()
{
	int i,len,another=1;
	char fc; /* first character (fc) of mobile number */	
	char g; /* for storing intermediate gender and assign if valid to cust.sex */
	char s[30]; /* to store gender */
	char name[30];
	char ph[20];
	
	printf("\n\t\tE N T E R    D E T A I L S\n\n");
	fflush(stdin);
	
	/* taking name, and also checking if it's valid */
	printf("\t\tEnter Name :: ");
 GET_NAME:	gets(name);
	
	//name:	gets(s);
	len=strlen(name);
	for(i=0;i<len;i++)
	{
		if(name[i]>=97 && name[i]<=122 || name[i]>=65 && name[i]<=90 || name[i]==' ')
		{
		//	printf("\nChecked valid name\n");			
		}
		else
		{
			printf("\n\t\tInvalid name\n");
			printf("\n\t\tPlease Enter a correct name :: ");
			goto GET_NAME;
			}	
	}		
	fflush(stdin);
	another=1;
	
    	printf("\t\tEnter Mobile No. :: ");  /* also checking for invalid numbers */
			
		while(another == 1)
		{
			scanf("%s",ph);
			fc=ph[0];
			len=strlen(ph);
	
			if(len == 10 && (fc=='7' || fc=='8' || fc=='9'))
			{
				for(i=1;i<len;i++)
				{
					if(isdigit(ph[i]))
					{
						
						another=0;	/* change only when number is valid */
					}
					else
					{
						another=1;
						break;
					}
				}		
				
			}
			if(another==1)
			{
				printf("\n\t\tInvalid Mobile Number\n");
				printf("\n\t\tNote :: Mobile number is of 10 digit and starts with 7, 8 or 9\n");
				printf("\n\t\tPlease Enter Again :: ");		
	
			}
		}
		another=1;
			
	fflush(stdin);	
	
	printf("\t\tEnter Gender  (M/F) :: ");
	while(another==1)
	{
		g=getche();
		/* checking for valid input */
		if(g == 'm' || g == 'f' || g == 'M' || g == 'F')
		{
			//printf("\n\t\tvalid\n\t\t");
			if(g == 'm' || g == 'M')
			  strcpy(s,"Male");   /* you simply can't assign a string to a variable  like s="male" is wrong */
			else
			  strcpy(s,"Female");
			another=0;
		}
		else
		{
	
			printf("\n\n\t\tYou have entered \"%c\" for Gender\n\n\t\tPlease Enter M for male and F for female :: ",g);
			fflush(stdin);
		
		}
		
	}

	printf("\n\n\t\tB I L L   I S   R E A D Y\n\n\t\tP R E S S      A      K E Y\n\n\t\t");
	getch();
	
	
	system("cls"); /* it will clear the screen (command terminal) */
	printf("\n\n\t\t---------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tC H A C H A J I   P E N - P E N C I L    S T O R E S\n");
	printf("\t\t---------------------------------------------------------------------------------------------\n");
	/* displaying current time and date */
	//printf();
	time_t mytime;
	mytime = time(NULL);	
   //	printf("\n\n");
	
	printf("\t\t\t\t\t\t\t    DATED :: ");
	printf(ctime(&mytime));
	printf("\n\t\tCustomer Information\n\t\t--------------------");
	
	printf("\n\t\tName :: %s\t\tMobile No. :: %s\t\tGender :: %s\n\n",name,ph,s);	
	
	//printf("\n");	
	
	printf("\t\t---------------------------------------------------------------------------------------------");	
	printf("\n\t\tSl.No\t\tItem Name              \t\tRate\t\tQuantity\tTotal (in Rs)\n");
	printf("\t\t---------------------------------------------------------------------------------------------\n\n");
	
	for(i=0;i<n;i++)
		printf("\t\t%d\t\t%s\t\t%d\t\t%d\t\t   %.2lf\n",(i+1),items[item_no[i]-1],price[item_no[i]-1],q[i],total[i]);
		
	printf("\t\t---------------------------------------------------------------------------------------------");	
	printf("\n\t\t       \t\t                       \t\t \t\t-----------------------------\n");	
	printf("\t\t       \t\t                       \t\t    \t\t     Total Amt     = %.2lf\n",total_amt);
	printf("\t\t       \t\t                       \t\t    \t\t     Discount (5%%) = %.2lf\n",dis);    
	printf("\t\t       \t\t                       \t\t    \t\t     Grand Total   = %.2lf\n",gta);
	printf("\t\t       \t\t                       \t\t  \t\t-----------------------------\n");	
	
	printf("\n\t\t---------------------------------------------------------------------------------------------");
	
	if(dec==0)
	
	printf("\n\t\t\t\tAmount to be paid  = Rs. %d.00 Only\n",rdf);	
	else
	printf("\n\t\t\t\tAmount to be paid (in Round Figure) = Rs. %d.00 Only\n",rdf);	
	printf("\t\t---------------------------------------------------------------------------------------------\n\n");	

}

#endif /* BILLING_H_INCLUDED */
