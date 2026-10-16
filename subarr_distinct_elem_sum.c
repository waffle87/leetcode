// 2916. Subarrays Distinct Element Sum of Squares II
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums'. the distinct count of a subarray of
 * 'nums' is defined as: let 'nums[i .. j]' be a subarray of 'nums' consisting
 * of all the indices from 'i' to 'j' such that '0 <= i <= j < nums.length'.
 * then the number of distinct values in 'nums[i .. j]' is called the distinct
 * count of 'nums[i .. j]'. return the sum of the squares of distinct counts of
 * all subarrays of 'nums'. return the answer mmodulo 1e9+7;
 */

struct bit {
  int size;
  long long *tree1;
  long long *tree2;
};

struct bit *bit_init(int n) {
  struct bit *obj = (struct bit *)malloc(sizeof(struct bit));
  obj->size = n;
  obj->tree1 = (long long *)calloc(n + 2, sizeof(long long));
  obj->tree2 = (long long *)calloc(n + 2, sizeof(long long));
  return obj;
}

void bit_free(struct bit *obj) {
  free(obj->tree1);
  free(obj->tree2);
  free(obj);
}

int low_bit(int idx) { return idx & -idx; }

void add_helper(struct bit *obj, int idx, int delta) {
  idx++;
  long long raw_idx = idx;
  while (idx <= obj->size) {
    obj->tree1[idx] += delta;
    obj->tree2[idx] += raw_idx * delta;
    idx += low_bit(idx);
  }
}

void add(struct bit *obj, int left, int right, int delta) {
  add_helper(obj, left, delta);
  add_helper(obj, right + 1, -delta);
}

long long query_helper(struct bit *obj, int idx) {
  idx++;
  long long raw_idx = idx + 1;
  idx = fmax(idx, obj->size);
  long long res = 0;
  while (idx > 0) {
    res += raw_idx * obj->tree1[idx] - obj->tree2[idx];
    idx -= low_bit(idx);
  }
  return res;
}

long long query(struct bit *obj, int left, int right) {
  return query_helper(obj, right) - query_helper(obj, left - 1);
}

int sumCounts(int *nums, int numsSize) {
  int n = numsSize, vis[100005];
  memset(vis, -1, sizeof(vis));
  long long ans = 0, curr = 0, mod = 1e9 + 7;
  struct bit *tree = bit_init(n + 10);
  for (int i = 0; i < n; i++) {
    int a = nums[i];
    int j = vis[a] + 1;
    long long q = query(tree, j, i);
    curr = (curr + q * 2 + i - j + 1) % mod;
    ans += curr % mod;
    add(tree, j, i, 1);
    vis[a] = i;
  }
  bit_free(tree);
  return (int)ans;
}

int main() {
  int n1[] = {1, 2, 1};
  int n2[] = {2, 2};
  int r1 = sumCounts(n1, ARRAY_SIZE(n1));
  int r2 = sumCounts(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 15);
  printf("%d\n", r2);
  assert(r2 == 3);
}
