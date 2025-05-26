// 1857. Largest Color Value in a Directed Graph
#include "leetcode.h"

/*
 * there is a directed graph of 'n' coloured nodes and 'm' edges. the nodes are
 * numbered from 0 to 'n - 1'. you are given a tring 'colours' where
 * 'colours[i]' is a lowercase english letter representing the colour of the
 * i'th node in this graph (0-indexed). you are also given a 2d integer array
 * 'edges' where 'edges[i] = [ai, bi]' indicates that there is a directed edge
 * from node 'ai' to 'bi'. a valid path in the graph is a sequence of nodes such
 * that there is a directed edge for every ' 1 <= i < k'. the collour value of
 * the path is the number of nodes that coloured the most frequently occuring
 * along the path. return the largest colour value of any valid path in the
 * given graph, or -1 if the graph contains a cycle.
 */

struct node {
  int val;
  struct node *next;
};

struct graph {
  struct node *next;
  char colour;
  int *cnt;
};

struct node *graph_create(struct node *prev, int val) {
  struct node *obj = (struct node *)malloc(sizeof(struct node));
  obj->next = prev;
  obj->val = val;
  return obj;
}

void graph_free(struct graph *s, int n) {
  for (int i = 0; i < n; i++) {
    while (s[i].next) {
      struct node *tmp = s[i].next;
      s[i].next = s[i].next->next;
      free(tmp);
    }
    free(s[i].cnt);
  }
  free(s);
}

void search(int val, struct graph *plan, bool *vis, bool *cycle, int *res) {
  vis[val] = true;
  while (plan[val].next) {
    int new = plan[val].next->val;
    if (vis[new]) {
      *cycle = true;
      return;
    }
    if (plan[new].cnt) {
      for (int i = 0; i < 26; i++)
        if (plan[val].cnt[i] < plan[new].cnt[i])
          plan[val].cnt[i] = plan[new].cnt[i];
      plan[val].next = plan[val].next->next;
      continue;
    }
    plan[new].cnt = (int *)calloc(26, sizeof(int));
    search(new, plan, vis, cycle, res);
    for (int i = 0; i < 26; i++)
      if (plan[val].cnt[i] < plan[new].cnt[i])
        plan[val].cnt[i] = plan[new].cnt[i];
    plan[val].next = plan[val].next->next;
  }
  plan[val].cnt[plan[val].colour - 'a']++;
  if (*res < plan[val].cnt[plan[val].colour - 'a'])
    *res = plan[val].cnt[plan[val].colour - 'a'];
  vis[val] = false;
}

int largestPathValue(char *colors, int **edges, int edgesSize,
                     int *edgesColSize) {
  int n = strlen(colors);
  struct graph *plan = (struct graph *)calloc(n, sizeof(struct graph));
  bool *vis = (bool *)calloc(n, sizeof(bool));
  for (int i = 0; i < n; i++)
    plan[i].colour = colors[i];
  for (int i = 0; i < edgesSize; i++) {
    if (edges[i][0] == edges[i][1]) {
      graph_free(plan, n);
      return -1;
    }
    plan[edges[i][0]].next = graph_create(plan[edges[i][0]].next, edges[i][1]);
  }
  bool cycle = false;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!plan[i].cnt) {
      plan[i].cnt = (int *)calloc(26, sizeof(int));
      search(i, plan, vis, &cycle, &ans);
      if (cycle) {
        graph_free(plan, n);
        return -1;
      }
    }
  }
  graph_free(plan, n);
  return ans;
}

int main() {
  char *c1 = "abaca", *c2 = "a";
  int e1i[4][2] = {{0, 1}, {0, 2}, {2, 3}, {3, 4}}, e2i[1][2] = {{0, 0}};
  struct two_d_arr e1, e2;
  two_d_arr_init(&e1, ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  two_d_arr_init(&e2, ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  printf("%d\n",
         largestPathValue(c1, e1.arr, e1.row_size, e1.col_size)); // expect: 3
  printf("%d\n",
         largestPathValue(c2, e2.arr, e2.row_size, e2.col_size)); // expect: -1
}
