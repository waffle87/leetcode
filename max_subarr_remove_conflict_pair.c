// 3480. Maximize Subarrays After Removing One Conflicting Pair
#include "leetcode.h"

/*
 * you are given an integer 'n' which represents an array 'nums' containing the
 * numbers from 1 to 'n' in order. additionally, you are given a 2d array
 * 'conflictingPairs' where 'conflictingPairs[i] = [a, b]' indicates that 'a'
 * and 'b' form a conflicting pair. remove exactly one element from
 * 'conflictingPairs'. afterward, count the number of non-empty subarrays of
 * 'nums' which do not contain both 'a' and 'b' for any remaining conflicting
 * pairs '[a, b]'. return the maximum number of subarrays possible after
 * removing exactly one conflicting pair.
 */

long long maxSubarrays(int n, int **conflictingPairs, int conflictingPairsSize,
                       int *conflictingPairsColSize) {
  int *s1 = (int *)calloc(n + 1, sizeof(int));
  int *s2 = (int *)calloc(n + 1, sizeof(int));
  for (int i = 0; i < conflictingPairsSize; ++i) {
    int a = conflictingPairs[i][0], b = conflictingPairs[i][1];
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    if (s1[b] < a) {
      s2[b] = s1[b];
      s1[b] = a;
    } else if (s2[b] < a)
      s2[b] = a;
  }
  int m1 = 0, m2 = 0;
  long long ans = 0, delta = 0, mid = 0;
  for (int i = 1; i <= n; ++i) {
    if (s1[i] > 0) {
      if (s1[i] > m1) {
        m2 = fmax(m1, s2[i]);
        m1 = s1[i];
        mid = fmax(mid, delta);
        delta = 0;
      } else if (s1[i] > m2)
        m2 = s1[i];
    }
    ans += (i - m1);
    delta += (m1 - m2);
  }
  free(s1), free(s2);
  return ans + fmax(mid, delta);
}

int main() {
  int cp1i[2][2] = {{2, 3}, {1, 4}}, cp2i[3][2] = {{1, 2}, {2, 5}, {3, 5}};
  struct two_d_arr *cp1 =
      two_d_arr_init(ARRAY_SIZE(cp1i), ARRAY_SIZE(cp1i[0]), cp1i);
  struct two_d_arr *cp2 =
      two_d_arr_init(ARRAY_SIZE(cp2i), ARRAY_SIZE(cp2i[0]), cp2i);
  printf("%lld\n",
         maxSubarrays(4, cp1->arr, cp1->row_size, cp1->col_size)); // expect: 9
  printf("%lld\n",
         maxSubarrays(5, cp2->arr, cp2->row_size, cp2->col_size)); // expect: 12
  two_d_arr_free(cp1);
  two_d_arr_free(cp2);
}
