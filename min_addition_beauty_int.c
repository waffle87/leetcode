// 2457. Minimum Addition to Make Integer Beautiful
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given: two positive integers 'n' & 'target'
 * an integer is considered beautiful if the sum of its
 * digits is less than or equal to the target.
 * return minimum non-negative integer 'x' such that 'n + x'
 * is beautiful.
 */

long long makeIntegerBeautiful(long long n, int target) {
  int *data = malloc(sizeof(int) * 64);
  int digit = 0, idx = 0;
  long long val = n, ans;
  while (val) {
    data[idx] = val % 10;
    digit += data[idx];
    idx++;
    val /= 10;
  }
  if (digit <= target) {
    ans = 0;
    goto exit;
  }
  digit = 0;
  for (int i = idx - 1; i >= 0; i--) {
    digit += data[i];
    if (digit >= target) {
      long long tmp = 0;
      for (int j = i; j >= 0; j--)
        tmp = tmp * 10 + data[j];
      ans = pow(10, i + 1) - tmp;
      break;
    }
  }
exit:
  free(data);
  return ans;
}

int main() {
  printf("%llu\n", makeIntegerBeautiful(16, 6));  // expect: 4
  printf("%llu\n", makeIntegerBeautiful(467, 6)); // expect: 33
  printf("%llu\n", makeIntegerBeautiful(1, 1));   // expect: 0
}
