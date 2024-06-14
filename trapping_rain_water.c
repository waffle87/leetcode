// 42. Trapping Rain Water
#include "leetcode.h"

/*
 * given 'n' non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 */

int trap(int *height, int heightSize) {
  int *left = (int *)malloc(heightSize * sizeof(int));
  int *right = (int *)malloc(heightSize * sizeof(int));
  left[0] = height[0];
  right[heightSize - 1] = height[heightSize - 1];
  for (int i = 1; i < heightSize; i++)
    left[i] = height[i] > left[i - 1] ? height[i] : left[i - 1];
  for (int i = heightSize - 2; i >= 0; i--)
    right[i] = height[i] > right[i + 1] ? height[i] : right[i + 1];
  int ans = 0;
  for (int i = 0; i < heightSize; i++)
    ans += (fmin(left[i], right[i]) - height[i]);
  free(left), free(right);
  return ans;
}

int main() {
  int h1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, h2[] = {4, 2, 0, 3, 2, 5};
  printf("%d\n", trap(h1, ARRAY_SIZE(h1))); // expect: 6
  printf("%d\n", trap(h2, ARRAY_SIZE(h2))); // expect: 9
}
