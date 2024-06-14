// 446. Arithmetic Slices II - Subsequence
#include "leetcode.h"
#include "lib/uthash/src/uthash.h"

/*
 * given an integer array 'nums', return the number of all the arithmetic
 * subsequences of 'nums'. a sequence of numbers is called arithmetic if it
 * consists of at least three elements and if the difference between any two
 * consecutive elements is the same. the test cases are generated such that the
 * answer fits in a 32-bit integer.
 */

struct seq_hash {
  long long diff;
  int cnt;
  UT_hash_handle hh;
};

int numberOfArithmeticSlices(int *nums, int nums_size) {
  int ans = 0;
  struct seq_hash **const dp = calloc(nums_size, sizeof(struct seq_hash *));
  for (int end = 1; end < nums_size; ++end) {
    for (int i = 0; i < end; i++) {
      const long long diff = ((long long)nums[end]) - nums[i];
      struct seq_hash *end_entry;
      HASH_FIND(hh, dp[end], &diff, sizeof(diff), end_entry);
      if (!end_entry) {
        end_entry = malloc(sizeof(struct seq_hash));
        end_entry->diff = diff;
        end_entry->cnt = 0;
        HASH_ADD(hh, dp[end], diff, sizeof(end_entry->diff), end_entry);
      }
      struct seq_hash *prev_entry;
      HASH_FIND(hh, dp[i], &diff, sizeof(diff), prev_entry);
      if (!prev_entry)
        ++end_entry->cnt;
      else {
        end_entry->cnt += prev_entry->cnt + 1;
        ans += prev_entry->cnt;
      }
    }
  }
  for (int i = 0; i < nums_size; i++) {
    struct seq_hash *entry, *tmp;
    HASH_ITER(hh, dp[i], entry, tmp) {
      HASH_DEL(dp[i], entry);
      free(entry);
    }
  }
  free(dp);
  return ans;
}

int main() {
  int n1[] = {2, 4, 6, 8, 10}, n2[] = {7, 7, 7, 7, 7};
  printf("%d\n", numberOfArithmeticSlices(n1, ARRAY_SIZE(n1))); // expect: 7
  printf("%d\n", numberOfArithmeticSlices(n2, ARRAY_SIZE(n2))); // expect: 16
}
