//2012017850_박창대
#include <stdio.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int N;
    int arr[100000];
    int i;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, N-1);

    for(i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
void merge_sort(int arr[], int left, int right)
{
    int mid;

    if(left < right){
        mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k, m;
    int tmp[100000];

    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right){
        if(arr[i] > arr[j]){
            tmp[k] = arr[i];
            i++;
        }
        else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        while(j <= right){
            tmp[k] = arr[j];
            k++;
            j++;
        }
    }
    else{
        while(i <= mid){
            tmp[k] = arr[i];
            k++;
            i++;
        }
    }

    for(m=left; m<=right; m++){
        arr[m] = tmp[m];
    }
}