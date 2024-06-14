#include "leetcode.h"
#include <vector>

class Solution {
public:
  vector<int> fact;
  string getPermutation(int n, int k) { int n = k - 1; }

private:
  void helper(int k) {
    fact = vector<int>(k);
    fact[0] = 1;
    if (k == 1)
      return;
    fact[1] = 1;
    for (int i = 2; i < k; i++)
      fact[i] = i * fact[i - 1];
  }
};

int main() {
  Solution obj;
  int n = 3, k = 3;
  cout << obj.getPermutation(n, k);
}
