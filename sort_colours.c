// 75. Sort Colors
#include "leetcode.h"

/*
 * given an array 'nums' with 'n' objects coloured red, white, or blue, sort
 * them in place so that objects of the same colour are adjacent with the
 * colours in the order red, white and blue. we will use the integer 0,1,2 to
 * represent the colour red, white, and blue respecitvely. you must solve this
 * problem without the library's sort function.
 */

void sortColors(int *nums, int numsSize) {
  int two_ptr = numsSize - 1, zero_ptr = 0, one_ptr = 0;
  while (one_ptr <= two_ptr) {
    if (!nums[one_ptr]) {
      int tmp = nums[zero_ptr];
      nums[zero_ptr] = nums[one_ptr];
      nums[one_ptr] = tmp;
      one_ptr++;
      zero_ptr++;
    } else if (nums[one_ptr] == 1)
      one_ptr++;
    else {
      int tmp = nums[two_ptr];
      nums[two_ptr] = nums[one_ptr];
      nums[one_ptr] = tmp;
      two_ptr--;
    }
  }
}

int main() {
  int n1[] = {2, 0, 2, 1, 1, 0}, n2[] = {2, 0, 1};
  sortColors(n1, ARRAY_SIZE(n1));
  sortColors(n2, ARRAY_SIZE(n2));
  for (int i = 0; i < ARRAY_SIZE(n1); i++)
    printf("%d ", n1[i]);
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", n2[i]);
  printf("\n");
}
