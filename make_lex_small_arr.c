// 2948. Make Lexicographically Smallest Array by Swapping Elements
#include "leetcode.h"

/*
 * you are given a 0-indexed array of positive integers 'nums' and a positive
 * integer 'limit'. in one operation, you can choose any two indices 'i' and 'j'
 * and swap 'nums[i]' and 'nums[j]' if '|nums[i] - nums[j]| <= limit'. return
 * the lexicographically smallest array that can be obtained by performingthe
 * operation any number of times.
 */

struct pair {
  int val;
  int idx;
};

int cmp(const void *a, const void *b) {
  return ((struct pair *)a)->val - ((struct pair *)b)->val;
}

int *lexicographicallySmallestArray(int *nums, int numsSize, int limit,
                                    int *returnSize) {
  struct pair *p = (struct pair *)malloc(numsSize * sizeof(struct pair));
  for (int i = 0; i < numsSize; i++) {
    p[i].val = nums[i];
    p[i].idx = i;
  }
  qsort(p, numsSize, sizeof(struct pair), cmp);
  int *ans = (int *)malloc(numsSize * sizeof(int));
  int *pos = (int *)malloc(numsSize * sizeof(int));
  int prev = INT_MIN, pos_cnt = 0;
  for (int s = 0, e = 0; e < numsSize;) {
    pos[pos_cnt++] = p[e].idx;
    prev = p[e].val;
    e++;
    if (e == numsSize || p[e].val - prev > limit) {
      qsort(pos, pos_cnt, sizeof(int), cmp);
      for (int i = 0; i < pos_cnt; i++) {
        ans[pos[i]] = p[s].val;
        s++;
      }
      pos_cnt = 0;
    }
  }
  free(p);
  free(pos);
  *returnSize = numsSize;
  return ans;
}

int main() {
  int n1[] = {1, 5, 3, 9, 8}, r1[] = {1, 3, 5, 8, 9}, rs1;
  int n2[] = {1, 7, 6, 18, 2, 1}, r2[] = {1, 6, 7, 18, 1, 2}, rs2;
  int n3[] = {1, 7, 28, 19, 10}, r3[] = {1, 7, 28, 19, 10}, rs3;
  int *lsa1 = lexicographicallySmallestArray(n1, ARRAY_SIZE(n1), 2, &rs1);
  int *lsa2 = lexicographicallySmallestArray(n2, ARRAY_SIZE(n2), 3, &rs2);
  int *lsa3 = lexicographicallySmallestArray(n3, ARRAY_SIZE(n3), 3, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", lsa1[i]);
    assert(lsa1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", lsa2[i]);
    assert(lsa2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", lsa3[i]);
    assert(lsa3[i] == r3[i]);
  }
  printf("\n");
  free(lsa1);
  free(lsa2);
  free(lsa3);
}
