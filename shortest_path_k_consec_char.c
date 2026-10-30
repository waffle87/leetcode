// 3970. Shortest Path With At Most K Consecutive Identical Characters
#include "leetcode.h"

/*
 * you are given an integer 'n' representing the nubmer of nodes in a directed
 * weighted graph, numbered from 0 to 'n - 1'. this is represented by a 2d
 * integer array 'edges' where 'edges[i] = [ui, vi, wi]' represents a directed
 * edge from node 'ui' to 'vi' with weight 'wi'. you are also given a string
 * 'labels' of length 'n' where 'labels[i]' is the character assigned to node
 * 'i' and integer 'k'. return the minimum total edge weight of a path from node
 * 0 to 'n - 1' such that the concatenation of the labels of the nodes along the
 * path contains at most 'k' consecutive identical characters. if no valid path
 * exists, return -1.
 */

struct state {
  long long d;
  int x;
  int cnt;
};

struct min_heap {
  struct state *data;
  int size;
  int capacity;
};

static void heap_push(struct min_heap *h, struct state s) {
  if (h->size == h->capacity) {
    h->capacity = h->capacity ? h->capacity * 2 : 16;
    h->data = (struct state *)realloc(h->data, (size_t)h->capacity *
                                                   sizeof(struct state));
  }
  int i = h->size++;
  while (i > 0 && h->data[(i - 1) / 2].d > s.d) {
    h->data[i] = h->data[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  h->data[i] = s;
}

static struct state heap_pop(struct min_heap *h) {
  struct state res = h->data[0], prev = h->data[--h->size];
  if (!h->size)
    return res;
  int i = 0;
  while (i * 2 + 1 < h->size) {
    int j = i * 2 + 1;
    if (j + 1 < h->size && h->data[j + 1].d < h->data[j].d)
      j++;
    if (prev.d <= h->data[j].d)
      break;
    h->data[i] = h->data[j];
    i = j;
  }
  h->data[i] = prev;
  return res;
}

int shortestPath(int n, int **edges, int edgesSize, int *edgesColSize,
                 char *labels, int k) {
  int *head = (int *)malloc(n * sizeof(int));
  int *to = (int *)malloc(edgesSize * sizeof(int));
  int *weight = (int *)malloc(edgesSize * sizeof(int));
  int *next = (int *)malloc(edgesSize * sizeof(int));
  memset(head, -1, n * sizeof(int));
  for (int i = 0; i < edgesSize; i++) {
    int x = edges[i][0];
    to[i] = edges[i][1];
    weight[i] = edges[i][2];
    next[i] = head[x];
    head[x] = i;
  }
  int width = k + 1;
  long long *dist = (long long *)malloc(n * width * sizeof(long long));
  for (int i = 0; i < n * width; i++)
    dist[i] = INT_MAX;
  struct min_heap pq = {NULL, 0, 0};
  heap_push(&pq, (struct state){0, 0, 1});
  dist[1] = 0;
  int ans = -1;
  while (pq.size > 0) {
    struct state curr = heap_pop(&pq);
    long long d = curr.d;
    int x = curr.x, cnt = curr.cnt;
    if (d > dist[x * width + cnt])
      continue;
    if (x == n - 1) {
      ans = (int)d;
      break;
    }
    for (int i = head[x]; i != -1; i = next[i]) {
      int y = to[i], w = weight[i];
      int new_cnt = labels[x] == labels[y] ? cnt + 1 : 1;
      if (new_cnt > k)
        continue;
      long long nd = d + w;
      int idx = y * width + new_cnt;
      if (nd < dist[idx]) {
        dist[idx] = nd;
        heap_push(&pq, (struct state){nd, y, new_cnt});
      }
    }
  }
  free(head);
  free(to);
  free(weight);
  free(next);
  free(dist);
  free(pq.data);
  return ans;
}

int main() {
  int e1i[3][3] = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
  int e2i[3][3] = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
  int e3i[2][3] = {{0, 1, 1}, {1, 2, 1}};
  char *s1 = "aab", *s2 = "aab", *s3 = "aaa";
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  int r1 = shortestPath(3, e1->arr, e1->row_size, e1->col_size, s1, 1);
  int r2 = shortestPath(3, e2->arr, e2->row_size, e2->col_size, s2, 2);
  int r3 = shortestPath(3, e3->arr, e3->row_size, e3->col_size, s3, 2);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == -1);
}
