/*
 * minesweeper.c
 *
 *  Created on: 24-Oct-2018
 *      Author: Dell
 */
#include<stdio.h>
#include<stdlib.h>

void rand_mines(char msweep[6][6]);
void printmine(char msweep[6][6],int r,char userboard[6][6]);
int process(char msweep[6][6],int r,int c,char userboard[6][6]);

int main()
{
setbuf(stdout, NULL);
char msweep[6][6] = {{'0'}};
int i,r,c;
char userboard[6][6] = {{'0'}};
rand_mines(msweep);
printmine(msweep,6,userboard);
printf("Enter location(ONLY 1 - 5) on the mine field (row, column)\n");
  scanf("%d%d",&r,&c);
i = process(msweep,r,c,userboard);
 while(i == 1)
   {
 printf(" %c Surrounding MINES\n\n",msweep[r][c]);
printmine(msweep,6,userboard);
printf("enter next location...(ONLY 1 - 5) ");
     scanf("%d%d",&r,&c);
     i=0;
i = process(msweep,r,c,userboard);
 }
if(i==0)
  { printf("GAME OVER \n");
  int i,j;
  for(i=1;i<6;i++)
    {
	  for(j=1;j<6;j++)
      {
       printf(" |%c| ",msweep[i][j]);
      }
     printf("\n\n");
 	}
  }
return 0;
}
void rand_mines(char msweep[6][6])
{
int r,c,m;
for(m=0;m<15;m++)
{
 r = rand() % 6;
c = rand() % 6;
msweep[r][c] = '*';
 // printf("%d %d \n",r,c); /*check or cheat*/
 }
return;
}
void printmine(char msweep[6][6],int r,char userboard[6][6])
{
int i,j;
for(i=1;i<r;i++)
  {
 for(j=1;j<6;j++)
    {
     printf(" |%c| ",userboard[i][j]);
    }
 printf("\n\n");
  }
return;
}
int process(char msweep[6][6],int r,int c,char user_chart[6][6])
{
int i=r,j=c,b=0,k;
 char C;
if(msweep[r][c] == '*')
 {  k=0;
   return k;
 }
 else
  {
   if(msweep[i-1][j-1] == '*')
    b++;
   if(msweep[i-1][j] == '*')
    b++;
   if(msweep[i-1][j+1] == '*')
    b++;
   if(msweep[i][j-1] == '*')
    b++;
   if(msweep[i][j+1] == '*')
    b++;
   if(msweep[i+1][j-1] == '*')
    b++;
   if(msweep[i+1][j] == '*')
    b++;
   if(msweep[i+1][j+1] == '*')
    b++;
C = (char)(((int)'0')+b);
 msweep[r][c] = C;
 user_chart[r][c] = C;
  }
return 1;
}
