// 1792. Maximum Average Pass Ratio
#include "leetcode.h"

/*
 * there is a school that has classes of students and each class will be having
 * a final exam. you are given a 2d integer array 'classes' where 'classes[i] =
 * [pass_i, total_i]'. you know beforehand that in the i'th there are 'total_i'
 * students, but only 'pass_i' students that will pass the exam. you are also
 * given in integer 'extraStudents'. there are another 'extraStudents' brilliant
 * students that are guaranteed to pass the exam of any class. return the
 * maximum possible average pass ratio after assigning the 'extraStudents'
 * students. answers within 10^-5 of the actual answer will be accepted.
 */

struct data {
  double gain_rate;
  int pass;
  int total;
};

struct heap {
  struct data *pq;
  int size;
  int capacity;
};

struct heap *heap_init(int n) {
  struct heap *obj = (struct heap *)malloc(sizeof(struct heap));
  obj->capacity = n;
  obj->size = 0;
  obj->pq = (struct data *)malloc(n * sizeof(struct data));
  return obj;
}

void swap(struct data *a, struct data *b) {
  struct data tmp = *a;
  *a = *b;
  *b = tmp;
}

void heap_up(struct heap *obj, int i) {
  while (i > 0) {
    int parent = ((i - 1) >> 1);
    if (obj->pq[i].gain_rate > obj->pq[parent].gain_rate) {
      swap(&(obj->pq[i]), &(obj->pq[parent]));
      i = parent;
      continue;
    }
    break;
  }
}

void heap_down(struct heap *obj, int i) {
  int largest = i, size = obj->size;
  int left = ((i << 1) + 1), right = ((i << 1) + 2);
  if (left < size && obj->pq[largest].gain_rate < obj->pq[left].gain_rate)
    largest = left;
  if (right < size && obj->pq[largest].gain_rate < obj->pq[right].gain_rate)
    largest = right;
  if (largest != i) {
    swap(&(obj->pq[i]), &(obj->pq[largest]));
    heap_down(obj, largest);
  }
}

void heap_push(struct heap *obj, struct data new) {
  if (obj->size == obj->capacity) {
    obj->capacity <<= 1;
    obj->pq =
        (struct data *)realloc(obj->pq, obj->capacity * sizeof(struct data));
  }
  obj->pq[obj->size] = new;
  heap_up(obj, obj->size);
  ++obj->size;
}

struct data heap_pop(struct heap *obj) {
  struct data top = obj->pq[0];
  obj->pq[0] = obj->pq[--(obj->size)];
  heap_down(obj, 0);
  return top;
}

void heap_free(struct heap *obj) {
  free(obj->pq);
  free(obj);
}

static inline double gain(int pass, int total) {
  return (double)(pass + 1) / (total + 1) - (double)pass / total;
}

double maxAverageRatio(int **classes, int classesSize, int *classesColSize,
                       int extraStudents) {
  double ans = 0.0;
  struct heap *obj = heap_init(classesSize);
  for (int i = 0; i < classesSize; ++i) {
    int pass = classes[i][0], total = classes[i][1];
    ans += (double)pass / total;
    struct data item = {gain(pass, total), pass, total};
    heap_push(obj, item);
  }
  for (int i = 0; i < extraStudents; ++i) {
    struct data top = heap_pop(obj);
    int pass = top.pass, total = top.total;
    ans -= (double)pass / total;
    ++pass;
    ++total;
    ans += (double)pass / total;
    struct data item = {gain(pass, total), pass, total};
    heap_push(obj, item);
  }
  heap_free(obj);
  return ans;
}

int main() {
  int c1i[3][2] = {{1, 2}, {3, 5}, {2, 2}},
      c2i[4][2] = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *c2 =
      two_d_arr_init(ARRAY_SIZE(c2i), ARRAY_SIZE(c2i[0]), c2i);
  printf("%f\n", maxAverageRatio(c1->arr, c1->row_size, c1->col_size,
                                 2)); // expect: 0.78333
  printf("%f\n", maxAverageRatio(c2->arr, c2->row_size, c2->col_size,
                                 4)); // expect: 0.53485
  two_d_arr_free(c1);
  two_d_arr_free(c2);
}
