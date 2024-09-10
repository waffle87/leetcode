// 2807. Insert Greatest Common Divisors in Linked List
#include "leetcode.h"

/*
 * given the head of a linked list 'head', in which each node contains an
 * integer value. between every pair of adjacent nodes, insert a new node with a
 * value equal to the greatest common divisor. return the linked list after
 * insertion. the greatest common divisor of two numbers is the largest positive
 * integer that evenly divides both numbers.
 */

int gcd(int a, int b) {
  int i = 2, res = 1;
  while (i <= a && i <= b) {
    if (!(a % i) && !(b % i))
      res = i;
    i++;
  }
  return res;
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head) {
  struct ListNode *ans = head;
  while (head && head->next) {
    int r = gcd(head->val, head->next->val);
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = r;
    struct ListNode *tmp = head->next;
    head->next = new;
    new->next = tmp;
    head = new->next;
  }
  return ans;
}

int main() {
  struct ListNode *head = listnode_create(18);
  head->next = listnode_create(6);
  head->next->next = listnode_create(10);
  head->next->next->next = listnode_create(3);
  struct ListNode *igcd = insertGreatestCommonDivisors(head);
  listnode_print(igcd); // expect: 18 6 6 2 10 1 3
  listnode_free(head);
  listnode_free(igcd);
}
