// 3003. Maximize the Number of Partitions After Operations
#include "leetcode.h"

/*
 * you are given a string 's' and an integer 'k'. first, you are allowed to
 * change at mose one index in 's' to another lowercase english letter. after
 * that, do the following partitioning operation until 's' is empty: chose the
 * longest prefix of 's' containing at most 'k' distinct characters, and delete
 * the prefix from 's' and increase the number of partitions by one. the
 * remaining characters (if any) in 's' maintain their initial order. return an
 * integer denoting the maximum number of resulting partitions after the
 * operations chosing at most one index to change.
 */

#define ALPHA_SIZE 26

int maxPartitionsAfterOperations(char *s, int k) {
  if (k == ALPHA_SIZE)
    return 1;
  int n = strlen(s), used = 0, cnt = 0, ans = 1;
  int *ansr = (int *)calloc(n, sizeof(int));
  int *usedr = (int *)calloc(n, sizeof(int));
  for (int i = n - 1; i >= 0; i--) {
    int curr = s[i] - 'a';
    if (!(used & (1 << curr))) {
      if (cnt == k) {
        cnt = 0;
        used = 0;
        ans++;
      }
      used |= 1 << curr;
      cnt++;
    }
    ansr[i] = ans;
    usedr[i] = used;
  }
  int ansl = 0, l = 0;
  ans = ansr[0];
  while (l < n) {
    used = cnt = 0;
    int used_prev = 0, used_2_prev = 0, last = -1, r = l;
    while (r < n) {
      int curr = s[r] - 'a';
      if (!(used & (1 << curr))) {
        if (cnt == k)
          break;
        used_prev = used;
        last = r;
        used |= 1 << curr;
        cnt++;
      } else if (cnt < k)
        used_2_prev |= 1 << curr;
      r++;
    }
    if (cnt == k) {
      if (last - 1 > __builtin_popcount(used_prev))
        ans = fmax(ans, ansl + 1 + ansr[last]);
      if (last + 1 < r) {
        if (last + 2 >= n)
          ans = fmax(ans, ansl + 1 + 1);
        else {
          if (__builtin_popcount(usedr[last + 2]) == k) {
            int valid = ((1 << ALPHA_SIZE) - 1) & ~used & ~usedr[last + 2];
            ans = fmax(ans, valid > 0 ? ansl + 1 + 1 + ansr[last + 2]
                                      : ansl + 1 + ansr[last + 2]);
            int l1 = s[last + 1] - 'a';
            if (!(used_2_prev & (1 << l1)))
              ans = fmax(ans, ansl + 1 + ansr[last + 1]);
          } else
            ans = fmax(ans, ansl + 1 + ansr[last + 2]);
        }
      }
    }
    l = r;
    ansl++;
  }
  free(ansr);
  free(usedr);
  return ans;
}

int main() {
  char *s1 = "accca", *s2 = "aabaab", *s3 = "xxyz";
  printf("%d\n", maxPartitionsAfterOperations(s1, 2)); // expect: 3
  printf("%d\n", maxPartitionsAfterOperations(s2, 3)); // expect: 1
  printf("%d\n", maxPartitionsAfterOperations(s3, 1)); // expect: 4
}
