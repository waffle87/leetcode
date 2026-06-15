// 2095. Delete the Middle Node of a Linked List
#include "leetcode.h"

/*
 * you are given the 'head' of a linked list. delete the middle node, and return
 * the 'head' of the modified linked list. the middle of a linked list of size
 * 'n' is the 'floor(n / 2)'th node from the start using 0-based indexing, where
 * 'floor(x)' denotes the largest integer less than or equal to 'x'.
 */

struct ListNode *deleteMiddle(struct ListNode *head) {
  struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
  prev->val = 0;
  prev->next = head;
  struct ListNode *slow = prev, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct ListNode *tmp = slow->next;
  slow->next = slow->next->next;
  free(tmp);
  struct ListNode *ans = prev->next;
  free(prev);
  return ans;
}

int main() {
  int h1i[] = {1, 3, 4, 7, 1, 2, 6}, r1[] = {1, 3, 4, 1, 2, 6};
  int h2i[] = {1, 2, 3, 4}, r2[] = {1, 2, 4};
  int h3i[] = {2, 1}, r3[] = {2};
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h2i, ARRAY_SIZE(h2i));
  struct ListNode *h3 = listnode_build(h3i, ARRAY_SIZE(h3i));
  struct ListNode *dm1 = deleteMiddle(h1);
  struct ListNode *dm2 = deleteMiddle(h2);
  struct ListNode *dm3 = deleteMiddle(h3);
  listnode_print(dm1, r1);
  listnode_print(dm2, r2);
  listnode_print(dm3, r3);
  listnode_free(h1);
  listnode_free(h2);
  listnode_free(h3);
}
