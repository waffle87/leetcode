#include "leetcode.h"

class Solution {
public:
  vector<int> countSubTrees(int n, vvd(int) & edges, string labels) {
    vector<int> ans(n);
    int cnt[26] = {};
    vvd(int) i(n);
    for (auto e : edges) {
      i[e[0]].push_back(e[1]);
      i[e[1]].push_back(e[0]);
    }
    dfs(0, labels, i, cnt, ans);
    return ans;
  }

private:
  void dfs(int i, string labels, vvd(int) & edges, int cnt[],
           vector<int> &ans) {
    if (ans[i] == 0) {
      ans[i] = 1;
      for (auto j : edges[i]) {
        int cnt1[26] = {};
        dfs(j, labels, edges, cnt1, ans);
        for (auto k = 0; k < 26; ++k)
          cnt[k] += cnt1[k];
      }
      ans[i] = ++cnt[labels[i] - 'a'];
    }
  }
};

int main() {
  Solution obj;
  vvd(int) edges1 = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}},
           edges2 = {{0, 1}, {1, 2}, {0, 3}},
           edges3 = {{0, 1}, {0, 2}, {1, 3}, {0, 4}};
  for (auto i : obj.countSubTrees(7, edges1, "abaedcd"))
    cout << i << ' '; // expect: 2,1,1,1,1,1,1
  cout << endl;
  for (auto i : obj.countSubTrees(4, edges2, "bbbb"))
    cout << i << ' '; // expect: 4,2,1,1
  cout << endl;
  for (auto i : obj.countSubTrees(5, edges3, "aabab"))
    cout << i << ' '; // expect: 3,2,1,1,1
  cout << endl;
}
