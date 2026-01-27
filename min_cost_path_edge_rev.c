// 3650. Minimum Cost Path with Edge Reversals
#include "leetcode.h"

/*
 * you are given a directed, weighted graph with 'n' nodes labeled from 0 to 'n
 * - 1', and an array 'edges' where 'edges[i] =[ui, vi, wi]' represents a
 * directed edge from node 'ui' to node 'vi' with cost 'wi'. each node 'ui' has
 * a switch that can be used at most once: when you arrive at 'ui' and have not
 * yet its switch, you may activate it on one of its incoming edges 'vi -> ui'
 * reverse that edge to 'ui -> vi' and immediately traverse it. the reversal is
 * only valid for that single move, and using a reversed edge costs '2 * wi'.
 * return the minimum cost to travel from node 0 to node 'n - 1'. if it is not
 * possible, return -1.
 */

struct edge {
  int to;
  int weight;
  struct edge *next;
};

struct heap_node {
  int node;
  int cost;
};

struct min_heap {
  struct heap_node *data;
  int size;
  int capacity;
};

struct min_heap *min_heap_init(int capacity) {
  struct min_heap *obj = (struct min_heap *)malloc(sizeof(struct min_heap));
  obj->data = (struct heap_node *)malloc(capacity * sizeof(struct heap_node));
  obj->size = 0;
  obj->capacity = capacity;
  return obj;
}

void swap(struct heap_node *a, struct heap_node *b) {
  struct heap_node tmp = *a;
  *a = *b;
  *b = tmp;
}

void min_heap_push(struct min_heap *obj, int node, int cost) {
  if (obj->size == obj->capacity)
    return;
  int idx = obj->size;
  obj->data[idx].node = node;
  obj->data[idx].cost = cost;
  while (idx > 0 && obj->data[(idx - 1) / 2].cost > obj->data[idx].cost) {
    swap(&obj->data[(idx - 1) / 2], &obj->data[idx]);
    idx = (idx - 1) / 2;
  }
}

struct heap_node min_heap_pop(struct min_heap *obj) {
  struct heap_node root = obj->data[0];
  obj->data[0] = obj->data[--obj->size];
  int idx = 0;
  while (2 * idx + 1 < obj->size) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < obj->size && obj->data[left].cost < obj->data[smallest].cost)
      smallest = left;
    if (right < obj->size && obj->data[right].cost < obj->data[smallest].cost)
      smallest = right;
    if (smallest != idx) {
      swap(&obj->data[idx], &obj->data[smallest]);
      idx = smallest;
    } else
      break;
  }
  return root;
}

bool is_empty(struct min_heap *obj) { return !obj->size; }

void add_edge(struct edge **adj, int u, int v, int w) {
  struct edge *obj = (struct edge *)malloc(sizeof(struct edge));
  obj->to = v;
  obj->weight = w;
  obj->next = adj[u];
  adj[u] = obj;
}

int minCost(int n, int **edges, int edgesSize, int *edgesColSize) {
  struct edge **adj = (struct edge **)calloc(n, sizeof(struct edge *));
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    add_edge(adj, u, v, w);
    add_edge(adj, v, u, w * 2);
  }
  int *dist = (int *)malloc(n * sizeof(int)), ans = -1;
  for (int i = 0; i < n; i++)
    dist[i] = INT_MAX;
  struct min_heap *pq = min_heap_init(edgesSize * 4 + 1000);
  dist[0] = 0;
  min_heap_push(pq, 0, 0);
  while (!is_empty(pq)) {
    struct heap_node top = min_heap_pop(pq);
    int u = top.node, d = top.cost;
    if (u == n - 1) {
      ans = d;
      break;
    }
    if (d > dist[u])
      continue;
    struct edge *curr = adj[u];
    while (curr) {
      int v = curr->to, w = curr->weight;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        min_heap_push(pq, v, dist[v]);
      }
      curr = curr->next;
    }
  }
  free(dist);
  free(pq->data);
  free(pq);
  for (int i = 0; i < n; i++) {
    struct edge *curr = adj[i];
    while (curr) {
      struct edge *tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(adj);
  return ans;
}

int main() {
  int e1i[4][3] = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
  int e2i[4][3] = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  printf("%d\n", minCost(4, e1->arr, e1->row_size, e1->col_size)); // expect: 5
  printf("%d\n", minCost(4, e2->arr, e2->row_size, e2->col_size)); // expect: 3
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
