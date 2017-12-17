
//2012017850_박창대_Algorithm
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef int weight;
typedef int vertex_no;

typedef struct node_ {
   int dest;
   weight w;
   struct node_ *next;
} node;

typedef struct tree_ {
   int vertexLen;
   node **vertexList;
} tree;

typedef struct dijkstra_ { 
   weight *w; 
   int *before; 
   int *finishied; 
   int len; 
   tree *t;
} dijkstra;

tree *tree_init(int len)
{
   tree *a = (tree*)malloc(sizeof(tree));
   int i;
   a->vertexLen = len;
   a->vertexList = (node**)malloc((len + 1) * sizeof(node));

   for ( i = 0; i < len+1; i++)
   {
      a->vertexList[i] = (node*)malloc(sizeof(node));
      a->vertexList[i]->next = NULL;
      a->vertexList[i]->dest = a->vertexList[i]->w = 0;
   }

   return a;
}

void tree_addVertex(tree *t, int origin, int dest, weight w)
{
   node *n = (node*)malloc(sizeof(node));
   n->w = w;
   n->dest = dest; 
   n->next = t->vertexList[origin];
   t->vertexList[origin] = n;
   return;
}

dijkstra *dijkstra_init(tree *t, int len)
{
   dijkstra *d = (dijkstra*)malloc(sizeof(dijkstra));
   int i;
   d->finishied = (int*)calloc(len + 1, sizeof(int));
   d->before = (int*)calloc(len + 1, sizeof(int));
   d->w = (int*)malloc((len + 1) * sizeof(int));
   d->len = len;
   d->t = t;
   for ( i = 0; i < len+1; i++)
   {
      d->w[i] = INT_MAX;
   }

   return d;
}

void dijkstra_solve(dijkstra *d, int start)
{
   int solved = 0; 
   vertex_no min_loc, loc;
   weight minV_value, tmp_weight;
   node *tmp_node;
   int k=0;
   
   d->w[start] = 0;

   while (solved < d->len)
   { 
      minV_value = INT_MAX;
      for ( loc = 1; loc < d->len + 1; loc++)
      {
         if (!d->finishied[loc] && minV_value >= d->w[loc])
         {
            min_loc = loc;
            minV_value = d->w[loc];
         }
            
      }

      tmp_node = d->t->vertexList[min_loc];
      while (tmp_node)
      {
         tmp_weight = d->w[min_loc] + tmp_node->w;
         if (tmp_weight < d->w[tmp_node->dest])
         {  
            d->w[tmp_node->dest] = tmp_weight;
            d->before[tmp_node->dest] = min_loc; 
         }
      
         tmp_node = tmp_node->next;
      }
      
      d->finishied[min_loc] = 1;
      solved++;
   }
}

int main()
{
   tree *t;
   dijkstra *d;

   int len, i, j;
   int edge, e_len, dest, w; 
   weight max;
   
   scanf("%d", &len);
   t = tree_init(len);
   d = dijkstra_init(t, len);
   for ( i = 0; i < len; i++)
   { 
      scanf("%d %d", &edge, &e_len);
      for ( j = 0; j < e_len; j++)
      {
         
         scanf("%d %d", &dest, &w);
         tree_addVertex(t, edge, dest, w);
      }
   }
   dijkstra_solve(d, 1);
   max = INT_MIN;
   for ( i = 1; i < d->len + 1; i++)
   {
      if (max < d->w[i])
         max = d->w[i];
   }
   printf("%d\n", max);

   return 0;
}
