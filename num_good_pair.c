// 1512. Number of Good Pairs
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums', return the number of good pairs. a pair
 * '(i, j)' is called good if 'nums[i] == nums[j]' and 'i < j'
 */

int numIdenticalPairs(int *nums, int nums_size) {
  int max = nums[0];
  for (int i = 0; i < nums_size; i++)
    max = nums[i] > max ? nums[i] : max;
  max++;
  int *arr = (int *)calloc(max, sizeof(int));
  for (int i = 0; i < nums_size; i++)
    arr[nums[i]]++;
  int ans = 0;
  for (int i = 0; i < max; i++)
    if (arr[i] > 1)
      ans += (arr[i] * (arr[i] - 1) / 2);
  free(arr);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 1, 1, 3}, n2[] = {1, 1, 1, 1}, n3[] = {1, 2, 3};
  printf("%d\n", numIdenticalPairs(n1, 6)); // expect: 4
  printf("%d\n", numIdenticalPairs(n2, 4)); // expect: 6
  printf("%d\n", numIdenticalPairs(n3, 3)); // expect: 0
}
