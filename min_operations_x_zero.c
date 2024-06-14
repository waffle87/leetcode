// 1658. Minimum Operations to Reduce X to Zero
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums' and an integer 'x'. in one operation, you can
 * either remove the leftmost or the rightmost element from the array 'nums' and
 * subtract its value from 'x'. note that this modifies the array for future
 * operations. return the minimum number of operations to reduce 'x' to exactly
 * 0. if it is possible, otherwise return -1
 */

int minOperations(int *nums, int nums_size, int x) {
  int n = nums_size, mod = 1e5 + 7, i;
  bool *table = calloc(mod, sizeof(bool));
  int **hash = malloc(sizeof(int *) * mod);
  long long pre_sum = nums[n - 1];
  hash[pre_sum % mod] = calloc(2, sizeof(int));
  hash[pre_sum % mod][0] = nums[n - 1];
  hash[pre_sum % mod][1] = n - 1;
  table[pre_sum % mod] = true;
  for (i = n - 2; i >= 0; i--) {
    pre_sum += nums[i];
    if (pre_sum > x)
      break;
    if (!table[pre_sum % mod]) {
      table[pre_sum % mod] = true;
      hash[pre_sum % mod] = calloc(2, sizeof(int));
      hash[pre_sum % mod][0] = pre_sum;
      hash[pre_sum % mod][1] = i;
    } else {
      int pos = pre_sum + 1;
      while (table[pos % mod])
        pos++;
      table[pos % mod] = true;
      hash[pos % mod] = calloc(2, sizeof(int));
      hash[pos % mod][0] = pre_sum;
      hash[pos % mod][1] = i;
    }
  }
  if (i == -1 && pre_sum == x)
    return n;
  int min = INT_MAX, sum = 0, k = 0;
  while (sum <= x && k < n) {
    int rem = x - sum;
    if (!rem) {
      min = fmin(min, k);
      break;
    }
    if (table[rem % mod]) {
      if (hash[rem % mod][0] == rem) {
        if (k >= hash[rem % mod][1])
          break;
        if (n - hash[rem % mod][1] + k < min)
          min = n - hash[rem % mod][1] + k;
      } else {
        int pos = rem + 1;
        while (table[pos % mod]) {
          if (hash[pos % mod][0] == rem) {
            if (k >= hash[pos % mod][1])
              break;
            if (n - hash[pos % mod][1] + k < min)
              min = n - hash[pos % mod][1] + k;
          }
          pos++;
        }
      }
    }
    sum += nums[k];
    k++;
  }
  if (min == INT_MAX)
    return -1;
  else
    return min;
}

int main() {
  int n1[] = {1, 1, 4, 2, 3}, n2[] = {5, 6, 7, 8, 9},
      n3[] = {3, 2, 20, 1, 1, 3};
  printf("%d\n", minOperations(n1, 5, 5));  // expect: 2
  printf("%d\n", minOperations(n2, 5, 4));  // expect: -1
  printf("%d\n", minOperations(n3, 6, 10)); // expect: 5
}
