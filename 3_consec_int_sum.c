// 2177. Find Three Consecutive Integers That Sum to a Given Number
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer 'num', return 3 consecutive integers (as a sorted array)
 * that sum to 'num'. if 'num' cannot be expressed as the sum of 3 consecutive
 * integers, return an empty array.
 */

long long *sumOfThree(long long num, int *returnSize) {
  if ((num - 3) % 3 != 0) {
    *returnSize = 0;
    return NULL;
  }
  *returnSize = 3;
  long long *ans = malloc(3 * sizeof(long long));
  ans[0] = (num - 3) / 3;
  ans[1] = ans[0] + 1;
  ans[2] = ans[1] + 1;
  return ans;
}

int main() {
  long long num1 = 33, num2 = 4;
  int rs1[] = {}, rs2[] = {};
  printf("%p\n", sumOfThree(num1, rs1)); // expect: 10, 11, 12
  printf("%p\n", sumOfThree(num2, rs2)); // expect: nil
}
