// 3691. Maximum Total Subarray Value II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and an integer 'k'. you
 * must select exactly 'k' distinct subarrays 'nums[l ... r]' of 'nums'.
 * subarrays may overlap, but the exact same subarrays (same 'l' and 'r') cannot
 * be chosen more than once. the value of a subarray 'nums[l ... r]' is defined
 * as 'max(nums[l ... r]) - min(nums[l ... r])'. the total value is the sum of
 * the values of all chosen subarrays. return the maximum possible total value
 * you can achieve.
 */

struct node {
  int val;
  int left;
  int right;
};

struct max_heap {
  struct node *data;
  int size;
};

void swap(struct node *a, struct node *b) {
  struct node tmp = *a;
  *a = *b;
  *b = tmp;
}

void push(struct max_heap *h, struct node n) {
  h->data[++h->size] = n;
  int i = h->size;
  while (i > 1 && h->data[i].val > h->data[i / 2].val) {
    swap(&h->data[i], &h->data[i / 2]);
    i /= 2;
  }
}

struct node pop(struct max_heap *h) {
  struct node top = h->data[1];
  h->data[1] = h->data[h->size--];
  int i = 1;
  while (2 * i <= h->size) {
    int j = 2 * i;
    if (j + 1 <= h->size && h->data[j + 1].val > h->data[j].val)
      j++;
    swap(&h->data[i], &h->data[j]);
    i = j;
  }
  return top;
}

int get_max(int *seg, int left, int right, int size) {
  int max = 0;
  for (left += size, right += size; left <= right; left >>= 1, right >>= 1) {
    if (left & 1) {
      if (seg[left] > max) {
        max = seg[left];
        left++;
      }
    }
    if (!(right & 1)) {
      if (seg[right] > max) {
        max = seg[right];
        right--;
      }
    }
  }
  return max;
}

int get_min(int *seg, int left, int right, int size) {
  int min = INT_MAX;
  for (left += size, right += size; left <= right; left >>= 1, right >>= 1) {
    if (left & 1) {
      if (seg[left] < min) {
        min = seg[left];
        left++;
      }
    }
    if (!(right & 1)) {
      if (seg[right] < min) {
        min = seg[right];
        right--;
      }
    }
  }
  return min;
}

long long maxTotalValue(int *nums, int numsSize, int k) {
  int n = 1;
  while (n < numsSize)
    n *= 2;
  int *seg_max = (int *)calloc(2 * n, sizeof(int));
  int *seg_min = (int *)malloc(2 * n * sizeof(int));
  for (int i = 0; i < 2 * n; i++)
    seg_min[i] = INT_MAX;
  for (int i = 0; i < numsSize; i++)
    seg_max[n + i] = seg_min[n + i] = nums[i];
  for (int i = n - 1; i > 0; i--) {
    seg_max[i] = (seg_max[2 * i] > seg_max[2 * i + 1]) ? seg_max[2 * i]
                                                       : seg_max[2 * i + 1];
    seg_min[i] = (seg_min[2 * i] < seg_min[2 * i + 1]) ? seg_min[2 * i]
                                                       : seg_min[2 * i + 1];
  }
  struct max_heap h = {
      (struct node *)malloc((numsSize + k + 1) * sizeof(struct node)), 0};
  for (int i = 0; i < numsSize; i++) {
    int val = get_max(seg_max, i, n - 1, n) - get_min(seg_min, i, n - 1, n);
    push(&h, (struct node){val, i, n - 1});
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    struct node top = pop(&h);
    ans += top.val;
    if (top.right > top.left) {
      int val = get_max(seg_max, top.left, top.right - 1, n) -
                get_min(seg_min, top.left, top.right - 1, n);
      push(&h, (struct node){val, top.left, top.right - 1});
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 2}, n2[] = {4, 2, 5, 1};
  long long r1 = maxTotalValue(n1, ARRAY_SIZE(n1), 2);
  long long r2 = maxTotalValue(n2, ARRAY_SIZE(n2), 3);
  printf("%lld\n", r1);
  assert(r1 == 4);
  printf("%lld\n", r2);
  assert(r2 == 12);
}
