// 3217. Delete Nodes From Linked List Present in Array
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' and the 'head' of a linked list.
 * return the 'head' of the modified linked list after removing all nodes from
 * the linked list that have a value that exists in 'nums'.
 */

struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head) {
  bool map[100001] = {false};
  for (int i = 0; i < numsSize; i++)
    if (nums[i] >= 0 && nums[i] <= 100000)
      map[nums[i]] = true;
  while (head && map[head->val])
    head = head->next;
  struct ListNode *curr = head;
  while (curr && curr->next) {
    if (map[curr->next->val])
      curr->next = curr->next->next;
    else
      curr = curr->next;
  }
  return head;
}

int main() {
  int n1[] = {1, 2, 3}, h1i[] = {1, 2, 3, 4, 5};
  int n2[] = {1}, h2i[] = {1, 2, 1, 2, 1, 2};
  int n3[] = {5}, h3i[] = {1, 2, 3, 4};
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h3 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *ml1 = modifiedList(n1, ARRAY_SIZE(n1), h1);
  struct ListNode *ml2 = modifiedList(n2, ARRAY_SIZE(n2), h2);
  struct ListNode *ml3 = modifiedList(n3, ARRAY_SIZE(n3), h3);
  listnode_print(ml1); // expect: 4 5
  listnode_print(ml2); // expect: 2 2 2
  listnode_print(ml3); // expect: 1 2 3 4
  listnode_free(h1);
  listnode_free(h2);
  listnode_free(h3);
  listnode_free(ml1);
  listnode_free(ml2);
  listnode_free(ml3);
}
