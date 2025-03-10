// 382. Linked List Random Node
#include "leetcode.h"

/*
 * given singly linked list, return a random node's value from the linked list.
 * each node must have the same probability of being chosen. implement
 * 'Solution' class: f1: initialises object with head of signly linked list
 * 'head' f2: chooses node randomly from list and returns its value. all nodes
 * should be equally likely to be chosen
 */

class Solution {
public:
  Solution(ListNode *head) {
    this->head = head;
    while (head != NULL) {
      this->n++;
      head = head->next;
    }
  }
  int getRandom() {
    int i = rand() % this->n;
    ListNode *p = this->head;
    while (i) {
      p = p->next;
      i -= 1;
    }
    return p->val;
  }

private:
  int n = 0;
  ListNode *head = NULL;
};

int main() {
  ListNode *head;
  Solution *obj = new Solution(head);
  int param_1 = obj->getRandom();
}
