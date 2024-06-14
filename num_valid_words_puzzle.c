// 1178. Number of Valid Words for Each Puzzle
#include "leetcode.h"

/*
 * with respect to a given puzzle string, a word is valid of both the following
 * conditions are satisfied. word contains the first letter of puzzle. for each
 * letter in word, that letter is in puzzle. invalid words are "beefed" (does
 * not include "a") and "based" (includes "s" which is not in the puzzle).
 * return an array where arr[i] is the number of words in the given word list
 * words that is valid with respect to the puzzle
 */

int *findNumOfValidWords(char **words, int wordsSize, char **puzzles,
                         int puzzlesSize, int *returnSize) {
  int *ans = (int *)calloc(puzzlesSize, sizeof(int));
  int *freq = (int *)calloc(68000000, sizeof(int));
  for (int i = 0; i < wordsSize; i++) {
    int tmp = 0, cnt = 0;
    for (int j = 0; j < strlen(words[i]); j++) {
      int bit = (1 << (int)(words[i][j] - 'a'));
      if (tmp & bit)
        continue;
      cnt++;
      if (cnt > 7)
        break;
      tmp |= (1 << (int)(words[i][j] - 'a'));
    }
    if (cnt > 7)
      continue;
    freq[tmp]++;
  }
  for (int i = 0; i < puzzlesSize; i++)
    for (int j = 0; j < 64; j++) {
      int tmp = (1 << (int)(puzzles[i][0] - 'a'));
      for (int k = 0; k < 6; k++)
        if (j & (1 << k))
          tmp |= (1 << (int)(puzzles[i][k + 1] - 'a'));
      ans[i] += freq[tmp];
    }
  *returnSize = puzzlesSize;
  free(freq);
  return ans;
}

int main() {
  char *w1[7][7] = {
      {"aaaa", "asas", "able", "ability", "actt", "actor", "access"}};
  char *w2[3][6] = {{"apple", "pleas", "please"}};
  char *p1[6][7] = {
      {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"}};
  char *p2[5][7] = {{"aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"}};
  int rs1, rs2;
  int *fnovw1 = findNumOfValidWords((char **)w1, 7, (char **)p1, 6, &rs1);
  int *fnovw2 = findNumOfValidWords((char **)w2, 3, (char **)p2, 5, &rs2);
  for (int i = 0; i < 6; i++)
    printf("%d ", fnovw1[i]); // expect: 1 1 3 2 4 0
  printf("\n");
  for (int i = 0; i < 5; i++)
    printf("%d ", fnovw2[i]); // expect: 0 1 3 2 0
  printf("\n");
}
