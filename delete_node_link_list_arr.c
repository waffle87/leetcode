// 3217. Delete Nodes From Linked List Present in Array
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' and the 'head' of a linked list.
 * return the 'head' of the modified linked list after removing all nodes from
 * the linked list that have a value that exists in 'nums'.
 */

#define HASH_SIZE 1000

struct hash_node {
  int val;
  struct hash_node *next;
};

int find_idx(int val) { return val % HASH_SIZE; }

void insert_hash_table(struct hash_node **table, int val) {
  int hash_idx = find_idx(val);
  if (!table[hash_idx]) {
    struct hash_node *new_hash =
        (struct hash_node *)malloc(sizeof(struct hash_node));
    new_hash->val = val;
    new_hash->next = NULL;
    table[hash_idx] = new_hash;
    return;
  }
  struct hash_node *trav = table[hash_idx], *prev = NULL;
  while (trav) {
    if (trav->val == val)
      return;
    else if (val > trav->val) {
      prev = trav;
      trav = trav->next;
    } else
      break;
  }
  struct hash_node *new_hash =
      (struct hash_node *)malloc(sizeof(struct hash_node));
  new_hash->val = val;
  if (!prev) {
    table[hash_idx] = new_hash;
    new_hash->next = trav;
  } else {
    prev->next = new_hash;
    new_hash->next = trav;
  }
  return;
}

bool search_hash_table(struct hash_node **table, int val) {
  int hash_idx = find_idx(val);
  struct hash_node *trav = table[hash_idx];
  while (trav) {
    if (trav->val)
      return true;
    trav = trav->next;
  }
  return false;
}

struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head) {
  struct hash_node **table =
      (struct hash_node **)malloc(sizeof(struct hash_node *) * HASH_SIZE);
  for (int i = 0; i < HASH_SIZE; i++)
    table[i] = NULL;
  for (int i = 0; i < numsSize; i++)
    insert_hash_table(table, nums[i]);
  struct ListNode *prev = NULL, *trav = head;
  while (trav) {
    bool found = search_hash_table(table, trav->val);
    if (found) {
      struct ListNode *del_node = trav;
      trav = trav->next;
      if (prev)
        prev->next = trav;
      else
        head = trav;
      free(del_node);
    } else {
      prev = trav;
      trav = trav->next;
    }
  }
  return head;
}

int main() {
  int nums[] = {1, 2, 3};
  struct ListNode *head = listnode_create(1);
  head->next = listnode_create(2);
  head->next->next = listnode_create(3);
  head->next->next->next = listnode_create(4);
  head->next->next->next->next = listnode_create(5);
  struct ListNode *ml1 = modifiedList(nums, ARRAY_SIZE(nums), head);
  listnode_print(ml1); // expect: 4 5
  listnode_free(head);
  listnode_free(ml1);
}
