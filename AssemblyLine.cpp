//2012017850_박창대
#include <stdio.h>

int main()
{
    int n;
    int le,fe;
    int i;
    scanf("%d",&n);
    int e[2];
    int x[2];
    int j;
    scanf("%d %d",&e[0],&e[1]);
    scanf("%d %d",&x[0],&x[1]);

    int a[2][n];
    int t[2][n-1];

    for(i = 0; i < n; i++){
        scanf("%d",&a[0][i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d",&a[1][i]);
    }
    for(i = 0; i < n-1; i++){
        scanf("%d",&t[0][i]);
    }
    for(i = 0; i < n-1; i++){
        scanf("%d",&t[1][i]);
    }


    int f1[n];
    int f2[n];
    int l[2][n];

    f1[0] = e[0] + a[0][0];

    f2[0] = e[1] + a[1][0];

    for(j = 1; j<n; ++j)
    {
        if( (f1[j-1]+a[0][j]) <= (f2[j-1]+t[1][j-1]+a[0][j]) )
        {
        f1[j] = f1[j-1] + a[0][j];
        l[0][j] = 1;
        }
        else
        {
        f1[j] = f2[j-1] + t[1][j-1] + a[0][j];
        l[0][j] = 2;
        }
        if( (f2[j-1]+a[1][j]) <= (f1[j-1]+t[0][j-1]+a[1][j]) )
        {
        f2[j] = f2[j-1] + a[1][j];
        l[1][j] = 2;
        }
        else
        {
        f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
        l[1][j] = 1;
        }
    }

    if( (f1[n-1] + x[0]) <= (f2[n-1] + x[1]) )
    {
    fe = f1[n-1] + x[0];
    le = 1;
    }
    else
    {
     fe = f2[n-1] + x[1];
     le = 2;
    }


    printf("%d\n",fe);

    int output[n];
    output[n-1]= le;

    for(i = n-1; i>0; i--){
        output[i-1]= l[output[i]-1][i];
    }

    for (int cnt = 0;cnt <n ; cnt ++){
        printf("%d %d\n",output[cnt],cnt+1);
    }


return 0;
}