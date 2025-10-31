// 3289. The Two Sneaky Numbers of Digitville
#include "leetcode.h"

/*
 * in the town of digitville, there was a list of numbers called 'nums'
 * containing integers from 0 to 'n - 1'. each number was supposed to appear
 * exactly once in the list, however two mischevious numbers snuck in an
 * additional time, making the list longer than usual. as the town detective,
 * your task is to find these two sneaky numbers. return an array of size 2
 * containing the two numbers, so peace can return to digitville.
 */

int *getSneakyNumbers(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int)), n = numsSize - 2;
  *returnSize = 2;
  unsigned int x = nums[n] ^ nums[n + 1];
  for (int i = 0; i < n; i++)
    x ^= i ^ nums[i];
  int y = 31 - __builtin_clz(x);
  for (int i = 0; i < n; i++) {
    ans[(i >> y) & 1] ^= i;
    ans[(nums[i] >> y) & 1] ^= nums[i];
  }
  ans[(nums[n] >> y) & 1] ^= nums[n];
  ans[(nums[n + 1] >> y) & 1] ^= nums[n + 1];
  return ans;
}

int main() {
  int n1[] = {0, 1, 1, 0}, rs1;
  int n2[] = {0, 3, 2, 1, 3, 2}, rs2;
  int n3[] = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2}, rs3;
  int *gsn1 = getSneakyNumbers(n1, ARRAY_SIZE(n1), &rs1);
  int *gsn2 = getSneakyNumbers(n2, ARRAY_SIZE(n2), &rs2);
  int *gsn3 = getSneakyNumbers(n3, ARRAY_SIZE(n3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gsn1[i]); // expect: 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gsn2[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", gsn3[i]); // expect: 4 5
  printf("\n");
  free(gsn1);
  free(gsn2);
  free(gsn3);
}
