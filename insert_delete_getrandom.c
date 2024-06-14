// 380. Insert Delete GetRandom O(1)
#include "leetcode.h"

/*
Implement the RandomizedSet class:
RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present.
Returns true if the item was not present, false otherwise. bool remove(int val)
Removes an item val from the set if present. Returns true if the item was
present, false otherwise. int getRandom() Returns a random element from the
current set of elements (it's guaranteed that at least one element exists when
this method is called). Each element must have the same probability of being
returned.
You must implement the functions of the class such that each function works in
average O(1) time complexity.
*/

typedef struct {
  int val;
  struct node *next;
} node;

typedef struct {
  node **lists;
  int *counts;
  int total;
} RandomizedSet;

RandomizedSet *randomizedSetCreate() {
  RandomizedSet *obj = (RandomizedSet *)malloc(sizeof(RandomizedSet));
  obj->lists = (node **)calloc(128, sizeof(node *));
  obj->counts = (int *)calloc(128, sizeof(int));
  obj->total = 0;
  return obj;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
  int key = abs(val) % 128;
  node *new_node, *tmp_node, *pre_node;
  if (obj->lists[key] == NULL) {
    new_node = (node *)malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL;
    obj->lists[key] = new_node;
  } else {
    tmp_node = obj->lists[key];
    while (tmp_node) {
      pre_node = tmp_node;
      if (tmp_node->val == val)
        return false;
      tmp_node = tmp_node->next;
    }
    if (tmp_node == NULL) {
      new_node = (node *)malloc(sizeof(node));
      new_node->val = val;
      new_node->next = NULL;
      pre_node->next = new_node;
    }
  }
  obj->counts[key]++;
  obj->total++;
  return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
  node *pre_node, *tmp_node;
  int key = abs(val) % 128;
  if (obj->lists[key] == NULL) {
    return false;
  } else {
    tmp_node = obj->lists[key];
    while (tmp_node) {
      if (tmp_node->val == val) {
        if (pre_node)
          pre_node->next = tmp_node->next;
        else
          obj->lists[key] = tmp_node->next;
        free(tmp_node);
        obj->counts[key]--;
        obj->total--;
        return true;
      }
      pre_node = tmp_node;
      tmp_node = tmp_node->next;
    }
    return false;
  }
}

int randomizedSetGetRandom(RandomizedSet *obj) {
  int pos = rand() % obj->total;
  int i, sum = 0, key = 0;
  node *tmp_node;

  for (i = 0; i < 128; i++) {
    if (pos >= obj->counts[i]) {
      pos -= obj->counts[i];
    } else {
      key = i;
      break;
    }
  }
  tmp_node = obj->lists[key];
  while (tmp_node && pos) {
    tmp_node = tmp_node->next;
    pos--;
  }
  return tmp_node->val;
}

void randomizedSetFree(RandomizedSet *obj) {
  int i;
  node *pre_node, *tmp_node;
  for (i = 0; i < 128; i++) {
    tmp_node = obj->lists[i];
    while (tmp_node) {
      pre_node = tmp_node;
      tmp_node = tmp_node->next;
      free(pre_node);
    }
  }
  free(obj->counts);
  free(obj);
}
