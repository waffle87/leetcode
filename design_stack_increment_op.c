// 1381. Design a Stack With Increment Operation
#include "leetcode.h"

/*
 * design a stack that supports increment operations on its elements. implement
 * the function increment that increments the bottom 'k' elements of the stack
 * by 'val' if there are less than 'k' elements in the stack, increment all the
 * elements in the stack
 */

typedef struct {
  int *data;
  int idx;
  int size;
} CustomStack;

CustomStack *customStackCreate(int maxSize) {
  CustomStack *obj = malloc(sizeof(CustomStack));
  obj->data = (int *)calloc(maxSize, sizeof(int));
  obj->size = maxSize;
  obj->idx = 0;
  return obj;
}

void customStackPush(CustomStack *obj, int x) {
  if (obj->idx == obj->size)
    return;
  obj->data[obj->idx] = x;
  obj->idx++;
}

int customStackPop(CustomStack *obj) {
  if (!(obj->idx))
    return -1;
  obj->idx--;
  return obj->data[obj->idx];
}

void customStackIncrement(CustomStack *obj, int k, int val) {
  int min = k < obj->idx ? k : obj->idx;
  for (int i = 0; i < min; i++)
    obj->data[i] += val;
}

void customStackFree(CustomStack *obj) {
  free(obj->data);
  free(obj);
}

int main() {
  CustomStack *obj = customStackCreate(3);
  customStackPush(obj, 1);
  customStackPush(obj, 2);
  printf("%d\n", customStackPop(obj)); // expect: 2
  customStackPush(obj, 2);
  customStackPush(obj, 3);
  customStackPush(obj, 4);
  customStackIncrement(obj, 5, 100);
  printf("%d\n", customStackPop(obj)); // expect: 103
  printf("%d\n", customStackPop(obj)); // expect: 202
  printf("%d\n", customStackPop(obj)); // expect: 201
  printf("%d\n", customStackPop(obj)); // expect: -1
  customStackFree(obj);
}
