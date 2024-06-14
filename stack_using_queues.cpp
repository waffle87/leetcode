#include "leetcode.h"

class MyStack {
public:
  queue<int> q;
  MyStack() {}
  void push(int x) {
    int n = q.size();
    q.push(x);
    while (n--) {
      q.push(q.front());
      q.pop();
    }
  }
  int pop() {
    int ans = top();
    q.pop();
    return ans;
  }
  int top() { return q.front(); }
  bool empty() { return q.empty(); }
};

int main() {}
