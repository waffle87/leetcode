#include "leetcode.h"

class MinStack {
public:
  stack<int> st;
  int min = INT_MAX;
  void push(int val) {
    if (min >= val) {
      st.push(min);
      min = val;
    }
    st.push(val);
  }
  void pop() {
    if (min == st.top()) {
      st.pop();
      min = st.top();
    }
    st.pop();
  }
  int top() { return st.top(); }
  int getMin() { return min; }
};
