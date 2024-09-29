// 432. All O`one Data Structure
#include "leetcode.h"

/*
 * design a data structure to store the strings' count with the ability to
 * return the strings with minimum and maximum counts. implement the 'allOne'
 * class. Note that each function must run in O(1) average time complexity
 */

struct data {
  char key[12];
  int val;
  void *next;
  void *above;
  void *below;
};

typedef struct {
  int table_size;
  struct data **hash_table;
  struct data *top;
  struct data *bottom;
} AllOne;

AllOne *allOneCreate() {
  AllOne *obj = (AllOne *)malloc(sizeof(AllOne));
  obj->table_size = 1024;
  obj->hash_table = calloc(sizeof(struct data), obj->table_size);
  obj->top = NULL;
  obj->bottom = NULL;
  return obj;
}

void allOneInc(AllOne *obj, char *key) {
  AllOne self = *obj;
  int hash = 0;
  for (int i = 0; i < strlen(key); i++)
    hash += key[i];
  hash %= self.table_size;
  struct data *check = self.hash_table[hash];
  while (check) {
    if (!strcmp(key, check->key)) {
      struct data *whirl = check->above;
      while (whirl && check->val > whirl->val) {
        if (check->below)
          ((struct data *)(check->below))->above = whirl;
        if (whirl->above)
          ((struct data *)(whirl->above))->below = check;
        whirl->below = check->below;
        check->above = whirl->above;
        check->below = (void *)whirl;
        whirl->above = (void *)check;
        whirl = (struct data *)check->above;
        if (self.bottom == check)
          self.bottom = check->below;
      }
      if (!whirl)
        self.top = check;
      *obj = self;
      return;
    }
    check = check->next;
  }
  struct data *new = (struct data *)malloc(sizeof(struct data));
  strcpy(new->key, key);
  new->val = 1;
  new->next = (void *)self.hash_table[hash];
  self.hash_table[hash] = new;
  if (!self.top)
    self.top = new;
  new->below = NULL;
  new->above = self.bottom;
  if (self.bottom)
    self.bottom->below = new;
  self.bottom = new;
  *obj = self;
}

void allOneDec(AllOne *obj, char *key) {
  AllOne self = *obj;
  int hash = 0;
  for (int i = 0; i < strlen(key); i++)
    hash += key[i];
  hash %= self.table_size;
  struct data *old_check = NULL, *check = self.hash_table[hash];
  while (check) {
    if (!strcmp(key, check->key)) {
      if (!check->val) {
        if (!old_check)
          self.hash_table[hash] = check->next;
        else
          old_check->next = check->next;
        if (check == self.top)
          self.top = check->below;
        if (check == self.bottom)
          self.bottom = check->above;
        if (check->above)
          ((struct data *)(check->below))->above = check->above;
        free(check);
        *obj = self;
        return;
      }
      struct data *whirl = (struct data *)check->below;
      while (whirl && check->val < whirl->val) {
        if (check->above)
          ((struct data *)(check->above))->below = whirl;
        if (whirl->below)
          ((struct data *)(whirl->below))->above = check;
        whirl->above = check->above;
        check->below = whirl->below;
        check->above = (void *)whirl;
        whirl->below = (void *)check;
        whirl = (struct data *)check->below;
        if (self.top == check)
          self.top = check->above;
      }
      if (!whirl)
        self.bottom = check;
      *obj = self;
      return;
    }
    old_check = check;
    check = check->next;
  }
  return;
}

char *allOneGetMaxKey(AllOne *obj) {
  if (!obj->top)
    return "";
  return obj->top->key;
}

char *allOneGetMinKey(AllOne *obj) {
  if (!obj->bottom)
    return "";
  return obj->bottom->key;
}

void allOneFree(AllOne *obj) {
  AllOne self = *obj;
  for (int i = 0; i < self.table_size; i++) {
    struct data *old_check, *check = self.hash_table[i];
    while (check) {
      old_check = check;
      check = check->next;
      free(old_check);
    }
  }
  free(self.hash_table);
  free(obj);
}

int main() {
  AllOne *obj = allOneCreate();
  char *k1 = "hello", *k2 = "hello", *k3 = "leet";
  allOneInc(obj, k1);
  allOneInc(obj, k2);
  printf("%s\n", allOneGetMaxKey(obj)); // expect: hello
  printf("%s\n", allOneGetMinKey(obj)); // expect: hello
  allOneInc(obj, k3);
  printf("%s\n", allOneGetMaxKey(obj)); // expect: hello
  printf("%s\n", allOneGetMinKey(obj)); // expect: leet
  allOneFree(obj);
}
