// 2462. Total Cost to Hire K Workers
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed integer array 'costs' where 'costs[i]' is the cost of
 * hiring the i'th worker. you are also given two integers 'k, candidates'. we
 * want to hire exactly 'k' workders according to the following rules:
 * - you will run 'k' sessions and hire exactly one worker in each session
 * - in each hiring session, choose the worker with the lowest cost from either
 * the first 'candidates' workers or the last 'candidates' workers. break the
 * tie by the smallest index.
 * - if there are fewer than candidates workers remaining, choose the workder
 * with the lowest cost among them. break the tie by the smallest index.
 * - a worker can only be chosen once
 * return the total cost to hire eactly 'k' workers.
 */

typedef struct {
  int val;
  int idx;
} node;

int cmp(const void *a, const void *b) {
  node *A = *(node **)a;
  node *B = *(node **)b;
  return A->val - B->val;
}
void swap(node **a, node **b) {
  node *tmp = *a;
  *a = *b;
  *b = tmp;
}
void modifyHeap(node **heap, int n) {
  int f = 0;
  while (1) {
    int c1 = 2 * f + 1;
    int c2 = 2 * f + 2;
    if (c2 < n) {
      if (heap[c1]->val <= heap[c2]->val) {
        if (heap[c1]->val < heap[f]->val) {
          swap(&heap[f], &heap[c1]);
          f = c1;
        } else
          break;
      } else {
        if (heap[c2]->val < heap[f]->val) {
          swap(&heap[f], &heap[c2]);
          f = c2;
        } else
          break;
      }
    } else if (c1 < n) {
      if (heap[c1]->val < heap[f]->val) {
        swap(&heap[f], &heap[c1]);
        f = c1;
      } else
        break;
    } else
      break;
  }
}
int heapPop(node **heap, int *n) {
  int ans = heap[0]->val;
  *n = *n - 1;
  heap[0] = heap[*n];

  int f = 0;
  int N = *n;
  while (1) {
    int c1 = 2 * f + 1;
    int c2 = 2 * f + 2;
    if (c2 < N) {
      if (heap[c1]->val <= heap[c2]->val) {
        if (heap[f]->val > heap[c1]->val) {
          swap(&heap[f], &heap[c1]);
          f = c1;
          continue;
        } else
          break;
      } else {
        if (heap[f]->val > heap[c2]->val) {
          swap(&heap[f], &heap[c2]);
          f = c2;
          continue;
        } else
          break;
      }
    } else if (c1 < N) {
      if (heap[f]->val > heap[c1]->val) {
        swap(&heap[f], &heap[c1]);
        f = c1;
        continue;
      } else
        break;
    } else
      break;
  }
  return ans;
}
long long totalCost(int *costs, int costsSize, int k, int candidates) {
  int n = costsSize;
  int left_cn = candidates;
  int right_cn = candidates;

  if ((left_cn + right_cn) > n) {
    left_cn = n / 2;
    right_cn = n - n / 2;
  }

  long long ans = 0;
  if (k == costsSize) {
    for (int i = 0; i < costsSize; i++) {
      ans = ans + costs[i];
    }
    return ans;
  }

  bool *used = calloc(n, sizeof(bool));
  node **left = malloc(left_cn * sizeof(node *));
  node **right = malloc(right_cn * sizeof(node *));
  for (int i = 0; i < left_cn; i++) {
    left[i] = malloc(sizeof(node));
    left[i]->val = costs[i];
    left[i]->idx = i;
    used[i] = true;
  }
  for (int i = 0; i < right_cn; i++) {
    right[i] = malloc(sizeof(node));
    right[i]->val = costs[n - 1 - i];
    right[i]->idx = n - 1 - i;
    used[n - 1 - i] = true;
  }
  qsort(left, left_cn, sizeof(node *), cmp);
  qsort(right, right_cn, sizeof(node *), cmp);
  int l_idx = left_cn;
  int r_idx = n - 1 - right_cn;

  int item = 0;
  while (item < k) {
    if (left_cn == 0) {
      ans += heapPop(right, &right_cn);
      item++;
      continue;
    }
    if (right_cn == 0) {
      ans += heapPop(left, &left_cn);
      item++;
      continue;
    }
    if (left[0]->val == right[0]->val && left[0]->idx == right[0]->idx) {
      ans += left[0]->val;
      heapPop(left, &left_cn);
      heapPop(right, &right_cn);
    } else if (left[0]->val <= right[0]->val) {
      ans += left[0]->val;
      if (used[l_idx])
        heapPop(left, &left_cn);
      else {
        left[0]->val = costs[l_idx];
        left[0]->idx = l_idx;
        used[l_idx] = true;
        l_idx++;
        modifyHeap(left, left_cn);
      }
    } else {
      ans += right[0]->val;
      if (used[r_idx]) {
        heapPop(right, &right_cn);
      } else {
        right[0]->val = costs[r_idx];
        right[0]->idx = r_idx;
        used[r_idx] = true;
        r_idx--;
        modifyHeap(right, right_cn);
      }
    }
    item++;
  }
  free(used);
  for (int i = 0; i < right_cn; i++)
    free(right[i]);
  for (int i = 0; i < left_cn; i++)
    free(left[i]);
  free(left);
  free(right);
  return ans;
}

int main() {
  int c1[] = {17, 12, 10, 2, 7, 2, 11, 20, 8}, c2[] = {1, 2, 4, 1};
  printf("%lld\n", totalCost(c1, 9, 3, 4)); // expect: 11
  printf("%lld\n", totalCost(c2, 4, 3, 3)); // expect: 4
}
