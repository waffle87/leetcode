// 442. Find All Duplicates in an Array
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums' of length 'n' where all the integers of 'nums'
 * are in the range [1, n] and each integer appears once or twice. return an
 * array of all the integers that appears twice. you must write an algorithm
 * that run O(n) time and uses only constant extra space.
 */

int *findDuplicats(int *nums, int nums_size, int *return_size) {
  if (!nums || nums_size < 2) {
    *return_size = 0;
    return 0;
  }
  int *ans = NULL;
  *return_size = 0;
  for (int i = 0; i < nums_size; i++) {
    int ti = abs(nums[i]) - 1;
    if (nums[ti] < 0) {
      *return_size += 1;
      ans = realloc(ans, sizeof(int));
      ans[*return_size - 1] = abs(nums[i]);
    } else
      nums[ti] = -1 * nums[ti];
  }
  return ans;
}

int main() {
  int n1[] = {4, 3, 2, 7, 8, 2, 3, 1}, ns1 = 8, rs1[] = {};
  int n2[] = {1, 1, 2}, ns2 = 3, rs2[] = {};
  int n3[] = {1}, ns3 = 1, rs3[] = {};
  int *fd1 = findDuplicats(n1, ns1, rs1);
  int *fd2 = findDuplicats(n2, ns2, rs2);
  int *fd3 = findDuplicats(n3, ns3, rs3);
  for (int i = 0; i < ns1; i++)
    printf("%d ", fd1[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < ns2; i++)
    printf("%d ", fd2[i]); // expect: 1
  printf("\n");
  for (int i = 0; i < ns3; i++)
    printf("%d ", fd3[i]); // expect:
  printf("\n");
}
