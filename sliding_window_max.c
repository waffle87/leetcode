// 239. Sliding Window Maximum
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums', there is a sliding window of size 'k',
 * which is moving from the very left of the array to the very right. you can
 * only see the 'k' numbers in each window. each time the sliding window moves
 * right by one position. return the max sliding window.
 */

void pushQueue(int *queue, int *head, int *tail, int val) {
  if (val <= queue[*tail - 1]) {
    queue[*tail] = val;
    *tail = *tail + 1;
    return;
  }
  int left = *head, right = *tail - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (queue[mid] < val)
      right = mid;
    else
      left = mid + 1;
  }
  queue[left] = val;
  *tail = left + 1;
}
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
  int N = k + 1;
  int n = numsSize;
  int *ans = malloc((numsSize - k + 1) * sizeof(int));
  int *queue = malloc(n * sizeof(int));
  queue[0] = nums[0];
  int head = 0, tail = 1;
  int i, j;
  for (i = 1; i < k; i++) {
    if (nums[i] <= queue[tail - 1]) {
      queue[tail] = nums[i];
      tail++;
      continue;
    }
    for (j = head; j < tail; j++) {
      if (nums[i] > queue[j]) {
        queue[j] = nums[i];
        tail = j + 1;
        break;
      }
    }
    if (j == tail) {
      queue[tail] = nums[i];
      tail = tail + 1;
    }
  }
  ans[0] = queue[0];
  int idx = 1;
  for (int i = k; i < n; i++) {
    if (nums[i] > queue[head]) {
      queue[head] = nums[i];
      ans[idx] = queue[head];
      tail = head + 1;
    } else {
      pushQueue(queue, &head, &tail, nums[i]);
      if (nums[i - k] == queue[head])
        head = head + 1;
      ans[idx] = queue[head];
    }
    idx++;
  }
  *returnSize = idx;
  return ans;
}

int main() {
  int n1[] = {1, 3, -1, -3, 5, 3, 6, 7}, n2[] = {1};
  int ns1 = 8, ns2 = 1;
  int k1 = 3, k2 = 1;
  int rs1[] = {}, rs2[] = {};
  int *msw1 = maxSlidingWindow(n1, ns1, k1, rs1);
  int *msw2 = maxSlidingWindow(n2, ns2, k2, rs2);
  for (int i = 0; i < 6; i++)
    printf("%d ", msw1[i]); // expect: 3,3,5,5,6,7
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%d ", msw2[i]); // expect: 1
  printf("\n");
}
