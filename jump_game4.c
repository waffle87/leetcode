// 1345. Jump Game IV
#include "lib/uthash/src/uthash.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given array of integers 'arr', you are initially positioned at first index of
 * array. in one step, you can jump from index 'i' to index 'j'. return minimum
 * number of steps to reach lat index of array. notice, you cannot jump outside
 * of array at any time.
 */

typedef struct {
  int key;
  struct list_node *ptr;
  UT_hash_handle hh;
} node;

typedef struct {
  int val;
  int *next;
} list_node;

typedef struct {
  int pos;
  int step;
} status;

int minJumps(int *arr, int arr_size) {
  if (arr_size <= 1)
    return 1;
  status obj[arr_size];
  int visited[arr_size];
  memset(visited, 0, arr_size * sizeof(int));
  node *hash = NULL, *s;
  struct list_node *tp;
  for (int i = 0; i < arr_size; i++) {
    HASH_FIND_INT(hash, &arr[i], s);
    if (!s) {
      s = (node *)calloc(1, sizeof(node));
      s->key = arr[i];
      HASH_ADD_INT(hash, key, s);
    }
    tp = (struct list_node *)calloc(1, sizeof(struct list_node));
    tp->val = i;
    tp->next = s->ptr;
    s->ptr = tp;
  }
  int top = 1, left = 0, pos, val;
  obj[0].step = obj[0].pos = 0;
  visited[0] = 1;
  while (left < top) {
    if (obj[left].pos == arr_size - 1)
      break;
    val = arr[obj[left].pos];
    HASH_FIND_INT(hash, &val, s);
    if (s) {
      tp = s->ptr;
      while (tp) {
        pos = tp->val;
        if (!visited[pos]) {
          visited[pos] = 1;
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
      if (pos < 0 || pos >= arr_size)
        continue;
      if (visited[pos])
        continue;
      obj[top].step = obj[left].step + 1;
      obj[top].pos = pos;
      visited[pos] = 1;
      top++;
    }
    left++;
  }
  free(tp);
  return obj[left].step;
}

int main() {
  int a1[] = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  int a2[] = {7};
  int a3[] = {7, 6, 9, 6, 9, 6, 9, 7};
  printf("%d\n", minJumps(a1, sizeof(a1) / sizeof(a1[0]))); // expect: 3
  printf("%d\n", minJumps(a2, sizeof(a2) / sizeof(a2[0]))); // expect: 0
  printf("%d\n", minJumps(a3, sizeof(a3) / sizeof(a3[0]))); // expect: 1
}
