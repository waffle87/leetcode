// 2467. Most Profitable Path in a Tree
#include "leetcode.h"

/*
 * there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1', rooted
 * at node 0. you are given a 2d integer array 'edges' of length 'n - 1' where
 * 'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
 * and 'b_i' in the tree. at every node 'i', there is a gate. you are also given
 * an array of even integers 'amount', where 'amount[i]' represents the price
 * needed to open the gate at node 'i', if 'amount[i]' is negative, or the case
 * reward obtained on oening the gate at node 'i' otherwise. return the maximum
 * net income alice can have if she travels towards the optimal leaf node.
 */

#define HIGH 100100
#define PASS 100010

struct node {
  int val;
  struct node *next;
};

struct head {
  struct node *head;
};

struct node *push_node(int val) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->val = val;
  new->next = NULL;
  return new;
}

void connect_edges(struct head *graph, int v1, int v2) {
  struct node *tmp = push_node(v2);
  tmp->next = graph[v1].head;
  graph[v1].head = tmp;
  tmp = push_node(v1);
  tmp->next = graph[v2].head;
  graph[v2].head = tmp;
}

struct head *create_graph(int **edges, int edgesSize) {
  struct head *graph =
      (struct head *)calloc(edgesSize + 1, sizeof(struct head));
  for (int i = 0; i < edgesSize; i++)
    connect_edges(graph, edges[i][0], edges[i][1]);
  return graph;
}

bool bob_traverse(struct head *graph, int *vis, int curr) {
  if (!curr)
    return true;
  struct node *new = graph[curr].head;
  while (new) {
    if (vis[new->val] == HIGH) {
      vis[new->val] = vis[curr] + 1;
      if (bob_traverse(graph, vis, new->val))
        return true;
      vis[new->val] = PASS;
    }
    new = new->next;
  }
  return false;
}

void alice_traverse(struct head *graph, int *alice_vis, int *bob_vis,
                    int *amount, int curr, int sum, int *max) {
  if (bob_vis[curr] > alice_vis[curr])
    sum += amount[curr];
  else if (bob_vis[curr] == alice_vis[curr])
    sum += amount[curr] / 2;
  struct node *new = graph[curr].head;
  bool leaf = true;
  while (new) {
    if (alice_vis[new->val] == HIGH) {
      leaf = false;
      alice_vis[new->val] = alice_vis[curr] + 1;
      alice_traverse(graph, alice_vis, bob_vis, amount, new->val, sum, max);
    }
    new = new->next;
  }
  if (leaf)
    *max = *max > sum ? *max : sum;
}

int mostProfitablePath(int **edges, int edgesSize, int *edgesColSize, int bob,
                       int *amount, int amountSize) {
  int *bob_vis = (int *)malloc((edgesSize + 1) * sizeof(int));
  int *alice_vis = (int *)malloc((edgesSize + 1) * sizeof(int));
  int max = INT_MIN;
  for (int i = 0; i <= edgesSize; i++)
    bob_vis[i] = alice_vis[i] = HIGH;
  struct head *graph = create_graph(edges, edgesSize);
  bob_vis[bob] = alice_vis[0] = 0;
  bob_traverse(graph, bob_vis, bob);
  alice_traverse(graph, alice_vis, bob_vis, amount, 0, 0, &max);
  return max;
}

int main() {
  int e1i[4][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}}, a1[] = {-2, 4, 2, -4, 6};
  int e2i[1][2] = {{0, 1}}, a2[] = {-7280, 2350};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  printf("%d\n", mostProfitablePath(e1->arr, e1->row_size, e1->col_size, 3, a1,
                                    ARRAY_SIZE(a1))); // expect: 6
  printf("%d\n", mostProfitablePath(e2->arr, e2->row_size, e2->col_size, 1, a2,
                                    ARRAY_SIZE(a2))); // expect: -7280
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
