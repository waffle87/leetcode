// 141. Linked List Cycle
#include "leetcode.h"

/*
 * given the 'head' of a linked list, determine if the linked list has a cycle
 * in it. there is a cycle in a linked list if there is some node in the list
 * that can be reached again by continuously following the 'next' pointer.
 * internally, 'pos' is used to denote the index of the node that tail's 'next'
 * pointer is connected to. note that 'pos' is not passed as a parameter. return
 * true if there is a cycle in the linked list. otherwise return false.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct hash_entry {
  int id;
  char name[10];
  UT_hash_handle hh;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode *tmp = head;
  struct hash_entry *s, *users = NULL;
  while (tmp) {
    long user_id = tmp;
    HASH_FIND_INT(users, &user_id, s);
    if (!s) {
      s = malloc(sizeof(*s));
      s->id = tmp;
      HASH_ADD_INT(users, id, s);
    } else
      return true;
    tmp = tmp->next;
  }
  return false;
}
