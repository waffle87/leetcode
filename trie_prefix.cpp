// 208. Implement Trie (Prefix Tree)
#include "leetcode.h"

class Trie {
public:
  Trie() {}
  void insert(string word) {
    Trie *node = this;
    for (char c : word) {
      if (!node->next.count(c))
        node->next[c] = new Trie();
      node = node->next[c];
    }
    node->is_word = true;
  }
  bool search(string word) {
    Trie *node = this;
    for (char c : word) {
      if (!node->next.count(c))
        return false;
      node = node->next[c];
    }
    return node->is_word;
  }
  bool startsWith(string prefix) {
    Trie *node = this;
    for (char c : prefix) {
      if (!node->next.count(c))
        return false;
      node = node->next[c];
    }
    return true;
  }

private:
  map<char, Trie *> next = {};
  bool is_word = false;
};

int main() {
  Trie *obj = new Trie();
  obj->insert("Trie");
  bool param_2 = obj->search("Trie");
  bool param_3 = obj->startsWith("Trie");
}
