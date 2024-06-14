// 648. Replace Words
#include "leetcode.h"

/*
 * in english we have a concept called root, which can be followed by some other
 * word to form another longer word lets call this word derivative. for example
 * when the root "help" is followed by the word "ful" we can form a derivative
 * "helpful". given a dictionary consisting of many roots and a 'sentence'
 * consisting of words separated by spaces, replace all the derivatives in the
 * sentence with the root forming it. if a derivative can be replaced by more
 * than one root, replace it with the root that has the shortest length. return
 * the 'sentence' after the replacement
 */

typedef struct Trie {
  struct Trie *children[26];
  bool is_leaf;
} Trie;

Trie *create() {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  for (int i = 0; i < 26; i++)
    node->children[i] = NULL;
  node->is_leaf = false;
  return node;
}

void insert(Trie *obj, char *word) {
  Trie *tmp = obj;
  for (int i = 0; word[i] != '\0'; i++) {
    int idx = word[i] - 'a';
    if (!tmp->children[idx])
      tmp->children[idx] = create();
    tmp = tmp->children[idx];
  }
  tmp->is_leaf = true;
}

int trieSearch(Trie *obj, char *word) {
  Trie *tmp = obj;
  int curr = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == ' ')
      return 0;
    int idx = word[i] - 'a';
    if (!tmp->children[idx])
      return 0;
    curr++;
    if (tmp->children[idx]->is_leaf)
      return curr;
    tmp = tmp->children[idx];
  }
  return 0;
}

int substring(char *str) {
  int l = strlen(str);
  for (int i = 0; i < l; i++)
    if (str[i] == ' ') {
      str[i] = '\0';
      return i;
    }
  return l;
}

char *replaceWords(char **dictionary, int dictionarySize, char *sentence) {
  Trie *root = create();
  for (int i = 0; i < dictionarySize; i++)
    insert(root, dictionary[i]);
  int len = strlen(sentence), a_idx = 0, idx = 0;
  char *ans = (char *)malloc((len + 1) * sizeof(char));
  while (idx < len) {
    int d = substring(&sentence[idx]);
    int l = trieSearch(root, &sentence[idx]);
    if (l) {
      strncpy(&ans[a_idx], &sentence[idx], l);
      ans[a_idx + l] = ' ';
      a_idx += l + 1;
    } else {
      strncpy(&ans[a_idx], &sentence[idx], d);
      ans[a_idx + d] = ' ';
      a_idx += d + 1;
    }
    idx += d + 1;
  }
  ans[a_idx - 1] = '\0';
  return ans;
}

int main() {
  char *d1[] = {"cat", "bat", "rat"}, *d2[] = {"a", "b", "c"};
  char *s1 = "the cattle was rattled by the battery",
       *s2 = "aadsfasf absbs bbab cadsfafs";
  printf("%s\n", replaceWords((char **)d1, ARRAY_SIZE(d1),
                              s1)); // expect: the cat was rat by the bat
  printf("%s\n",
         replaceWords((char **)d2, ARRAY_SIZE(d2), s2)); // expect: a a b c
}
