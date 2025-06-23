// 528. Random Pick with Weight
#include "leetcode.h"

/*
 * you are given a 0-indexed array of positive integers 'w' where 'w[i]'
 * describes the weight of the i'th index. you need to implement the function
 * 'pickIndex()' which randomly picks an index in the range '[0, w.len - 1]' and
 * returns it. the probability of picking an index 'i' is 'w[i] / sum(w)'.
 */

typedef struct {
  int size;
  int *data;
} Solution;

Solution *solutionCreate(int *w, int wSize) {
  Solution *obj = (Solution *)malloc(sizeof(Solution));
  obj->data = (int *)malloc(wSize * sizeof(int));
  obj->size = wSize;
  obj->data[0] = w[0];
  for (int i = 0; i < wSize; i++)
    obj->data[i] = w[i] + obj->data[i - 1];
  return obj;
}

int solutionPickIndex(Solution *obj) {
  float rand_num = (float)rand() / RAND_MAX;
  int target = rand_num * obj->data[obj->size - 1];
  int left = 0, right = obj->size - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (obj->data[mid] > target)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

void solutionFree(Solution *obj) {
  free(obj->data);
  free(obj);
}

int main() {
  int w1[] = {1}, w2[] = {1, 3};
  Solution *obj1 = solutionCreate(w1, ARRAY_SIZE(w1));
  Solution *obj2 = solutionCreate(w2, ARRAY_SIZE(w2));
  printf("%d\n", solutionPickIndex(obj1)); // expect: 0
  printf("%d\n", solutionPickIndex(obj2)); // expect: 1
  printf("%d\n", solutionPickIndex(obj2)); // expect: 1
  printf("%d\n", solutionPickIndex(obj2)); // expect: 1
  printf("%d\n", solutionPickIndex(obj2)); // expect: 1
  printf("%d\n", solutionPickIndex(obj2)); // expect: 0
  solutionFree(obj1);
  solutionFree(obj2);
}
