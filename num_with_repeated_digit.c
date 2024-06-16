// 1012. Numbers With Repeated Digits
#include "leetcode.h"

/*
 * given an integer 'n', return the number of positive integers in range '[1,
 * n]' that have at least one repeated digit.
 */

static inline int cnt_digits(int n) {
  int cnt = 0;
  while (n) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int numDupDigitsAtMostN(int n) {
  const int n_orig = n, dig_orig = cnt_digits(n);
  bool used[10] = {false};
  int cnt = 0, multiple = 1;
  for (int i = 1; i < dig_orig; i++)
    multiple *= 10;
  const int mult_orig = multiple;
  if (n / multiple > 1) {
    int add = (n / multiple) - 1;
    for (int i = 1; i < dig_orig; i++)
      add *= 10 - i;
    cnt += add;
  }
  for (int i = dig_orig; i > 0; i--) {
    const int high_dig = n / multiple, high_n = high_dig * multiple;
    n -= high_n;
    multiple /= 10;
    if (used[high_dig])
      break;
    else if (i == 1)
      cnt++;
    else {
      const int next_high = n / multiple;
      int num_options = 0, num_used = 0;
      used[high_dig] = true;
      for (int j = 0; j < 10; j++) {
        if (!used[i]) {
          if (i < next_high)
            num_options++;
        } else
          num_used++;
      }
      if (num_options) {
        int add = num_options;
        num_used++;
        for (; num_used < dig_orig; num_used++)
          add *= 10 - num_used;
        cnt += add;
      }
    }
  }
  n = n_orig;
  multiple = mult_orig;
  for (int i = dig_orig; i > 0; i--) {
    const int high_dig = n / multiple, high_n = high_dig * multiple;
    if (i > 1) {
      int add = 9;
      for (int j = 1; j < i - 1; j++)
        add *= 10 - j;
      cnt += add;
    }
    n -= high_n;
    multiple /= 10;
  }
  return n_orig - cnt;
}

int main() {
  printf("%d\n", numDupDigitsAtMostN(20));   // expect: 1
  printf("%d\n", numDupDigitsAtMostN(100));  // expect: 10
  printf("%d\n", numDupDigitsAtMostN(1000)); // expect: 262
}
