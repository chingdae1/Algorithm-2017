//2012017850_박창대
#include <stdio.h>
#define MAX 100000
int n = 0;
int out_index = 0;
void enqueue(int *heap, int input);
int dequeue(int *heap);
void changeKey(int *heap, int index, int input);
void heapify_Down(int *heap, int i);
void heapify_Up(int *heap, int i);
void print_out(int *heap, int *out);
void swap(int *a1, int *a2);
int main(void)
{
    int key, input, index;
    int heap[MAX];
    int out[MAX];
    while (1)
    {
        scanf("%d", &key);
        switch (key)
        {
            case 1:
                scanf("%d", &input);
                enqueue(heap, input);
                break;
            case 2:
                out[out_index] = dequeue(heap);
                out_index++;
                break;
            case 3:
                scanf("%d", &index);
                scanf("%d", &input);
                changeKey(heap, index, input);
                break;
            case 0:
                print_out(heap, out);
                return 0;
        }
    }
}
void enqueue(int *heap, int input)
{
    int i;
    i = ++n;
    while ((i != 1) && input>heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = input;
}
int dequeue(int *heap)
{
    int parent, child;
    int output, temp;
    output = heap[1];
    swap(&heap[1], &heap[n--]);
    heapify_Down(heap, 1);
    return output;
}
void heapify_Up(int *heap, int child)
{
    int parent = child / 2;
    while ((child != 1) && heap[child]>heap[parent])
    {
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent /= 2;
    }
}

void heapify_Down(int *heap, int parent)
{
    int child, large;
    while (parent <= n / 2)
    {
        child = parent * 2;
        if (n >= child + 1)
        {
            if (heap[child + 1] >= heap[child])
                large = child + 1;
            else
                large = child;
        }
        else
        {
            large = child;
        }
        if (heap[parent]<heap[large])
        {
            swap(&heap[parent], &heap[large]);
            parent = large;
        }
        else
            break;
    }
}
void print_out(int *heap, int *out)
{
    int i = n;
    int j = out_index;
    for (i = 0; i<out_index; i++)
        printf("%d ", out[i]);
    printf("\n");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);
}
void changeKey(int *heap, int index, int input)
{
    int i = 0;
    if (heap[index]>input){
        heap[index] = input;
        heapify_Down(heap, index);
    }
    else if (heap[index]<input){
        heap[index] = input;
        heapify_Up(heap, index);
    }
    else
        heap[index] = input;
}
void swap(int *a1, int *a2)
{
    int temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
