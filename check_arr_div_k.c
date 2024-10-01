// 1497. Check If Array Pairs Are Divisible by k
#include "leetcode.h"

/*
 * given an array of integers 'arr' of even length 'n' and an integer 'k'. we
 * want to divide the array into exactly 'n / 2' pairs such that the sum of each
 * pair is divisible by 'k'. return 'true' if you can find a way to to that or
 * 'false' otherwise.
 */

bool canArrange(int *arr, int arrSize, int k) {
  int *freq = (int *)calloc(k, sizeof(int));
  for (int i = 0; i < arrSize; i++) {
    int rem = ((arr[i] % k) + k) % k;
    freq[rem]++;
  }
  if (freq[0] % 2)
    return false;
  if (!(k % 2))
    if (freq[k / 2] % 2) {
      free(freq);
      return false;
    }
  for (int r = 1; r <= k / 2; r++)
    if (r != k - r)
      if (freq[r] != freq[k - r])
        return false;
  return true;
}

int main() {
  int a1[] = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, a2[] = {1, 2, 3, 4, 5, 6},
      a3[] = {1, 2, 3, 4, 5, 6};
  printf("%d\n", canArrange(a1, ARRAY_SIZE(a1), 5));  // expect: 1
  printf("%d\n", canArrange(a2, ARRAY_SIZE(a2), 7));  // expect: 1
  printf("%d\n", canArrange(a3, ARRAY_SIZE(a3), 10)); // expect: 0
}
