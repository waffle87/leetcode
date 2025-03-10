#include "leetcode.h"
#include <string>

class Solution {
public:
  string pushDominoes(string dominoes) {
    dominoes = 'L' + dominoes + 'R';
    string ans = "";
    for (int i = 0, j = 1; j < dominoes.size(); ++j) {
      if (dominoes[j] == '.')
        continue;
      int middle = j - i - 1;
      if (i > 0)
        ans += dominoes[i];
      if (dominoes[i] == dominoes[j])
        ans += string(middle, dominoes[i]);
      else if (dominoes[i] == 'L' && dominoes[j] == 'R')
        ans += string(middle, '.');
      else
        ans += string(middle / 2, 'R') + string(middle % 2, '.') +
               string(middle / 2, 'L');
      i = j;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.pushDominoes("RR.L");
}
