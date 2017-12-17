//2012017850_박창대
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define isLeaf(root) (!(root->left) && !(root->right))
#define isSizeOne(minimum_heap) (minimum_heap->size == 1)
#define MAX_NUMBER_OF_CHAR 30000
void swapminimum_heapNode(struct minimum_heapNode** a, struct minimum_heapNode** b);
void minimum_heapify(struct minimum_heap* minimum_heap, int idx);
void insertminimum_heap(struct minimum_heap* minimum_heap, struct minimum_heapNode* minimum_heapNode);
void buildminimum_heap(struct minimum_heap* minimum_heap);
void printAnswer(struct minimum_heapNode* root, int arr[], int top);
void HuffmanCodes(char data[], int freq[], int size);

int frequencyList[MAX_NUMBER_OF_CHAR];
char characterList[MAX_NUMBER_OF_CHAR]; 
int huff_sum = 0;
int num_char;

struct minimum_heapNode{
   char data;
   int freq;
   struct minimum_heapNode *left, *right;
};

struct minimum_heap{
   int size;
   int capacity;
   struct minimum_heapNode **array;
};

struct minimum_heapNode* newNode(char data, int freq){
   struct minimum_heapNode* temp =
   (struct minimum_heapNode*) malloc(sizeof(struct minimum_heapNode));
   temp->left = temp->right = NULL;
   temp->data = data;
   temp->freq = freq;
   return temp;
}

struct minimum_heap* createminimum_heap(int capacity){
   struct minimum_heap* minimum_heap =
   (struct minimum_heap*) malloc(sizeof(struct minimum_heap));
   minimum_heap->size = 0;
   minimum_heap->capacity = capacity;
   minimum_heap->array =
   (struct minimum_heapNode**)malloc(minimum_heap->capacity * sizeof(struct minimum_heapNode*));
   return minimum_heap;
}

struct minimum_heapNode* extractMin(struct minimum_heap* minimum_heap){
   struct minimum_heapNode* temp = minimum_heap->array[0];
   minimum_heap->array[0] = minimum_heap->array[minimum_heap->size - 1];
   --minimum_heap->size;
   minimum_heapify(minimum_heap, 0);
   return temp;
}

struct minimum_heap* createAndBuildminimum_heap(char data[], int freq[], int size){
   struct minimum_heap* minimum_heap = createminimum_heap(size);
   for (int i = 0; i < size; ++i)
      minimum_heap->array[i] = newNode(data[i], freq[i]);
   minimum_heap->size = size;
   buildminimum_heap(minimum_heap);
   return minimum_heap;
}

struct minimum_heapNode* build_huffman_tree(char data[], int freq[], int size){
   struct minimum_heapNode *left, *right, *top;

   struct minimum_heap* minimum_heap = createAndBuildminimum_heap(data, freq, size);

   while (!isSizeOne(minimum_heap)){
      left = extractMin(minimum_heap);
      right = extractMin(minimum_heap);
      top = newNode('$', left->freq + right->freq);
      top->left = left;
      top->right = right;
      insertminimum_heap(minimum_heap, top);
   }
   return extractMin(minimum_heap);
}

void swapminimum_heapNode(struct minimum_heapNode** a, struct minimum_heapNode** b){
   struct minimum_heapNode* t = *a;
   *a = *b;
   *b = t;
}

void minimum_heapify(struct minimum_heap* minimum_heap, int idx){
   int smallest = idx;
   int left = 2 * idx + 1;
   int right = 2 * idx + 2;

   if (left < minimum_heap->size &&
      minimum_heap->array[left]->freq < minimum_heap->array[smallest]->freq)
      smallest = left;

   if (right < minimum_heap->size &&
      minimum_heap->array[right]->freq < minimum_heap->array[smallest]->freq)
      smallest = right;

   if (smallest != idx){
      swapminimum_heapNode(&minimum_heap->array[smallest], &minimum_heap->array[idx]);
      minimum_heapify(minimum_heap, smallest);
   }
}




void insertminimum_heap(struct minimum_heap* minimum_heap, struct minimum_heapNode* minimum_heapNode){
   ++minimum_heap->size;
   int i = minimum_heap->size - 1;
   while (i && minimum_heapNode->freq < minimum_heap->array[(i - 1) / 2]->freq){
      minimum_heap->array[i] = minimum_heap->array[(i - 1) / 2];
      i = (i - 1) / 2;
   }
   minimum_heap->array[i] = minimum_heapNode;
}


void buildminimum_heap(struct minimum_heap* minimum_heap){
   int n = minimum_heap->size - 1;
   int i;
   for (i = (n - 1) / 2; i >= 0; --i)
      minimum_heapify(minimum_heap, i);
}






void printAnswer(struct minimum_heapNode* root, int arr[], int top){
   if (root->left){
      arr[top] = 0;
      printAnswer(root->left, arr, top + 1);
   }
   if (root->right){
      arr[top] = 1;
      printAnswer(root->right, arr, top + 1);
   }
   if (isLeaf(root)){
      huff_sum += root->freq * top;
   }
}

void HuffmanCodes(char data[], int freq[], int size)
{
   struct minimum_heapNode* root = build_huffman_tree(data, freq, size);

   int arr[100], top = 0;
   printAnswer(root, arr, top);
   free(root);
}

int main()
{
   int St;

   char intmp[1000];
   int i;
   char aa[100];
   char bb[100];
   int num = 0;
   int tmp;



   scanf("%d", &num_char);

   for (i = 0; i < num_char; i++){
      scanf("%s", &intmp);
      characterList[i] = intmp[1];
      scanf("%d", &frequencyList[i]);
   }
   scanf("%d", &St);
   getchar();


    for(i='A';i<='Z';i++) 
    { 
        aa[65-i] = i;
        bb[65-i] = aa[65-i];
     } 

   tmp = 1; 
   while (tmp < num_char){
      tmp = tmp * 2;
      num++;
   }
   printf("%d\n", St*num); 
   HuffmanCodes(characterList, frequencyList, num_char);
   printf("%d", huff_sum);


   return 0;
}
