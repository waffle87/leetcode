// 907. Sum of Subarray Minimums
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'arr', find the sum of 'min(b)', where 'b' ranges
 * over every contiguous subarray of 'arr'. since the answer may be large,
 * return the answer modulo 10^9+7
 */

int sumSubarrayMins(int *arr, int arr_size) {
  int *stk = calloc(arr_size, sizeof(int));
  int *ple = calloc(arr_size, sizeof(int));
  int *nle = calloc(arr_size, sizeof(int));
  int pt = -1;
  for (int i = 0; i < arr_size; i++) {
    ple[i] = i + 1;
    nle[i] = arr_size - i;
  }
  for (int i = 0; i < arr_size; i++) {
    while (pt != -1 && arr[stk[pt]] > arr[i]) {
      int x = stk[pt];
      nle[x] = i - x;
      pt--;
    }
    ple[i] = (pt == -1 ? i + 1 : i - stk[pt]);
    stk[++pt] = i;
  }
  free(stk);
  int sum = 0, mod = 1e9 + 7;
  for (int i = 0; i < arr_size; i++)
    sum = (sum + arr[i] * (unsigned)ple[i] * (unsigned)nle[i]) % mod;
  free(ple), free(nle);
  return sum;
}

int main() {
  int a1[] = {3, 1, 2, 4}, a2[] = {11, 81, 94, 43, 3};
  printf("%d\n", sumSubarrayMins(a1, 4)); // expect: 17
  printf("%d\n", sumSubarrayMins(a2, 5)); // expect: 444
}
