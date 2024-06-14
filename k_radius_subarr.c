// 2090. K Radius Subarray Averages
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed array 'nums' of 'n' integers, and an integer 'k'. the
 * k-radius average for a subarray of 'nums' centered at some index 'i' with the
 * radius 'k' is the average of all elements in 'nums' between the indices 'i -
 * k' and 'i + k' (inclusive). if there are less than 'k' elements before or
 * after the index 'i', then the k-radius average is -1. build and return 'avgs'
 * of length 'n' where 'avgs[i]' is the k-radius average for the subarray
 * centered at index 'i'. the average of 'x' elements is the sum of the 'x'
 * elements divided by 'x', using integer division. the integer division
 * truncates toward zero, which means losing its fractional part.
 */

int *getAverages(int *nums, int nums_size, int k, int *return_size) {
  int n = nums_size, d = 2 * k + 1;
  int *ans = malloc(n * sizeof(int));
  *return_size = n;
  long long sum = 0;
  if (n < d) {
    for (int i = 0; i < n; i++)
      ans[i] = -1;
    return ans;
  }
  for (int i = 0; i < k; i++) {
    ans[i] = -1;
    sum += nums[i];
  }
  sum += nums[k];
  for (int i = k + 1; i < 2 * k + 1; i++)
    sum += nums[i];
  ans[k] = sum / d;
  for (int i = k + 1; i < n - k; i++) {
    int d = nums[i + k] - nums[i - k - 1];
    if (!d)
      ans[i] = ans[i - 1];
    else {
      sum += d;
      ans[i] = sum / d;
    }
  }
  for (int i = 0; i < k; i++)
    ans[n - 1 - i] = -1;
  return ans;
}

int main() {
  int n1[] = {7, 4, 3, 9, 1, 8, 5, 2, 6}, ns1 = 9, k1 = 3, rs1[] = {};
  int n2[] = {100000}, ns2 = 1, k2 = 0, rs2[] = {};
  int n3[] = {8}, ns3 = 1, k3 = 100000, rs3[] = {};
  int *ga1 = getAverages(n1, ns1, k1, rs1);
  int *ga2 = getAverages(n2, ns2, k2, rs2);
  int *ga3 = getAverages(n3, ns3, k3, rs3);
  for (int i = 0; i < ns1; i++)
    printf("%d ", ga1[i]); // expect: -1,-1,-1,5,4,4,-1,-1,-1
  printf("\n");
  for (int i = 0; i < ns2; i++)
    printf("%d ", ga2[i]); // expect: 100000
  printf("\n");
  for (int i = 0; i < ns3; i++)
    printf("%d ", ga3[i]); // expect: -1
  printf("\n");
}
