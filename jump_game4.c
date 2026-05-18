// 1345. Jump Game IV
#include "leetcode.h"

/*
 * given array of integers 'arr', you are initially positioned at first index of
 * array. in one step, you can jump from index 'i' to index 'j'. return minimum
 * number of steps to reach lat index of array. notice, you cannot jump outside
 * of array at any time.
 */

struct node {
  int key;
  struct ListNode *ptr;
  UT_hash_handle hh;
};

struct status {
  int pos;
  int step;
};

int minJumps(int *arr, int arrSize) {
  if (arrSize <= 1)
    return 0;
  struct status *obj = (struct status *)malloc(arrSize * sizeof(struct status));
  bool *vis = (bool *)calloc(arrSize, sizeof(int));
  struct node *hash = NULL, *s;
  struct ListNode *tp;
  for (int i = 0; i < arrSize; i++) {
    HASH_FIND_INT(hash, &arr[i], s);
    if (!s) {
      s = (struct node *)calloc(1, sizeof(struct node));
      s->key = arr[i];
      HASH_ADD_INT(hash, key, s);
    }
    tp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    tp->val = i;
    tp->next = s->ptr;
    s->ptr = tp;
  }
  int top = 1, left = 0, pos, val;
  obj[0].step = obj[0].pos = 0;
  vis[0] = true;
  while (left < top) {
    if (obj[left].pos == arrSize - 1)
      break;
    val = arr[obj[left].pos];
    HASH_FIND_INT(hash, &val, s);
    if (s) {
      tp = s->ptr;
      while (tp) {
        pos = tp->val;
        if (!vis[pos]) {
          vis[pos] = true;
          obj[top].step = obj[left].step + 1;
          obj[top].pos = pos;
          top++;
        }
        tp = tp->next;
      }
      HASH_DEL(hash, s);
    }
    for (int i = 0; i < 2; i++) {
      pos = obj[left].pos + (i ? 1 : -1);
      if (pos < 0 || pos >= arrSize)
        continue;
      if (vis[pos])
        continue;
      obj[top].step = obj[left].step + 1;
      obj[top].pos = pos;
      vis[pos] = true;
      top++;
    }
    left++;
  }
  int ans = obj[left].step;
  free(tp);
  free(vis);
  free(obj);
  return ans;
}

int main() {
  int a1[] = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  int a2[] = {7};
  int a3[] = {7, 6, 9, 6, 9, 6, 9, 7};
  int r1 = minJumps(a1, ARRAY_SIZE(a1));
  int r2 = minJumps(a2, ARRAY_SIZE(a2));
  int r3 = minJumps(a3, ARRAY_SIZE(a3));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 1);
}
