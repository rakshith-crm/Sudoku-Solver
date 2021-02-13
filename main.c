#include <stdio.h>
#include <stdlib.h>
#include "row_function.h"

void main()
{
int A[9][9];//={{5,0,7,6,9,0,0,0,2},{9,3,0,0,0,2,7,4,5},{0,0,0,3,0,7,1,0,0},{0,4,5,0,6,0,3,0,8},{2,0,0,4,0,0,0,0,0},{0,0,0,0,8,1,0,2,0},{0,0,9,0,2,0,0,1,3},{3,0,0,0,0,6,0,5,7},{7,0,0,1,3,0,9,8,4}};
int r1[50][9]={0},r2[50][9]={0},r3[50][9]={0},r4[50][9]={0},r5[50][9]={0},r6[50][9]={0},r7[50][9]={0},r8[50][9]={0},r9[50][9]={0};
int sum9[9]={0},flagcheck=0;
int a1,a2,a3,a4,a5,a6,a7,a8,a9,i,j,a,n;
        printf("\t    1   2   3   4   5   6   7   8   9\n");
        for(i=0;i<9;i++)
        {
        printf("\t  +---+---+---+---+---+---+---+---+---+\n\t%d ",i+1);
                for(j=0;j<9;j++)
                {
                        printf("|   ");
                }
        printf("|\n");
        }
        printf("\t  +---+---+---+---+---+---+---+---+---+\n");
        int b,c,t;
int inputtype;
	printf("How would you like to give inputs for your sudoku question?\n");
	printf("Row-wise or using its position\n");
	printf("Enter '1' for Row-wise and '2' for using it's position\n");
	scanf("%d",&inputtype);
        for(i=0;i<9;i++)
        {
             for(j=0;j<9;j++)
             {
                   A[i][j]=0;
	     }
     	}
	if(inputtype==2)
	{

	        do
        	{
        	        printf("Enter or Modify your Puzzle Values:\n");
               	        printf("Enter number and it's position((Row,Column)(Format))( Position is given above)\n");
                       	scanf("%d %d %d",&a,&b,&c);
                        A[b-1][c-1]=a;
//                	printf("Is this your Sudoku Puzzle('0' Indicates no number)\n");
                        printf("\t    1   2   3   4   5   6   7   8   9\n");
                        for(i=0;i<9;i++)
                        {
                                 printf("\t  +---+---+---+---+---+---+---+---+---+\n\t%d ",i+1);
                                for(j=0;j<9;j++)
                                {
                                        printf("| %d ",A[i][j]);
                                }
                        printf("|\n");
                        }
                        printf("\t  +---+---+---+---+---+---+---+---+---+\n");

        	        printf("Enter '111' if sudoku question is correct and all inputs are correctly given\n");
	                scanf("%d",&a);

	        }while(a!=111);
	}
	else
	{
		printf("Enter row-wise and denote empty spaces with '0'\n");
		do
		{
			for(i=0;i<9;i++)
			{
				printf("Enter values for Row %d\n",i+1);
				for(j=0;j<9;j++)
				{
					scanf("%d",&A[i][j]);
				}
			}
		        	printf("\t    1   2   3   4   5   6   7   8   9\n");
                        	for(i=0;i<9;i++)
                        	{
                                	 printf("\t  +---+---+---+---+---+---+---+---+---+\n\t%d ",i+1);
                                	for(j=0;j<9;j++)
                                	{
                                        	printf("| %d ",A[i][j]);
                                	}
                        	printf("|\n");
                        	}
                        	printf("\t  +---+---+---+---+---+---+---+---+---+\n");
		 printf("Enter '111' if sudoku question is correct and all inputs are correctly given\n");
	         scanf("%d",&a);
		}while(a!=111);

	}


	printf("Sudoku to solve is\n");
			printf("\t    1   2   3   4   5   6   7   8   9\n");
	                for(i=0;i<9;i++)
        	        {
                	        printf("\t  +---+---+---+---+---+---+---+---+---+\n\t%d ",i+1);
                        	for(j=0;j<9;j++)
	                        {
        	                        printf("| %d ",A[i][j]);
                	        }
                        	printf("|\n");
         	       }
                	printf("\t  +---+---+---+---+---+---+---+---+---+\n");

			printf("\n");

        solvefor(0,r1,A,sum9);
        solvefor(1,r2,A,sum9);
        solvefor(2,r3,A,sum9);
        solvefor(3,r4,A,sum9);
        solvefor(4,r5,A,sum9);
        solvefor(5,r6,A,sum9);
        solvefor(6,r7,A,sum9);
        solvefor(7,r8,A,sum9);
        solvefor(8,r9,A,sum9);
	long long int possible=1;
	for(i=0;i<9;i++)
	{
		possible*=sum9[i];
	}
	printf("Total Possibilities to check = %lld\nPlease Wait...\n",possible);
possible=0;
sleep(4);
//THE FOLLOWING LOOP IS USED TO SOLVE THE SUDOKU USING THE POSSIBLE ROWS
        for(a1=0;a1<sum9[0];a1++){
        for(a2=0;a2<sum9[1];a2++){
        for(a3=0;a3<sum9[2];a3++){
        for(a4=0;a4<sum9[3];a4++){
        for(a5=0;a5<sum9[4];a5++){
        for(a6=0;a6<sum9[5];a6++){
        for(a7=0;a7<sum9[6];a7++){
        for(a8=0;a8<sum9[7];a8++){
        for(a9=0;a9<sum9[8];a9++){
	possible++;
	printf("Checking %d Possiblity\n",possible);
                for(a=0;a<9;a++)
                {
                        A[0][a]=r1[a1][a];
                }
                for(a=0;a<9;a++)
                {
                        A[1][a]=r2[a2][a];
                }
                for(a=0;a<9;a++)
                {
                        A[2][a]=r3[a3][a];
                }
                for(a=0;a<9;a++)
                {
                        A[3][a]=r4[a4][a];
                }
                for(a=0;a<9;a++)
                {
                        A[4][a]=r5[a5][a];
                }
                for(a=0;a<9;a++)
                {
                        A[5][a]=r6[a6][a];
                }
                for(a=0;a<9;a++)
                {
                        A[6][a]=r7[a7][a];
                }
                for(a=0;a<9;a++)
                {
                        A[7][a]=r8[a8][a];
                }
                for(a=0;a<9;a++)
                {
                        A[8][a]=r9[a9][a];
                }
                int summ1=0,summ2=0,summ3=0,summ4=0,summ5=0,summ6=0,summ7=0,summ8=0,summ9=0;
//CHECKING COLUMN SUM
		for(a=0;a<9;a++)
		{
			summ1+=A[a][0];
		}
		for(a=0;a<9;a++)
		{
			summ2+=A[a][1];
		}
		for(a=0;a<9;a++)
		{
			summ3+=A[a][2];
		}
		for(a=0;a<9;a++)
		{
			summ4+=A[a][3];
		}
		for(a=0;a<9;a++)
		{
			summ5+=A[a][4];
		}
		for(a=0;a<9;a++)
		{
			summ6+=A[a][5];
		}
		for(a=0;a<9;a++)
		{
			summ7+=A[a][6];
		}
		for(a=0;a<9;a++)
		{
			summ8+=A[a][7];
		}
		for(a=0;a<9;a++)
		{
			summ9+=A[a][8];
		}
                if(summ1==45&&summ2==45&&summ3==45&&summ4==45&&summ5==45&&summ6==45&&summ7==45&&summ8==45&&summ9==45)
		{
			flagcheck=1;
                        goto g;
		}
}}}}}}}}}
g:              if(flagcheck==1)
		{
			printf("\t    1   2   3   4   5   6   7   8   9\n");
	                for(i=0;i<9;i++)
        	        {
                	        printf("\t  +---+---+---+---+---+---+---+---+---+\n\t%d ",i+1);
                        	for(j=0;j<9;j++)
	                        {
        	                        printf("| %d ",A[i][j]);
                	        }
                        	printf("|\n");
         	       }
                	printf("\t  +---+---+---+---+---+---+---+---+---+\n");

			printf("\n");
		}
		else printf("No solution\n");



}




