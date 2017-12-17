//2012017850_박창대
#include <stdio.h>

void print_sol(int p[],int s[], int n){
    int temp = n;
    while(true){

    printf("%d ",s[temp]);
    if (temp == s[temp]) break;
    else temp = temp- s[temp];

    }

}

void rodcut(int p[], int r[], int s[],int n){
    int q;
    r[0]= 0;

    for (int j =1 ; j<=n ; j++){
        q = -99999;
        for (int i = 1; i <=j ; i ++){
            if(q<p[i]+r[j-i]){
                q = p[i] + r[j-i];
                s[j]=i;
            }
        r[j]= q;
        }
    }

    printf("%d\n",r[n]);

    print_sol(p,s,n);
}




int main(){

    int n;

    scanf("%d",&n);

    int price[n+1];
    int r[n+1];
    int s[n+1];

    for (int i =1 ;i<=n ; i++){
        scanf("%d",&price[i]);
    }


    // int n = 10;

    // int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    // int r[n+1];
    // int s[n+1];

    rodcut(price,r,s,n);

    return 0 ;
}





