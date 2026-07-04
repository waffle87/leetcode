// 3620. Network Recovery Pathways
#include "leetcode.h"

/*
 * you are given a directed acyclic graph of 'n' nodes numbered from 0 to 'n -
 * 1'.this is represented by a 2d array 'edges' of length 'm', where 'edges[i] =
 * [ui, vi, costi]' indicates a one-way communication from node 'ui' to node
 * 'vi' with a recovery of 'costi'. some nodes may be offline. you are given a
 * boolean array where 'online[i] = true' means node 'i' is online. a path from
 * to 0 to 'n - 1' is valid if all intermediate nodes on the path are online,
 * and the total recovery cost of all edges on the path does not exceed 'k'.
 * return the maximum path score among all valid paths. if no valid path exists,
 * return -1.
 */

struct edge {
  int to;
  int weight;
  struct edge *next;
};

struct heap_node {
  long long cost;
  int node;
};

void add_edge(struct edge **graph, int from, int to, int weight) {
  struct edge *e = (struct edge *)malloc(sizeof(struct edge));
  e->to = to;
  e->weight = weight;
  e->next = graph[from];
  graph[from] = e;
}

void swap_heap(struct heap_node *a, struct heap_node *b) {
  struct heap_node tmp = *a;
  *a = *b;
  *b = tmp;
}

void push(struct heap_node *heap, int *size, struct heap_node node) {
  heap[++(*size)] = node;
  int i = *size;
  while (i > 1 && heap[i].cost < heap[i / 2].cost) {
    swap_heap(&heap[i], &heap[i / 2]);
    i /= 2;
  }
}

struct heap_node pop(struct heap_node *heap, int *size) {
  struct heap_node top = heap[1];
  heap[1] = heap[(*size)--];
  int i = 1;
  while (i * 2 <= *size) {
    int j = i * 2;
    if (j + 1 <= *size && heap[j + 1].cost < heap[j].cost)
      j++;
    if (heap[i].cost <= heap[j].cost)
      break;
    swap_heap(&heap[i], &heap[j]);
    i = j;
  }
  return top;
}

bool check(int min_weight, struct edge **graph, bool *online, int n,
           long long k, int heap_capacity) {
  struct heap_node *heap = (struct heap_node *)malloc((heap_capacity + 5) *
                                                      sizeof(struct heap_node));
  int heap_size = 0;
  long long *best_cost = (long long *)malloc(n * sizeof(long long));
  memset(best_cost, -1, n * sizeof(long long));
  push(heap, &heap_size, (struct heap_node){0, 0});
  while (heap_size > 0) {
    struct heap_node curr = pop(heap, &heap_size);
    long long curr_cost = curr.cost;
    int curr_node = curr.node;
    if (curr_node == n - 1) {
      free(heap);
      free(best_cost);
      return true;
    }
    if (best_cost[curr_node] != -1 && best_cost[curr_node] <= curr_cost)
      continue;
    best_cost[curr_node] = curr_cost;
    for (struct edge *e = graph[curr_node]; e != NULL; e = e->next) {
      int next_node = e->to, edge_weight = e->weight;
      if (curr_cost + edge_weight > k)
        continue;
      if (!online[next_node])
        continue;
      if (edge_weight < min_weight)
        continue;
      push(heap, &heap_size,
           (struct heap_node){curr_cost + edge_weight, next_node});
    }
  }
  free(heap);
  free(best_cost);
  return false;
}

int findMaxPathScore(int **edges, int edgesSize, int *edgesColSize,
                     bool *online, int onlineSize, long long k) {
  int max_weight = 0;
  struct edge **graph =
      (struct edge **)calloc(onlineSize, sizeof(struct edge *));
  for (int i = 0; i < edgesSize; i++) {
    int from_node = edges[i][0];
    int to_node = edges[i][1];
    int weight = edges[i][2];
    add_edge(graph, from_node, to_node, weight);
    max_weight = fmax(weight, max_weight);
  }
  int left = -1, right = max_weight + 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (check(mid, graph, online, onlineSize, k, edgesSize + onlineSize + 5))
      left = mid + 1;
    else
      right = mid - 1;
  }
  return right >= 0 ? right : -1;
}

int main() {
  int e1i[4][3] = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
  int e2i[6][3] = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6},
                   {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
  bool o1[] = {true, true, true, true}, o2[] = {true, true, true, false, true};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  int r1 = findMaxPathScore(e1->arr, e1->row_size, e1->col_size, o1,
                            ARRAY_SIZE(o1), 10);
  int r2 = findMaxPathScore(e2->arr, e2->row_size, e2->col_size, o2,
                            ARRAY_SIZE(o2), 12);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 6);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
