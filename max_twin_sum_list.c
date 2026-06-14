// 2130. Maximum Twin Sum of a Linked List
#include "leetcode.h"

/*
 * in a linked-list of size 'n', where 'n' is even, the i'th node (0-indexed) of
 * the linked list is known as the twin of the 'n - 1 - i' node, if 0 <= i <= (n
 * / 2) - 1. for example, if 'n = 4', then node 0 is the twin of node 3, and
 * node 1 is the twin node of node 2. these are the only nodes with twins for 'n
 * = 4'. the twin sum is defined as the sum of a node and its twin. given the
 * 'head' of a linked list with even length, return the maximum twin sum of the
 * linked list.
 */

struct ListNode *reverse(struct ListNode *head) {
  struct ListNode *prev = NULL;
  while (head) {
    struct ListNode *next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

int pairSum(struct ListNode *head) {
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  while (fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct ListNode *half_head = reverse(slow->next);
  int ans = 0;
  while (half_head) {
    int curr = head->val + half_head->val;
    ans = fmax(ans, curr);
    head = head->next;
    half_head = half_head->next;
  }
  return ans;
}

int main() {
  int h1i[] = {5, 4, 2, 1};
  int h2i[] = {4, 2, 2, 3};
  int h3i[] = {1, 100000};
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h2i, ARRAY_SIZE(h2i));
  struct ListNode *h3 = listnode_build(h3i, ARRAY_SIZE(h3i));
  int r1 = pairSum(h1);
  int r2 = pairSum(h2);
  int r3 = pairSum(h3);
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 7);
  printf("%d\n", r3);
  assert(r3 == 100001);
  listnode_free(h1);
  listnode_free(h2);
  listnode_free(h3);
}
