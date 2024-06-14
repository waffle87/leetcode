// 46. Permutations
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'nums' of distinct integers, return all the possible
 * permutations. you can return the answer in any order
 */

void swap(int *p, int *q) {
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

void search(int *nums, int nums_size, int ***arr, int *return_size, int begin,
            int end) {
  if (begin == end) {
    (*return_size)++;
    *arr = (int **)realloc(*arr, sizeof(int *) * (*return_size));
    (*arr)[*return_size - 1] = (int *)malloc(sizeof(int) * nums_size);
    for (int i = 0; i < nums_size; i++)
      (*arr)[*return_size - 1][i] = nums[i];
    return;
  }
  for (int i = begin; i <= end; i++) {
    swap(nums + begin, nums + i);
    search(nums, nums_size, arr, return_size, begin + 1, end);
    swap(nums + begin, nums + i);
  }
}

int **permute(int *nums, int nums_size, int *return_size,
              int **return_col_size) {
  *return_size = 0;
  int **ans = (int **)malloc(sizeof(int *));
  search(nums, nums_size, &ans, return_size, 0, nums_size - 1);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {0, 1}, n3[] = {1};
  int **p1 = permute(n1, 3, NULL, NULL);
  int **p2 = permute(n2, 2, NULL, NULL);
  int **p3 = permute(n3, 1, NULL, NULL);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", p1[i][j]);
  printf("\n");
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", p2[i][j]);
  printf("\n");
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", p3[i][j]);
  printf("\n");
}
