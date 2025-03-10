// 445. Add Two Numbers II
#include "leetcode.h"

/*
 * given two non-empty linked lists representing two non-negative integers. the
 * most significant digit comes first and each of their nodes contains a single
 * digit. add the two numbers and return the same as a linked list. you may
 * assume the two numbers do not contain any leading zero, except the number 0
 * itself.
 */

class Solution {
  ListNode *append(int val, ListNode *head) {
    ListNode *tmp = new ListNode(val);
    tmp->next = head;
    return tmp;
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int n1 = 0, n2 = 0, carry = 0;
    ListNode *curr1 = l1, *curr2 = l2, *ans = NULL;
    while (curr1)
      curr1 = curr1->next, n1++;
    while (curr2)
      curr2 = curr2->next, n2++;
    curr1 = l1, curr2 = l2;
    while (n1 && n2) {
      int sum = 0;
      if (n1 >= n2) {
        sum += curr1->val;
        curr1 = curr1->next;
        n1--;
      }
      if (n2 > n1) {
        sum += curr2->val;
        curr2 = curr2->next;
        n2--;
      }
      ans = append(sum, ans);
    }
    curr1 = ans;
    ans = NULL;
    while (curr1) {
      curr1->val += carry;
      carry = curr1->val / 10;
      ans = append(curr1->val % 10, ans);
      curr2 = curr1;
      curr1 = curr1->next;
      delete curr2;
    }
    if (carry)
      ans = append(1, ans);
    return ans;
  }
};
