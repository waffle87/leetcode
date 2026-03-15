// 1622. Fancy Sequence
#include "leetcode.h"

/*
 * write an api that generates fancy sequences using the 'append', 'addAll', and
 * 'multAll' operations.
 */

static int mod = 1e9 + 7;

enum operations { op_mult, op_add };

struct list {
  struct list *next;
  int data[4];
};

struct list_op {
  struct list_op *next;
  enum operations op[4];
  long val[4];
  uint16_t qty_curr[4];
};

typedef struct {
  int qty_elem;
  int qty_op_elem;
  struct list *first;
  struct list *last;
  struct list_op *list_op_first;
  struct list_op *list_op_last;
  int last_req_val;
  int last_req_idx;
  int last_req_valid;
  int last_req_num;
} Fancy;

Fancy *fancyCreate() {
  Fancy *obj = (Fancy *)calloc(1, sizeof(Fancy));
  return obj;
}

void fancyAppend(Fancy *obj, int val) {
  int tmp = obj->qty_elem % 4;
  obj->qty_elem++;
  if (!obj->last) {
    obj->last = (struct list *)calloc(1, sizeof(struct list));
    obj->first = obj->last;
    obj->last->data[0] = val;
    return;
  }
  if (!tmp) {
    obj->last->next = (struct list *)calloc(1, sizeof(struct list));
    obj->last = obj->last->next;
  }
  obj->last->data[tmp] = val;
}

void fancy_all(Fancy *obj, int val, enum operations op) {
  int tmp = obj->qty_op_elem % 4;
  int tmp_prev = (obj->qty_op_elem - 1) % 4;
  obj->last_req_val++;
  if (!obj->list_op_last) {
    obj->list_op_last = (struct list_op *)calloc(1, sizeof(struct list_op));
    obj->list_op_first = obj->list_op_last;
  } else {
    if (op == obj->list_op_last->op[tmp_prev] &&
        obj->qty_elem == obj->list_op_last->qty_curr[tmp_prev]) {
      if (op == op_add)
        obj->list_op_last->val[tmp_prev] += val;
      else
        obj->list_op_last->val[tmp_prev] *= val;
      if (obj->list_op_last->val[tmp_prev] >= mod)
        obj->list_op_last->val[tmp_prev] %= mod;
      return;
    }
    if (!tmp) {
      obj->list_op_last->next =
          (struct list_op *)calloc(1, sizeof(struct list_op));
      obj->list_op_last = obj->list_op_last->next;
    }
  }
  obj->list_op_last->val[tmp] = val;
  obj->list_op_last->op[tmp] = op;
  obj->list_op_last->qty_curr[tmp] = obj->qty_elem;
  obj->qty_op_elem++;
}

void fancyAddAll(Fancy *obj, int inc) { fancy_all(obj, inc, op_add); }

void fancyMultAll(Fancy *obj, int m) { fancy_all(obj, m, op_mult); }

int fancyGetIndex(Fancy *obj, int idx) {
  struct list *list_p = obj->first;
  struct list_op *list_op_p = obj->list_op_first;
  long tmp;
  int idx_loc = idx / 4;
  if (obj->qty_elem <= idx)
    return -1;
  if (obj->last_req_idx == idx && obj->last_req_valid == obj->last_req_num &&
      obj->qty_op_elem != 0)
    return obj->last_req_val;
  while (idx_loc-- > 0)
    list_p = list_p->next;
  tmp = list_p->data[idx % 4];
  while (list_op_p) {
    for (int i = 0; i < 4; i++) {
      if (list_op_p->qty_curr[i] <= idx)
        continue;
      if (list_op_p->op[i] == op_add)
        tmp += list_op_p->val[i];
      else
        tmp *= list_op_p->val[i];
      if (tmp >= mod)
        tmp %= mod;
    }
    list_op_p = list_op_p->next;
  }
  obj->last_req_val = tmp;
  obj->last_req_idx = idx;
  obj->last_req_valid = obj->last_req_num;
  return (int)tmp;
}

void fancyFree(Fancy *obj) {
  struct list *list_p1 = obj->first, *list_p2;
  struct list_op *list_op_p1 = obj->list_op_first, *list_op_p2;
  while (list_p1) {
    list_p2 = list_p1->next;
    free(list_p1);
    list_p1 = list_p2;
  }
  while (list_op_p1) {
    list_op_p2 = list_op_p1->next;
    free(list_op_p1);
    list_op_p1 = list_op_p2;
  }
  free(obj);
}

int main() {
  Fancy *obj = fancyCreate();
  fancyAppend(obj, 2);
  fancyAddAll(obj, 3);
  fancyAppend(obj, 7);
  fancyMultAll(obj, 2);
  int r1 = fancyGetIndex(obj, 0);
  printf("%d\n", r1);
  assert(r1 == 10);
  fancyAddAll(obj, 3);
  fancyAppend(obj, 10);
  fancyMultAll(obj, 2);
  int r2 = fancyGetIndex(obj, 0);
  printf("%d\n", r2);
  assert(r2 == 26);
  int r3 = fancyGetIndex(obj, 1);
  printf("%d\n", r3);
  assert(r3 == 34);
  int r4 = fancyGetIndex(obj, 2);
  printf("%d\n", r4);
  assert(r4 == 20);
  fancyFree(obj);
}
