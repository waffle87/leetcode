// 472. Concatenated Words
#include "leetcode.h"

/*
 * given an array of strings 'words' (without duplicates), return all the
 * concatenated words in the given list of 'words'. a concatenated word is
 * defined as as string that is comprised entirely of at least two shorter
 * words in the given array.
 */

class Solution {
private:
  struct Trie {
    struct Trie *arr[26];
    bool end = false;
    Trie() {
      memset(arr, 0, sizeof(arr));
      end = false;
    }
  };
  Trie *root;
  void insert(string s) {
    Trie *node = root;
    for (int i = s.length() - 1; i >= 0; i--) {
      char c = s[i];
      if (!node->arr[c - 'a'])
        node->arr[c - 'a'] = new Trie();
      node = node->arr[c - 'a'];
    }
    node->end = true;
  }

public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    sort(words.begin(), words.end(),
         [](string &w1, string &w2) { return (w1.length() <= w2.length()); });
    vector<string> ans;
    root = new Trie();
    for (string w : words) {
      if (w.length() == 0)
        continue;
      vector<bool> dp(w.length() + 1, false);
      dp[0] = true;
      for (int i = 0; i < w.length(); i++) {
        Trie *node = root;
        for (int j = i; j >= 0; j--) {
          if (node->arr[w[j] - 'a'] == NULL)
            break;
          node = node->arr[w[j] - 'a'];
          if (dp[j] && node->end) {
            dp[i + 1] = true;
            break;
          }
        }
      }
      if (dp[w.length()])
        ans.push_back(w);
      insert(w);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> words1 = {"cat", "cats",        "catsdogcats",
                           "dog", "dogcatsdog",  "hippopotamuses",
                           "rat", "ratcatdogcat"};
  vector<string> words2 = {"cat", "dog", "catdog"};
  for (auto i : obj.findAllConcatenatedWordsInADict(words1))
    cout << i << ' ';
  cout << endl;
  for (auto i : obj.findAllConcatenatedWordsInADict(words2))
    cout << i << ' ';
}
