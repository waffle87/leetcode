// 645. Set Mismatch
#include "leetcode.h"

/*
 * you have a set of integers 's' which originally contains all the numbers from
 * 1 to 'n'. unfortunately, due to some error, one of the numbers in 's' was
 * duplicated to another number in the sett, which results in reptition of one
 * number and loss of another number. given an integer array 'nums' representing
 * the data state of this set after the error. find the number that occurs twice
 * and the number that is missing and return them in the form of an array
 */

int *findErrorNums(int *nums, int nums_size, int *return_size) {
  int a[10001] = {0};
  int *ans = (int *)malloc(sizeof(int) * 2);
  *return_size = 2;
  for (int i = 0; i < nums_size; i++)
    if (++a[nums[i]] == 2)
      ans[0] = nums[i];
  for (int i = 1; i <= nums_size; i++)
    if (!a[i]) {
      ans[1] = i;
      return ans;
    }
  return ans;
}

int main() {
  int n1[] = {1, 2, 2, 4}, n2[] = {1, 1};
  int rs1[] = {}, rs2[] = {};
  int *fen1 = findErrorNums(n1, ARRAY_SIZE(n1), rs1);
  int *fen2 = findErrorNums(n2, ARRAY_SIZE(n2), rs2);
  for (int i = 0; i < ARRAY_SIZE(n1) / 2; i++)
    printf("%d ", fen1[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", fen2[i]); // expect: 1 2
  printf("\n");
}
