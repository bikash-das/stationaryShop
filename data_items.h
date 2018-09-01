/*data_items.h */
#ifndef DATA_ITEMS_H_INCLUDED
#define DATA_ITEMS_H_INCLUDED

#include "display_items.h" /*contains display_item() , and this function is called from this program*/

int validate(char s[]);

//const char *items[20];
int n=0,q[20],item_no[20];
const int price[20]={10,5,10,20,25,45,3,10,15,20,25,125,100,8,15,10,30,30,5,10};
const int quantity[20]={70,80,90,100,200,90,123,234,350,100,200,70,100,50,60,70,80,90,100,200}; /* Stock quantity */
char c,ch,mod;
int quan,approved=1,f1;
void data_items()
{
	int i,j,temp1,flag;
	char choice,bik,tmp1[10],tmp2[10],tmp3[10];
	 /* tmp1 for taking item number, tmp2 for quantity , assigning only after validating the input is a proper integer like if user enter 
	 	quantity= "ey37"
		it is an invalid input and ask the user to enter again */

	system("cls");
	display_item();
	
	i=0;   /* we can use i as the number of items input by the user or use n */

	printf("\n\t\tDo you want to add items (y or n) :: ");
	CHOICE:	choice=getche();
	if(choice == 'Y' || choice == 'y')
	{
		/* Asking user to enter item number and quantity */	
			/* i will increase only when data is validated and checked */
		approved=1;
		f1=1;
        for(;;)	
		{	
		    flag=0;
		    if(i==0)
			{
				printf("\n\n\t\tYour First Item ");
			}
								
			printf("\n\n\t\tEnter item number \t\t  ::\t\t");
		    OKAY:	scanf("%s",tmp1);		 		
		 	if(validate(tmp1) == 0)  /* checking if user entered number or char or group of characters instead of integer */
		 	{
		 		//invalid input
		 		printf("\n\t\tInvalid Input\n\n\t\tEnter Item Number (again) :: ");
		 		goto OKAY;
		 			
			}
			else
			{
				/*valid input     storing it in temporary, to check if it is valid number or not means entered in range or not */
				temp1 = atoi(tmp1);  /* converting to integer if input is valid */			 
			 
			   	if(temp1>0 && temp1<=20)
		    	{
		    		flag=0;
		    		/* checking if user enters the same item number again or it exist in the bucket */
		    		/* then we'll ask if user want to modify the quantity or keep as it is */
		    		j=0;
		    		for(j=0;j<i;j++)
		    		{
		    			if(item_no[j] == temp1)   /* it's in j location, the same item, we can manipulate j */
		    			{
		    				flag=1;
		   					printf("\n\t\tAlready present %s\n",items[temp1-1]);
		    				printf("\n\t\tDo you want to modify the quantity (y or n) :: ");
		    	 			MODIFY:	mod=getche();
		    				if(mod == 'y')
		    				{
		    					printf("\n\n\t\tCurrent quantity is %d for %s\t\t",q[j],items[temp1-1]);
		    					printf("\n\t\tEnter new quantity for %s\n\t\t",items[temp1-1]);
		  						NEW_QUAN: scanf("%s",tmp3);  /* check if user enters number so take it in character first, and assign it to quan */
		    					
		    					if(validate(tmp3) == 0)
		    					{
		    						printf("\n\t\tPlease enter a valid number :: ");
		    						goto NEW_QUAN;
								}
								else
								{
									quan=atoi(tmp3); /* converting the string into a number after verification */    					
		    						f1=0;
		    						goto CHECK;
								}		    				
							}
							else if(mod == 'n')
							{
								/* ask if user want to keep the item in the bucket or want to remove */
								system("cls");
								display_item();
								printf("\n\n\t\tOK Item original quantity preserved\n");			
								printf("\n\t\tDo you want to add more item (y or n) :: ");					
								goto CHOICE;
							}
							else
							{
								printf("\n\t\tPlease enter y for yes and n for no\n\t\t");
								goto MODIFY;
							}
		    				
		    				
						}
					}
					/* put some where else */
					if(flag==0)
					{
						goto QUANTITY_AGAIN;   /* if valid it will break from the for loop */
					}
		    				
				}
			}
			/* otherwise ask again until entered correct number */		
			if(flag!=1)
			{	
				system("cls");	 
				display_item();  
				printf("\n\t\tYou Entered item no. %d which does not exist\n\n\t\tPlease Enter Again",temp1);	
			}
		    	
			
		} /* infinite for loop ends here */
				
		printf("\n");
		QUANTITY_AGAIN:	printf("\t\tHow many %s  ::\t\t",items[temp1-1]);
		scanf("%s",tmp2);		 		
		if(validate(tmp2) == 0)  /* checking if user entered number or char or group of characters instead of integer */
		{
			//invalid input
			printf("\n\t\tInvalid Input\n\n\t\tEnter Again\n\n");
			goto QUANTITY_AGAIN;
		}
		else
		{
			quan = atoi(tmp2);
			CHECK: if(quan <= 0)
				   {
				   		if(quan == 0)
							printf("\n\t\tYou Have Entered Zero\n");
						else
			    			printf("\n\t\tYou Have Entered %d\n\t\tAn Invalid Quanity Number\n\n",quan);
			
						printf("\n\t\tENTER AGAIN\n\n");
						goto QUANTITY_AGAIN;
					}	
					// quantity check
		  			if(quan > quantity[temp1-1])  /* it checks quantity of item_no which is temp1 minus one */
  		  			{	
  		  				printf("\n\t\tSorry , In our Stock, there is only %d %s\n",quantity[temp1-1],items[temp1-1]);
     					printf("\n\t\tDo you want to reduce the quantity (y or n) :: ");
		    			fflush(stdin);
						REDUCE:	c = getche();
		 				if(c=='y')
		   				{
		     				printf("\n\n\t\tAlright, Please Enter Again \n\n");
		     				goto QUANTITY_AGAIN;
	     				}	
						else if(c=='n')
						{
							approved=0;				
		    			}
		    			else
		    			{
		    				printf("\n\t\tPlease enter y for yes and n for no\n");
		    				goto REDUCE;
						}
	      			}	
	  	}
		// if approved 	    
		if(approved!=0)
		{
		  	if(f1==0)  /* quantity modified (same item present in the j th location, so using j value */
		  	{
		  		item_no[j]=temp1;
		  		q[j]=quan;
		  		
		    }
		    else
			{
			  	item_no[i]=temp1;
		    	q[i] = quan;
			 
			 	i++;
			 	n++;
			}
		     
		}
		
		system("cls");
		/* loop termination condition */
		//if(i<=n-1)
		display_item();
		printf("\n\t\tDo You want to add more items (y or n) :: ");
		goto CHOICE;
   	
   } /* if ends here, taking values part */
   
   else if(choice == 'N' || choice =='n')
   {
		/* Viewing what we have added */
  		if(n==0)
  		{
  	  		system("cls");
  	  		printf("\n\t\tBucket is empty\n\t\tAre you sure you don't want to buy anything? \n");
  	  		printf("\n\t\tPress \'y\' for \'You don't want to buy\'or \'n\' for \"You want to buy\" :: ");
			CONFIRM: bik=getche();
      		if(bik == 'y' || bik == 'Y')
  	  		{
  	  			printf("\n\t\tThank You. Have A Good Day\n\t\t");
  	  			getch();
  	  			exit(0); /* if user don't want to buy anything, exiting the program */ 	  	
	  		}
	  		else if(bik == 'n' || bik == 'N')
	  		{
	  	  		system("cls");
	  	  		display_item();
	  	 		printf("\n\t\tDo You want to add items (y or n) ::  ");
	  	 		goto CHOICE;
	  		}
  	  		else
			{
				printf("\n\t\tEnter y for yes or n for no :: ");
				goto CONFIRM;
			}	
  		}
   		else
   		{ 
			system("cls");
			printf("\n\n\t\tDo you want to View the I T E M S you have Added\n");
			printf("\n\t\tPress y or n :: ");
			VIEWS :	ch=getche();
			if(ch == 'n')
			{
				printf("\n\n\t\tOK! Now, Moving to the billing section\n");
				printf("\n\n\t\tPress a key\n\t\t");
				getch();
			}
			else if(ch == 'y')
			{
				printf("\n\n");
				printf("\t\t-----------------------------------------------");
				printf("\n\t\tItems \t\t\t\t     Quantity\n");
				printf("\t\t-----------------------------------------------\n");
			
				for(i=0;i<n;i++)
				{
					printf("\t\t%s\t\t\t%d\n",items[item_no[i]-1],q[i]);
				}
				printf("\n\t\t");
				//getch();
				printf("\n\n\t\tOK! Now, Moving to the billing section\n");
				printf("\n\n\t\tPress a key\n\t\t");
				getch();
			}
			else
			{
				printf("\n\n\t\tPlease enter y for yes and n for no :: ");
		   		goto VIEWS;
			}
		}
	
  	}	 /* condition for choice = n ends here */
 	
    else
  	{
  		printf("\n\t\tYou have entered \'%c\'\n\t\tPlease enter y for yes and n for no ::  ",choice);
  	  	goto CHOICE;
  	}
	    
} /* data_items() function  ends here */


/* validating function */
int validate(char s[])
{
	int i,len,flag=0;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(!isdigit(s[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	  return 0;
	return 1;
}
#endif /* DATA_ITEMS_H_INCLUDED */
