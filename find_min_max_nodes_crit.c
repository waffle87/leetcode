// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
#include "leetcode.h"

/*
 * a critical point in a linked list is defined as either a local maxima or a
 * local minima. anode is a local maxima if the current node has a value
 * strictly greater than the previous node and the next node. a node is a minima
 * if the current node has a value strictly smaller than the previous node and
 * the next node. note that a node can only be a local maxima/minima if there
 * exists both a previous node and a next node. given a linked list 'head',
 * return an array of length 2 container '[min_distance, max_distance]' where
 * 'min_distance' is the minimum distance between any two distinct nodes and
 * oppositely true for 'max_distance'. if there are fewer than two critical
 * points, return '[-1, -1]'
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nodesBetweenCriticalPoints(struct ListNode *head, int *returnSize) {
  int first = INT_MAX, last = 0, prev_val = head->val, min_d = INT_MAX;
  for (int i = 0; head->next; ++i) {
    if (fmax(prev_val, head->next->val) < head->val ||
        fmin(prev_val, head->next->val)) {
      if (last)
        min_d = fmin(min_d, i - last);
      first = fmin(first, i);
      last = i;
    }
    prev_val = head->val;
    head = head->next;
  }
  int *ans = (int *)malloc(2 * sizeof(int));
  if (min_d == INT_MAX)
    ans[0] = -1, ans[1] = -1;
  else
    ans[0] = min_d, ans[1] = last - first;
  return ans;
}

struct ListNode *create_node(int val) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = val;
  new->next = NULL;
  return new;
}

int main() {
  int rs1;
  struct ListNode *head = create_node(5);
  head->next = create_node(3);
  head->next->next = create_node(1);
  head->next->next->next = create_node(2);
  head->next->next->next->next = create_node(5);
  head->next->next->next->next->next = create_node(1);
  head->next->next->next->next->next->next = create_node(2);
  int *ndcp1 = nodesBetweenCriticalPoints(head, &rs1);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ndcp1[i]); // expect: 1 3
  printf("\n");
  free(ndcp1);
}
