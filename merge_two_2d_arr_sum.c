// 2570. Merge Two 2D Arrays by Summing Values
#include "leetcode.h"

/*
 * you are given two 2d integer arrays 'nums1' and 'nums2'. 'nums1[i] = [id_i,
 * val_i]' indicate that the number with id 'id_i' has a value equal. to
 * 'val_i'. 'nums2[i] = [id_i, val_i]' indicates that the number with the id
 * 'id_i' has a value equal to 'val_i'. each array contains unique ids and is
 * sorted in ascending order by id. merge the two arrays into one array that is
 * sorted in ascending order by id. return the resulting array. the returned
 * array must be sorted in ascending order by id.
 */

int **mergeArrays(int **nums1, int nums1Size, int *nums1ColSize, int **nums2,
                  int nums2Size, int *nums2ColSize, int *returnSize,
                  int **returnColumnSizes) {
  int **ans = (int **)malloc((nums1Size + nums2Size) * sizeof(int *));
  for (int i = 0; i < nums1Size + nums2Size; i++)
    ans[i] = (int *)calloc(2, sizeof(int));
  *returnColumnSizes = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
  for (int i = 0; i < nums1Size + nums2Size; i++)
    (*returnColumnSizes)[i] = 2;
  *returnSize = 0;
  int i = 0, j = 0, k = 0;
  bool valid = false;
  while (1) {
    valid = false;
    if (j < nums1Size)
      if (i == nums1[j][0]) {
        ans[(*returnSize)][0] = i;
        ans[(*returnSize)][1] += nums1[j][1];
        valid = true;
        j++;
      }
    if (k < nums2Size)
      if (i == nums2[k][0]) {
        ans[(*returnSize)][0] = i;
        ans[(*returnSize)][1] += nums2[k][1];
        valid = true;
        k++;
      }
    if (valid)
      (*returnSize)++;
    if (k == nums2Size && j == nums1Size)
      break;
    i++;
  }
  return ans;
}

int main() {
  int n11i[3][2] = {{1, 2}, {2, 3}, {4, 5}},
      n21i[3][2] = {{1, 4}, {3, 2}, {4, 1}}, rs1, *rcs1;
  int n12i[3][2] = {{2, 4}, {3, 6}, {5, 5}}, n22i[2][2] = {{1, 3}, {4, 3}}, rs2,
      *rcs2;
  struct two_d_arr *n11 =
      two_d_arr_init(ARRAY_SIZE(n11i), ARRAY_SIZE(n11i[0]), n11i);
  struct two_d_arr *n21 =
      two_d_arr_init(ARRAY_SIZE(n21i), ARRAY_SIZE(n21i[0]), n21i);
  struct two_d_arr *n12 =
      two_d_arr_init(ARRAY_SIZE(n12i), ARRAY_SIZE(n12i[0]), n12i);
  struct two_d_arr *n22 =
      two_d_arr_init(ARRAY_SIZE(n22i), ARRAY_SIZE(n22i[0]), n22i);
  int **ma1 = mergeArrays(n11->arr, n11->row_size, n11->col_size, n21->arr,
                          n21->row_size, n21->col_size, &rs1, &rcs1);
  int **ma2 = mergeArrays(n12->arr, n12->row_size, n12->col_size, n22->arr,
                          n22->row_size, n22->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", ma1[i][j]); // expect: [[1,6],[2,3],[3,2],[4,6]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", ma2[i][j]); // expect: [[1,3],[2,4],[3,6],[4,3],[5,5]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(ma1[i]);
  free(ma1);
  free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(ma2[i]);
  free(ma2);
  free(rcs2);
  two_d_arr_free(n11);
  two_d_arr_free(n21);
  two_d_arr_free(n12);
  two_d_arr_free(n22);
}
