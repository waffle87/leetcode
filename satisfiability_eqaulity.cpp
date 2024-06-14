#include "leetcode.h"

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    for (int i = 0; i < 26; ++i)
      uf[i] = i;
    for (string e : equations)
      if (e[1] == '=')
        uf[find(e[0] - 'a')] = find(e[3] - 'a');
    for (string e : equations)
      if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
        return false;
    return true;
  }

private:
  int uf[26];
  int find(int x) {
    if (x != uf[x])
      uf[x] = find(uf[x]);
    return uf[x];
  }
};

int main() {
  Solution obj;
  vector<string> equations = {"a==b", "b!=a"};
  if (obj.equationsPossible(equations))
    cout << "true";
  else
    cout << "false";
}
