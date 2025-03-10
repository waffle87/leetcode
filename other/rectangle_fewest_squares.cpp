#include "leetcode.h"

class Solution {
public:
  int maxDepth = 0;
  int tilingRectangle(int n, int m) {
    if (n > m)
      swap(n, m);
    vector<int> s;
    for (int i = 0; i < n; i++)
      s.push_back(m);
    maxDepth = max(n, m);
    dfs(s, 0);
    return maxDepth;
  }

private:
  typedef long long key;
  unordered_map<key, int> dp;
  key hash(vector<int> &j) {
    key r = 0;
    for (int n : j)
      r = (r << 4LL) + n;
    return r;
  }
  void dfs(vector<int> j, int depth) {
    key h = hash(j);
    if (h == 0) {
      maxDepth = min(maxDepth, depth);
      return;
    }
    if (depth >= maxDepth || dp.count(h))
      return;
    auto topLeft = max_element(j.begin(), j.end());
    int width = 1;
    for (auto top = topLeft + 1; top != j.end() && *top == *topLeft; top++)
      width++;
    for (int w = min(width, *topLeft); w > 0; w--) {
      for (int i = 0; i < w; i++)
        *(topLeft + i) -= w;
      dfs(j, depth + 1);
      for (int i = 0; i < w; i++)
        *(topLeft + i) += w;
    }
  }
};

int main() {
  Solution obj;
  cout << obj.tilingRectangle(2, 3);
}
