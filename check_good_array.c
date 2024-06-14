// 1250. Check If It Is a Good Array
#include <stdbool.h>
#include <stdio.h>

/*
 * given an array 'nums' of positive integers. your task is to select some
 * subset of 'nums', multiply each element by an integer and add all these
 * numbers. the array is said to be good if you can obtain a sum of 1 from the
 * array by any possible subset and multiplicand. return 'true' if the array is
 * good, otherwise return 'false'
 */

int gcd(int a, int b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}

bool isGoodArray(int *nums, int nums_size) {
  if (nums_size == 1)
    return (nums[0] == 1);
  int flag = gcd(nums[0], nums[1]);
  for (int i = 2; i < nums_size; i++)
    flag = gcd(flag, nums[i]);
  return flag == 1;
}

int main() {
  int n1[] = {12, 5, 7, 23}, n2[] = {29, 6, 10}, n3[] = {3, 6};
  printf("%d\n", isGoodArray(n1, 4)); // expect: 1
  printf("%d\n", isGoodArray(n2, 3)); // expect: 1
  printf("%d\n", isGoodArray(n3, 2)); // expect: 0
}
