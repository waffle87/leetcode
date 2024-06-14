// 1122. Relative Sort Array
#include "leetcode.h"

/*
 * given two arrays 'arr1' and 'arr2', the elements of 'arr2' are distinct and
 * all elements in 'arr2' are also in 'arr1'. sort the elements of 'arr1' such
 * that the relative ordering of items in 'arr1' are the same as in 'arr2'.
 * elements that do not appear in 'arr2' should be placed at the end of 'arr1'
 * in ascending order.
 */

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size,
                       int *returnSize) {
  int cnt = 0;
  for (int i = 0; i < arr2Size; i++)
    for (int j = 0; j < arr1Size; j++)
      if (arr1[j] == arr2[i])
        swap(&arr1[j], &arr1[cnt++]);
  for (int i = cnt; i < arr1Size; i++) {
    int min = arr1[i], idx = i;
    for (int j = i + 1; j < arr1Size; j++)
      if (arr1[j] < min)
        min = arr1[j], idx = j;
    swap(&arr1[i], &arr1[idx]);
  };
  *returnSize = arr1Size;
  return arr1;
}

int main() {
  int a11[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, a21[] = {2, 1, 4, 3, 9, 6},
      a12[] = {28, 6, 22, 8, 44, 17}, a22[] = {22, 28, 8, 6}, rs1, rs2;
  int *rsa1 =
      relativeSortArray(a11, ARRAY_SIZE(a11), a21, ARRAY_SIZE(a21), &rs1);
  int *rsa2 =
      relativeSortArray(a12, ARRAY_SIZE(a12), a22, ARRAY_SIZE(a22), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", rsa1[i]); // expect: 2,2,2,1,4,3,3,9,6,7,19
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", rsa2[i]); // expect: 22,28,8,6,17,44
  printf("\n");
  free(rsa1), free(rsa2);
}
