//2012017850_박창대
#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int main(){

    int n,m,i,j,least,temp;
    scanf("%d %d",&n,&m);

    int array[n];

    for(int i=0 ; i<n ; i++){
        scanf("%d", &array[i]);
    }

    for(i=0;i<m;i++){
        least = i;
        for(j=i+1;j<n;j++){
            if(array[j]<array[least])
                least=j;
        }
        SWAP(array[i],array[least],temp);
    }

    for(i=0;i<n;i++){
        printf("%d\n",array[i]);
    }


    return 0;
}