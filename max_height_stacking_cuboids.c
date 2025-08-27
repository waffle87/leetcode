// 1691. Maximum Height by Stacking Cuboids
#include "leetcode.h"

/*
 * given 'n' cuboids where the dimensions of the i'th cuboid is 'cuboids[i] =
 * [width_i, length_i, height_i]' (0-indexed). choosee a subset of 'cuboids' and
 * place them on each other. you can place cuboid 'i' on cuboid 'j' if 'width_i
 * <= width_j', and similarily for length and height. you can rearrange any
 * cuboid's dimensions by rotating it to put it on another cuboid. return the
 * maximum height of the stacked 'cuboids'.
 */

int cmp_len(const void *a, const void *b) {
  int aa = *(int *)a, bb = *(int *)b;
  return aa > bb ? 1 : -1;
}

int cmp_box(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  if (aa[2] > bb[2])
    return 1;
  if (aa[2] < bb[2])
    return -1;
  else {
    if (aa[1] > bb[1])
      return 1;
    if (aa[1] < bb[1])
      return -1;
    else {
      if (aa[0] > bb[0])
        return 1;
      if (aa[0] < bb[0])
        return -1;
      else
        return 0;
    }
  }
}

bool check(int *bottom, int *top) {
  return top[2] <= bottom[2] && top[1] <= bottom[1] && top[0] <= bottom[0]
             ? false
             : true;
}

int maxHeight(int **cuboids, int cuboidsSize, int *cuboidsColSize) {
  for (int i = 0; i < cuboidsSize; i++)
    qsort(cuboids[i], 3, sizeof(int), cmp_len);
  qsort(cuboids, cuboidsSize, sizeof(cuboids[0]), cmp_box);
  int *arr = (int *)malloc(cuboidsSize * sizeof(int)), max = arr[0];
  for (int i = 1; i < cuboidsSize; i++) {
    for (int j = 0; j < i; j++)
      if (check(cuboids[i], cuboids[j]))
        arr[i] = fmax(arr[i], arr[j] + cuboids[i][2]);
    max = fmax(max, arr[i]);
  }
  free(arr);
  return max;
}

int main() {
  int c1i[3][3] = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}},
      c2i[2][3] = {{38, 25, 45}, {76, 35, 3}},
      c3i[6][3] = {{7, 11, 17}, {7, 17, 11}, {11, 7, 17},
                   {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
  struct two_d_arr *c1 = two_d_arr_init(3, 3, c1i);
  struct two_d_arr *c2 = two_d_arr_init(2, 3, c2i);
  struct two_d_arr *c3 = two_d_arr_init(6, 3, c3i);
  printf("%d\n", maxHeight(c1->arr, c1->row_size, c1->col_size)); // expect: 190
  printf("%d\n", maxHeight(c2->arr, c2->row_size, c2->col_size)); // expect: 76
  printf("%d\n", maxHeight(c3->arr, c3->row_size, c3->col_size)); // expect: 102
  two_d_arr_free(c1);
  two_d_arr_free(c2);
  two_d_arr_free(c3);
}
