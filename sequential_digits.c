// 1291. Sequential Digits
#include "leetcode.h"

/*
 * an integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit. return a sorted list of all the integers in
 * the range '[low, high]' inclusive that have sequential digits.
 */

int *sequentialDigits(int low, int high, int *returnSize) {
  static int nums[36] = {
      12,      23,       34,       45,       56,     67,     78,      89,
      123,     234,      345,      456,      567,    678,    789,     1234,
      2345,    3456,     4567,     5678,     6789,   12345,  23456,   34567,
      45678,   56789,    123456,   234567,   345678, 456789, 1234567, 2345678,
      3456789, 12345678, 23456789, 123456789};
  int *ans = NULL;
  *returnSize = 0;
  for (int i = 0; i < 36; i++) {
    if (nums[i] < low)
      continue;
    if (nums[i] > high)
      break;
    (*returnSize)++;
    ans = (int *)realloc(ans, (*returnSize) * sizeof(int));
    ans[(*returnSize) - 1] = nums[i];
  }
  return ans;
}

int main() {
  int rs1, r1[] = {123, 234};
  int rs2, r2[] = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
  int *sd1 = sequentialDigits(100, 300, &rs1);
  int *sd2 = sequentialDigits(1000, 13000, &rs2);
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
  free(sd1);
  free(sd2);
}
