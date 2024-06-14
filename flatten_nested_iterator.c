// 341. Flatten Nested List Iterator
#include <stdbool.h>
#include <stdlib.h>

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a
 * nested list. bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested
 * list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a
 * nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

bool NestedIntegerIsInteger(struct NestedInteger *);
int NestedIntegerGetInteger(struct NestedInteger *);
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
int NestedIntegerGetListSize(struct NestedInteger *);

struct NestedIterator {
  int *list;
  int cur;
  int n;
};

void process(int *list, int *idx, struct NestedInteger *nestedList) {
  if (NestedIntegerIsInteger(nestedList)) {
    list[*idx] = NestedIntegerGetInteger(nestedList);
    *idx = *idx + 1;
    return;
  }
  struct NestedInteger **newNestedList = NestedIntegerGetList(nestedList);
  int newnestedListSize = NestedIntegerGetListSize(nestedList);
  for (int i = 0; i < newnestedListSize; i++) {
    process(list, idx, newNestedList[i]);
  }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList,
                                        int nestedListSize) {
  struct NestedIterator *ret =
      (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
  ret->list = malloc(50000 * sizeof(int));
  int id = 0;
  for (int i = 0; i < nestedListSize; i++) {
    process(ret->list, &id, nestedList[i]);
  }
  ret->list = realloc(ret->list, id * sizeof(int));
  ret->cur = 0;
  ret->n = id;
  return ret;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
  return ((iter->cur) < (iter->n));
}

int nestedIterNext(struct NestedIterator *iter) {
  return (iter->list[iter->cur++]);
}

void nestedIterFree(struct NestedIterator *iter) {
  free(iter->list);
  free(iter);
}
