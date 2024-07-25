// 937. Reorder Data in Log Files
#include "leetcode.h"

/*
 * given an array of 'logs'. each log is a space delimited sting of words where
 * the first word is the identifier. there are two types of logs. letter logs
 * where all words consist of lowercase english letters, and digit logs where
 * all words consist of digits. reorder thesse logs so that the letter logs come
 * before the digit logs, the letter logs are sorted lexicographically by their
 * contents. if their contents are the same, then sort them lexicographically by
 * their identifiers, the digit logs maintain their relative order. return the
 * final order of the logs.
 */

int cmp(const void *x, const void *y) {
  const char *s1 = *(const char **)x, *s2 = *(const char **)y;
  const char *sp1 = strchr(s1, ' '), *sp2 = strchr(s2, ' ');
  bool a1 = isalpha(*++sp1), a2 = isalpha(*++sp2);
  int r = 0, l = sp1 - s1;
  return a1 && a2 ? !(r = strcmp(sp1, sp2)) ? strncmp(s1, s2, l) : r : a2 - a1;
}

char **reorderLogFiles(char **logs, int logsSize, int *returnSize) {
  qsort(logs, logsSize, sizeof(char *), cmp);
  return *returnSize = logsSize, logs;
}

int main() {
  char *l1[] = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig",
                "let3 art zero"};
  char *l2[] = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog",
                "a8 act zoo"};
  int rs1, rs2;
  char **rlf1 = reorderLogFiles((char **)l1, ARRAY_SIZE(l1), &rs1);
  char **rlf2 = reorderLogFiles((char **)l2, ARRAY_SIZE(l2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", rlf1[i]); // expect: "let1 art can","let3 art zero","let2 own
                            // kit dig","dig1 8 1 5 1","dig2 3 6"
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", rlf2[i]); // expect: "g1 act car","a8 act zoo","ab1 off key
                            // dog","a1 9 2 3 1","zo4 4 7"
  printf("\n");
  free(rlf1), free(rlf2);
}
