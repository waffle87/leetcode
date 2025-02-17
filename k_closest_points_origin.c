// 973. K Closest Points to Origin
#include "leetcode.h"

/*
 * given an array of 'points' where 'points[i] = [x_i, y_i]' represents a point
 * on the x-y plane and an integer 'k', return the 'k' closest points to the
 * origin '(0, 0)'. the distance between two points on the x-y plane is the
 * euclidean distance (ie. 'sqrt((x1 - x2)^2 + (y1 - y2)^2))'.  you may return
 * the answer in any order. the answer is guaranteed to be unique (except for
 * the order that it is in).
 */

struct node {
  int x;
  int y;
  int dist;
};

void swap(struct node *a, struct node *b) {
  struct node tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(struct node *heap, int size, int i) {
  int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  if (left < size && heap[left].dist > heap[largest].dist)
    largest = left;
  if (right < size && heap[right].dist > heap[largest].dist)
    largest = right;
  if (largest != i) {
    swap(&heap[i], &heap[largest]);
    heapify(heap, size, largest);
  }
}

void heap_push(struct node *heap, int *size, struct node n) {
  heap[*size] = n;
  int i = *size;
  (*size)++;
  while (i && heap[(i - 1) / 2].dist < heap[i].dist) {
    swap(&heap[i], &heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

struct node get_max(struct node *heap, int *size) {
  struct node max = heap[0];
  heap[0] = heap[*size - 1];
  (*size)--;
  heapify(heap, *size, 0);
  return max;
}

int **kClosest(int **points, int pointsSize, int *pointsColSize, int k,
               int *returnSize, int **returnColumnSizes) {
  struct node *max_heap = (struct node *)malloc(k * sizeof(struct node));
  int heap_size = 0;
  for (int i = 0; i < k; i++) {
    struct node n;
    n.x = points[i][0];
    n.y = points[i][1];
    n.dist = n.x * n.x + n.y * n.y;
    heap_push(max_heap, &heap_size, n);
  }
  for (int i = k; i < pointsSize; i++) {
    struct node n;
    n.x = points[i][0];
    n.y = points[i][1];
    n.dist = n.x * n.x + n.y * n.y;
    if (n.dist < max_heap[0].dist) {
      get_max(max_heap, &heap_size);
      heap_push(max_heap, &heap_size, n);
    }
  }
  *returnSize = k;
  *returnColumnSizes = (int *)malloc(k * sizeof(int));
  int **ans = (int **)malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++) {
    ans[i] = (int *)malloc(2 * sizeof(int));
    ans[i][0] = max_heap[i].x;
    ans[i][1] = max_heap[i].y;
    (*returnColumnSizes)[i] = 2;
  }
  free(max_heap);
  return ans;
}

int main() {
  int p1i[2][2] = {{1, 3}, {-2, 2}}, p2i[3][2] = {{3, 3}, {5, -1}, {-2, 4}};
  struct two_d_arr p1, p2;
  two_d_arr_init(&p1, ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  two_d_arr_init(&p2, ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  int rs1, rs2, *rcs1, *rcs2;
  int **kc1 = kClosest(p1.arr, p1.row_size, p1.col_size, 1, &rs1, &rcs1);
  int **kc2 = kClosest(p2.arr, p2.row_size, p2.col_size, 2, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", kc1[i][j]); // expect: [[-2,2]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", kc2[i][j]); // expect: [[3,3],[-2,4]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(kc1);
  free(kc1);
  free(rcs1);
  two_d_arr_free(&p1);
  for (int i = 0; i < rs2; i++)
    free(kc2);
  free(kc2);
  free(rcs2);
  two_d_arr_free(&p2);
}
