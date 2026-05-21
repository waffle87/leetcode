// 3043. Find the Length of the Longest Common Prefix
#include "leetcode.h"

/*
 * given two arrays with positive integers 'arr1' and 'arr2'. a prefix of a
 * positive integer is an integer formed by one or more of its digits, starting
 * from its leftmost digit. a common prefix of two integers 'a' and 'b' is an
 * integer 'c' such that is a prefix of both a and b. for example 6555359 and
 * 56554 have a common prefix 565 while q223 and 43456 do not have a common
 * prefix. return the length of the longest common prefix among all pairs. if no
 * common prefix exists among them, return 0.
 */

struct map {
  int id;
  UT_hash_handle hh;
};

int longestCommonPrefix(int *arr1, int arr1Size, int *arr2, int arr2Size) {
  struct map *obj = NULL, *tmp, *iter;
  int ans = 0, n;
  for (int i = 0; i < arr1Size; i++)
    for (int j = arr1[i]; j > 0; j /= 10) {
      HASH_FIND_INT(obj, &j, tmp);
      if (tmp)
        continue;
      tmp = (struct map *)malloc(sizeof(struct map));
      *tmp = (struct map){j};
      HASH_ADD_INT(obj, id, tmp);
    }
  for (int i = 0; i < arr2Size; i++)
    for (int j = arr2[i]; j > 0; j /= 10) {
      HASH_FIND_INT(obj, &j, tmp);
      if (!tmp)
        continue;
      n = floor(log10(j)) + 1;
      ans = ans >= n ? ans : n;
      ans = fmax(ans, n);
      break;
    }
  HASH_ITER(hh, obj, iter, tmp) {
    HASH_DEL(obj, iter);
    free(iter);
  }
  return ans;
}

int main() {
  int a11[] = {1, 10, 100}, a21[] = {1000};
  int a12[] = {1, 2, 3}, a22[] = {4, 4, 4};
  int r1 = longestCommonPrefix(a11, ARRAY_SIZE(a11), a21, ARRAY_SIZE(a21));
  int r2 = longestCommonPrefix(a12, ARRAY_SIZE(a12), a22, ARRAY_SIZE(a22));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
}
