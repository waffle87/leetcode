#include "leetcode.h"

/*
 * given: 2 strings of same length ('s1', 's2'), & a string 'baseStr'
 * s1[i] and s2[i] are equivalent characters
 * eg. s1 = "abc", s2 = "cde", 'a' == 'c', 'b' == 'd', etc.
 * return lexicographically smallest equivalent string of 'baseStr' by using
 * equivalency information from 's1' & 's2'
 */

class Solution {
public:
  // union find
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> ds(26, -1);
    for (auto i = 0; i < s1.size(); ++i)
      dsMerge(ds, s1[i] - 'a', s2[i] - 'a');
    for (auto i = 0; i < baseStr.size(); ++i)
      baseStr[i] = dsFind(ds, baseStr[i] - 'a') + 'a';
    return baseStr;
  }

private:
  int dsFind(vector<int> &ds, int p) {
    return ds[p] == -1 ? p : ds[p] = dsFind(ds, ds[p]);
  }
  void dsMerge(vector<int> &ds, int p1, int p2) {
    p1 = dsFind(ds, p1), p2 = dsFind(ds, p2);
    if (p1 != p2)
      ds[max(p1, p2)] = min(p1, p2);
  }
};

int main() {
  Solution obj;
  cout << obj.smallestEquivalentString("parker", "morris",
                                       "parser"); // expect: makkek
  cout << obj.smallestEquivalentString("hello", "world", "hold"); // expect:
                                                                  // hdld
  cout << obj.smallestEquivalentString("leetcode", "programs",
                                       "sourcecode"); // expect: aauaaaaada
}
