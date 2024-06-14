// 445. Add Two Numbers II
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given two non-empty linked lists representing two non-negative integers. the
 * most significant digit comes first and each of their nodes contains a single
 * digit. add the two numbers and return the same as a linked list. you may
 * assume the two numbers do not contain any leading zero, except the number 0
 * itself.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

static int append(struct ListNode *l1, struct ListNode *l2, int missing) {
  int carry, val;
  if (!l1)
    return 0;
  if (!missing) {
    carry = append(l1->next, l2->next, 0);
    val = l1->val + l2->val + carry;
  } else {
    carry = append(l1->next, l2->next, -1);
    val = l1->val + carry;
  }
  l1->val = val % 10;
  return val / 10;
}

static int length(struct ListNode *n) {
  int len;
  for (len = 0; n; n = n->next)
    len++;
  return len;
}

static void swap(struct ListNode **p1, struct ListNode **p2) {
  struct ListNode *tmp;
  tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int len1, len2, carry;
  struct ListNode *head;
  len1 = length(l1);
  len2 = length(l2);
  if (len1 < len2)
    swap(&l1, &l2);
  carry = append(l1, l2, abs(len1 - len2));
  if (carry) {
    if (!(head = malloc(sizeof(struct ListNode))))
      return head;
    head->val = 1;
    head->next = l1;
  }
  return l1;
}
