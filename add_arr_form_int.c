// 989. Add to Array-Form of Integer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * the array-form of an integer 'num' is an array representing its digits in
 * left to right order. eg 'num = 1231', the array form is 1,3,2,1. given 'num',
 * the array form of an integer, and an integer 'k', return the array-form of
 * 'num + k'
 */

int *addToArrayForm(int *num, int numSize, int k, int *returnSize) {
  int *k_arr, *ans, k_size, r_size, p;
  for (int i = k, k_size = 0; i > 0; i /= 10)
    k_size++;
  k_arr = malloc(sizeof(int) * k_size);
  for (int i = k_size - 1, p = k; i >= 0; p /= 10)
    k_arr[i--] = p % 10;
  r_size = k_size > numSize ? k_size : numSize;
  ans = malloc(sizeof(int) * (++r_size));
  for (int i = numSize, j = k_size, c = 0, p = r_size - 1; p >= 0; p--) {
    c += i > 0 ? num[--i] : 0;
    c += j > 0 ? k_arr[--j] : 0;
    ans[p] = c % 10;
    c /= 10;
  }
  if (ans[0] == 0)
    memmove(ans, ans + 1, sizeof(int) * (--r_size));
  *returnSize = r_size;
  free(k_arr);
  return ans;
}

int main() {
  int num1[] = {1, 2, 0, 0}, ns1 = 4, k1 = 34, rs1[] = {4};
  int num2[] = {2, 7, 4}, ns2 = 3, k2 = 181, rs2[] = {3};
  int num3[] = {2, 1, 4}, ns3 = 3, k3 = 806, rs3[] = {4};
  printf("%d\n" * addToArrayForm(num1, ns1, k1, rs1));
  printf("%d\n" * addToArrayForm(num2, ns2, k2, rs2));
  printf("%d\n" * addToArrayForm(num3, ns3, k3, rs3));
}
