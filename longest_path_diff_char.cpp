#include "leetcode.h"

class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    int n = parent.size(), ans = 1;
    queue<int> q;
    vector<int> cnt(n), top1(n, 1), top2(n, 1);
    for (int i = 1; i < n; ++i)
      ++cnt[parent[i]];
    for (int i = 1; i < n; ++i)
      if (cnt[i] == 0)
        q.push(i);
    while (!q.empty() && q.front() != 0) {
      int i = q.front(), p = parent[i];
      q.pop();
      if (int len = 1 + (s[i] != s[p] ? top1[i] : 0); top1[p] <= len) {
        top2[p] = top1[p];
        top1[p] = len;
      } else
        top2[p] = max(top2[p], len);
      if (--cnt[p] == 0) {
        q.push(p);
        ans = max(ans, top1[p] + top2[p] - 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> parent1 = {-1, 0, 0, 1, 1, 2}, parent2 = {-1, 0, 0, 0};
  cout << obj.longestPath(parent1, "abacbe") << endl; // expect: 3
  cout << obj.longestPath(parent2, "aabc") << endl;   // expect: 3
}
