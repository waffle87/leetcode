// 1224. Maximum Equal Frequency
#include "leetcode.h"

/*
 * given an array 'nums' of positive integers, return the longest possible
 * length of an array prefix of 'nums' such that it is possible to remove
 * exactly one element from this prefix so that ever number has appear in it
 * will have the same number occurrences. if after removing one element there
 * are no remaining elements, it's still considered that every appear number has
 * the same number of occurrences.
 */

typedef struct {
  int key;
  int cnt;
} data;

int maxEqualFreq(int *nums, int numsSize) {
  int n = numsSize, m = n, type = 0, ans = 0, max_freq = 1;
  data **num_freq = calloc(m, sizeof(data *));
  int *cnt = calloc(n + 1, sizeof(int));
  for (int i = 0; i < n; i++) {
    int val = nums[i], curr = val;
    while (1) {
      if (!num_freq[curr % m]) {
        num_freq[curr % m] = malloc(sizeof(data));
        num_freq[curr % m]->key = val;
        num_freq[curr % m]->cnt = 1;
        cnt[1]++;
        type++;
        break;
      } else if (num_freq[curr % m]->key == val) {
        num_freq[curr % m]->cnt++;
        cnt[num_freq[curr % m]->cnt]++;
        cnt[num_freq[curr % m]->cnt - 1]--;
        if (num_freq[curr % m]->cnt > max_freq)
          max_freq = num_freq[curr % m]->cnt;
        break;
      } else
        curr++;
    }
    if (type == i + 1)
      ans = fmax(ans, i + 1);
    else if (cnt[1] == 1 && max_freq * cnt[max_freq] == i)
      ans = fmax(ans, i + 1);
    else if ((max_freq - 1) * (cnt[max_freq - 1] + 1) == i)
      ans = fmax(ans, i + 1);
  }
  for (int i = 0; i < m; i++)
    if (num_freq[i])
      free(num_freq[i]);
  free(num_freq), free(cnt);
  return ans;
}

int main() {
  int n1[] = {2, 2, 1, 1, 5, 3, 3, 5},
      n2[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
  printf("%d\n", maxEqualFreq(n1, ARRAY_SIZE(n1))); // expect: 7
  printf("%d\n", maxEqualFreq(n2, ARRAY_SIZE(n2))); // expect: 13
}
