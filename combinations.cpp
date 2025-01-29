// 77. Combinations
#include "leetcode.h"

/*
 * given two integers 'n' and 'k', return all possible combinations of 'k'
 * numbers chosen from the range '[1, n]'. you may return the answer in any
 * order
 */

class Solution {
public:
  vvd combine(int n, int k) {
    vvd ans;
    int i = 0;
    vector<int> p(k, 0);
    while (i >= 0) {
      p[i]++;
      if (p[i] > n)
        --i;
      else if (i == k - 1)
        ans.push_back(p);
      else
        i++, p[i] = p[i - 1];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  for (auto i : obj.combine(4, 2))
    for (auto j : i)
      printf("%d ", j); // expect: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
  printf("\n");
  for (auto i : obj.combine(1, 1))
    for (auto j : i)
      printf("%d ", j); // expect: [[1]]
  printf("\n");
}
