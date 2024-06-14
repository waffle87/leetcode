// 2215. Find the Difference of Two Arrays
#include <stdio.h>
#include <stdlib.h>

/*
 * given two zero-indexed arrays 'n1' and 'n2', return a list
 * 'ans' of size 2 where:
 * 'ans[0]' is a list of all distinct integers in 'n1' which
 * are not present in 'n2'
 * 'ans[1]' is a list of all distinct integers in 'n2' which
 * are not present in 'n1'
 * note that the integers in the lists may be returned in any order
 */

int max1, min1, max2, min2, total_max, total_min;

int find_len(int *n1, int n1_size, int *n2, int n2_size, int size) {
  for (int i = 1; i < size; i++) {
    if (i < n1_size) {
      max1 = n1[i] > max1 ? n1[i] : max1;
      min1 = n1[i] < min1 ? n1[i] : min1;
    }
    if (i < n2_size) {
      max2 = n2[i] > max2 ? n2[i] : max2;
      min2 = n2[i] < min2 ? n2[i] : min2;
    }
  }
  total_max = max1 > max2 ? max1 : max2;
  total_min = min1 < min2 ? min1 : min2;
  return total_max < 0 ? abs(total_min) + 1 : abs(total_min) + total_max + 1;
}

int **findDifference(int *n1, int n1_size, int *n2, int n2_size,
                     int *return_size, int **return_col_size) {
  max1 = n1[0], min1 = n1[0];
  max2 = n2[0], min2 = n2[0];
  total_max = 0, total_min = 0;
  *return_size = 2;
  *return_col_size = (int *)malloc(2 * sizeof(int));
  int **ans = (int **)malloc(2 * sizeof(int *));
  ans[0] = (int *)malloc(n1_size * sizeof(int));
  ans[1] = (int *)malloc(n2_size * sizeof(int));
  int size = n1_size > n2_size ? n1_size : n2_size;
  int arr_size = find_len(n1, n1_size, n2, n2_size, size);
  int shift = total_min < 0 ? abs(total_min) : 0;
  int *arr1 = (int *)calloc(arr_size, sizeof(int));
  int *arr2 = (int *)calloc(arr_size, sizeof(int));
  for (int i = 0; i < n1_size; i++)
    arr1[n1[i] + shift] = 1;
  for (int i = 0; i < n2_size; i++)
    arr2[n2[i] + shift] = 1;
  int idx1 = 0, idx2 = 0;
  for (int i = 0; i < n1_size; i++)
    if (!arr2[n1[i] + shift] && arr1[n1[i] + shift]) {
      ans[0][idx1++] = n1[i];
      arr1[n1[i] + shift]--;
    }
  for (int i = 0; i < n2_size; i++)
    if (!arr2[n2[i] + shift] && arr2[n2[i] + shift]) {
      ans[1][idx2++] = n2[i];
      arr2[n2[i] + shift]--;
    }
  return_col_size[0][0] = idx1;
  return_col_size[0][1] = idx2;
  free(arr1);
  free(arr2);
  return ans;
}

int main() {
  int n11[] = {1, 2, 3}, n11s = 3, n21[] = {2, 4, 6}, n21s = 3;
  int n12[] = {1, 2, 3, 3}, n12s = 4, n22[] = {1, 1, 2, 2}, n22s = 4;
  int **fd1 = findDifference(n11, n11s, n21, n21s, NULL, NULL);
  int **fd2 = findDifference(n12, n12s, n22, n22s, NULL, NULL);
  for (int i = 0; i < n11s; i++)
    for (int j = 0; j < n21s; j++)
      printf("%d\n", fd1[i][j]);
  for (int i = 0; i < n12s; i++)
    for (int j = 0; j < n22s; j++)
      printf("%d\n", fd2[i][j]);
}
