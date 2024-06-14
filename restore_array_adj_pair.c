// 1743. Restore the Array From Adjacent Pairs
#include "leetcode.h"

/*
 * there is an integer array 'nums' that contains 'n' unique elements, but you
 * have forgotten it. however, you do remember that every pair of adjacent
 * elements in 'nums'. you are given a 2d integer array 'adjacent_pairs' of size
 * 'n - 1' where each adjacent_pairs[i] = [ui, vi] indicates that the elements
 * 'ui' and 'vi' are adjacent in 'nums'. it is guaranteed that every adjacent
 * pair of elements 'nums[i]' and 'nums[i + 1]' will exist in 'adjacent_pairs'
 * either as '[nums[i], nums[i + 1]]'. the pairs can appear in any order. return
 * the original array 'nums'. if there are multiple solutions, return any of
 * them.
 */

typedef struct {
  int key;
  int size;
  int *data;
} edge;

int findFirst(int **adjacent_pairs, int adjacent_pairs_size, edge **hash, int n,
              int *neighbor) {
  int val, d;
  for (int i = 0; i < adjacent_pairs_size; i++) {
    val = adjacent_pairs[i][0];
    d = abs(val);
    while (1) {
      if (hash[d % n]->key == val)
        if (hash[d % n]->size == 1) {
          *neighbor = hash[d % n]->data[0];
          return val;
        } else
          break;
      else
        d++;
    }
    val = adjacent_pairs[i][1];
    d = abs(val);
    while (1) {
      if (hash[d % n]->key == val)
        if (hash[d % n]->size == 1) {
          *neighbor = hash[d % n]->data[0];
          return val;
        } else
          break;
      else
        d++;
    }
  }
  return INT_MAX;
}

void findnext(int **adjacent_pairs, int adjacent_pairs_size, edge **hash, int n,
              int ptr, int *one, int *two) {
  int d = abs(ptr);
  while (1) {
    if (hash[d % n]->key == ptr) {
      *one = hash[d % n]->data[0];
      *two = hash[d % n]->data[1];
      return;
    } else
      d++;
  }
}

int *restoreArray(int **adjacent_pairs, int adjacent_pairs_size,
                  int *adjacent_pairsColSize, int *returnSize) {
  int n = adjacent_pairs_size + 1;
  int n = 10 * n;
  edge **hash = calloc(n, sizeof(edge *));
  for (int i = 0; i < adjacent_pairs_size; i++) {
    int a = adjacent_pairs[i][0];
    int b = adjacent_pairs[i][1];
    int val = a;
    int d = abs(val);

    while (1) {
      if (!hash[d % n]) {
        hash[d % n] = malloc(sizeof(edge));
        hash[d % n]->data = malloc(2 * sizeof(int));
        hash[d % n]->key = val;
        hash[d % n]->size = 1;
        hash[d % n]->data[0] = b;
        break;
      } else if (hash[d % n]->key == val) {
        hash[d % n]->size = 2;
        hash[d % n]->data[1] = b;
        break;
      } else
        d++;
    }

    val = b;
    d = abs(val);
    while (1) {
      if (!hash[d % n]) {
        hash[d % n] = malloc(sizeof(edge));
        hash[d % n]->data = malloc(2 * sizeof(int));
        hash[d % n]->key = val;
        hash[d % n]->size = 1;
        hash[d % n]->data[0] = a;
        break;
      } else if (hash[d % n]->key == val) {
        hash[d % n]->size = 2;
        hash[d % n]->data[1] = a;
        break;
      } else
        d++;
    }
  }

  int neighbor;
  int first =
      findFirst(adjacent_pairs, adjacent_pairs_size, hash, n, &neighbor);

  int *ans = malloc(n * sizeof(int));
  *returnSize = n;
  ans[0] = first;
  ans[1] = neighbor;
  int ptr = neighbor;
  int a, b;
  for (int i = 2; i < n; i++) {
    findnext(adjacent_pairs, adjacent_pairs_size, hash, n, ptr, &a, &b);
    if (ans[i - 2] == a)
      ans[i] = b;
    else
      ans[i] = a;
    ptr = ans[i];
  }

  for (int i = 0; i < n; i++)
    if (hash[i]) {
      free(hash[i]->data);
      free(hash[i]);
    }
  free(hash);
  return ans;
}
