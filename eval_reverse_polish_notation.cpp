#include "leetcode.h"

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    unordered_map<string, function<int(int, int)>> umf = {
        {"+", [](long a, long b) { return a + b; }},
        {"-", [](long a, long b) { return a - b; }},
        {"*", [](long a, long b) { return a * b; }},
        {"/", [](long a, long b) { return a / b; }}};
    stack<long> stk;
    for (string &s : tokens) {
      if (!umf.count(s))
        stk.push(stoi(s));
      else {
        long op1 = stk.top();
        stk.pop();
        long op2 = stk.top();
        stk.pop();
        stk.push(umf[s](op2, op1));
      }
    }
    return static_cast<int>(stk.top());
  }
};

int main() {
  Solution obj;
  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  // output: 9
  // ((2 + 1) * 3)
  cout << obj.evalRPN(tokens1);
  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  // output: 6
  // (4 + (13 / 5))
  cout << obj.evalRPN(tokens2);
  vector<string> tokens3 = {"10", "6", "9",  "3", "+", "-11", "*",
                            "/",  "*", "17", "+", "5", "+"};
  // output: 22
  // ((10 * (6 / (12 * -11))) + 17) + 5
  // ((10 * (6 / -132)) + 17) + 5
  // ((10 * 0) + 17) + 5
  // (0 + 17) + 5
  // 17 + 5
  cout << obj.evalRPN(tokens3);
}
