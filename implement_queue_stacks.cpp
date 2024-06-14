#include "leetcode.h"

class MyQueue {
public:
  stack<int> input, output;
  void push(int x) { input.push(x); }
  int pop() {
    int x = output.top();
    peek();
    return x;
  }
  int peek() {
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }
  bool empty() { return input.empty() && output.empty(); }
};

int main() {
  MyQueue *obj = new MyQueue();
  obj->push(2);
  int param_2 = obj->pop();
  int param_3 = obj->peek();
  bool param_4 = obj->empty();
  cout << param_2 << endl << param_3 << endl;
  if (param_4)
    cout << "true";
  else
    cout << "endl";
}
