// 725. Split Linked List in Parts
#include <stdlib.h>

/*
 * given the 'head' of a singly linked list and an integer 'k', split the linked
 * list into 'k' consecutive linked list parts. the length of each part should
 * be as equal as possible: no two parts should have a size differing by more
 * than one. this may lead some parts being null. the parts should be in the
 * order of occurence in the input list, and parts occuring earlier should
 * always have a size greater than or equal to parts occuring later. return an
 * array of the 'k' parts.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

int length(struct ListNode *head) {
  if (!head)
    return 0;
  return length(head->next) + 1;
}

struct ListNode **splitListToParts(struct ListNode *head, int k,
                                   int *return_size) {
  int n = length(head);
  *return_size = k;
  int items = n / k, left = n % k, idx_a = 0;
  struct ListNode **ans = malloc(k * sizeof(struct ListNode *));
  struct ListNode *ptr = head, *tmp;
  for (int i = 0; i < left; i++) {
    ans[idx_a] = ptr;
    idx_a++;
    for (int j = 0; j < items; j++)
      ptr = ptr->next;
    tmp = ptr;
    ptr = ptr->next;
    tmp->next = NULL;
  }
  for (int i = left; i < k; i++) {
    if (items <= 0) {
      ans[idx_a] = NULL;
      idx_a++;
      continue;
    }
    ans[idx_a] = ptr;
    idx_a++;
    for (int j = 0; j < items - 1; j++)
      ptr = ptr->next;
    if (i < k - 1) {
      tmp = ptr;
      ptr = ptr->next;
      tmp->next = NULL;
    }
  }
  return ans;
}
