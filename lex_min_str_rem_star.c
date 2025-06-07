// 3170. Lexicographically Minimum String After Removing Stars
#include "leetcode.h"

/*
 * you are given a string 's'. it may contain any number of '*' characters. your
 * task to remove all '*' characters. while there is a '*' character, do the
 * following: delete the leftmost '*' and the smallest non-'*' character to its
 * left. if there are several smallest characters, you can delete any of them.
 * return the lexicographically smallest resulting string after removing all '*'
 * characters.
 */

struct node {
  char c;
  int idx;
};

struct pq {
  int (*cmp)(const void *, const void *);
  int size;
  int capacity;
  void **data;
};

struct node *node_init(char c, int idx) {
  struct node *obj = (struct node *)malloc(sizeof(struct node));
  obj->c = c;
  obj->idx = idx;
  return obj;
}

int cmp(const void *a, const void *b) {
  char c1 = ((struct node *)a)->c;
  char c2 = ((struct node *)b)->c;
  int n1 = ((struct node *)a)->idx;
  int n2 = ((struct node *)b)->idx;
  if (c1 < c2)
    return 1;
  if (c1 > c2)
    return -1;
  if (n1 > n2)
    return 1;
  if (n1 < n2)
    return -1;
  return 0;
}

struct pq *pq_init(int capacity, int (*cmp)(const void *, const void *)) {
  struct pq *obj = (struct pq *)malloc(sizeof(struct pq));
  obj->cmp = cmp;
  obj->size = 0;
  obj->capacity = capacity;
  obj->data = (void **)malloc(capacity * sizeof(void *));
  for (int i = 0; i < capacity; i++)
    obj->data[i] = NULL;
  return obj;
}

void pq_swap(struct pq *obj, const int key1, const int key2) {
  void *tmp = obj->data[key1];
  obj->data[key1] = obj->data[key2];
  obj->data[key2] = tmp;
  return;
}

void pq_repair_bottom(struct pq *obj) {
  int child = obj->size - 1, parent = (child - 1) / 2;
  while (child > 0 && obj->cmp(obj->data[child], obj->data[parent]) == 1) {
    pq_swap(obj, child, parent);
    child = parent;
    parent = (child - 1) / 2;
  }
  return;
}

void pq_push(struct pq *obj, void *item) {
  assert(obj->size < obj->capacity);
  obj->data[obj->size++] = item;
  pq_repair_bottom(obj);
  return;
}

void pq_repair_top(struct pq *obj) {
  int parent = 0, child = parent * 2 + 1;
  while (child < obj->size) {
    if (child + 1 < obj->size &&
        obj->cmp(obj->data[child + 1], obj->data[child]) == 1)
      child++;
    if (obj->cmp(obj->data[parent], obj->data[child]) == 1)
      break;
    pq_swap(obj, parent, child);
    parent = child;
    child = parent * 2 + 1;
  }
  return;
}

void *pq_pop(struct pq *obj) {
  assert(obj->size > 0);
  pq_swap(obj, 0, obj->size - 1);
  obj->size--;
  pq_repair_top(obj);
  return obj->data[obj->size];
}

void pq_free(struct pq *obj) {
  for (int i = 0; i < obj->size; i++)
    free(obj->data[i]);
  free(obj->data);
  free(obj);
  return;
}

char *clearStars(char *s) {
  const int n = strlen(s);
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  struct pq *pq = pq_init(n, cmp);
  for (int i = 0; i < n; i++) {
    if (s[i] != '*') {
      struct node *n = node_init(*(s + i), i);
      pq_push(pq, n);
    } else if (pq->size > 0) {
      struct node *curr = pq_pop(pq);
      s[curr->idx] = '#';
    }
  }
  pq_free(pq);
  int idx = 0;
  for (; *s; s++)
    if (*s != '#' && *s != '*')
      ans[idx++] = *s;
  ans[idx] = '\0';
  return ans;
}

int main() {
  char *s1 = "aaba*", *cs1 = clearStars(s1);
  char *s2 = "abc", *cs2 = clearStars(s2);
  printf("%s\n", cs1); // expect: aab
  printf("%s\n", cs2); // expect: abc
}
