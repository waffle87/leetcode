// 3041. Maximize Consecutive Elements in an Array After Modification
#include "leetcode.h"

struct hash_entry {
  int key;
  int len;
  UT_hash_handle hh;
};

int cmp(const void *a, const void *b) {
  int aa = *(const int *)a, bb = *(const int *)b;
  return (aa > bb) - (aa < bb);
}

int maxSelectedElements(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  struct hash_entry *dp = NULL, *entry, *tmp;
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int d = 1; d >= 0; d--) {
      int key = nums[i] + d, prev_key = key - 1;
      HASH_FIND_INT(dp, &prev_key, entry);
      int len = (entry == NULL ? 0 : entry->len) + 1;
      HASH_FIND_INT(dp, &key, entry);
      if (!entry) {
        entry = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        entry->key = key;
        entry->len = 0;
        HASH_ADD_INT(dp, key, entry);
      }
      entry->len = fmax(entry->len, len);
      ans = fmax(ans, entry->len);
    }
  }
  HASH_ITER(hh, dp, entry, tmp) {
    HASH_DEL(dp, entry);
    free(entry);
  }
  return ans;
}

int main() {
  int n1[] = {2, 1, 5, 1, 1};
  int n2[] = {1, 4, 7, 10};
  int r1 = maxSelectedElements(n1, ARRAY_SIZE(n1));
  int r2 = maxSelectedElements(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 1);
}
