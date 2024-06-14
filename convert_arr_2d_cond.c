// 2610. Convert an Array Into a 2D Array With Conditions
#include "leetcode.h"

/*
 * given an integer array 'nums', you should create a 2d array from 'nums'
 * satisfying the following conditions. the 2d array should contain only the
 * elements of the array 'nums'. each row in the 2d array contains distinct
 * integers. the number of rows in the 2d array should be minimal. return the
 * resulting array. if there are multiple answers, return any of them. note that
 * the 2d array can have a different number of elements on each row.
 */

int **findMatrix(int *nums, int nums_size, int *return_size,
                 int **return_column_sizes) {
  int *table = calloc(201, sizeof(int));
  *return_size = 0;
  for (int i = 0; i < nums_size; i++) {
    table[nums[i]]++;
    *return_size = fmax(*return_size, table[nums[i]]);
  }
  int **ans = malloc(sizeof(int *) * *return_size);
  *return_column_sizes = calloc(*return_size, sizeof(int));
  for (int i = 0; i < *return_size; i++)
    ans[i] = calloc(nums_size, sizeof(int));
  for (int i = 0; i <= 200; i++) {
    int row = 0;
    while (table[i]) {
      ans[row][*return_column_sizes[row]++] = i;
      table--;
      row++;
    }
  }
  free(table);
  return ans;
}
