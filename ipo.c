// 502. IPO
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * suppose leetcode will start its ipo soon. in order to sell a good price of
 * its shares to venture capital, leetcode woule like to work on some projects
 * to increase its capital before the ipo. since it has limited resources, it
 * can only finish at most k distinct projects before the ipo. maximise capital
 * after finishing at most 'k' distinct projects. given 'n' projects where the
 * i'th project has a pure profit 'profits[i]' and min capital of 'capital[i]'
 * is needed to start it.
 */

typedef struct heap_s {
  int capacity;
  int size;
  int **arr;
} heap_t;

heap_t *init(int);
void insert(heap_t *, int, int);
int *top(heap_t *);
void pop(heap_t *);
bool empty(heap_t *);

int undo_cmp(void **a, void **b) { return (*(int **)a)[1] - (*(int **)b)[1]; }

int findMaximizedCapital(int k, int w, int *profits, int profitsSize,
                         int *capital, int capitalSize) {
  heap_t *doable = init(profitsSize);
  int **undoable = NULL;
  int i, undoableSize = 0;
  for (int i = 0; i < profitsSize; i++) {
    if (profits[i] <= 0)
      continue;
    if (capital[i] <= w)
      insert(doable, profits[i], capital[i]);
    else {
      undoable = (int **)realloc(undoable, sizeof(int *) * (++undoableSize));
      int *item = (int *)malloc(sizeof(int) * 2);
      item[0] = profits[i];
      item[1] = capital[i];
      undoable[undoableSize - 1] = item;
    }
  }
  qsort(undoable, undoableSize, sizeof(int *), undo_cmp);
  i = 0;
  while (!empty(doable) && k--) {
    w += top(doable)[0];
    pop(doable);
    while (i < undoableSize) {
      if (w >= undoable[i][1]) {
        insert(doable, undoable[i][0], undoable[i][1]);
        i++;
      } else
        break;
    }
  }
  return w;
}

heap_t *init(int max) {
  heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
  heap->capacity = max;
  heap->size = 0;
  heap->arr = (int **)malloc(sizeof(int *) * (max + 1));
  return heap;
}

bool empty(heap_t *heap) { return heap->size == 0; }

int *top(heap_t *heap) { return heap->arr[1]; }

bool cmp(int *a, int *b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; }

void swap(int **a, int i, int j) {
  int *tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void insert(heap_t *heap, int val, int len) {
  int *node = (int *)malloc(sizeof(int) * 2);
  node[0] = val;
  node[1] = len;
  heap->arr[++heap->size] = node;
  for (int i = heap->size; i > 1 && cmp(heap->arr[i], heap->arr[i / 2]); i /= 2)
    swap(heap->arr, i, i / 2);
}

void pop(heap_t *heap) {
  heap->arr[1] = heap->arr[heap->size--];
  for (int i = 1; i * 2 <= heap->size;) {
    int child = cmp(heap->arr[i * 2], heap->arr[i * 2 + 1]) ? i * 2 : i * 2 + 1;
    if (cmp(heap->arr[child], heap->arr[i])) {
      swap(heap->arr, child, i);
      i = child;
    } else
      break;
  }
}

int main() {
  int profits[] = {1, 2, 3}, c1[] = {0, 1, 1}, c2[] = {0, 1, 2};
  printf("%d\n", findMaximizedCapital(2, 0, profits, 3, c1, 3)); // expect: 4
  printf("%d\n", findMaximizedCapital(3, 0, profits, 3, c2, 3)); // expect: 6
}
