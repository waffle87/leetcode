// 1203. Sort Items by Groups Respecting Dependencies
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * there are 'n' items in each belonging to zero or one of 'm' groups where
 * 'group[i]' is the group that the i'th item beglons to and it's equal to '-1'
 * if the i'th item beglongs to no group. the items and the groups are zero
 * indexed. a group can have no item belonging to it. return a sorted list of
 * the items such that
 * - the items that belong to the same group are next to each other in the
 * sorted list
 * - there are some relations between these items where 'beforeItems[i]' is a
 * list containing all the items that should come before the i'th item in the
 * sorted array (to the left of the i'th item) return any solution if there is
 * more than one solution and return an empty list if there is no solution.
 */

typedef enum {
  UnVisited,
  Exploring,
  Visited,
} Status;

typedef struct Node_t {
  Status status;
  int id;
  bool isVertex;
  struct AdjNode_t *next;
  struct AdjNode_t *adj;
} Node;

typedef struct AdjNode_t {
  Node *data;
  struct AdjNode_t *next;
} AdjNode;

void append_adj(Node *head, Node *data) {
  AdjNode *adj = head->adj;
  if (adj) {
    while (adj->next)
      adj = adj->next;
    adj->next = malloc(sizeof(AdjNode));
    memset(adj->next, 0, sizeof(AdjNode));
    adj->next->data = data;
  } else {
    head->adj = malloc(sizeof(AdjNode));
    memset(head->adj, 0, sizeof(AdjNode));
    head->adj->data = data;
  }
  return;
}

void append_next(Node *head, Node *data) {
  AdjNode *node = (AdjNode *)head->next;
  if (node) {
    while (node->next)
      node = node->next;
    node->next = malloc(sizeof(AdjNode));
    memset(node->next, 0, sizeof(AdjNode));
    node->next->data = data;
  } else {
    head->next = malloc(sizeof(AdjNode));
    memset(head->next, 0, sizeof(AdjNode));
    head->next->data = data;
  }
  return;
}

int N = 0;  // return size
int *R = 0; // return array

bool dfs(Node *node) {
  if (node == 0 || node->status == Visited)
    return true;
  else if (node->status == Exploring)
    return false;
  node->status = Exploring;

  AdjNode *next = node->next;
  while (next) {
    if (!dfs(next->data))
      return false;
    next = next->next;
  }
  if (!node->isVertex) {
    AdjNode *adj = node->adj;
    while (adj) {
      if (!dfs(adj->data))
        return false;
      adj = adj->next;
    }
  }
  if (node->isVertex)
    R[--N] = node->id;
  node->status = Visited;
  return true;
}

int *sortItems(int n, int m, int *group, int groupSize, int **beforeItems,
               int beforeItemsSize, int *beforeItemsColSize, int *returnSize) {
  R = malloc(sizeof(int) * n);
  N = n;
  Node items[n];
  memset(items, 0, sizeof(Node) * n);
  for (int i = 0; i < n; i++) {
    items[i].id = i;
    items[i].isVertex = true;
    if (group[i] == -1)
      group[i] = m++;
  }
  Node groupheads[m];
  memset(groupheads, 0, sizeof(Node) * m);
  for (int i = 0; i < n; i++) {
    append_adj(&(groupheads[group[i]]), &(items[i]));
    for (int j = 0; j < beforeItemsColSize[i]; j++) {
      int before = beforeItems[i][j];
      if (group[before] == group[i])
        append_next(&(items[before]), &(items[i]));
      else
        append_next(&(groupheads[group[before]]), &(groupheads[group[i]]));
    }
  }
  for (int i = 0; i < m; i++)
    if (!dfs(&(groupheads[i]))) {
      printf("\ncycle detected...\n");
      *returnSize = 0;
      return 0;
    }
  *returnSize = n;
  return R;
}
