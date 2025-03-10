// 133. Clone Graph
#include <cstddef>
#include <unordered_map>
#include <vector>
using namespace std;

// given reference of a node in a connected undirected graph. return a deep copy
// (clone) of the graph. each node in the graph contains a value  and a
// list (list[node]).

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  Node *dfs(Node *curr, unordered_map<Node *, Node *> &um) {
    vector<Node *> neighbour;
    Node *clone = new Node(curr->val);
    um[curr] = clone;
    for (auto i : curr->neighbors) {
      if (um.find(i) != um.end())
        neighbour.push_back(um[i]);
      else
        neighbour.push_back(dfs(i, um));
    }
    clone->neighbors = neighbour;
    return clone;
  }

public:
  Node *cloneGraph(Node *node) {
    unordered_map<Node *, Node *> um;
    if (node == NULL)
      return NULL;
    if (!node->neighbors.size()) {
      Node *clone = new Node(node->val);
      return clone;
    }
    return dfs(node, um);
  }
};
