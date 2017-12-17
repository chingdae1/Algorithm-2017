//2012017850_박창대
#include <stdio.h>
#include <limits.h>
 
int m[101][101];
int s[101][101];
int size;

void printph(int p, int q){


    if(p==q){
        printf("%d ",p);
        return;
    }
    else if(q-p ==1){
        printf("( ");
        printf("%d ",p);
        printf("%d ",q);
        printf(") ");
        return;
    }

    int mid = s[p][q];
    
    printf("( ");
    
    printph(p,mid);
    printph(mid+1,q);   

    printf(") "); 

}

void MatrixChainOrder(int p[], int n)
{
 
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (i=1; i<n; i++)
        s[i][i] = 0; 
 
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }


    printf("%d\n",m[1][n-1]);

    printph(1,n-1);
      
}

 
int main()
{
    scanf("%d",&size);
    int arr[size+1];

    for(int i = 0; i<size+1; i++){
        scanf("%d",&arr[i]);
    }
    
    MatrixChainOrder(arr,size+1);


    return 0;
}
