// 2179. Count Good Triplets in an Array
#include "leetcode.h"

/*
 * you are given two 0-indexed arrays 'nums1' and 'nums2' of length 'n', both of
 * which are permutations of '[0, 1, ..., n - 1]'. a good triplet is a set of
 * three distinct values which are present in increasing order by position in
 * both 'nums1' and 'nums2'. in other words, if we consider 'pos1v' as the index
 * of the value 'v' in 'nums1' and 'pos2v' as the index of the value 'v' in
 * 'nums2', then a good triplet will be a set '(x, y, z)'. return the total
 * number of good triplets.
 */

#define MAX_SIZE 100010

static int tree[MAX_SIZE];

void tree_push(int idx, int val, int n) {
  idx++;
  while (idx <= n + 2) {
    tree[idx] += val;
    idx += idx & (-idx);
  }
}

int tree_query(int idx) {
  idx++;
  int res = 0;
  while (idx > 0) {
    res += tree[idx];
    idx -= idx & (-idx);
  }
  return res;
}

long long goodTriplets(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int n = nums1Size, p2v[MAX_SIZE], arr[MAX_SIZE], left[MAX_SIZE] = {0};
  for (int i = 0; i < n; i++)
    p2v[nums2[i]] = i;
  for (int i = 0; i < n; i++)
    arr[i] = p2v[nums1[i]];
  memset(tree, 0, sizeof(tree));
  for (int i = 0; i < n; i++) {
    left[i] = tree_query(arr[i] - 1);
    tree_push(arr[i], 1, n);
  }
  memset(tree, 0, sizeof(tree));
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int right = tree_query(n - 1) - tree_query(arr[i]);
    ans += (long long)left[i] * right;
    tree_push(arr[i], 1, n);
  }
  return ans;
}

int main() {
  int n11[] = {2, 0, 1, 3}, n21[] = {0, 1, 2, 3};
  int n12[] = {4, 0, 1, 3, 2}, n22[] = {4, 1, 0, 2, 3};
  printf("%lld\n",
         goodTriplets(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21))); // expect: 1
  printf("%lld\n",
         goodTriplets(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22))); // expect: 4
}
