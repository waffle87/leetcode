// 2553. Separate the Digits in an Array
#include "leetcode.h"

/*
 * given an array of positive integers 'nums', return an array 'answer' that
 * consists of the digits of each integer in 'nums'. to separate the digits of
 * an integer is to get all the digits it has in the same order.
 */

int *separateDigits(int *nums, int numsSize, int *returnSize) {
  int digit_cnt = 0, index = 0;
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i];
    if (!x)
      digit_cnt++;
    else {
      while (x > 0) {
        digit_cnt++;
        x /= 10;
      }
    }
  }
  int *ans = (int *)malloc(digit_cnt * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i], m = 0;
    int *tmp = (int *)malloc(10 * sizeof(int));
    if (!x) {
      ans[index++] = 0;
      continue;
    }
    while (x > 0) {
      tmp[m++] = x % 10;
      x /= 10;
    }
    for (int j = m - 1; j >= 0; j--)
      ans[index++] = tmp[j];
    free(tmp);
  }
  *returnSize = digit_cnt;
  return ans;
}

int main() {
  int n1[] = {13, 25, 83, 77}, r1[] = {1, 3, 2, 5, 8, 3, 7, 7}, rs1;
  int n2[] = {7, 1, 3, 9}, r2[] = {7, 1, 3, 9}, rs2;
  int *sd1 = separateDigits(n1, ARRAY_SIZE(n1), &rs1);
  int *sd2 = separateDigits(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", sd1[i]);
    assert(sd1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", sd2[i]);
    assert(sd2[i] == r2[i]);
  }
  printf("\n");
}
