// 238. Product of Array Except Self
#include "leetcode.h"

/*
 * given an integer array 'nums' return an array 'answer' such that 'answer[i]'
 * is equal to the product of all the elements of 'nums' except 'nums[i]'. the
 * product of any prefix or suffix of 'nums' is guaranteed to fit in a 32-bit
 * integer. you must write an algorithm that runs in O(n) time and without the
 * division operation.
 */

int *productExceptSelf(int *nums, int nums_size, int *return_size) {
  int *ans = (int *)malloc(nums_size * sizeof(int));
  *return_size = nums_size;
  ans[0] = 1;
  for (int i = 1; i < nums_size; i++)
    ans[i] = nums[i - 1] * ans[i - 1];
  int tmp = 1;
  for (int i = nums_size - 1; i >= 0; i--) {
    ans[i] *= tmp;
    tmp *= nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {-1, 1, 0, -3, 3};
  int rs1[] = {}, rs2[] = {};
  int *pes1 = productExceptSelf(n1, ARRAY_SIZE(n1), rs1);
  int *pes2 = productExceptSelf(n2, ARRAY_SIZE(n2), rs2);
  for (int i = 0; i < ARRAY_SIZE(n1); i++)
    printf("%d ", pes1[i]); // expect: 24 12 8 6
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", pes2[i]); // expect: 0 0 9 0 0
  printf("\n");
}
