// 2521. Distinct Prime Factors of Product of Array
#include "leetcode.h"

/*
 * given an array of positive integers 'nums', return the number of distinct
 * prime factors in the product of the element of 'nums'. note that a number
 * greater than 1 is called prime if it is divisible by only 1 and itself. an
 * integer 'val1' is a factor of another integer 'val2' if 'val2 / val1' is an
 * integer
 */

bool prime(int n) {
  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int *prime_arr(int n, int *return_size) {
  int *arr = (int *)malloc(n * sizeof(int)), cnt = 0;
  for (int i = 2; i <= n; i++)
    if (!(n % i) && prime(i)) {
      arr[cnt] = i;
      cnt++;
      while (!(n % i))
        n /= i;
    }
  *return_size = cnt;
  return arr;
}

bool contains(int *arr, int arr_size, int n) {
  for (int i = 0; i < arr_size; i++)
    if (arr[i] == n)
      return true;
  return false;
}

int distinctPrimeFactors(int *nums, int numsSize) {
  int cnt = 0, arr[10000];
  for (int i = 0; i < numsSize; i++) {
    int n = nums[i], tmp, *prime = prime_arr(n, &tmp);
    for (int j = 0; j < tmp; j++)
      if (!contains(arr, cnt, prime[j])) {
        arr[cnt] = prime[j];
        cnt++;
      }
  }
  return cnt;
}

int main() {
  int n1[] = {2, 4, 3, 7, 10, 6}, n2[] = {2, 4, 8, 16};
  printf("%d\n", distinctPrimeFactors(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", distinctPrimeFactors(n2, ARRAY_SIZE(n2))); // expect: 1
}
