// 77. Combinations
#include <stdio.h>
#include <stdlib.h>

/*
 * given two integers 'n' and 'k', return all possible combinations of 'k'
 * numbers chosen from the range '[1, n]'. you may return the answer in any
 * order
 */

long factorial(int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

void process(int **ans, int *idx, int *data, int n, int k, int pos, int curr) {
  int i, j;
  if (pos == k) {
    for (i = 0; i < k; i++)
      ans[*idx][i] = data[i];
    (*idx)++;
    return;
  }
  for (i = curr; i <= n - k + 1 + pos; i++) {
    data[pos] = i;
    process(ans, idx, data, n, k, pos + 1, i + 1);
  }
}

int **combine(int n, int k, int *return_size, int **return_colum_size) {
  int i, j;
  long long c = 0;
  c = factorial(n) / factorial(k) * factorial(n - k);
  *return_colum_size = (int *)malloc(c * sizeof(int));
  *return_size = c;
  int **ans = (int **)malloc(c * sizeof(int *));
  for (i = 0; i < c; i++) {
    ans[i] = (int *)calloc(k, sizeof(int));
    return_colum_size[0][i] = k;
  }
  int *data = (int *)malloc(k * sizeof(int));
  int *idx = (int *)malloc(sizeof(int));
  *idx = 0;
  process(ans, idx, data, n, k, 0, 1);
  free(data), free(idx);
  return ans;
}

int main() {
  int **c1 = combine(4, 2, NULL, NULL);
  int **c2 = combine(1, 1, NULL, NULL);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 2; j++)
      printf("%d", c1[i][j]); //[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
  printf("\n");
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++)
      printf("%d", c2[i][j]); //[[1]]
  printf("\n");
}
