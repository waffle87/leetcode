#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  int val;
  struct node *next;
};

struct table {
  int size;
  struct node **list;
};

struct table *createTable(int size) {
  struct table *t = (struct table *)malloc(sizeof(struct table));
  t->size = size;
  t->list = (struct node **)malloc(sizeof(struct node *) * size);
  for (int i = 0; i < size; i++)
    t->list[i] = NULL;
  return t;
}

int hashCode(struct table *t, int key) {
  if (key < 0)
    return -(key % t->size);
  return key % t->size;
}

void insert(struct table *t, int key, int val) {
  int pos = hashCode(t, key);
  struct node *list = t->list[pos];
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->key = key;
  newNode->val = val;
  newNode->next = list;
  t->list[pos] = newNode;
}

int lut(struct table *t, int key) {
  int pos = hashCode(t, key);
  struct node *list = t->list[pos];
  struct node *tmp = list;
  while (tmp) {
    if (tmp->key == key)
      return tmp->val;
    tmp = tmp->next;
  }
  return INT_MAX;
}

bool checkSubarraySum(int *nums, int numsSize, int k) {
  struct table *t = createTable(10);
  int sum = 0;
  insert(t, 0, -1);
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    if (k)
      sum %= k;
    if (lut(t, sum) != INT_MAX) {
      if (i - lut(t, sum) > 1)
        return true;
    } else
      insert(t, sum, i);
  }
  return false;
}

int main() {
  int nums1[] = {23, 2, 4, 6, 7}, nums2[] = {23, 2, 6, 4, 7};
  printf("%d\n", checkSubarraySum(nums1, 5, 6));  // expect: 1
  printf("%d\n", checkSubarraySum(nums2, 5, 6));  // expect: 1
  printf("%d\n", checkSubarraySum(nums2, 5, 13)); // expect: 0
}
