// 2416. Sum of Prefix Scores of Strings
#include "leetcode.h"

/*
 * you are given an array 'words' of size 'n' consisting of non empty strings.
 * we define the score of a string 'word' as the number of strings 'words[i]'
 * such that 'word' is a prefix of 'words[i]'. return an array 'answer' of size
 * 'n' where 'answer[i]' is the sum of the scores of every non empty prefix of
 * 'words[i]'. note that a string is considered as a prefix of itself.
 */

struct trie {
  struct trie *children[26];
  int cnt;
};

struct trie *trie_init() {
  return (struct trie *)calloc(sizeof(struct trie), 1);
}

int trie_insert(struct trie *obj, char *word) {
  int n = strlen(word), idx;
  for (int i = 0; i < n; i++) {
    idx = word[i] - 'a';
    if (!obj->children[idx])
      obj->children[idx] = trie_init();
    obj->children[idx]->cnt++;
    obj = obj->children[idx];
  }
  return n;
}

int trie_pre_cnt(struct trie *obj, char *word) {
  int n = strlen(word), res = 0, idx;
  for (int i = 0; i < n; i++) {
    idx = word[i] - 'a';
    res += obj->children[idx]->cnt;
    obj = obj->children[idx];
  }
  return res;
}

int *sumPrefixScores(char **words, int wordsSize, int *returnSize) {
  struct trie *t = trie_init();
  int max_len = INT_MIN;
  for (int i = 0; i < wordsSize; i++)
    max_len = fmax(max_len, trie_insert(t, words[i]));
  int *ans = (int *)calloc(sizeof(int), max_len + 1);
  *returnSize = 0;
  for (int i = 0; i < wordsSize; i++)
    ans[(*returnSize)++] = trie_pre_cnt(t, words[i]);
  return ans;
}

int main() {
  int rs1, rs2;
  char *w1[] = {"abc", "ab", "bc", "b"}, *w2[] = {"abcd"};
  int *sps1 = sumPrefixScores((char **)w1, ARRAY_SIZE(w1), &rs1);
  int *sps2 = sumPrefixScores((char **)w2, ARRAY_SIZE(w2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sps1[i]); // expect: 5 4 3 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sps2[i]); // expect: 4
  printf("\n");
  free(sps1), free(sps2);
}
