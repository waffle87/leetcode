// 898. Bitwise ORs of Subarrays
#include "leetcode.h"

/*
 * given an integer array 'arr', return the number of distinct bitwise or's of
 * all the non-empty subarrays of 'arr'. the bitwise or of a subarray is the
 * bitwise or of each interger in the subarray. the bitwise or of a subarray of
 * one integer is that integer. a subarray is a contiguous non-empty sequence of
 * elements within an array.
 */

struct node {
  int value;
  struct node *next;
};

struct hashset {
  struct node **buckets;
  int size;
  int capacity;
};

struct hashset *hashset_create(int capacity) {
  struct hashset *obj = (struct hashset *)malloc(sizeof(struct hashset));
  obj->buckets = (struct node **)calloc(capacity, sizeof(struct node *));
  obj->size = 0;
  obj->capacity = capacity;
  return obj;
}

bool contains(struct hashset *set, int value) {
  uint hash = (uint)value % set->capacity;
  struct node *curr = set->buckets[hash];
  while (curr) {
    if (curr->value == value)
      return true;
    curr = curr->next;
  }
  return false;
}

void insert(struct hashset *set, int value) {
  if (contains(set, value))
    return;
  uint hash = (uint)value % set->capacity;
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->value = value;
  new->next = set->buckets[hash];
  set->buckets[hash] = new;
  set->size++;
}

void hashset_free(struct hashset *obj) {
  for (int i = 0; i < obj->capacity; i++) {
    struct node *curr = obj->buckets[i];
    while (curr) {
      struct node *tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(obj->buckets);
  free(obj);
}

int subarrayBitwiseORs(int *arr, int arrSize) {
  struct hashset *set = hashset_create(1024);
  for (int i = 0; i < arrSize; i++) {
    int j = i - 1, x = 0, y = arr[i];
    insert(set, y);
    while (j >= 0 && x != y) {
      x |= arr[j];
      y |= arr[j];
      insert(set, y);
      j--;
    }
  }
  int ans = set->size;
  hashset_free(set);
  return ans;
}

int main() {
  int a1[] = {0}, a2[] = {1, 1, 2}, a3[] = {1, 2, 4};
  printf("%d\n", subarrayBitwiseORs(a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", subarrayBitwiseORs(a2, ARRAY_SIZE(a2))); // expect: 3
  printf("%d\n", subarrayBitwiseORs(a3, ARRAY_SIZE(a3))); // expect: 6
}
