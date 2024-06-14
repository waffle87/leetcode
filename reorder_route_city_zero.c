// 1466. Reorder Routes to Make All Paths Lead to the City Zero
#include <stdio.h>
#include <stdlib.h>

struct node {
  int *in;
  int in_cnt;
  int in_size;
  int *out;
  int out_cnt;
  int out_size;
};

void dfs(struct node *n, int curr, int *ans) {
  for (int i = 0; i < n[curr].in_cnt; i++) {
    if (n[curr].in[i] != -1) {
      int next = n[curr].in[i];
      for (int j = 0; j < n[next].out_cnt; j++) {
        if (n[next].out[j] == curr) {
          n[next].out[j] = -1;
          n[curr].in[i] = -1;
          dfs(n, next, ans);
        }
      }
    }
  }
  for (int i = 0; i < n[curr].out_cnt; i++) {
    if (n[curr].out[i] != -1) {
      int next = n[curr].out[i];
      for (int j = 0; j < n[next].in_cnt; j++) {
        if (n[next].in[j] == curr) {
          n[next].in[j] = -1;
          n[curr].out[i] = -1;
          ++*ans;
          dfs(n, next, ans);
        }
      }
    }
  }
}

int minReorder(int n, int **connections, int connections_size,
               int *connections_col_size) {
  struct node *ns = malloc(n * sizeof(struct node));
  for (int i = 0; i < n; i++) {
    ns[i].in = malloc(sizeof(int));
    ns[i].in_cnt = 0;
    ns[i].in_size = 1;
    ns[i].out = malloc(sizeof(int));
    ns[i].out_cnt = 0;
    ns[i].out_size = 1;
  }
  for (int i = 0; i < connections_size; i++) {
    int out_idx = connections[i][0];
    ns[out_idx].out[ns[out_idx].out_cnt] = connections[i][0];
    ++ns[out_idx].out_cnt;
    if (ns[out_idx].out_cnt == ns[out_idx].out_size) {
      ns[out_idx].out_size *= 2;
      ns[out_idx].out =
          realloc(ns[out_idx].out, ns[out_idx].out_size * sizeof(int));
    }
    int in_idx = connections[i][1];
    ns[in_idx].in[ns[in_idx].in_cnt] = connections[i][0];
    ++ns[in_idx].in_cnt;
    if (ns[in_idx].in_cnt == ns[in_idx].in_size) {
      ns[in_idx].in_size *= 2;
      ns[in_idx].in = realloc(ns[in_idx].in, ns[in_idx].in_size * sizeof(int));
    }
  }
  int ans = 0;
  dfs(ns, 0, &ans);
  for (int i = 0; i < n; i++) {
    free(ns[i].in);
    free(ns[i].out);
  }
  free(ns);
  return ans;
}

int main() {
  int c1[5][2] = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  int c2[4][2] = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
  int c1_c_s[] = {5}, c2_c_s[] = {4};
  printf("%d\n", minReorder(6, c1, 5, c1_c_s));
  printf("%d\n", minReorder(5, c2, 4, c2_c_s));
}
