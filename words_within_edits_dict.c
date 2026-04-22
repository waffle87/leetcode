// 2452. Words Within Two Edits of Dictionary
#include "leetcode.h"

/*
 * you are given two string arrays 'queries' and 'dictionary'. all words in each
 * array comprise of lowercase english letters and have the same length. in one
 * edit, you can take a word from 'queries' and change any letter in it to any
 * other letter. find all words from 'queries' that, after a maximum of two
 * edits, equal some word from 'dictionary'. return a list of all words from
 * 'queries' that match with some word from 'dictionary' after a maximum of two
 * edits. return the words in the same order that they appear in 'queries'.
 */

char **twoEditWords(char **queries, int queriesSize, char **dictionary,
                    int dictionarySize, int *returnSize) {
  int n = strlen(queries[0]), cnt = 0;
  char **ans = (char **)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    char *q = queries[i];
    for (int k = 0; k < dictionarySize; k++) {
      char *d = dictionary[k];
      int diff = 0;
      for (int j = 0; j < n; j++) {
        if (q[j] != d[j])
          diff++;
        if (diff > 2)
          break;
      }
      if (diff <= 2) {
        ans[cnt++] = q;
        break;
      }
    }
  }
  *returnSize = cnt;
  return ans;
}

int main() {
  char *q1[] = {"word", "note", "ants", "wood"};
  char *d1[] = {"wood", "joke", "moat"};
  char *q2[] = {"yes"};
  char *d2[] = {"not"};
  char *r1[] = {"word", "note", "wood"};
  char *r2[] = {};
  int rs1, rs2;
  char **tew1 = twoEditWords(q1, ARRAY_SIZE(q1), d1, ARRAY_SIZE(d1), &rs1);
  char **tew2 = twoEditWords(q2, ARRAY_SIZE(q2), d2, ARRAY_SIZE(d2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", tew1[i]);
    assert(!strcmp(tew1[i], r1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", tew2[i]);
    assert(!strcmp(tew2[i], r2[i]));
  }
  printf("\n");
  free(tew1);
  free(tew2);
}
