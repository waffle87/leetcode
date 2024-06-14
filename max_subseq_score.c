// 2542. Maximum Subsequence Score
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given two 0-indexed integer arrays 'num1' and 'nums2' of equal length 'n' and
 * a positive integer 'k'. you must choose a subsequence of indices from 'nums1'
 * of length 'k'. for chosen indices 'i0, i1, ..., ik-1', your score is defined
 * as
 * - the sum of the selected elements from 'nums1' multiplied with the minimum
 * of the selected elements from 'nums2'
 * - it can defined simply as '(num1[i0] + nums1[i1] + ... + nums1[ik - 1]) *
 * min(nums2[i0], nums2[i1], ..., nums2[ik - 1])' return the maximum possible
 * score. a subseqnce of indices of an array is a set that can be derived from
 * the set '{0, 1, ..., n - 1}' by deleting no elements
 */

int cmp(const void *a, const void *b) {
  int *ptr_a = *(int **)a;
  int *ptr_b = *(int **)b;
  if (ptr_a[1] == ptr_b[1])
    return ptr_a[0] - ptr_b[0];
  return ptr_a[1] - ptr_b[1];
}

int cmp1(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void insert(int *heap, int k, int val, long long *sum) {
  if (val <= heap[0])
    return;
  int f = 0;
  *sum = *sum + val - heap[0];
  heap[0] = val;
  while (1) {
    int child1 = 2 * f + 1;
    int child2 = 2 * f + 2;
    if (child2 < k) {
      if (heap[child1] <= heap[child2]) {
        if (heap[child1] < heap[f]) {
          int tmp = heap[child1];
          heap[child1] = heap[f];
          heap[f] = tmp;
          f = child1;
        } else
          break;
      } else {
        if (heap[child2] < heap[f]) {
          int tmp = heap[child2];
          heap[child2] = heap[f];
          heap[f] = tmp;
          f = child2;
        } else
          break;
      }
    } else if (child1 < k) {
      if (heap[child1] < heap[f]) {
        int tmp = heap[child1];
        heap[child1] = heap[f];
        heap[f] = tmp;
        f = child1;
      } else
        break;
    } else
      break;
  }
}

long long maxScore(int *nums1, int nums1_size, int *nums2, int nums2_size,
                   int k) {
  long long ans = 0, sum = 0;
  int n = nums1_size;
  int **tmp = malloc(n * sizeof(int *));
  int *heap = malloc(2 * k * sizeof(int));
  for (int i = 0; i < n; i++) {
    tmp[i] = malloc(2 * sizeof(int));
    tmp[i][0] = nums1[i];
    tmp[i][1] = nums2[i];
  }
  qsort(tmp, n, sizeof(int *), cmp);
  for (int i = 0; i < k; i++) {
    heap[i] = tmp[n - 1 - i][0];
    sum += tmp[n - 1 - i][0];
  }
  ans = sum * (long long)tmp[n - k][1];
  qsort(heap, k, sizeof(int), cmp1);
  for (int i = n - k - 1; i >= 0; i--) {
    insert(heap, k, tmp[i][0], &sum);
    ans = fmax(ans, sum * tmp[i][1]);
  }
  return ans;
}

int main() {
  int n11[] = {1, 3, 3, 2}, n21[] = {2, 1, 3, 4};
  int n12[] = {4, 2, 3, 1, 1}, n22[] = {7, 5, 10, 9, 6};
  printf("%lld\n", maxScore(n11, 4, n21, 4, 3)); // expect: 12
  printf("%lld\n", maxScore(n12, 5, n22, 5, 1)); // expect: 30
}
