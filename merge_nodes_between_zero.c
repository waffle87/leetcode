// 2181. Merge Nodes in Between Zeros
#include "leetcode.h"

/*
 * given the 'head' of a linked list which contains a series of integers
 * separated by 0's. the beginning and end of the linked list will have
 * 'node.val == 0'. for every consecutive 0's, merge all the nodes lying in
 * between them into a single node whose value is the sum of all the merged
 * nodes. the modified list should not contain any 0's. return the 'head' of the
 * modified linked list.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeNodes(struct ListNode *head) {
  head = head->next;
  struct ListNode *trav = head;
  while (trav)
    if (trav->next && trav->next->val) {
      trav->val = trav->val + trav->next->val;
      trav->next = trav->next->next;
    } else {
      trav->next = trav->next->next;
      trav = trav->next;
    }
  return head;
}

struct ListNode *create_node(int val) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = val;
  new->next = NULL;
  return new;
}

void print_node(struct ListNode *head) {
  struct ListNode *curr = head;
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct ListNode *head = create_node(0);
  head->next = create_node(3);
  head->next->next = create_node(1);
  head->next->next->next = create_node(0);
  head->next->next->next->next = create_node(4);
  head->next->next->next->next->next = create_node(5);
  head->next->next->next->next->next->next = create_node(2);
  head->next->next->next->next->next->next->next = create_node(0);
  struct ListNode *merged_head = mergeNodes(head);
  print_node(merged_head); // expect: 4 11
}
