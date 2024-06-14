// 705. Design HashSet
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * design a 'HashSet' without using any built-in hash table libraries. implement
 * 'MyHashSet' class:
 * - 'void add(key)' inserts the value 'key' into the HashSet
 * - 'bool contains(key)' returns whether the value 'key' exists or not
 * - 'void remove(key)' removes the value 'key'. does nothing if 'key' does not
 * exist
 */

#define TABLE_SIZE 500

struct Node {
  struct Node *next;
  int val;
};

typedef struct {
  struct Node *table[TABLE_SIZE];
} MyHashSet;

MyHashSet *myHashSetCreate() {
  MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
  if (obj)
    memset(obj, 0, sizeof(MyHashSet));
  return obj;
}

void myHashSetAdd(MyHashSet *obj, int key) {
  int idx = key % TABLE_SIZE;
  struct Node **added_node;
  struct Node *n = obj->table[idx];
  if (!n)
    added_node = &obj->table[idx];
  else
    while (n) {
      if (n->val == key)
        return;
      if (!n->next) {
        added_node = &n->next;
        break;
      }
      n = n->next;
    }
  *added_node = (struct Node *)malloc(sizeof(struct Node));
  (*added_node)->val = key;
  (*added_node)->next = NULL;
}

void myHashSetRemove(MyHashSet *obj, int key) {
  int idx = key % TABLE_SIZE;
  struct Node *n = obj->table[idx], *t;
  if (n && n->val == key) {
    obj->table[idx] = n->next;
    free(n);
  } else {
    while (n) {
      if (n->next && n->next->val == key) {
        t = n->next;
        n->next = t->next;
        free(t);
        break;
      }
      n = n->next;
    }
  }
}

bool myHashSetContains(MyHashSet *obj, int key) {
  int idx = key % TABLE_SIZE;
  struct Node *n = obj->table[idx];
  while (n) {
    if (n->val == key)
      return true;
    n = n->next;
  }
  return false;
}

void myHashSetFree(MyHashSet *obj) {
  struct Node *n, *t;
  for (int i = 0; i < TABLE_SIZE; i++) {
    n = obj->table[i];
    while (n) {
      t = n->next;
      free(n);
      n = t;
    }
  }
  free(obj);
}

int main() {
  MyHashSet *obj = myHashSetCreate();
  myHashSetAdd(obj, 1);
  myHashSetAdd(obj, 2);
  printf("%d\n", myHashSetContains(obj, 1)); // expect: 1
  printf("%d\n", myHashSetContains(obj, 3)); // expect: 0
  myHashSetAdd(obj, 2);
  printf("%d\n", myHashSetContains(obj, 2)); // expect: 1
  myHashSetRemove(obj, 2);
  printf("%d\n", myHashSetContains(obj, 2)); // expect: 0
}
