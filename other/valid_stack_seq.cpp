// 946. Validate Stack Sequences
#include "leetcode.h"

/*
 * given two integer arrays 'pushed' & 'popped' each with distinct
 * values, return true if this could have been the result of a sequence
 * of push and pop operations on an initially empty stack, or false otherwise
 */

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int i = 0;
    for (int x : pushed) {
      s.push(x);
      while (s.size() && s.top() == popped[i]) {
        s.pop();
        i++;
      }
    }
    return !s.size();
  }
};

int main() {
  Solution obj;
  vector<int> pushed = {1, 2, 3, 4, 5};
  vector<int> p1 = {4, 5, 3, 2, 1}, p2 = {4, 3, 5, 1, 2};
  printf("%d\n", obj.validateStackSequences(pushed, p1)); // expect: 1
  printf("%d\n", obj.validateStackSequences(pushed, p2)); // expect: 0
}
