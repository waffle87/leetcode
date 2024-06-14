// 2971. Find Polygon With the Largest Perimeter
#include "leetcode.h"

/*
 * given an arry of positive integers 'nums' of length 'n'. a polygon is a
 * closed plane figure that has at least 3 sides. the longest side of a polygon
 * is smaller than the sum of its other sides. conversely, if you have 'k (k >=
 * 3)' positive real numbers then there always exists a polygon with 'k' sides
 * whose lengths are 'a1,a2,...ak'. the perimeter of a polygon is the sum of
 * lengths of its sides. return the largest possible perimeter of a polygon
 * whose sides can be formed from 'nums' or '-1' if it is not possible to create
 * a polygon.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

long long largestPerimeter(int *nums, int nums_size) {
  long long ans = -1, sums[nums_size - 1];
  qsort(nums, nums_size, sizeof(int), cmp);
  sums[nums_size - 2] = nums[nums_size - 2] + nums[nums_size - 1];
  for (int i = nums_size - 3; i >= 0; i--) {
    sums[i] = nums[i] + sums[i + 1];
    if (nums[i] < sums[i + 1])
      ans = sums[i];
  }
  return ans;
}

int main() {
  int n1[] = {5, 5, 5}, n2[] = {1, 12, 1, 2, 5, 50, 3}, n3[] = {5, 5, 50};
  printf("%lld\n", largestPerimeter(n1, ARRAY_SIZE(n1))); // expect: 15
  printf("%lld\n", largestPerimeter(n2, ARRAY_SIZE(n2))); // expect: 12
  printf("%lld\n", largestPerimeter(n3, ARRAY_SIZE(n3))); // expect: -1
}
