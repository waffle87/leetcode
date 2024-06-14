// 900. RLE Iterator
#include "leetcode.h"

/*
 * we can use run length encoding to encode a sequence of integers. in a run
 * length encoded array of even length encoding, for all even 'i', 'encoding[i]'
 * tells us the number of times that the non negative integer value 'encoding[i
 * + 1]' is repeated in the sequence. given that a run length encoded array,
 * design an iterator that iterates through it.
 */

typedef struct {
  int *val;
  int *cnt;
  int size;
  int curr;
} RLEIterator;

RLEIterator *rLEIteratorCreate(int *encoding, int encodingSize) {
  int size = encodingSize / 2, idx = 0;
  int *val = (int *)malloc(size * sizeof(int));
  int *cnt = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    if (!encoding[2 * i])
      continue;
    val[idx] = encoding[2 * i + 1];
    cnt[idx] = encoding[2 * i];
    idx++;
  }
  val = realloc(val, idx * sizeof(int));
  cnt = realloc(cnt, idx * sizeof(int));
  RLEIterator *res = malloc(sizeof(RLEIterator));
  res->val = val;
  res->cnt = cnt;
  res->size = idx;
  res->curr = 0;
  return res;
}

int rLEIteratorNext(RLEIterator *obj, int n) {
  if (obj->curr >= obj->size)
    return -1;
  int res = -1, items = n, p = obj->curr, *cnt = obj->cnt;
  while (items && p < obj->size) {
    if (cnt[p] > items) {
      cnt[p] -= items;
      items = 0;
      res = obj->val[p];
    } else {
      items -= cnt[p];
      if (!items)
        res = obj->val[p];
      cnt[p] = 0;
      p++;
    }
  }
  obj->curr = p;
  return res;
}

void rLEIteratorFree(RLEIterator *obj) {
  free(obj->val);
  free(obj->cnt);
  free(obj);
}

int main() {
  int e1[] = {3, 8, 0, 9, 2, 5};
  RLEIterator *obj = rLEIteratorCreate(e1, ARRAY_SIZE(e1));
  printf("%d\n", rLEIteratorNext(obj, 2)); // expect: 8
  printf("%d\n", rLEIteratorNext(obj, 1)); // expect: 8
  printf("%d\n", rLEIteratorNext(obj, 1)); // expect: 5
  printf("%d\n", rLEIteratorNext(obj, 2)); // expect: -1
}
