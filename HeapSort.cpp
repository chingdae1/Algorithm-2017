//2012017850_박창대
#include <stdio.h>
void max_heapify(int arr[], int currentIdx, int arraySize);
void swap(int *a, int *b);
void build_max_heap(int arr[], int lastIdx);
void heap_sort(int arr[], int arraySize);
int main() {
    int arr[100001];
    int N, k;
    int i;
    scanf("%d %d", &N, &k);

    for(i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }

    heap_sort(arr, N);

    for(i=N; i>N-k; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(i=N-k; i>0; i--){
        printf("%d ", arr[i]);
    }
    return 0;
}
void max_heapify(int arr[], int currentIdx, int arraySize)
{
    int left, right, largestIdx;

    left = currentIdx * 2;
    right = left + 1;
    if(left <= arraySize && arr[currentIdx] < arr[left]){
        largestIdx = left;
    }
    else{
        largestIdx = currentIdx;
    }
    if(right <= arraySize && arr[largestIdx] < arr[right]){
        largestIdx = right;
    }
    if(largestIdx != currentIdx){
        swap(&arr[largestIdx], &arr[currentIdx]);
        max_heapify(arr, largestIdx, arraySize);
    }
}

void build_max_heap(int arr[], int lastIdx)
{
    int i;
    for(i=lastIdx/2; i>0; i--){
        max_heapify(arr, i, lastIdx);
    }
}

void heap_sort(int arr[], int arraySize)
{
    int i;
    build_max_heap(arr, arraySize);
    for(i=arraySize; i>0; i--){
        swap(&arr[1], &arr[i]);
        max_heapify(arr, 1, i-1);
    }
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}