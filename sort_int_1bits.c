// 1356. Sort Integers by The Number of 1 Bits
#include "leetcode.h"

/*
 * given an integer array 'arr', sort the integers in the array in ascending
 * order by the number of 1's in their binary representation and in case of two
 * or more integers have the same number of 1's, you have to sort them in
 * ascending order. return the array after sorting it.
 */

struct pair {
  int val;
  int cnt;
};

int cmp(const void *a, const void *b) {
  const struct pair pa = *(const struct pair *)a;
  const struct pair pb = *(const struct pair *)b;
  return pa.cnt == pb.cnt ? pa.val - pb.val : pa.cnt - pb.cnt;
}

int find(int a) {
  int res = 0;
  while (a) {
    res += a % 2;
    a /= 2;
  }
  return res;
}

int *sortByBits(int *arr, int arr_size, int *return_size) {
  *return_size = arr_size;
  struct pair *p = (struct pair *)malloc(sizeof(struct pair) * arr_size);
  for (int i = 0; i < arr_size; i++) {
    p[i].val = arr[i];
    p[i].cnt = find(arr[i]);
  }
  qsort(p, arr_size, sizeof(struct pair), cmp);
  for (int i = 0; i < arr_size; i++)
    arr[i] = p[i].val;
  free(p);
  return arr;
}

int main() {
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8},
      a2[] = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  int rs1[] = {}, rs2[] = {};
  int *sbb1 = sortByBits(a1, ARRAY_SIZE(a1), rs1);
  int *sbb2 = sortByBits(a2, ARRAY_SIZE(a2), rs2);
  for (int i = 0; i < 8; i++)
    printf("%d ", sbb1[i]); // expect: 0,1,2,4,8,3,5,6,7
  printf("\n");
  for (int i = 0; i < 11; i++)
    printf("%d ", sbb2[i]); // expect: 1,2,4,8,16,32,64,128,256,512,1024
  printf("\n");
}
