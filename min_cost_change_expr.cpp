#include "leetcode.h"

class Solution {
public:
  int minOperationsToFlip(string expression) {
    vector<vector<array<char, 2>>> vva(1);
    for (auto ch : expression) {
      if (ch == '(')
        vva.push_back(vector<array<char, 2>>());
      else if (ch == ')') {
        auto val = eval(vva.back(), vva.back().size() - 1);
        vva.pop_back();
        vva.back().push_back(val);
      } else
        vva.back().push_back({ch, 1});
    }
    return eval(vva.back(), vva.back().size() - 1)[1];
  }

private:
  array<char, 2> eval(vector<array<char, 2>> &exp, int i) {
    if (i == 0)
      return exp[0];
    auto left = eval(exp, i - 2), right = exp[i];
    int v1 = left[0] - '0', v2 = right[0] - '0', cost = 1;
    if (exp[i - 1][0] == '|') {
      if (v1 == v2)
        cost = min(left[1], right[1]) + (v1 == 1);
      return {v1 | v2 ? '1' : '0', (char)cost};
    }
    if (v1 == v2)
      cost = min(left[1], right[1]) + (v1 == 0);
    return {v1 & v2 ? '1' : '0', (char)cost};
  }
};

int main() {
  Solution obj;
  cout << obj.minOperationsToFlip("(0|(1|0&1))");
}
