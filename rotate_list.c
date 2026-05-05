// 61. Rotate List
#include "leetcode.h"

/*
 * given the 'head' of a linked list, rotate the list to the rigt by 'k' places.
 */

struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head)
    return NULL;
  int n = 1;
  struct ListNode *tail = head;
  while (tail->next) {
    n++;
    tail = tail->next;
  }
  tail->next = head;
  int m = n - k % n;
  for (int i = 0; i < m; i++)
    tail = tail->next;
  head = tail->next;
  tail->next = NULL;
  return head;
}

int main() {
  int h1i[] = {1, 2, 3, 4, 5}, r1[] = {4, 5, 1, 2, 3};
  int h2i[] = {0, 1, 2}, r2[] = {2, 0, 1};
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h2i, ARRAY_SIZE(h2i));
  struct ListNode *rr1 = rotateRight(h1, 2);
  struct ListNode *rr2 = rotateRight(h2, 4);
  listnode_print(rr1, r1);
  listnode_print(rr2, r2);
  listnode_free(h1);
  listnode_free(h2);
}
