// 208. Implement Trie (Prefix Tree)
#include <stdbool.h>
#include <stdlib.h>

typedef struct Trie {
  struct Trie *children[26];
  bool is_leaf;
} Trie;

Trie *trieCreate() {
  Trie *node = malloc(sizeof(Trie));
  for (int i = 0; i < 26; i++)
    node->children[i] = NULL;
  node->is_leaf = false;
  return node;
}

void trieInsert(Trie *obj, char *word) {
  Trie *tmp = obj;
  for (int i = 0; word[i] != '\0'; i++) {
    int idx = word[i] - 'a';
    if (tmp->children[idx] == NULL)
      tmp->children[idx] = trieCreate();
    tmp = tmp->children[idx];
  }
  tmp->is_leaf = true;
}

bool trieSearch(Trie *obj, char *word) {
  Trie *tmp = obj;
  for (int i = 0; word[i] != '\0'; i++) {
    int idx = word[i] - 'a';
    if (tmp->children[idx] == NULL)
      return false;
    tmp = tmp->children[idx];
  }
  return tmp->is_leaf;
}

bool trieStartsWith(Trie *obj, char *prefix) {
  Trie *tmp = obj;
  for (int i = 0; prefix[i] != '\0'; i++) {
    int idx = prefix[i] - 'a';
    if (tmp->children[idx] == NULL)
      return false;
    tmp = tmp->children[idx];
  }
  return true;
}

void trieFree(Trie *obj) {
  Trie *tmp = obj;
  for (int i = 0; i < 26; i++)
    if (tmp->children[i] != NULL)
      trieFree(tmp->children[i]);
  free(obj);
}

int main() {
  Trie *obj = trieCreate();
  trieInsert(obj, word);
  bool param_2 = trieSearch(obj, word);
  bool param_3 = trieStartsWith(obj, prefix);
  trieFree(obj);
}
