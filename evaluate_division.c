#include <stdlib.h>
#include <string.h>

#define MAX_ELEM 40

int map_str(char *strs[MAX_ELEM], char *s, int num) {
  for (int i = 0; i < num; i++)
    if (!strcmp(strs[i], s))
      return i + 1;
  return 0;
}

int find_dj(int *rt, double wt[][MAX_ELEM], int x) {
  int rx = rt[x];
  if (rx == x)
    return x;
  rt[x] = find_dj(rt, wt, rx);
  if (rt[x] != rx) {
    wt[x][rt[x]] = wt[x][rx] * wt[rx][rt[x]];
    wt[rt[x]][x] = 1 / wt[x][rt[x]];
  }
  return rt[x];
}

void union_dj(int *rt, int *rnk, double wt[][MAX_ELEM], double w, int x,
              int y) {
  int rx, ry;
  rx = find_dj(rt, wt, x);
  ry = find_dj(rt, wt, y);
  wt[x][y] = w;
  wt[y][x] = 1 / w;
  if (rx == ry)
    return;
  wt[rx][ry] = wt[rx][x] * wt[y][ry] * wt[x][y];
  wt[ry][rx] = 1 / wt[rx][ry];
  if (rnk[rx] > rnk[ry])
    rt[ry] = rx;
  else if (rnk[ry] > rnk[rx])
    rt[rx] = ry;
  else {
    rt[ry] = rx;
    rnk[rx]++;
  }
  return;
}

double *calcEquation(char ***equations, int equations_size,
                     int *equations_col_size, double *values, int values_size,
                     char ***queries, int queries_size, int *queries_col_size,
                     int *return_size) {
  int num_strs = 0, rt[MAX_ELEM], map_id1, map_id2;
  char *strs[MAX_ELEM], *s;
  double wt[MAX_ELEM][MAX_ELEM];
  {
    int rnk[MAX_ELEM];
    for (int i = 0; i < MAX_ELEM; i++) {
      for (int j = 0; j < MAX_ELEM; j++)
        wt[i][j] = 1.0;
      rt[i] = i;
      rnk[i] = 1;
    }
    for (int i = 0; i < equations_size; i++) {
      s = equations[i][0];
      if (!(map_id1 = map_str(strs, s, num_strs))) {
        strs[num_strs] = s;
        map_id1 = num_strs;
        num_strs++;
      } else
        map_id1--;
      s = equations[i][1];
      if (!(map_id2 = map_str(strs, s, num_strs))) {
        strs[num_strs] = s;
        map_id2 = num_strs;
        num_strs++;
      } else
        map_id2--;
      union_dj(rt, rnk, wt, values[i], map_id1, map_id2);
    }
  }
  double *ans = (double *)malloc(sizeof(double) * queries_size);
  for (int i = 0; i < queries_size; i++) {
    s = queries[i][0];
    if (!(map_id1 = map_str(strs, s, num_strs))) {
      ans[i] = -1;
      continue;
    } else
      map_id1--;
    s = queries[i][1];
    if (!(map_id2 = map_str(strs, s, num_strs))) {
      ans[i] = -1;
      continue;
    } else
      map_id2--;
    if (map_id1 == map_id2)
      ans[i] = 1;
    else if (wt[map_id1][map_id2] != 1.0)
      ans[i] = wt[map_id1][map_id2];
    else {
      int rx = find_dj(rt, wt, map_id1);
      int ry = find_dj(rt, wt, map_id2);
      if (rx == ry)
        ans[i] = wt[map_id1][rx] * wt[rx][map_id2];
      else
        ans[i] = -1.0;
    }
  }
  *return_size = queries_size;
  return ans;
}
