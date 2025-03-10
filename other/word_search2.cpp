#include "leetcode.h"

struct Trie {
  bool isEnd;
  string word;
  Trie *child[26];
  Trie() {
    isEnd = false;
    word = "";
    for (int i = 0; i < 26; i++)
      child[i] = NULL;
  }
};

class Solution {
public:
  vector<string> ans;
  vector<string> findWords(vvd(char) & board, vector<string> &words) {
    int n = board.size(), m = board[0].size();
    for (auto w : words)
      insert(w);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        dfs(board, i, j, n, m, root);
    return ans;
  }

private:
  vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
  Trie *root = new Trie();
  void insert(string &s) {
    int n = s.size();
    Trie *curr = root;
    for (int i = 0; i < n; i++) {
      int idx = s[i] - 'a';
      if (curr->child[idx] == NULL)
        curr->child[idx] = new Trie();
      curr = curr->child[idx];
    }
    curr->isEnd = true;
    curr->word = s;
  }
  void dfs(vvd(char) & board, int i, int j, int n, int m, Trie *curr) {
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#')
      return;
    int idx = board[i][j] - 'a';
    if (curr->child[idx] == NULL)
      return;
    curr = curr->child[idx];
    if (curr->isEnd) {
      ans.push_back(curr->word);
      curr->isEnd = false;
    }
    char val = board[i][j];
    board[i][j] = '#';
    for (int k = 0; k < 4; k++) {
      int newI = i + dx[k], newJ = j + dy[k];
      dfs(board, newI, newJ, n, m, curr);
    }
    board[i][j] = val;
  }
};

int main() {
  Solution obj;
  vvd(char) board = {{'a', 'b'}, {'c', 'd'}};
  vector<string> words = {"abcb"};
  for (auto i : obj.findWords(board, words))
    cout << i << endl;
}
