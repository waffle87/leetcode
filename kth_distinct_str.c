// 2053. Kth Distinct String in an Array
#include "leetcode.h"

/*
 * a distinct string is a string that is present only once in an array. given an
 * array of strings 'arr' and an integer 'k', return the k'th eldistinct string
 * present in 'arr'. if there are fewer than 'k' distinct strings, return an
 * empty string "". note the strings are considered in the order in which they
 * appear in the array.
 */

typedef struct {
  char str[6];
  bool distinct;
  int pos;
  UT_hash_handle hh;
} element;

int cmp_pos(const element *e1, const element *e2) { return e1->pos - e2->pos; }

char *kthDistinct(char **arr, int arrSize, int k) {
  element *hash = NULL, *e;
  for (size_t i = 0; i < arrSize; i++) {
    const char *str = arr[i];
    HASH_FIND_STR(hash, str, e);
    if (e) {
      e->distinct = false;
    } else {
      e = (element *)malloc(sizeof(*e));
      e->distinct = true;
      e->pos = i;
      strcpy(e->str, str);
      HASH_ADD_STR(hash, str, e);
    }
  }
  HASH_SORT(hash, cmp_pos);
  char *ans = (char *)malloc(6 * sizeof(char));
  *ans = '\0';
  int i = 0;
  for (e = hash; e; e = e->hh.next)
    if (e->distinct)
      if (++i == k) {
        strcpy(ans, e->str);
        break;
      }
  return ans;
}

int main() {
  char *a1[] = {"d", "b", "c", "b", "c", "a"}, *a2[] = {"aaa", "aa", "a"},
       *a3[] = {"a", "b", "a"};
  printf("%s\n", kthDistinct((char **)a1, ARRAY_SIZE(a1), 2)); // expect: a
  printf("%s\n", kthDistinct((char **)a2, ARRAY_SIZE(a2), 1)); // expect: aaa
  printf("%s\n", kthDistinct((char **)a3, ARRAY_SIZE(a3), 3)); // expect: null
}
