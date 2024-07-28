// 2045. Second Minimum Time to Reach Destination
#include "leetcode.h"

/*
 * a city is represented as a bi directional connected graph with 'n' vertices
 * where each vertex is labeled from 1 to 'n' inclusively. the edges in the
 * graph are represented as a 2d integer array 'edges' where each 'edges[i] =
 * [ui, vi]' denotes a bi directional edge between vertex 'ui' and vertex 'vi'.
 * every vertex pair is connected by at most one edge, and no vertex has an edge
 * to itself. the time taken to traverse any edge is 'time' minutes. each vertex
 * has a traffic signal which changes its colour from green to red and vice
 * versa every 'change' minutes. all signals change at the same time. you can
 * entre a vertex at any time, but can leave a vertex only when the signal is
 * green. you cannot wait at a vertex if the signal is green.
 */

struct state {
  int node;
  int time;
};

struct min_heap {
  struct state *data;
  int size;
  int capacity;
};

void swap(struct state *a, struct state *b) {
  struct state tmp = *a;
  *a = *b;
  *b = tmp;
}

struct min_heap *create_min_heap(int capacity) {
  struct min_heap *heap = (struct min_heap *)malloc(sizeof(struct min_heap));
  heap->data = (struct state *)malloc(capacity * sizeof(struct state));
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void min_heapify(struct min_heap *heap, int idx) {
  int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
  if (left < heap->size && heap->data[left].time < heap->data[smallest].time)
    smallest = left;
  if (right < heap->size && heap->data[right].time < heap->data[smallest].time)
    smallest = right;
  if (smallest != idx) {
    swap(&heap->data[idx], &heap->data[smallest]);
    min_heapify(heap, smallest);
  }
}

struct state extract_min(struct min_heap *heap) {
  if (heap->size <= 0)
    return (struct state){-1, -1};
  if (heap->size == 1) {
    heap->size--;
    return heap->data[0];
  }
  struct state root = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  heap->size--;
  min_heapify(heap, 0);
  return root;
}

void insert_min_heap(struct min_heap *heap, struct state k) {
  if (heap->size == heap->capacity) {
    heap->capacity *= 2;
    heap->data = (struct state *)realloc(heap->data,
                                         heap->capacity * sizeof(struct state));
  }
  heap->size++;
  int i = heap->size - 1;
  heap->data[i] = k;
  while (i && heap->data[(i - 1) / 2].time > heap->data[i].time) {
    swap(&heap->data[i], &heap->data[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void free_min_heap(struct min_heap *heap) {
  free(heap->data);
  free(heap);
}

struct node {
  int val;
  struct node *next;
};

struct graph {
  struct node **heads;
  int *sizes;
  int size;
};

struct graph *create_graph(int n) {
  struct graph *g = (struct graph *)malloc(sizeof(struct graph));
  g->heads = (struct node **)malloc((n + 1) * sizeof(struct node *));
  g->sizes = (int *)calloc(n + 1, sizeof(int));
  g->size = n;
  for (int i = 0; i <= n; i++)
    g->heads[i] = NULL;
  return g;
}

void add_edges(struct graph *g, int u, int v) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = v;
  n->next = g->heads[u];
  g->heads[u] = n;
  n = (struct node *)malloc(sizeof(struct node));
  n->val = u;
  n->next = g->heads[v];
  g->heads[v] = n;
  g->sizes[u]++;
  g->sizes[v]++;
}

void free_graph(struct graph *g) {
  for (int i = 0; i <= g->size; i++) {
    struct node *head = g->heads[i];
    while (head) {
      struct node *tmp = head;
      head = head->next;
      free(tmp);
    }
  }
  free(g->heads);
  free(g->sizes);
  free(g);
}

int secondMinimum(int n, int **edges, int edgesSize, int *edgesColSize,
                  int time, int change) {
  struct graph *g = create_graph(n);
  for (int i = 0; i < edgesSize; i++)
    add_edges(g, edges[i][0], edges[i][1]);
  int *min_time = (int *)malloc((n + 1) * sizeof(int));
  int *second_min_time = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++) {
    min_time[i] = INT_MAX;
    second_min_time[i] = INT_MAX;
  }
  struct min_heap *pq = create_min_heap(edgesSize * 2);
  insert_min_heap(pq, (struct state){1, 0});
  min_time[1] = 0;
  while (pq->size) {
    struct state curr = extract_min(pq);
    int curr_node = curr.node;
    int curr_time = curr.time;
    struct node *neighbour_node = g->heads[curr_node];
    while (neighbour_node) {
      int neighbour = neighbour_node->val, wait_time = 0;
      if ((curr_time / change) % 2 == 1)
        wait_time = change = (curr_time % change);
      int next_time = curr_time + time + wait_time;
      if (next_time < min_time[neighbour]) {
        second_min_time[neighbour] = min_time[neighbour];
        min_time[neighbour] = next_time;
        insert_min_heap(pq, (struct state){neighbour, next_time});
      } else if (next_time > min_time[neighbour] &&
                 next_time < second_min_time[neighbour]) {
        second_min_time[neighbour] = next_time;
        insert_min_heap(pq, (struct state){neighbour, next_time});
      }
      neighbour_node = neighbour_node->next;
    }
  }
  int ans = second_min_time[n];
  free(min_time), free(second_min_time);
  free_min_heap(pq);
  free_graph(g);
  return ans;
}

int main() {
  int e1[5][2] = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}}, e2[1][2] = {{1, 2}};
  int ecs1 = 5, ecs2 = 1;
  printf("%d\n", secondMinimum(5, (int **)e1, ARRAY_SIZE(e1), &ecs1, 3,
                               5)); // expect: 13
  printf("%d\n", secondMinimum(2, (int **)e2, ARRAY_SIZE(e2), &ecs2, 3,
                               2)); // expect: 11
}
