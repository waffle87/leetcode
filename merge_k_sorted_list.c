// 23. Merge k Sorted Lists
#include <stddef.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int lists_size) {
  if (lists_size == 0)
    return NULL;
  struct ListNode *head = malloc(sizeof(struct ListNode));
  struct ListNode *tmp = head, *min;
  int id;
  while (1) {
    min = lists[0];
    id = 0;
    for (int i = 1; i < lists_size; i++) {
      if (min == NULL && lists[i]) {
        min = lists[i];
        id = i;
      }
      if (lists[i] == NULL)
        continue;
      else {
        if (lists[i]->val < min->val) {
          min = lists[i];
          id = i;
        }
      }
    }
    if (min == NULL) {
      tmp->next = NULL;
      break;
    }
    tmp->next = min;
    tmp = tmp->next;
    lists[id] = lists[id]->next;
    while (lists[id] && lists[id]->val == tmp->val) {
      tmp->next = lists[id];
      tmp = tmp->next;
      lists[id] = lists[id]->next;
    }
  }
  return head->next;
}
