// 1514. Path with Maximum Probability
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an undirected weighted graph of 'n' nodes (0-indexed). represented by
 * an edge list where 'edges[i] = [a, b]' is an undirected edge connecting the
 * nodes 'a' and 'b' with a probability of success of traversing that edge
 * 'succ_prob[i]'. given two nodes 'start, end', find the path with the maximum
 * probability of success to go from 'start' to 'end' and return its success
 * probability. if there is no path from 'start' to 'end', return 0. your answer
 * will be accepted if it differs from the correct answer by at most '1e-5'
 */

#define LOWER_BOUND 1e-5

typedef struct {
  int next;
  double val;
} node;

void dfs(int n, bool *visited, double val, double *ans, int curr, int end,
         int *cn, node **map) {
  if (curr == end)
    *ans = fmax(*ans, val);
  if (*ans >= val)
    return;
  if (val - *ans <= LOWER_BOUND)
    return;
  if (visited[curr])
    return;
  visited[curr] = true;
  for (int i = 0; i < cn[curr]; i++) {
    double new_val = val * map[curr][i].val;
    dfs(n, visited, new_val, ans, map[curr][i].next, end, cn, map);
  }
  visited[curr] = false;
}

double maxProbability(int n, int **edges, int edges_size, int *edges_col_size,
                      double *succ_prob, int succ_prob_size, int start,
                      int end) {
  double ans = 0;
  bool *visited = calloc(n, sizeof(bool));
  int *cn = calloc(n, sizeof(int));
  node **map = calloc(n, sizeof(node *));
  for (int i = 0; i < edges_size; i++) {
    cn[edges[i][0]]++;
    cn[edges[i][1]]++;
  }
  for (int i = 0; i < n; i++)
    if (cn[i])
      map[i] = malloc(cn[i] * sizeof(node));
  int *m_idx = calloc(n, sizeof(int));
  for (int i = 0; i < edges_size; i++) {
    int prob = edges[i][0], next = edges[i][1], idx = m_idx[prob];
    map[prob][idx].next = next;
    map[prob][idx].val = succ_prob[i];
    m_idx[prob]++;
    prob = edges[i][1];
    next = edges[i][0];
    idx = m_idx[prob];
    map[prob][idx].next = next;
    map[prob][idx].val = succ_prob[i];
    m_idx[prob]++;
  }
  dfs(n, visited, 1.0, &ans, start, end, cn, map);
  free(visited);
  for (int i = 0; i < n; i++)
    if (cn[i])
      free(map[i]);
  free(cn);
  free(map);
  return ans;
}
