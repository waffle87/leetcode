// 90. Subsets II
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an integer array 'nums' that may contain duplicates, return all
 * possible subsets (the power set). the solution set must not contain duplicate
 * subsets. return the solution in any order.
 */

void process(int **res, int *idx, int *data, int pos, int **nums, int nums_size,
             int *cols) {
  if (!nums_size) {
    cols[*idx] = pos;
    if (!pos) {
      (*idx)++;
      return;
    }
    res[*idx] = malloc(pos * sizeof(int));
    memcpy(res[*idx], data, pos * sizeof(int));
    (*idx)++;
    return;
  }
  for (int i = 0; i <= nums[0][1]; i++) {
    if (!i)
      process(res, idx, data, pos, &nums[1], nums_size - 1, cols);
    else {
      data[pos] = nums[0][0];
      pos++;
      process(res, idx, data, pos, &nums[1], nums_size - 1, cols);
    }
  }
}

int **subsetsWithDup(int *nums, int nums_size, int *return_size,
                     int **return_col_size) {
  int **ans = malloc(1024 * sizeof(int *));
  return_col_size[0] = malloc(1024 * sizeof(int));
  int *data = malloc(10 * sizeof(int));
  int *idx = calloc(1, sizeof(int));
  int *hash = calloc(21, sizeof(int));
  for (int i = 0; i < nums_size; i++)
    hash[nums[i] + 10]++;
  int **n_nums = malloc(nums_size * sizeof(int *));
  int n_nums_size = 0;
  for (int i = 0; i < 21; i++)
    if (hash[i]) {
      n_nums[n_nums_size] = malloc(2 * sizeof(int));
      n_nums[n_nums_size][0] = i - 10;
      n_nums[n_nums_size][1] = hash[i];
      n_nums_size++;
    }
  free(hash);
  process(ans, idx, data, 0, n_nums, n_nums_size, *return_col_size);
  ans = realloc(ans, (*idx) * sizeof(int *));
  return_col_size[0] = realloc(return_col_size[0], (*idx) * sizeof(int));
  *return_size = *idx;
  return ans;
}

int main() {
  int n1[] = {1, 2, 2}, n2[] = {0};
  int **swd1 = subsetsWithDup(n1, 3, NULL, NULL);
  int **swd2 = subsetsWithDup(n2, 1, NULL, NULL);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", swd1[i][j]);
  printf("\n");
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 1; j++)
      printf("%d ", swd2[i][j]);
  printf("\n");
}
