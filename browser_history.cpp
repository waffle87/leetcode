// 1472. Design Browser History
#include "leetcode.h"

/*
 * you have a browser of one tab where you start on the homepage and can visit
 * another url, get back in the history number of steps or move forward in the
 * history number of steps. implement BrowserHistory class (they're self
 * explantory)
 */

class BrowserHistory {
public:
  BrowserHistory(string homepage) { curr = homepage; }
  void visit(string url) {
    h_forward = stack<string>();
    h_back.push(curr);
    curr = url;
  }
  string back(int steps) {
    while (--steps >= 0 && !h_back.empty()) {
      h_forward.push(curr);
      curr = h_back.top();
      h_back.pop();
    }
    return curr;
  }
  string forward(int steps) {
    while (--steps >= 0 && !h_forward.empty()) {
      h_back.push(curr);
      curr = h_forward.top();
      h_forward.pop();
    }
    return curr;
  }

private:
  stack<string> h_back, h_forward;
  string curr;
};

int main() {
  BrowserHistory *obj = new BrowserHistory("https.xyz");
  string param_2 = obj->back(1);
  string param_3 = obj->forward(1);
}
