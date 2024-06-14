// 2121. Intervals Between Identical Elements
#include "leetcode.h"

/*
 * given a 0-indexed array of 'n' integers 'arr'. the interval between two
 * elements in 'arr' is defined as the absolute difference between their
 * indices. more formally, the interval between 'arr[i]' and 'arr[j]' is |i -
 * j|. return an array intervals of length 'n' where 'intervals[i]' is the sum
 * of the intervals between 'arr[i]' and each element in 'arr' with the same
 * value as 'arr[i]'.
 */

typedef struct {
  int value;
  uint64_t idx_sum;
  int idx_max;
  int idx_cnt;
  int *idx;
} node;

typedef struct {
  int size;
  node *n;
} hash;

node *hash_find(hash *h, int v) {
  int idx = v % h->size;
  for (int i = 0; i < h->size; i++) {
    int curr_idx = (idx + i) % h->size;
    node *curr = &h->n[curr_idx];
    if (!curr->idx_cnt || curr->value == v)
      return curr;
  }
  return NULL;
}

long long *getDistances(int *arr, int arrSize, int *returnSize) {
  long long *ans = calloc(arrSize, sizeof(long long));
  hash h = {0, NULL};
  h.size = arrSize * 2;
  h.n = calloc(h.size, sizeof(node));
  for (int i = 0; i < arrSize; i++) {
    node *curr = hash_find(&h, arr[i]);
    if (!curr->idx_cnt) {
      curr->value = arr[i];
      curr->idx_max = 10;
      curr->idx = calloc(curr->idx_max, sizeof(int));
    }
    if (curr->idx_cnt == curr->idx_max) {
      curr->idx_max *= 2;
      curr->idx = realloc(curr->idx, curr->idx_max * sizeof(int));
    }
    curr->idx[curr->idx_cnt++] = i;
    curr->idx_sum += i;
  }
  for (int i = 0; i < h.size; i++) {
    node *curr = &h.n[i];
    if (curr->idx_cnt) {
      uint64_t pre_sum = 0, post_sum = curr->idx_sum;
      for (int j = 0; j < curr->idx_cnt; j++) {
        uint64_t curr_idx = curr->idx[j];
        post_sum -= curr_idx;
        ans[curr_idx] = (j * curr_idx - pre_sum) +
                        (post_sum - (curr->idx_cnt - j - 1) * curr_idx);
        pre_sum += curr_idx;
      }
      free(curr->idx);
    }
  }
  free(h.n);
  *returnSize = arrSize;
  return ans;
}

int main() {
  int a1[] = {2, 1, 3, 1, 2, 3, 3}, a2[] = {10, 5, 10, 10};
  int rs1 = 0, rs2 = 0;
  long long *gd1 = getDistances(a1, ARRAY_SIZE(a1), &rs1);
  long long *gd2 = getDistances(a2, ARRAY_SIZE(a2), &rs2);
  for (int i = 0; i < ARRAY_SIZE(a1); i++)
    printf("%lld ", gd1[i]); // expect: [4,2,7,2,4,4,5]
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(a2); i++)
    printf("%lld ", gd2[i]); // expect: [5,0,3,4]
  printf("\n");
  free(gd1), free(gd2);
}
