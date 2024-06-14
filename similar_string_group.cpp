// 839. Similar String Groups
#include "leetcode.h"

/*
 * two strings 'x' and 'y' are similar if we can swap two letters
 * of 'x' so that it equals 'y'. also two strings 'x' and 'y' are
 * given a list of 'strs' of strings where every string in 'strs'
 * is an anagram of every other string in 'strs'. how many groups?
 */

class disjointSet {
  vector<int> v;
  int sz;

public:
  void make_set(int n) {
    v.resize(n);
    iota(v.begin(), v.end(), 0);
    sz = n;
  }
  disjointSet(int n) { make_set(n); }
  int find(int i) {
    if (i != v[i])
      v[i] = find(v[i]);
    return v[i];
  }
  void join(int i, int j) {
    int r_i = find(i), r_j = find(j);
    if (r_i != r_j) {
      v[r_i] = r_j;
      sz--;
    }
  }
  int size() { return sz; }
};

class Solution {
  bool similar(string a, string b) {
    int n = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i] && ++n > 2)
        return false;
    return true;
  }

public:
  int numSimilarGroups(vector<string> &strs) {
    disjointSet ds(strs.size());
    for (int i = 0; i < strs.size(); i++)
      for (int j = i + 1; j < strs.size(); j++)
        if (similar(strs[i], strs[j]))
          ds.join(i, j);
    return ds.size();
  }
};

int main() {
  Solution obj;
  vector<string> s1 = {"tars", "rats", "arts", "star"};
  vector<string> s2 = {"omv", "ovm"};
  printf("%d\n", obj.numSimilarGroups(s1));
  printf("%d\n", obj.numSimilarGroups(s2));
}
