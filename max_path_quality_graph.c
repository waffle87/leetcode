// 2065. Maximum Path Quality of a Graph
#include "leetcode.h"

/*
 * there is an undirected graph with 'n' nodes numbered from 0 to 'n - 1'. you
 * are given a 0-indexed integer array 'values' where 'values[i]' is the value
 * of the i'th node. you are also given a 0-indexed 2d integer array 'edges',
 * where each 'edges[j] = [uj, vj, timej]' indicates that there is an undirected
 * edge between the nodes 'uj' and 'vj', and it takes 'timej' seconds to travel
 * between the two nodes. finally, you are given an integer 'maxTime'. a valid
 * path in the graph is any path that starts at node 0, ends at node 0, and
 * takes at most 'maxTime' seconds to complete. you may visit the same node
 * multiple times. the quality of a valid path is the sum of the value of the
 * unique nodes visited in the path (each node's value is added at most once to
 * the sum). return the maximum quality of a valid path.
 */

struct map {
  struct map *next;
  int adj;
  int time;
};

void find_path(struct map **times, int *values, int size, int *vis, int *res,
               int max, int i, int time, int max_time) {
  if (time > max_time)
    return;
  if (!vis[i])
    max += values[i];
  if (!i)
    *res = fmax(*res, max);
  vis[i]++;
  if (times[i]) {
    struct map *curr = times[i];
    while (curr) {
      int j = curr->adj, new_time = time + curr->time;
      find_path(times, values, size, vis, res, max, j, new_time, max_time);
      curr = curr->next;
    }
  }
  vis[i]--;
}

int maximalPathQuality(int *values, int valuesSize, int **edges, int edgesSize,
                       int *edgesColSize, int maxTime) {
  if (valuesSize == 1)
    return values[0];
  int *ans = (int *)malloc(sizeof(int));
  *ans = 0;
  struct map **times = (struct map **)malloc(valuesSize * sizeof(struct map *));
  int *vis = (int *)malloc(valuesSize * sizeof(int));
  for (int i = 0; i < valuesSize; i++) {
    times[i] = NULL;
    vis[i] = 0;
  }
  for (int i = 0; i < edgesSize; i++) {
    int src = edges[i][0], dst = edges[i][1], time = edges[i][2];
    struct map *ins1 = (struct map *)malloc(sizeof(struct map));
    ins1->adj = dst;
    ins1->time = time;
    ins1->next = times[src];
    times[src] = ins1;
    struct map *ins2 = (struct map *)malloc(sizeof(struct map));
    ins2->adj = src;
    ins2->time = time;
    ins2->next = times[dst];
    times[dst] = ins2;
  }
  find_path(times, values, valuesSize, vis, ans, 0, 0, 0, maxTime);
  return *ans;
}

int main() {
  int v1[] = {0, 32, 10, 43}, e1i[3][3] = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
  int v2[] = {5, 10, 15, 20}, e2i[3][3] = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}};
  int v3[] = {1, 2, 3, 4},
      e3i[4][3] = {{0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  printf("%d\n", maximalPathQuality(v1, ARRAY_SIZE(v1), e1->arr, e1->row_size,
                                    e1->col_size, 49)); // expect: 75
  printf("%d\n", maximalPathQuality(v1, ARRAY_SIZE(v1), e1->arr, e1->row_size,
                                    e1->col_size, 30)); // expect: 25
  printf("%d\n", maximalPathQuality(v1, ARRAY_SIZE(v1), e1->arr, e1->row_size,
                                    e1->col_size, 50)); // expect: 50
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
