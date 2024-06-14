// 1669. Merge In Between Linked Lists
#include "leetcode.h"

/*
 * given two linked lists 'l1' and 'l2' of sizes 'n' and 'm' respectively.
 * remove 'l1' nodes from the a'th node to the b'th node, and put 'l2' in their
 * place. the blue edges and nodes in the following figure indicate the result.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeInBetween(struct ListNode *list1, int a, int b,
                                struct ListNode *list2) {
  struct ListNode *nodea = list1, *nodeb = list1;
  int cnt = 0;
  for (struct ListNode *node = list1; node; node = node->next) {
    if (cnt == a - 1)
      nodea = node;
    if (cnt == b) {
      nodeb = node->next;
      break;
    }
    cnt++;
  }
  struct ListNode *tmp = list1;
  bool is_change = false;
  while (tmp) {
    if (tmp == nodea)
      tmp->next = list2;
    if (!tmp->next && !is_change) {
      tmp->next = nodeb;
      is_change = true;
    }
    tmp = tmp->next;
  }
  return list1;
}
