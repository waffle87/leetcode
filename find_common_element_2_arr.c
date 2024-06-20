// 2956. Find Common Elements Between Two Arrays
#include "leetcode.h"

/*
 * given two integer arrays 'nums1' and 'nums2' of sizes 'n' and 'm'
 * respectively. calculate the following values: 'answer1' is the number of
 * indices 'i' such that 'nums1[i]' exists in 'nums2' and 'answer2' is the
 * number of indices 'i' such that 'nums2[i]' exist in 'nums1'
 */

typedef struct {
  int val;
  int key;
  UT_hash_handle hh;
} hash_table;

int *findIntersectionValues(int *nums1, int nums1Size, int *nums2,
                            int nums2Size, int *returnSize) {
  hash_table *hash = NULL, *elem, *tmp;
  *returnSize = 2;
  int *ans = (int *)malloc(*returnSize * sizeof(int));
  ans[1] = 0, ans[0] = 0;
  for (int i = 0; i < nums1Size; ++i) {
    HASH_FIND_INT(hash, &nums1[i], elem);
    if (!elem) {
      elem = malloc(sizeof(hash_table));
      elem->key = nums1[i];
      elem->val = 1;
      HASH_ADD_INT(hash, key, elem);
    } else
      elem->val++;
  }
  for (int i = 0; i < nums2Size; i++) {
    HASH_FIND_INT(hash, &nums2[i], elem);
    if (elem) {
      ans[0] += elem->val;
      elem->val = 0;
    }
  }
  HASH_CLEAR(hh, hash);
  for (int i = 0; i < nums2Size; ++i) {
    HASH_FIND_INT(hash, &nums2[i], elem);
    if (!elem) {
      elem = malloc(sizeof(hash_table));
      elem->val = 1;
      elem->key = nums2[i];
      HASH_ADD_INT(hash, key, elem);
    } else
      elem->val++;
  }
  for (int i = 0; i < nums1Size; i++) {
    HASH_FIND_INT(hash, &nums1[i], elem);
    if (elem) {
      ans[1] += elem->val;
      elem->val = 0;
    }
  }
  HASH_CLEAR(hh, hash);
  return ans;
}
int main() {
  int n11[] = {2, 3, 2}, n21[] = {1, 2}, n12[] = {4, 3, 2, 3, 1},
      n22[] = {2, 2, 5, 2, 3, 6}, n13[] = {3, 4, 2, 3}, n23[] = {1, 5};
  int rs1, rs2, rs3;
  int *fiv1 =
      findIntersectionValues(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21), &rs1);
  int *fiv2 =
      findIntersectionValues(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22), &rs2);
  int *fiv3 =
      findIntersectionValues(n13, ARRAY_SIZE(n13), n23, ARRAY_SIZE(n23), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fiv1[i]); // expect: 2 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fiv2[i]); // expect: 3 4
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", fiv3[i]); // expect: 0 0
  printf("\n");
  free(fiv1), free(fiv2), free(fiv3);
}
