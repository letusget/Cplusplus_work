#include<stdio.h>

char *segment_one(int digit)
{	
	char a[8];
	int i = 0;
	switch (digit)
	{	
		case 1: 
		{
			
			for ( i = 0; i <7; i++) 
			{
				 a[i]=' ';
			}
				 a[i]='*';
			break;
		}
			  
		case 4: 
		{   a[0]='*';
			for ( i = 1; i < 7; i++) 
			{
				 a[i]=' ';
			}
			 a[i]='*';
			break;
		}
		default:
		{
			for ( i = 0; i <= 7 ; i++) 
			{
				 a[i]='*';
			}
			break;	
		}		
	}
	return a;
}

char ** segment_two(int digit){
	char a[3][8];
	int i = 0;
	int j = 0;
	switch (digit)
	{	
		case 1:
		case 2:
		case 3:
		case 7: {
			for ( i = 0; i < 3; i++) {
				for ( j = 0; j <7; j++) {
					a[i][j]=' ';
				}
				a[i][j]='*';
			}break;
		}			  
		case 4:
		case 5:
		case 6:{
			for ( i = 0; i < 3; i++) {
				j=0;
				a[i][j]='*';
				for (j = 1; j <7; j++) {
					a[i][j]=' ';
				}
				
			}break;
		}		  
		case 0:
		case 8: 
		case 9:{
			for ( i = 0; i < 3; i++) {
				j=0;
				a[i][j]='*';
				for ( j = 1; j <6; j++) {
					a[i][j]=' ';
				}
				a[i][j]='*';
			}break;
		}	  
	}
	return a;
} 

void *segment_three(int digit){
	char a[8];
	int i=0;
	switch(digit){
		case 1:
		case 7:
		{	
			for( i=0;i<7;i++)
				{
					 a[i]=' ';
				}
			 a[i]='*';			
			break;
		}
		
		case 0:	
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 8:	{
			for( i=0;i<8;i++)
			{
				 a[i]='*';	
			}
			break;
		}
	}
	return a;
}
void **segment_four(int digit){
	char a[3][8];
	int i = 0; 
	int j = 1; 
	switch(digit)
	{	
		case 0:
		case 6:
		case 8:
		{
			
			for ( i = 0; i < 3; i++) {
				j=0;
				a[i][j]='*';
				for ( j = 1; j <6; j++) {
					a[i][j]=' ';
				}
				a[i][j]='*';
			}break;
		}
		
		case 1:
		case 3:
		case 4:
		case 5:
		case 7:
		case 9:{
			for ( i = 0; i < 3; i++) {
				for ( j = 0; j <7; j++) {
					a[i][j]=' ';
				}
				a[i][j]='*';
			}break;
		}
			
		case 2:{
			int i = 0;
			int j = 0;
			for ( i = 0; i < 3; i++) {
				j=0;
				a[i][j]='*';
				for (j = 1; j <7; j++) {
					a[i][j]=' ';
				}
				
			}break;
		}

	}
	return a;
}
void *segment_five(int digit){
	char a[8];
	int i=0,j=0;
	switch(digit){
		case 0:
		case 2:
		case 3:
		case 5:
		case 6:
		case 8:{
			for(i=0;i<7;i++){
				a[i]='*';
			}
			break;
		}
			
		
		case 1:
		case 4:
		case 7:
		case 9:{
			for(i=0;i<6;i++){
				a[i]=' ';
			}
			a[i]='*';
			break;
		}
	}
	return a;
}

int main(){
	int a,b;
	int i=0,j=0;
	char *c1,*c3,*c5;
	char *c11,*c33,*c55;
	char /***c2,*/**c4;
	char /***c22,*/**c44;
	int n;
	printf("请输入一个10-90数：") ;
	scanf("%d",&n);
	a=n/10;
	b=n%10;
	c1=segment_one(a);
	for(i=0;i<8;i++)
	printf("%c",c1[i]);
	printf(" ");
	c11=segment_one(b);	
	for(i=0;i<8;i++)
	printf("%c",c11[i]);
	printf("\n");
	
//	c2=segment_two(a);
//	for(i=0;i<=2;i++)
//	for(j=0;j<=7;j++)
//		printf("%c",c2[i][j]);
//	printf(" ");
//	c22=segment_two(b);
//	for(i=0;i<=2;i++)
//	for(j=0;j<=7;j++)
//		printf("%c",c22[i][j]);
//	printf("\n");
		
	c3=segment_three(a);
	for(i=0;i<8;i++)
		printf("%c",c3[i]);
	printf(" ");
	c33=segment_three(b);
	for(i=0;i<8;i++)
		printf("%c",c33[i]);
	printf("\n");

	c4=segment_four(a);
	for(i=0;i<=2;i++)
	for(j=0;j<=7;j++)
	printf("%c",c4[i][j]);
	printf(" ");
	c44=segment_four(b);
	for(i=0;i<=2;i++)
	for(j=0;j<=7;j++)
		printf("%c",c44[i][j]);
	printf("\n");

	c5=segment_five(a);
	for(i=0;i<8;i++)
	printf("%c",c5[i]);
	printf(" ");
	c55=segment_five(b);
	for(i=0;i<8;i++)
	printf("%c",c55[i]);
	printf("\n");
	



//		


	
}
