// 20. Valid Parentheses
#include "leetcode.h"

/*
 * given a string 's' containing just the characters '(, ), {, }, [, ]',
 * determine if the input string is valid. a input string is valid if open
 * brackets must be closed by the same type of brackets. open brackets must be
 * closed in the correct order. every close bracket has a corresponding open
 * bracket of the same type.
 */

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (ch == '(' || ch == '{' || ch == '[')
        stk.push(ch);
      else {
        if (!stk.empty()) {
          char top = stk.top();
          if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
              (ch == ']' && top == '['))
            stk.pop();
          else
            return false;
        } else
          return false;
      }
    }
    if (stk.empty())
      return true;
    return false;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.isValid("()"));     // expect: 1
  printf("%d\n", obj.isValid("()[]{}")); // expect: 1
  printf("%d\n", obj.isValid("(]"));     // expect: 0
}
