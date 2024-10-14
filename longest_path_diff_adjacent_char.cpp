// 2246. Longest Path With Different Adjacent Characters
#include "leetcode.h"

/*
 * you are given a tree (ie. a connected undirected graph that has no cycles)
 * rooted at node '0' consisting of 'n' nodes numbered from '0' to 'n - 1'. the
 * tree is represented by a 0-indexed array 'parent' of size 'n' where
 * 'parent[i]' is the parent of node 'i'. since node 0 is the root, 'parent[0] =
 * -1'. you are also given a string 's' of length 'n', where 's[i]' is the
 * character assigned to node 'i'. return the legnth of the longest path in the
 * tree such that no pair of adjacnet nodes on the path have the same character
 * assigned to them.
 */

class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    int n = parent.size(), ans = 1;
    queue<int> q;
    vector<int> cnt(n), top1(n, 1), top2(n, 1);
    for (int i = 1; i < n; ++i)
      ++cnt[parent[i]];
    for (int i = 1; i < n; ++i)
      if (!cnt[i])
        q.push(i);
    while (!q.empty() && q.front()) {
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
  vector<int> p1 = {-1, 0, 0, 1, 1, 2}, p2 = {-1, 0, 0, 0};
  printf("%d\n", obj.longestPath(p1, "abacbe")); // expect: 3
  printf("%d\n", obj.longestPath(p2, "aabc"));   // expect: 3
}
