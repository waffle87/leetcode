#include "leetcode.h"

class Solution {
public:
  int calPoints(vector<string> &ops) {
    int val1, val2, ans = 0;
    stack<int> s;
    for (string i : ops) {
      if (i == "C")
        s.pop();
      else if (i == "D")
        s.push(s.top() * 2);
      else if (i == "+") {
        val1 = s.top();
        s.pop();
        val2 = s.top();
        s.push(val1);
        s.push(val1 + val2);
      } else
        s.push(stoi(i));
    }
    while (s.size() != 0) {
      ans += s.top();
      s.pop();
    }
    return ans;
  }
};

int main() {}
