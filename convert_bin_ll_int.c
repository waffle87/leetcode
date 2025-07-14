// 1290. Convert Binary Number in a Linked List to Integer
#include "leetcode.h"

/*
 * given 'head' which is a reference node to a singly linked list. the value of
 * each node in the linked list is either 0 or 1. the linked list holds the
 * binary representation of a number. return the decimal value of the number in
 * the linked list. the most significant bit is at the head of the linked list.
 */

int getDecimalValue(struct ListNode *head) {
  int ans = 0;
  while (head) {
    ans <<= 1;
    ans += head->val;
    head = head->next;
  }
  return ans;
}

int main() {
  struct ListNode *h1 = listnode_create(1);
  h1->next = listnode_create(0);
  h1->next->next = listnode_create(1);
  struct ListNode *h2 = listnode_create(0);
  printf("%d\n", getDecimalValue(h1)); // expect: 5
  printf("%d\n", getDecimalValue(h2)); // expect: 0
  listnode_free(h1);
  listnode_free(h2);
}
