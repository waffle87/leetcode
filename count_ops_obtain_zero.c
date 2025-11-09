// 2169. Count Operations to Obtain Zero
#include "leetcode.h"

/*
 * you are given two non-negative integers 'num1' and 'num2'. in one operation,
 * if 'num1 >= num2', you must subtract 'num2' from 'num1' otherwise subtract
 * 'num1' from 'num2'. return the number of operations required to make either
 * 'num1 = 0', or 'num2 = 0'
 */

static inline __attribute__((always_inline)) int32_t iif(int32_t a, int32_t b,
                                                         int c) {
  return (a & (-c)) + (b & (~(-c)));
}

static inline __attribute__((always_inline)) void swap(int32_t *a, int32_t *b) {
  int32_t cond = iif(~(int32_t)0, 0, *a > *b);
  int32_t mask = (*a ^ *b) & cond;
  *a ^= mask;
  *b ^= mask;
}

int countOperations(int num1, int num2) {
  int cnt = 0;
  while (num1 && num2) {
    swap(&num2, &num1);
    int tmp = num1 / num2;
    cnt += tmp;
    num1 -= tmp * num2;
  }
  return cnt;
}

int main() {
  printf("%d\n", countOperations(2, 3));   // expect: 3
  printf("%d\n", countOperations(10, 10)); // expect: 1
}
