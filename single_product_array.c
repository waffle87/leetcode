// 1822. Sign of the Product of an Array
#include <stdio.h>

/*
 * there is a function signFunc(x) that returns
 * 1 if x is positive
 * -1 if x is negative
 *  0 if x is equal to 0
 *  given an integer array 'nums', let 'product' be the product
 *  of all values in the array 'nums' return signFunc(product)
 */

int arraySign(int *nums, int nums_size) {
  int sign = 1;
  for (int i = 0; i < nums_size; i++) {
    if (!nums[i])
      return 0;
    else if (nums[i] < 0)
      sign = -sign;
  }
  return sign;
}

int main() {
  int n1[] = {-1, -2, -3, -4, 3, 2, 1};
  int n2[] = {1, 5, 0, 2, -3};
  int n3[] = {-1, 1, -1, 1, -1};
  printf("%d\n", arraySign(n1, 7)); // expect:  1
  printf("%d\n", arraySign(n2, 5)); // expect:  0
  printf("%d\n", arraySign(n3, 5)); // expect: -1
}
