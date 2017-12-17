//2012017850_박창대

#include <stdio.h>

int main(){

    int n = 0;
    scanf("%d",&n);
    int array[n];

    for(int i=0 ; i<n ; i++){
        scanf("%d", &array[i]);
    }


    int i, j, t;
    int cnt;

    for ( i = 1 ; i <n; i ++){
        t = array[i];
        j = i;
        while( array[j-1]< t && j > 0){ 
            array[j] = array[j-1];
            j--;
        }
        array[j] = t ;
    }

    for (cnt = 0; cnt < n; cnt++){
        printf("%d\n",array[cnt]);
    }
    return 0;
}