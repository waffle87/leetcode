// 3483. Unique 3-Digit Even Numbers
#include "leetcode.h"

/*
 * you are given an array of digits called 'digits'. your task is to determine
 * the number of distinct three digit even numbers that can be formed using
 * these digits. note: each copy of a digit can only be used once per number,
 * and there may not be leading zeros.
 */

int totalNumbers(int *digits, int digitsSize) {
  int freq[10] = {0}, ans = 0;
  bool nums[3000] = {false};
  for (int i = 0; i < digitsSize; ++i)
    ++freq[digits[i]];
  for (int i = 0; i < 10; ++i) {
    if (freq[i] > 0 && i != 0) {
      --freq[i];
      for (int j = 0; j < 10; ++j) {
        if (freq[j] > 0) {
          --freq[j];
          for (int k = 0; k < 10; ++k) {
            if (freq[k] > 0 && !(k % 2)) {
              const int sum = (i << 8) + (j << 4) + k;
              if (!nums[sum]) {
                ++ans;
                nums[sum] = true;
              }
            }
          }
          ++freq[j];
        }
      }
      ++freq[i];
    }
  }
  return ans;
}

int main() {
  int d1[] = {1, 2, 3, 4};
  int d2[] = {0, 2, 2};
  int d3[] = {6, 6, 6};
  int d4[] = {1, 3, 5};
  int r1 = totalNumbers(d1, ARRAY_SIZE(d1));
  int r2 = totalNumbers(d2, ARRAY_SIZE(d2));
  int r3 = totalNumbers(d3, ARRAY_SIZE(d3));
  int r4 = totalNumbers(d4, ARRAY_SIZE(d4));
  printf("%d\n", r1);
  assert(r1 == 12);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 1);
  printf("%d\n", r4);
  assert(r4 == 0);
}
