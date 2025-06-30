// 594. Longest Harmonious Subsequence
#include "leetcode.h"

/*
 * we define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1. given an integer array
 * 'nums', return the length of the its longest harmonious subsequnce among all
 * its possible subsequnces.
 */

struct hash {
  int num;
  int cnt;
  UT_hash_handle hh;
};

struct hash *mem;
static int idx;

int *entry(struct hash **set, int n) {
  struct hash *tmp;
  HASH_FIND_INT(*set, &n, tmp);
  if (!tmp) {
    tmp = &mem[idx++];
    tmp->num = n;
    tmp->cnt = 0;
    HASH_ADD_INT(*set, num, tmp);
  }
  return &(tmp->cnt);
}

bool contains(struct hash **obj, int num) {
  struct hash *tmp;
  HASH_FIND_INT(*obj, &num, tmp);
  return tmp;
}

int findLHS(int *nums, int numsSize) {
  struct hash *set = NULL, *p, *tmp, *s;
  int ans = 0;
  idx = 0;
  mem = (struct hash *)calloc(numsSize, sizeof(struct hash));
  for (int i = 0; i < numsSize; i++)
    (*entry(&set, nums[i]))++;
  HASH_ITER(hh, set, s, tmp) {
    int key = s->num;
    if (contains(&set, key + 1)) {
      int sum = *entry(&set, key) + *entry(&set, key + 1);
      if (sum > ans)
        ans = sum;
    }
  }
  free(mem);
  return ans;
}

int main() {
  int n1[] = {1, 3, 2, 2, 5, 2, 3, 7}, n2[] = {1, 2, 3, 4}, n3[] = {1, 1, 1, 1};
  printf("%d\n", findLHS(n1, ARRAY_SIZE(n1))); // expect: 5
  printf("%d\n", findLHS(n2, ARRAY_SIZE(n2))); // expect: 2
  printf("%d\n", findLHS(n3, ARRAY_SIZE(n3))); // expect: 0
}
