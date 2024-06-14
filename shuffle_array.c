// 1470. Shuffle the Array
#include <stdio.h>
#include <stdlib.h>

/*
 * given array 'nums' consisting of '2n' elements in the form
 * [x1, x2, ..., xn, y1, y2, ..., yn]
 * return the array in the form [x1, y1, x2, y2, ..., xn, yn]
 */

int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
  int i = 0, j = n, k = 0;
  int *ans = (int *)malloc(numsSize * sizeof(int));
  while (i < n && j < numsSize) {
    ans[k++] = nums[i];
    ans[k++] = nums[j];
    i++;
    j++;
  }
  *returnSize = numsSize;
  return ans;
}

int main() {
  int nums1[] = {2, 5, 1, 3, 4, 7}, rs1[] = {6}, ns1 = 6, n1 = 3;
  int nums2[] = {1, 2, 3, 4, 4, 3, 2, 1}, rs2[] = {8}, ns2 = 8, n2 = 4;
  int nums3[] = {1, 1, 2, 2}, rs3[] = {4}, ns3 = 4, n3 = 2;
  printf("%d\n", *shuffle(nums1, ns1, n1, rs1));
  printf("%d\n", *shuffle(nums2, ns2, n2, rs2));
  printf("%d\n", *shuffle(nums3, ns3, n3, rs3));
}
