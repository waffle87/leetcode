// 347. Top K Frequent Elements
#include "lib/uthash/src/uthash.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums' and an integer 'k', return the 'k' most
 * frequent elements you may return the right answer in any order!!!
 */

typedef struct {
  int idxs[500];
  int num_idx;
} pair;

typedef struct {
  int elem;
  int count;
  UT_hash_handle hh;
} h_elem;

int *topKFrequent(int *nums, int nums_size, int k, int *return_size) {
  h_elem *count = NULL, *s, *curr;
  pair *freq = calloc(sizeof(pair), nums_size + 1);
  int *ans = malloc(sizeof(int) * k);
  *return_size = 0;
  for (int i = 0; i < nums_size; i++) {
    HASH_FIND_INT(count, &nums[i], s);
    if (s)
      s->count++;
    else {
      s = malloc(sizeof(h_elem));
      s->elem = nums[i];
      s->count = 1;
      HASH_ADD_INT(count, elem, s);
    }
  }
  HASH_ITER(hh, count, curr, s)
  freq[curr->count].idxs[freq[curr->count].num_idx++] = curr->elem;
  for (int i = nums_size; i >= 0; i--)
    if (freq[i].num_idx)
      for (int j = 0; j < freq[i].num_idx; j++) {
        ans[(*return_size)++] = freq[i].idxs[j];
        if (*return_size == k)
          return ans;
      }
  return ans;
}

int main() {
  int n1[] = {1, 1, 1, 2, 2, 3}, n2[] = {1};
  int *r1 = topKFrequent(n1, 6, 2, NULL);
  int *r2 = topKFrequent(n2, 1, 1, NULL);
  for (int i = 0; i < 6; i++)
    printf("%d ", r1[i]);
  printf("\n%d ", r1[0]);
}
