// 1425. Constrained Subsequence Sum
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums' and an integer 'k', return the maximum sum of a
 * non-empty subsequnce of that array for every two consecutive integers in the
 * subsequence 'nums[i] and 'nums[j] where 'i < j', the condition 'j - i <= k'
 * is satisfied. a subsequence of an array is obtained by deleting some number
 * of elements (can be zero) from the array, leaving the remaining elements in
 * their original order.
 */

int bfs(int *nums, int n, int val) {
  int left = 0, right = n - 1, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (nums[mid] >= val)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int constrainedSubsetSum(int *nums, int nums_size, int k) {
  int n = nums_size, max = INT_MIN, head = 0, tail = 1;
  int *queue = malloc((n + 1) * sizeof(int));
  int *dp = malloc((n + 1) * sizeof(int));
  dp[0] = 0;
  queue[head] = 0;
  for (int i = 1; i <= k; i++) {
    dp[i] = nums[i - 1];
    if (queue[head])
      dp[i] += queue[head];
    max = fmax(max, dp[i]);
    if (dp[i] < 0)
      continue;
    else if (dp[i] > queue[head]) {
      queue[head] = dp[i];
      tail = head + 1;
    } else if (dp[i] <= queue[tail - 1]) {
      queue[tail] = dp[i];
      tail++;
    } else {
      int m = bfs(&queue[head], tail - head, dp[i]);
      queue[head + m] = dp[i];
      tail = head + m + 1;
    }
  }
  for (int i = k + 1; i <= n; i++) {
    dp[i] = nums[i - 1];
    if (queue[head])
      dp[i] += queue[head];
    max = fmax(max, dp[i]);
    if (queue[head] == dp[i - k] && dp[i - k]) {
      head++;
      if (head == tail) {
        queue[head] = 0;
        tail = head + 1;
      }
    }
    if (dp[i] < 0)
      continue;
    else if (dp[i] > queue[head]) {
      queue[head] = dp[i];
      tail = head + 1;
    } else if (dp[i] <= queue[tail - 1]) {
      queue[tail] = dp[i];
      tail++;
    } else {
      int m = bfs(&queue[head], tail - head, dp[i]);
      queue[head + m] = dp[i];
      tail = head + m + 1;
    }
  }
  return max;
}

int main() {
  int n1[] = {10, 2, -10, 5, 20}, n2[] = {-1, -2, -3},
      n3[] = {10, -2, -10, -5, 20};
  printf("%d\n", constrainedSubsetSum(n1, 5, 2)); // expect: 37
  printf("%d\n", constrainedSubsetSum(n2, 3, 1)); // expect: -1
  printf("%d\n", constrainedSubsetSum(n3, 5, 2)); // expect: 23
}
