/**
 * 8_queens.c
 * Copyright (C) 2021 Zenon Xiu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define NUM (8)  //number of queens, can be changed to other numbers


void print_martix(int M[NUM][NUM])
{
 int i, j;
 for(i=0;i<NUM;i++)
   {
    for(j=0;j<NUM;j++)
       printf("%2d ", M[i][j]);

    printf("\n");	 
   }	

  printf("*********************\n");	 
}


void copy_martix(int * p_src, int * p_dst)
{
 int i, j;
 for(i=0;i<NUM;i++)
   {
     for(j=0;j<NUM;j++)
	*(p_dst+NUM*i+j)=*(p_src+NUM*i+j);
   }	
}


void go_through(int M[NUM][NUM], int line)
{
  int M1[NUM][NUM];
  int i,j,k, m,n;

  if(line>=NUM)   //run out of lines?
	 return ;

  for(i=0;i<NUM;i++)
  {	
   if(M[line][i]==TRUE)
   {
     if(line==NUM-1)   //if reachs to the last line, and there is a TRUE 
       {
	//printf("found one match\n");
	 print_martix(M);
	 continue;
	}
     else
	 {
	 copy_martix(&M[0][0],&M1[0][0]);  //copy M to M1

	 /*begining of setting other elemetns of cross lines to false */

	 for(j=0;j<NUM;j++)    //set the row false
	   {
	    if(j!=i)
	      M1[line][j]=FALSE;
	  }
	 for(j=0;j<NUM;j++)    //set the column to false
	  {
	    if(j!=line)
	      M1[j][i]=FALSE;
	  }

         m=i+1;  //set top_right elements to false
	 n=line-1;
	 while(n>=0&&m<NUM) 
	   {
	     M1[n][m]=FALSE;
	     n=n-1;
	     m=m+1;
	   }

         m=i-1;   //set top_left elements to false
	 n=line-1;
	 while(n>=0&&m>=0) //set top_right elements to false
	   {
	    M1[n][m]=FALSE;
	    n=n-1;
	    m=m-1;
	   }

	 m=i-1;   //set bottom_left false
	 n=line+1;
	 while(n<NUM&&m>=0) //set top_right false
	   {
	     M1[n][m]=FALSE;
	     n=n+1;
	     m=m-1;
	   }	 

	 m=i+1;   //set bottom_right false
	 n=line+1;
	 while(n<NUM&&m<NUM) //set top_right false
	   {
	     M1[n][m]=FALSE;
	     n=n+1;
	     m=m+1;
	   }	 	 
	
	/* end of setting other elemetns of cross lines to false */	 
	
	line++;	 //move to next line

	go_through(M1,line); //run throgh possibility of next line

	line--; //move back to current line

	 }
		
   }	   
  }
}

int main()
{
 int Matrix[NUM][NUM];	
 int i, j;
 for(i=0;i<NUM;i++)
   {
     for(j=0;j<NUM;j++)
	Matrix[i][j]=TRUE; 
  }	
 go_through(Matrix,0);
 return 0;
}
