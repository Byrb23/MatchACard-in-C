#include<stdio.h>
#include<stdlib.h>						
#include<unistd.h>						
#define TRUE 1							///////////// Mar 19 , 2017/////////////////////
#define FALSE 0
void rmn_pos(int array[],int n);
int error;
//This program is a very basic matching of pairs card game where the user will attempt to find a pair of cards.//
//1.)The user will be asked to choose a board size.//
//2.)User will play the game//
//3.)If user entered a wrong pair,he or she will be asked if he or she wants to continue to play the game or exit.//

////////////////////////////////////////////////////////////////W E L C O M E -- F U N C T I O N///////////////////
int welcome()
{
char yn;
     printf("======================================================================================================\n");
     printf("||                                                                                                  ||\n");
     printf("||                                                   *                                              ||\n");
     printf("||   *      *      *    *******  *****   *   *     *   *                                            ||\n");
     printf("||   * *  * *     * *      *     *       *   *    * * * *                                           ||\n");
     printf("||   *   *  *    * * *     *     *       *****   *       *                              	         ||\n");
     printf("||   *      *   *     *    *     *       *   *         *****   *   ****   * *                       ||\n");
     printf("||   *      *  *       *   *     *****   *   *         *      * *  * *    *  *                      ||\n");
     printf("||                                                     ***** *   * *   *  * *                       ||\n");
     printf("||                                                                    Developed by Byron Banzon     ||\n");
     printf("======================================================================================================\n");
     printf("Do you want to play?\n");
     do{
     		printf("Enter Y to go to setup and N to exit.\n");
     		scanf(" %c",&yn);
     		if(yn=='n'||yn=='N')
    			 {
     				printf("Bye!\n");
     				exit(0);
    			 }
    		else if(yn=='Y'||yn=='y')
    			{
    					return TRUE;
    			}
    		else
    			{
			printf("Error,you entered an invalid character\n");
    			}			 
     	}while(yn!='n'||'N'||'Y'||'y');	

}
///////////////////////////////////////////////D I S P L A Y -- B O A R D //////////////////////////////

int display_board(int array[],int n)
{

   	
  	//Replace numbers with characters with positions specified by the user//
	if(n==8)
		{ 		
 	printf("******   ******    ******   ****** \n");
	printf("*    *   *    *    *    *   *    *\n");
	printf("* %c  *   * %c  *    * %c  *   * %c  *\n",array[1],array[2],array[3],array[4]);    
	printf("*    *   *    *    *    *   *    *\n");
    printf("******   ******    ******   ******\n");
	printf("******   ******    ******   ****** \n");
	printf("*    *   *    *    *    *   *    *\n");
	printf("*  %c *   *  %c *    *  %c *   * %c  *\n", array[5], array[6], array[7], array[8]);
	printf("*    *   *    *    *    *   *    *\n");
    printf("******   ******    ******   ******\n");
		}
    else if(n==18)
 		{
 		printf("******   ******    ******   ******   ******   ****** \n");
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
		printf("*  %c *   *  %c *    * %c  *   * %c  *   * %c  *   * %c  *\n",array[1],array[2],array[3],array[4],array[5],array[6]);
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
    	printf("******   ******    ******   ******   ******   ******\n");	 			
		printf("******   ******    ******   ******   ******   ******\n");				 
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
		printf("*  %c *   *  %c *    * %c  *   * %c  *   * %c  *   * %c  *\n",array[7],array[8],array[9],array[10],array[11],array[12]);
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
    	printf("******   ******    ******   ******   ******   ******\n");
    	printf("******   ******    ******   ******   ******   ******\n");
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
		printf("*  %c *   *  %c *    * %c  *   * %c  *   * %c  *   * %c  \n",array[13],array[14],array[15],array[16],array[17],array[18]);
		printf("*    *   *    *    *    *   *    *   *    *   *    *\n");
    	printf("******   ******    ******   ******   ******   ******\n");


 	}	
	else//returns -1 if invalid parameter//
	{
		return -1;
	}

return 0;
  
   																																				
}


//////////////////////////////////////////////////////D I S P L A Y -- P O S I T I O N S/////////////////////////////

void display_pos(int n)
{

    	
  	// Display which positions that the numbers 1 -18 represent//
	if(n==8)
 		{	
 	printf(" ____     ____      ____     ____ \n");
	printf("|    |   |    |    |    |   |    |\n");
	printf("|  1 |   |  2 |    |  3 |   |  4 |\n");   
	printf("|    |   |    |    |    |   |    |\n");
    printf("|____|   |____|    |____|   |____|\n");
	printf(" ____     ____      ____     ____ \n");
	printf("|    |   |    |    |    |   |    |\n");
	printf("|  5 |   |  6 |    |  7 |   | 8  |\n");
	printf("|    |   |    |    |    |   |    |\n");
    printf("|____|   |____|    |____|   |____|\n");
		}
	else if(n==18)
	{
		printf(" ____     ____      ____     ____     ____     ____ \n");
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
		printf("|  1 |   |  2 |    | 3  |   | 4  |   | 5  |   | 6  |\n");
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
    	printf("|____|   |____|    |____|   |____|   |____|   |____|\n");	 			 
		printf(" ____     ____      ____     ____     ____     ____ \n");				 
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
		printf("|  7 |   |  8 |    | 9  |   | 10 |   | 11 |   | 12 |\n");
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
    	printf("|____|   |____|    |____|   |____|   |____|   |____|\n");
    	printf(" ____     ____      ____     ____     ____     ____ \n");
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
		printf("| 13 |   | 14 |    | 15 |   | 16 |   | 17 |   | 18 |\n");
		printf("|    |   |    |    |    |   |    |   |    |   |    |\n");
    	printf("|____|   |____|    |____|   |____|   |____|   |____|\n");

	}	



}     	
///////////////////////////////////C H E C K -- V A L I D -- I N P U T/////////////////////////////////////
int checkrng(int i,int comp[],int n)
{
	if(n==8)	//Function to check if user input is valid,if not it will prompt until user will enter a valid number//
  {
	do
		{	
			if((i<1)||(i>8))
			{printf("%d is not a valid number\n",i);
			printf("Please enter a valid number.\n");
			scanf("%d",&i);
			}
			else if((i>=1)||(i<=8))
				{
					while( i==(comp[1]) || i==(comp[2]) || i==(comp[3]) ||i==(comp[4]) || i==(comp[5]) || i==(comp[6]) || i==(comp[7]) || i==(comp[8]) )
    	    						{
    		  							
    			  							printf("%d has already been entered, please enter another number\n",i);
    			  							rmn_pos(comp,n);
    			  							scanf("%d",&i);
    		   							  
    								}    
					
				}



		}
	while ((i<1) || (i>8));
						
	printf("You entered %d\n\n",i);						 
   }

   if(n==18)
   {
   	do
		{	
			if((i<1)||(i>18))
			{printf("%d is not a valid number\n",i);
			printf("Please enter a valid number.\n");
			scanf("%d",&i);
			}
			else if((i>=1)||(i<=18))
				{
					while( i==(comp[1]) || i==(comp[2]) || i==(comp[3]) ||i==(comp[4]) || i==(comp[5]) || i==(comp[6]) || i==(comp[7]) || i==(comp[8])|| i==(comp[9]) || i==(comp[10]) || i==(comp[11]) || i==(comp[12]) || i==(comp[13]) || i==(comp[14]) || i==(comp[15]) || i==(comp[16]) || i==(comp[17]) || i==(comp[18]) )
    	    						{
    		  							
    			  							printf("%d has already been entered, please enter another number\n",i);
    			  							rmn_pos(comp,n);
    			  							scanf("%d",&i);
    		   							  
    								}    
					
				}



		}
	while ((i<1) || (i>18));
						
	printf("You entered %d\n\n",i);
   }
    	  		
    	  						

	return i;
}
																																		

/////////////////////////////////////////////////////////////////////P H A S E -- T W 0/////////////////////////////////
int play_game(int arr[],int pos1,int pos2)
{
	int s;	

//Function that has the game mechanics,if the two cards are equal//
//both of them will get a value of 1,if not equal their value will be 0//

	
	
	s=0;
	while(s!=1|| s!=1)
		{
	 			if((arr[pos2])==(arr[pos1]))
					{	
			  		printf("Match!pick another pair!\n");
			  		s = 1;
			  		
			  		
			  		break;
			  		
			  		}			
	
				else if((arr[pos2])!=(arr[pos1]))
				{	   printf(" %d and %d does not match.......\n",pos2,pos1);

					   
					s = 1;		
				}		
		}

	return s;
} 
																																			


//////////////////////////////////////////////////W I N -- C O N D I T I O N/////
int win_condition(int array[], int n)
{int i;
if(n==8)		//Function responsible for checking if all of the cards are faced up or not.//
	{	
	if (array[8] == TRUE && array[7] == TRUE && array[6]  == TRUE && array[5]  == TRUE && array[4]  == TRUE && array[3]  == TRUE && array[2]  == TRUE && array[1] == TRUE)
		{
		i=TRUE;
		}
	else 
		{
		i=FALSE;
		}
	}
if(n==18)
	{
		if (array[8] == TRUE && array[7] == TRUE && array[6]  == TRUE && array[5]  == TRUE && array[4]  == TRUE && array[3]  == TRUE && array[2]  == TRUE && array[1] == TRUE && array[9] == TRUE && array[10] == TRUE && array[11] == TRUE && array[12] == TRUE && array[13] == TRUE && array[14] == TRUE && array[15] == TRUE && array[16] == TRUE && array[17] == TRUE && array[18] == TRUE)
		{
		i=TRUE;
		}
	else 
		{
		i=FALSE;
		}
	}		
return i;		
}
																																			
///////////////////////////////////////////////////////////C O U N T -- D O W N -- T I M E R /////////////////////////////
void cnt_down()		//A simple countdown timer that will give 5 seconds to the user to see the cards in their proper//
{			//positions.//
 for (int i = 5; i > 0 ; --i)
		 {
    		printf("%d......\n",i);  
				sleep(1);
				
		 }			
}																							

///////////////////////////////////////////////////////////C L E A R -- S C R E E N //////////////////////////////////////
void clr_screen()		//Function that clears the screen.//
				//Prints \n 45 times.//
{
	for(int i =0;i<45;i++)
	{
		printf("\n");
	}
}
////////////////////////////////////////////////////////P R I N T -- R E M A I N I N G -- P O S I T I O N S /////////////////////////
void rmn_pos(int array[],int n)		//Prints remaining positions that the user can assign the cards to//
{	if(n==8)			//I made this so that when it comes to the 18 cards the user will not be having//
		{			//a hard time which place is vacant.//
				for(int i = 1;i<=8;i++)
				{	if(array[i]==0)
					{
					printf("index[%d] is still available.\n",i);
					}
					else if(array[i]!=0)
					{
						printf("\n");
					}	

				}
		}
	else if (n==18)
		{
			for(int i = 1;i<=18;i++)
				{
					if(array[i]==0)
					{
					printf("index[%d] is still available.\n",i);
					}
					else if(array[i]!=0)
					{
						printf("\n");
					}	

				}
		}	printf("\n\n");
}	

////////////////////////////////////////////////////C O M M A N D -- L I N E -- C H E C K E R/////////////////////////////
int cl_chk(int n,int i)
{
	if(i==8)
	{
			if(n<1 && n>8)
     			{
     				return -1;
     			}
	}

	else if(i==18)
	{
		if(n<1 && n>18)
     			{
     				return -1;
     			}
	}
 return n;	
}
/////////////////////////////////// M A I N  -- F U N C T I O N /////////////////////

int main(int argc,char *argv[])
{
	//Declare variables//
	 int blank_card[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	 int blank_card18[19]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	 int placeA[2];//1st character//
	 int placeB[2];//2nd//
	 int placeC[2];//3rd//
	 int placeD[2];//4th//
	 int placeE[2];//5th//
	 int placeF[2];//6th//
	 int placeG[2];//7th//
	 int placeH[2];//8th//
	 int placeI[2];//9th
	 int cards_18[19];
	 int comp18_1[19]={0};	//set up arrays to be used for 18 cards//
	 int comp18_2[19]={0};
	 int cards[9];
     int comp[8]={0};		//set up arrays to be used for 8 cards//
     int comp2[8]={0};
     int n;
     int j;
     int i;
     int w;
     int choice;
     char d;
   
    
     //////////////////////C O M M A N D -- L I N E -- I N T E R F A C E///////////////////////////////////////
     if (argc>1 && argc<10)			//User can open the program and assign the cards positions from the terminal//
     		{
     			n=atoi(argv[1]);
     			n=cl_chk(n,8);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    			
     			cards[n]='A';
		
     			printf("%d is has %c\n",n,cards[n]);
     			n=atoi(argv[2]);
     			n=cl_chk(n,8); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards[n]='A';
			
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[3]);
     			n=cl_chk(n,8); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards[n]='B';
			
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[4]);
     			n=cl_chk(n,8); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards[n]='B';
			
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[5]);
     			n=cl_chk(n,8);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards[n]='C';
			
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[6]);
     			n=cl_chk(n,8);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards[n]='C';
		
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[7]);
     			n=cl_chk(n,8);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards[n]='D';
			
     			printf("%d is has %c\n",n,cards[n]);

     			n=atoi(argv[8]);
     			n=cl_chk(n,8);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards[n]='D';
			
     			printf("%d is has %c\n",n,cards[n]);
     		
     		goto startgame1;
     			
     		}
     else if(argc>1&&argc<20)
     		{
     			n=atoi(argv[1]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    			
     			cards_18[n]='A';
     			printf("%d is has %c\n",n,cards_18[n]);
     			
     			n=atoi(argv[2]);
     			n=cl_chk(n,18); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards_18[n]='A';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[3]);
     			n=cl_chk(n,18); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards_18[n]='B';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[4]);
     			n=cl_chk(n,18); 
     			if(n==-1)
     				{
     					goto maininterface;
     				}   
     			cards_18[n]='B';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[5]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='C';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[6]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='C';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[7]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='D';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[8]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='D';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[9]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='E';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[10]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='E';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[11]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='F';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[12]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='F';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[13]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='G';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[14]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='G';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[15]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='H';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[16]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='H';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[17]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='I';
     			printf("%d is has %c\n",n,cards_18[n]);

     			n=atoi(argv[18]);
     			n=cl_chk(n,18);
     			if(n==-1)
     				{
     					goto maininterface;
     				}    
     			cards_18[n]='I';
     			printf("%d is has %c\n",n,cards_18[n]);

     			goto startgame2;


     		}
     else	
     {

     	goto maininterface;
     }					








     /////////////////////M A I N -- I N T E R F A C E /////////////////////////////////////////

    maininterface: //for the go to loop in the command line interface.//
     choice=welcome();
    	if(choice==TRUE)
 	{	

 printf("Choose number of cards to be played\n");
		
     }			
     		
     		
     	

do
{
     			printf("Enter 8 or 18 ONLY\n");
     			scanf("%d",&choice);

    																						
   switch(choice)
 {
     ////////////////////////////////////////////////////8 -- C A R D S////////////////////////////
     case 8:	
    {
     /////C A R D -- A///////
     	display_pos(choice);
     	printf("\n");
        printf("Where do you want to place A?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp,choice);
		comp[n]=n;
		placeA[n]=n;
		cards[placeA[n]]='A';
		
		printf("   %c is placed on %d\n\n",cards[placeA[n]],n);

		
		
		n=checkrng(j,comp,choice);
		comp[n]=n;
		placeA[n]=n;
		
		cards[placeA[n]]='A';
	
		printf("   %c is placed on %d\n\n",cards[placeA[n]],n);

	
		

	////C A R D --  B///////

		printf("Where do you want to place B?\n\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp,choice);
		comp[n]=n;
		placeB[n]=n;
		cards[placeB[n]]='B';
	
		printf("    %c is placed on %d\n\n",cards[placeB[n]],n);

		

		
		n=checkrng(j,comp,choice);
		comp[n]=n;
		placeB[n]=n;
		cards[placeB[n]]='B';
	
		printf("    %c is placed on %d\n\n",cards[placeB[n]],n);

		
		
	/////CARD -- C////////
		printf("Where do you want to place C?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp,choice);
		comp[n]=n;
		placeC[n]=n;
		cards[placeC[n]]='C';
		
		printf("    %c is placed on %d\n\n",cards[placeC[n]],n);



		
		n=checkrng(j,comp,choice);
		comp[n]=n;
		placeC[n]=n;
		cards[placeC[n]]='C';
	
		printf("    %c is placed on %d\n\n",cards[placeC[n]],n);

		
		
	//////CARD -- D//////
 		printf("Where do you want to place D?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp,choice);
		comp[n]=n;
		placeD[n]=n;
		cards[placeD[n]]='D';
		
		printf("    %c is placed on %d\n\n",cards[placeD[n]],n);

		

	
		n=checkrng(j,comp,choice);
		comp[n]=n;
		placeD[n]=n;
		cards[placeD[n]]='D';
	
		printf("    %c is placed on %d\n\n",cards[placeD[n]],n);

		


	startgame1:
		clr_screen();
		printf("Show the cards one last time!\n");
		display_board(cards,8);
		
		cnt_down();
		clr_screen();
		////////////// P L A Y I N G -- T H E -- G A M E//////////////////////////////////////////
		printf("Start playing!\n");
		display_board(blank_card,8);
		
		w=0;
		
	loop://go to loop declaration//
		while(w!=1)
		{	printf("Enter the position of the two cards you would like to compare.\n");
			printf("Format:1st card -single space- 2nd card\n");
			 scanf("%d %d",&n,&j);
			 n=checkrng(n,comp2,8);
			 comp2[n]=n;
			 j=checkrng(j,comp2,8);
			 comp2[j]=j;
			 i=play_game(cards,n,j);
			 blank_card[n]=cards[n];
			 blank_card[j]=cards[j];
			 display_board(blank_card,8);
			 if((blank_card[n])!=(blank_card[j]))
			 	{  do
			 		{	

			 			printf("Do you want to continue? Enter Y to continue and enter N to exit.\n");
					   scanf(" %c",&d);
					   printf("You have entered %c\n",d);
					   if(d=='y'||d=='Y')
					   {
					   	 comp2[n]=0;
					   	 comp2[j]=0;
					   	blank_card[n]=blank_card[0];
			 			blank_card[j]=blank_card[0];
			 			 
			 			 clr_screen();
			 			display_board(blank_card,8);
					   	goto loop;
					   }
					   else if (d=='n'||d=='N')
					   {
					   	printf("Thanks for playing!\n");
					   	exit(0);
					   	
					   }
					   else{
					   	printf("Please enter the correct character\n");
					   }
					}while(d!='Y'||'y'||'N'||'n');    
			 	}
			 cards[n]=i;
			 cards[j]=i;
			
			
			 w=win_condition(cards,8);
			 
		    
		
		
		}	
		printf("You won!\n");																						
		exit(0);
		break;
	}	
////////////////////////////////////////////////////////////18 -- C A R D S////////////////////////////////////// 	 
 	

 	case 18:
 	{
 		display_pos(choice);
 		  /////C A R D -- A///////
     	printf("\n");
        printf("Where do you want to place A?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeA[n]=n;
		cards_18[placeA[n]]='A';
		printf("   %c is placed on %d\n\n",cards_18[placeA[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeA[n]=n;
		cards_18[placeA[n]]='A';
		printf("   %c is placed on %d\n\n",cards_18[placeA[n]],n);

		
	

	////C A R D --  B///////

		printf("Where do you want to place B?\n\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeB[n]=n;
		cards_18[placeB[n]]='B';
		printf("   %c is placed on %d\n\n",cards_18[placeB[n]],n);
		
		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeB[n]=n;
		cards_18[placeB[n]]='B';
		printf("   %c is placed on %d\n\n",cards_18[placeB[n]],n);

		

	/////CARD -- C////////
		printf("Where do you want to place C?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeC[n]=n;
		cards_18[placeC[n]]='C';
		printf("   %c is placed on %d\n\n",cards_18[placeC[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeC[n]=n;
		cards_18[placeC[n]]='C';
		printf("   %c is placed on %d\n\n",cards_18[placeC[n]],n);

		

	//////CARD -- D//////
 		printf("Where do you want to place D?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeD[n]=n;
		cards_18[placeD[n]]='D';
		printf("   %c is placed on %d\n\n",cards_18[placeD[n]],n);
	
		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeD[n]=n;
		cards_18[placeD[n]]='D';
		printf("   %c is placed on %d\n\n",cards_18[placeD[n]],n);

		

	///////CARD -- E///////////
		printf("Where do you want to place E?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeE[n]=n;
		cards_18[placeE[n]]='E';
		printf("   %c is placed on %d\n\n",cards_18[placeE[n]],n);
	
		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeE[n]=n;
		cards_18[placeE[n]]='E';
		printf("   %c is placed on %d\n\n",cards_18[placeE[n]],n);

		
	
	///////CARD -- F///////////
		printf("Where do you want to place F?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeF[n]=n;
		cards_18[placeF[n]]='F';
		printf("   %c is placed on %d\n\n",cards_18[placeF[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeF[n]=n;
		cards_18[placeF[n]]='F';
		printf("   %c is placed on %d\n\n",cards_18[placeF[n]],n);

	

	///////CARD -- G///////////
	    printf("Where do you want to place G?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeG[n]=n;
		cards_18[placeG[n]]='G';
		printf("   %c is placed on %d\n\n",cards_18[placeG[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeG[n]=n;
		cards_18[placeG[n]]='G';
		printf("   %c is placed on %d\n\n",cards_18[placeG[n]],n);

		

	///////CARD -- H///////////
		printf("Where do you want to place H?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeH[n]=n;
		cards_18[placeH[n]]='H';
		printf("   %c is placed on %d\n\n",cards_18[placeH[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeH[n]=n;
		cards_18[placeH[n]]='H';
		printf("   %c is placed on %d\n\n",cards_18[placeH[n]],n);

		

	///////CARD -- I///////////
	    printf("Where do you want to place I?\n");
		scanf("%d %d",&n,&j);
		n=checkrng(n,comp18_1,choice);
		comp18_1[n]=n;
		placeI[n]=n;
		cards_18[placeI[n]]='I';
		printf("   %c is placed on %d\n\n",cards_18[placeI[n]],n);

		n=checkrng(j,comp18_1,choice);
		comp18_1[n]=n;
		placeI[n]=n;
		cards_18[placeI[n]]='I';
		printf("   %c is placed on %d\n\n",cards_18[placeI[n]],n);

	
		startgame2://go to loop declaration//
		clr_screen();
		printf("Show the cards one last time!\n");
		display_board(cards_18,18);
		cnt_down();
		clr_screen();
			////////////// P L A Y I N G -- T H E -- G A M E(18 -- C A R D S)//////////////////////////////////////////
		printf("Start playing!\n");
		display_board(blank_card18,18);
		
		w=0;
		
	loop2://go to loop declaration//
		while(w!=1)
		{	printf("Enter the position of the two cards you would like to compare.\n");
			printf("Format:1st card -single space- 2nd card\n");
			 scanf("%d %d",&n,&j);
			 n=checkrng(n,comp18_2,18);
			 comp18_2[n]=n;
			 j=checkrng(j,comp18_2,18);
			 comp18_2[j]=j;
			 i=play_game(cards_18,n,j);
			 blank_card18[n]=cards_18[n];
			 blank_card18[j]=cards_18[j];
			 display_board(blank_card18,18);
			 if((blank_card18[n])!=(blank_card18[j]))
			 	{  do
			 		{	

			 			printf("Do you want to continue? Enter Y to continue and enter N to exit.\n");
					   scanf(" %c",&d);
					   printf("You have entered %c\n",d);
					   if(d=='y'||d=='Y')
					   {
					   	 comp18_2[n]=0;
					   	 comp18_2[j]=0;
					   	blank_card18[n]=blank_card18[0];
			 			blank_card18[j]=blank_card18[0];
			 			 
			 			 clr_screen();
			 			display_board(blank_card18,18);
					   	goto loop2;
					   }
					   else if (d=='n'||d=='N')
					   {
					   	printf("Thanks for playing!\n");
					   	exit(0);
					   	
					   }
					   else{
					   	printf("Please enter the correct character\n");
					   }
					}while(d!='Y'||'y'||'N'||'n');    
			 	}
			 cards_18[n]=i;
			 cards_18[j]=i;
			
			
			 w=win_condition(cards_18,18);
			 
		    
			
		
		}	
	printf("You won!\n");																						
		exit(0);
		break;
 	}
  				default:
               printf("invalid input,please enter the correct letter:\n");
  }             
} while (choice!= 8 || 18);
return 0;
}
//////////////////////////////////////////////////////E N D -- O F -- M A I N//////////////////////
