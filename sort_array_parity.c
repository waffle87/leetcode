// 905. Sort Array By Parity
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums', move all the even integers at the beginning of
 * the array followed by all the odd integers. return any array that satisfies
 * this condition
 */

int *sortArrayByParity(int *nums, int nums_size, int *return_size) {
  int left = 0, right = nums_size - 1;
  int *ans = (int *)malloc(sizeof(int) * nums_size);
  *return_size = nums_size;
  for (int i = 0; i < nums_size; i++) {
    if (!(nums[i] % 2))
      ans[left++] = nums[i];
    else
      ans[right--] = nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {3, 1, 2, 4}, n2[] = {0};
  int *sabp1 = sortArrayByParity(n1, 4, NULL);
  int *sabp2 = sortArrayByParity(n2, 1, NULL);
  for (int i = 0; i < 4; i++)
    printf("%d ", sabp1[i]); // expect: 2 4 3 1
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%d ", sabp2[i]); // expect: 0
  printf("\n");
}
