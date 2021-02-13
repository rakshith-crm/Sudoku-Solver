#include <stdio.h>
void solvefor(int g,int r[50][9],int A[9][9],int sum9[9])
{
        int i,j,z,k,a,sum=0;
        int abc2[9][10]={0};
        int S2[18]={0},copy[9][9];
//S2 holds number of possibilities for a cell
//abc2 holds all the possibilities for a cell
        for(a=0;a<9;a++)
        {
                for(i=0;i<9;i++)
                {
                        copy[a][i]=A[a][i];
                }
        }
                        for(i=0;i<9;i++)
                        {
                                if(A[g][i]==0)
                                {
                                        int B[10]={0,1,2,3,4,5,6,7,8,9};
                                        for(j=0;j<9;j++)
                                        {
                                                if(j!=i)
                                                {
                                                        B[A[g][j]]=0;
                                                }
                                        }
                                        for(j=0;j<9;j++)
                                        {
                                                if(j!=g)
                                                {
                                                        B[A[j][i]]=0;
                                                }

                                        }
                                        int row,col;
                                        if(g>=0&&g<=2)
                                        {
                                                row=0;
                                        }
                                        else if(g>=3&&g<=5)
                                        {
                                                row=3;
                                        }
                                        else if(g>=6&&g<=8)
                                        {
                                                row=6;
                                        }
                                        if(i>=0&&i<=2)
                                        {
                                                col=0;
                                        }
                                        else if(i>=3&&i<=5)
                                        {
                                                col=3;
                                        }
                                        else if(i>=6&&i<=8)
                                        {
                                                col=6;
                                        }
                                        for(z=row;z<row+3;z++)
                                        {
                                                for(j=col;j<col+3;j++)
                                                {
                                                        B[A[z][j]]=0;
                                                }
                                        }
                                        int C[10]={0},count=0;
                                        for(j=0;j<10;j++)
                                        {
                                                if(B[j]!=0)
                                                {
                                                        C[count]=B[j];
                                                        count++;
                                                }
                                        }
                                        for(j=0;j<10;j++)
                                        {
                                                abc2[i][j]=C[j];
                                        }
                                        S2[i]=count;
                                }
                        }
//REPLACING ALL CELL POSSIBILITIES WHICH ARE ZERO WITH COPY VALUES
        for(i=0;i<9;i++)
        {
                if(S2[i]==0)
                {
                        S2[i]=1;
                        abc2[i][0]=A[g][i];
                }
        }
//CHECKING ALL ROW POSSIBILITIES
        int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
        for(a1=0;a1<S2[0];a1++){
        for(a2=0;a2<S2[1];a2++){
        for(a3=0;a3<S2[2];a3++){
        for(a4=0;a4<S2[3];a4++){
        for(a5=0;a5<S2[4];a5++){
        for(a6=0;a6<S2[5];a6++){
        for(a7=0;a7<S2[6];a7++){
        for(a8=0;a8<S2[7];a8++){
        for(a9=0;a9<S2[8];a9++){
                {
                        A[g][0]=abc2[0][a1];
                        A[g][1]=abc2[1][a2];
                        A[g][2]=abc2[2][a3];
                        A[g][3]=abc2[3][a4];
                        A[g][4]=abc2[4][a5];
                        A[g][5]=abc2[5][a6];
                        A[g][6]=abc2[6][a7];
                        A[g][7]=abc2[7][a8];
                        A[g][8]=abc2[8][a9];
//Replacing '0's with copy values
                        for(i=0;i<9;i++)
                        {
                                if(A[g][i]==0)
                                {
                                        A[g][i]=copy[g][i];
                                }
                        }
                int flag=0;
//Checking duplicates in the row
                for(a=0;a<9;a++)
                {
                        for(i=0;i<9;i++)
                        {
                                if(i!=a)
                                {
                                        if(A[g][i]==A[g][a])
                                        {
                                                flag=1;
                                        }
                                }
                        }
                }
//ADDING ROWS THAT COULD BE A POSSIBLE ANSWER TO THE PUZZLE
                if(flag==0)
                {
                        for(a=0;a<9;a++)
                        {
                                r[sum][a]=A[g][a];//define 'row' here
                        }
                        sum++;

                }
        }}}}}}}}}}
        sum9[g]=sum;
        for(a=0;a<9;a++)
        {
                for(i=0;i<9;i++)
                {
                        A[a][i]=copy[a][i];
                }
        }
	printf("No. of Possibilities for row %d is %d\n",g+1,sum);
}


