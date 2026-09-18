// 1520. Maximum Number of Non-Overlapping Substrings
#include "leetcode.h"

/*
 * given a string 's' of lowercase letters, you need to find the maximum number
 * of non-empty substrings of 's' that meet the following conditions: the
 * substrings do not overlap, that is for any two substrings 's[i..j]' and
 * 's[x..y]', either 'j < x' or 'i > y' is true, and a substring that contains a
 * certain character 'c' must also contain all occurrences of 'c'. find the
 * maximum number of substrings that meet the above conditions. if there are
 * multiple solutions with the same number of substrings, return the one with
 * minimum total length. it can be shown that there exists a unique solution of
 * minimum total length. notice that you can return the substrings in any order.
 */

struct segment {
  int left;
  int right;
};

int cmp(const void *a, const void *b) {
  struct segment *x = (struct segment *)a;
  struct segment *y = (struct segment *)b;
  if (x->right == y->right)
    return y->left - x->left;
  return x->right - y->right;
}

char **maxNumOfSubstrings(char *s, int *returnSize) {
  struct segment seg[26];
  for (int i = 0; i < 26; i++)
    seg[i].left = seg[i].right = -1;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    int idx = s[i] - 'a';
    if (seg[idx].left == -1)
      seg[idx].left = seg[idx].right = i;
    else
      seg[idx].right = i;
  }
  for (int i = 0; i < 26; i++) {
    if (seg[i].left != -1) {
      int j = seg[i].left;
      while (j <= seg[i].right) {
        int idx = s[j] - 'a';
        if (seg[i].left <= seg[idx].left && seg[idx].right <= seg[i].right) {
        } else {
          if (seg[idx].left < seg[i].left)
            seg[i].left = seg[idx].left;
          if (seg[idx].right > seg[i].right)
            seg[i].right = seg[idx].right;
          j = seg[i].left;
        }
        j++;
      }
    }
  }
  qsort(seg, 26, sizeof(struct segment), cmp);
  char **ans = (char **)malloc(26 * sizeof(char));
  *returnSize = 0;
  int end = -1;
  for (int i = 0; i < 26; i++) {
    int left = seg[i].left, right = seg[i].right;
    if (left == -1)
      continue;
    if (end == -1 || left > end) {
      end = right;
      int len = right - left + 1;
      ans[*returnSize] = (char *)malloc((len + 1) * sizeof(char));
      strncpy(ans[*returnSize], s + left, len);
      ans[(*returnSize)++][len] = '\0';
    }
  }
  return ans;
}

int main() {
  char *s1 = "adefaddaccc";
  char *r1[] = {"e", "f", "ccc"};
  char *s2 = "abbaccd";
  char *r2[] = {"bb", "cc", "d"};
  int rs1, rs2;
  char **mnos1 = maxNumOfSubstrings(s1, &rs1);
  char **mnos2 = maxNumOfSubstrings(s2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", mnos1[i]);
    assert(!strcmp(mnos1[i], r1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", mnos2[i]);
    assert(!strcmp(mnos2[i], r2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(mnos1[i]);
  free(mnos1);
  for (int i = 0; i < rs2; i++)
    free(mnos2[i]);
  free(mnos2);
}
