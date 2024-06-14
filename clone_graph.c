// 133. Clone Graph
#include <stdbool.h>
#include <stdlib.h>

// given reference of a node in a connected undirected graph. return a deep copy
// (clone) of the graph. each node in the graph contains a value (int) and a
// list (list[node]).

struct Node {
  int val;
  int numNeighbors;
  struct Node **neighbors;
};

struct Node *process(struct Node *s, bool *hash, struct Node **data) {
  if (hash[s->val])
    return data[s->val];
  struct Node *root = malloc(sizeof(struct Node));
  root->val = s->val;
  hash[s->val] = true;
  data[s->val] = root;
  root->numNeighbors = s->numNeighbors;
  root->neighbors = malloc(s->numNeighbors * sizeof(struct Node *));
  for (int i = 0; i < s->numNeighbors; i++)
    root->neighbors[i] = process(s->neighbors[i], hash, data);
  return root;
}

struct Node *cloneGraph(struct Node *s) {
  if (s == NULL)
    return NULL;
  bool *hash = calloc(101, sizeof(int));
  struct Node **data = malloc(101 * sizeof(struct Node *));
  return process(s, hash, data);
}
