//2012017850_박창대
#include <stdio.h>
#include <string.h>
int i,j,m,n,c[501][501];
char x[500],y[500],b[501][501];
void print_lcs(int i,int j)
{ 							
  if(i==0 || j==0)
                  return;
  if(b[i][j]=='c')
  {
    print_lcs(i-1,j-1);
    printf("%c",x[i-1]);
  }
  else if(b[i][j]=='u')
    print_lcs(i-1,j);
  else
    print_lcs(i,j-1);
}
void lcs_length(char x1[],char y1[],int m1,int n1)
{
  for(i=0;i<=m1;i++)
    c[i][0]=0;
  for(i=0;i<=n1;i++)
    c[0][i]=0;
  for(i=1;i<=m1;i++)
  for(j=1;j<=n1;j++)
  {
    if(x1[i-1]==y1[j-1])
    {
      c[i][j]=c[i-1][j-1]+1;
      b[i][j]='c';
    }
    else if(c[i-1][j]>=c[i][j-1])
    {
      c[i][j]=c[i-1][j];
      b[i][j]='u';
    }
    else
    {
      c[i][j]=c[i][j-1];
      b[i][j]='l';
    }
  }
   print_lcs(m1,n1);
}
int main()
{
  scanf("%s",x);
  scanf("%s",y);
 	
 	m = strlen(x);
 	n = strlen(y);

 	if( m>=n){
 		lcs_length(x,y,m,n);
 	}
 	else{
 		lcs_length(y,x,n,m);
 	}

	for (i=0; i<20; i++){
		for(j=0;j<20;j++){
			printf("b[%d][%d] : %d",i,j,c[i][j]);
		}
	}

	for (i=0; i<20; i++){
		for(j=0;j<20;j++){
			printf("c[%d][%d] : %d",i,j,c[i][j]);
		}
	}

  return 0;
}
