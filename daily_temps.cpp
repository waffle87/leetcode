#include "leetcode.h"

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> nge(n, 0);
    stack<int> stk{};
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && temperatures[stk.top()] <= temperatures[i])
        stk.pop();
      if (!stk.empty())
        nge[i] = stk.top() - i;
      stk.push(i);
    }
    return nge;
  }
};

int main() {
  Solution obj;
  vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> t2 = {30, 40, 50, 60};
  vector<int> t3 = {30, 60, 90};
  obj.dailyTemperatures(t1); // expect 1,1,4,2,1,1,0,0
  obj.dailyTemperatures(t2); // expect 1,1,1,0
  obj.dailyTemperatures(t3); // expect 1,1,0
}
