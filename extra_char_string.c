// 2707. Extra Characters in a String
#include "leetcode.h"

/*
 * you are given a 0-indexed string 's' and a dictionary of words 'dictionary'.
 * you have to break 's' into one or more non-overlapping substrings that each
 * substring is present in 'dictionary'. there may be some extra characters in
 * 's' which are not present in any of the substrings. return the minimum number
 * of extra characters left over if you break up 's' optimally
 */

struct node {
  struct node *next[26];
  bool is_end;
};

void trie_init(struct node **head) {
  *head = (struct node *)calloc(1, sizeof(struct node));
}

void trie_insert(struct node *head, char *s) {
  while (*s) {
    char c = *s - 'a';
    if (!head->next[c])
      head->next[c] = (struct node *)calloc(1, sizeof(struct node));
    head = head->next[c];
    s++;
  }
  head->is_end = true;
}

int trie_search(struct node *head, char *s, int *len_out) {
  int cnt = 0, len = 0;
  while (*s) {
    char c = *s - 'a';
    if (!head->next[c])
      break;
    head = head->next[c];
    s++;
    len++;
    if (head->is_end) {
      len_out[cnt] = len;
      cnt++;
    }
  }
  return cnt;
}

void trie_free(struct node *head) {
  if (head) {
    for (int i = 0; i < 26; i++)
      trie_free(head->next[i]);
    free(head);
  }
}

int minExtra(int idx, char *s, struct node *trie, int *dp) {
  int lens[50], cnt = 0, min = INT_MAX, extra;
  if (!s[idx])
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  cnt = trie_search(trie, &s[idx], lens);
  for (int i = 0; i < cnt; i++) {
    extra = minExtra(idx + lens[i], s, trie, dp);
    min = fmin(min, extra);
  }
  extra = minExtra(idx + 1, s, trie, dp) + 1;
  min = fmin(min, extra);
  dp[idx] = min;
  return min;
}

int minExtraChar(char *s, char **dictionary, int dictionarySize) {
  struct node *trie = NULL;
  int min = 0, n = strlen(s), *dp = (int *)malloc(n * sizeof(int *));
  trie_init(&trie);
  for (int i = 0; i < n; i++)
    dp[i] = -1;
  for (int i = 0; i < dictionarySize; i++)
    trie_insert(trie, dictionary[i]);
  min = minExtra(0, s, trie, dp);
  trie_free(trie);
  free(dp);
  return min;
}

int main() {
  char *s1 = "leetscode", *d1[] = {"leet", "code", "leetcode"};
  char *s2 = "sayhelloworld", *d2[] = {"hello", "world"};
  printf("%d\n", minExtraChar(s1, (char **)d1, ARRAY_SIZE(d1))); // expect: 1
  printf("%d\n", minExtraChar(s2, (char **)d2, ARRAY_SIZE(d2))); // expect: 3
}
