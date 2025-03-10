#include "leetcode.h"

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (auto a : s)
      freq[a]++;
    priority_queue<pair<int, char>> pqp;
    for (auto [a, f] : freq)
      pqp.push({f, a});
    string ans;
    pair<int, char> curr;
    while (!pqp.empty()) {
      curr = pqp.top();
      pqp.pop();
      ans += string(curr.first, curr.second);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.frequencySort("tree");
}
