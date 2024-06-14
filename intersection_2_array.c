// 349. Intersection of Two Arrays
#include "leetcode.h"

/*
 * given two integer arrays 'nums1' and 'nums2' return an array of their
 * intersection. each element in the result must be unique and you may return
 * the result in any order.
 */

typedef struct {
  int key;
  bool intersect;
  UT_hash_handle hh;
} map;

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
                  int *returnSize) {
  map *m = NULL, *element, *tmp;
  int *ans = malloc(*returnSize * sizeof(int)), len = 0;
  *returnSize = nums1Size < nums2Size ? nums1Size : nums2Size;
  for (int i = 0; i < nums1Size; i++) {
    element = malloc(sizeof(map));
    element->key = nums1[i];
    element->intersect = 0;
    HASH_ADD_INT(map, key, element);
  }
  for (int i = 0; i < nums2Size; i++) {
    element = NULL;
    HASH_FIND_INT(map, &nums2[i], element);
    if (element)
      element->intersect = 1;
  }
  HASH_ITER(hh, map, element, tmp) {
    if (element->intersect)
      ans[len++] = element->key;
  }
  *returnSize = len;
  return realloc(ans, sizeof(int) * len);
}

int main() {
  int n11[] = {1, 2, 2, 1}, n21[] = {2, 2}, n12[] = {4, 9, 5},
      n22[] = {9, 4, 9, 8, 4};
  int rs1[] = {}, rs2[] = {};
  int *i1 = intersection(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21), rs1);
  int *i2 = intersection(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22), rs2);
  for (int i = 0; i < 1; i++)
    printf("%d ", i1[i]); // expect: 2
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", i2[i]); // expect: 9 4
  printf("\n");
}
