// 2976. Minimum Cost to Convert String I
#include "leetcode.h"

/*
 * you are given two 0 indexed strings 'source' and 'target', both of length 'n'
 * and consisting of lowercase english letters. you are also given two 0 indexed
 * character arrays 'original' and 'changed', and an integer array 'cost' where
 * 'cost[i]' represents the cost of changing the character 'original[i]' to the
 * character 'changed[i]' you start with the string 'source'. in one operation,
 * you can pick a character 'x' from te string and change it to the character
 * 'y' at a cost of 'z' if there exists any index 'j' such that 'cost[j] == z,
 * original[j] == x, changed[j] == y'. return the minimum cost to conver the
 * string 'source' to the string 'target'.
 */

class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    long long ans = 0;
    vector<vector<long long>> n(26, vector<long long>(26, INT_MAX));
    for (int i = 0; i < original.size(); ++i) {
      int s = original[i] = 'a', t = changed[i] - 'a';
      n[s][t] = min(n[s][t], (long long)cost[i]);
    }
    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
          n[i][j] = min(n[i][j], n[i][k] + n[k][j]);
    for (int i = 0; i < source.size(); ++i) {
      if (source[i] == target[i])
        continue;
      int s = source[i] - 'a', t = target[i] - 'a';
      if (n[s][t] >= INT_MAX)
        return -1;
      ans += n[s][t];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<char> o1 = {'a', 'b', 'c', 'c', 'e', 'd'},
               ch1 = {'b', 'c', 'b', 'e', 'b', 'e'}, o2 = {'a', 'b'},
               ch2 = {'c', 'b'}, o3 = {'a'}, ch3 = {'e'};
  vector<int> co1 = {2, 5, 5, 1, 2, 20}, co2 = {1, 2}, co3 = {10000};
  printf("%lld\n", obj.minimumCost("abcd", "acbe", o1, ch1, co1)); // expect: 28
  printf("%lld\n", obj.minimumCost("aaaa", "bbbb", o2, ch2, co2)); // expect: 12
  printf("%lld\n", obj.minimumCost("abcd", "acbe", o3, ch3, co3)); // expect: -1
}
