// 3403. Find the Lexicographically Largest String From the Box I
#include "leetcode.h"

/*
 * you are given a string 'word', and an integer 'numFriends'. alice is
 * organising a game for her 'numFriends' friends. there are multiple rounds in
 * the game, where each round: 'word' is split into 'numFriends' non-empty
 * strings such that no previous round has the exact same split, and all the
 * split words are put into a box. find the lexicographically largest string
 * from the box after all rounds are finished.
 */

char *answerString(char *word, int numFriends) {
  int n = strlen(word), m = n - (numFriends - 1);
  if (numFriends == 1) {
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    strcpy(ans, word);
    return ans;
  }
  char *ans = (char *)malloc((m + 1) * sizeof(char));
  ans[0] = '\0';
  for (int i = 0; i < m; ++i) {
    int k = n - i < m ? n - i : m;
    char *tmp = (char *)malloc((k + 1) * sizeof(char));
    strncpy(tmp, word + i, k);
    tmp[k] = '\0';
    if (strcmp(ans, tmp) < 0) {
      free(ans);
      ans = tmp;
    } else
      free(tmp);
  }
  return ans;
}

int main() {
  char *w1 = "dbca", *w2 = "gggg";
  printf("%s\n", answerString(w1, 2)); // expect: dbc
  printf("%s\n", answerString(w2, 4)); // expect: g
}
