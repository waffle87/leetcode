// 234. Palindrome Linked List
#include "leetcode.h"

/*
 * given the head of a signly linked list return true if it is a palindrome or
 * false otherwise.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverse_list(struct ListNode *head) {
  if (!head || !head->next)
    return head;
  struct ListNode *tmp = reverse_list(head->next);
  head->next->next = head;
  head->next = NULL;
  return tmp;
}

bool isPalindrome(struct ListNode *head) {
  if (!head)
    return 1;
  struct ListNode *iter = head, *reversed_half_list;
  int cnt = 0;
  bool flag = 1;
  while (iter) {
    cnt++;
    iter = iter->next;
  }
  iter = head;
  for (int i = 0; i < cnt / 2; i++)
    iter = iter->next;
  if (!(cnt % 2))
    reversed_half_list = reverse_list(iter);
  else if (iter->next)
    reversed_half_list = reverse_list(iter->next);
  iter = head;
  if (cnt == 1)
    return 1;
  if (!reversed_half_list)
    return 0;
  while (iter && reversed_half_list) {
    if (iter->val != reversed_half_list->val) {
      flag = 0;
      break;
    }
    iter = iter->next;
    reversed_half_list = reversed_half_list->next;
  }
  return flag;
}
