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

int *nodesBetweenCriticalPoints(struct ListNode *head, int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;
  memset(ans, -1, 2 * sizeof(int));
  if (!head->next)
    return ans;
  int cp1 = -1, cp2 = -1, cp3 = -1;
  int a = head->val, b = head->next->val, c, i = 0;
  head = head->next->next;
  while (head) {
    c = head->val;
    if ((b > a && b > c) || (b < a && b < c)) {
      if (cp1 < 0)
        cp1 = i;
      else if (cp2 < 0) {
        cp2 = i;
        ans[0] = ans[1] = cp2 - cp1;
      } else {
        if (cp3 > 0)
          cp2 = cp3;
        cp3 = i;
        ans[0] = fmin(ans[0], cp3 - cp2);
        ans[1] = cp3 - cp1;
      }
    }
    a = b;
    b = c;
    ++i;
    head = head->next;
  }
  return ans;
}

int main() {
  int h1i[] = {3, 1}, r1[] = {-1, -1}, rs1;
  int h2i[] = {5, 3, 1, 2, 5, 1, 2}, r2[] = {1, 3}, rs2;
  int h3i[] = {1, 3, 2, 2, 3, 2, 2, 2, 7}, r3[] = {3, 3}, rs3;
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h2i, ARRAY_SIZE(h2i));
  struct ListNode *h3 = listnode_build(h3i, ARRAY_SIZE(h3i));
  int *nbcp1 = nodesBetweenCriticalPoints(h1, &rs1);
  int *nbcp2 = nodesBetweenCriticalPoints(h2, &rs2);
  int *nbcp3 = nodesBetweenCriticalPoints(h3, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", nbcp1[i]);
    assert(nbcp1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", nbcp2[i]);
    assert(nbcp2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", nbcp3[i]);
    assert(nbcp3[i] == r3[i]);
  }
  printf("\n");
  listnode_free(h1);
  listnode_free(h2);
  listnode_free(h3);
  free(nbcp1);
  free(nbcp2);
  free(nbcp3);
}
