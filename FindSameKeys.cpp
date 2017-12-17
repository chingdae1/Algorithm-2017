//2012017850_박창대
#include <stdio.h>

int main(){

    int n=0;
    int m=0;
    int max = 100000;
    int count=0;



    scanf("%d %d",&n,&m);

    int A[n];
    int B[m];
    int C[100000];
    for (int i = 0; i< max; i++){
        C[i] =0;
    }

    for(int i =0 ; i< n ; i++){
        scanf("%d", &A[i]);
        //숫자 등장 횟수 세기
        C[A[i]]++;
    }
    for(int i =0 ; i< m ; i++) {
        scanf("%d", &B[i]);
        //숫자 등장 횟수 세기
        if(C[B[i]]!=0){
            count++;
        }
    }


    printf("%d",count);

        return 0 ;
}