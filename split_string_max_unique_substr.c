// 1593. Split a String Into the Max Number of Unique Substrings
#include "leetcode.h"

/*
 * given a string 's', return the maximum number of unique substrings that the
 * given string can be split into. you can split string 's' into any list of
 * non-empty substrings, where the concatenation of the substrings forms the
 * origin string. however, you must split the substrings such that all of them
 * are unique. a substring is a contiguous sequence of characters within a
 * string.
 */

struct map {
  int len;
  char s[16];
};

bool find(struct map *m, int idx, char *tmp, int tmp_len) {
  if (idx == -1)
    return false;
  for (int i = 0; i <= idx; i++)
    if (m[i].len == tmp_len)
      if (!strncmp(m[i].s, tmp, tmp_len))
        return true;
  return false;
}

bool is_valid(char *s, int s_len, int split, int *active_bits) {
  struct map m[s_len];
  int idx = -1, tmp_len = 1;
  char tmp[s_len];
  memcpy(&tmp[0], &s[0], 1);
  for (int i = 0; i < s_len - 1; i++) {
    if ((split >> i) & 1) {
      if (find(m, idx, tmp, tmp_len))
        return false;
      idx++;
      memcpy(&(m[idx].s), &tmp[0], tmp_len);
      m[idx].s[tmp_len] = '\0';
      m[idx].len = tmp_len;
      (*active_bits)++;
      tmp_len = 0;
      tmp[tmp_len++] = s[i + 1];
    } else
      tmp[tmp_len++] = s[i + 1];
  }
  if (tmp_len && find(m, idx, tmp, tmp_len))
    return false;
  return true;
}

int maxUniqueSplit(char *s) {
  int n = strlen(s);
  if (n == 1)
    return 1;
  int max_size = pow(2, n - 1), max_split = 0;
  for (int i = 0; i < max_size; i++) {
    int m = 0;
    if (is_valid(s, n, i, &m))
      max_split = fmax(max_split, m);
  }
  return max_split + 1;
}

int main() {
  char *s1 = "ababccc", *s2 = "aba", *s3 = "aa";
  printf("%d\n", maxUniqueSplit(s1)); // expect: 5
  printf("%d\n", maxUniqueSplit(s2)); // expect: 2
  printf("%d\n", maxUniqueSplit(s3)); // expect: 1
}
