//2012017850_박창대
#include <stdio.h>

int main() {

    
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k); //n =5 m = 100 k =3
    int a[k];
    int b[k];
    int i,j;
    int values[n];
    int count=0;

    for (i = 0; i < k; i++) {
        scanf("%d %d",&a[i],&b[i]);
    }

    for (i = 0;i<n;i++){
        scanf("%d",&values[i]);
    }

    for(i=0;i<k;i++){
        for(j=0;j<n;j++){
            if(values[j]>=a[i]&&values[j]<=b[i]){
                count++;
            }
        }
        printf("%d\n",count);
        count=0;
    }




    return 0;
}