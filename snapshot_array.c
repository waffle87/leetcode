// 1146. Snapshot Array
#include <stdio.h>
#include <stdlib.h>

/*
 * implement a 'SnapshotArray' class that supports the following interface
 * - 'SnapshotArray(int length)' initialises an array-like data structure with
 * the given length. initially, each element equals zero.
 * - 'void set(index, val)' sets the element at the given 'index' to be equal to
 * 'val'
 * - 'int snap()' takes a snapshot of the array and retusn the 'snap_id': the
 * total number of times we called 'snap()' minus 1
 * - 'int get(index, snap_id)' returns the value at the given 'index', at the
 * time we took the snapshot with the given 'snap_id'
 */

#define SIZE 50000

struct v {
  int v;
  int i;
  struct v *n;
};

typedef struct {
  struct v *vl[SIZE];
  int i;
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length) {
  return calloc(1, sizeof(SnapshotArray));
}

void snapshotArraySet(SnapshotArray *obj, int index, int val) {
  SnapshotArray *s = obj;
  struct v *v = s->vl[s->i], *p = NULL;
  for (; v && index > v->i; p = v, v = v->n)
    ;
  if (v && index == v->i)
    v->v = val;
  else {
    struct v *n = calloc(1, sizeof(*n));
    n->v = val;
    n->i = index;
    n->n = v;
    p ? p->n = n : (s->vl[s->i] = n);
  }
}

int snapshotArraySnap(SnapshotArray *obj) {
  SnapshotArray *s = obj;
  struct v *h = s->vl[s->i++];
  for (struct v **p = &s->vl[s->i]; h; h = h->n) {
    (*p = calloc(1, sizeof(**p)))->v = h->v;
    (*p)->i = h->i;
    p = &(*p)->n;
  }
  return s->i - 1;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id) {
  SnapshotArray *s = obj;
  struct v *h;
  for (h = s->vl[snap_id]; h && h->i < index; h = h->n)
    ;
  return h && h->i == index ? h->v : 0;
}

void snapshotArrayFree(SnapshotArray *obj) { free(obj); }

int main() {
  SnapshotArray *obj = snapshotArrayCreate(3);
  snapshotArraySet(obj, 0, 5);
  printf("%d\n", snapshotArraySnap(obj)); // expect: 0
  snapshotArraySet(obj, 0, 6);
  printf("%d\n", snapshotArrayGet(obj, 0, 0)); // expect: 5
}
