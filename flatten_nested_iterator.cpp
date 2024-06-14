#include "leetcode.h"

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    int n = nestedList.size();
    for (int i = n - 1; i >= 0; --i)
      nodes.push(nestedList[i]);
  }
  int next() {
    int ans = nodes.top().getInteger();
    nodes.pop();
    return ans;
  }
  bool hasNext() {
    while (!nodes.empty()) {
      NestedInteger curr = nodes.top();
      if (curr.isInteger())
        return true;
      nodes.pop();
      vector<NestedInteger> &adj = curr.getList();
      int n = adj.size();
      for (int i = n - 1; i >= 0; --i)
        nodes.push(adj[i]);
    }
    return false;
  }

private:
  stack<NestedInteger> nodes;
};

int main() {}
