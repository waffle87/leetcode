// 11. Container With Most Water
#include "leetcode.h"

/*
 * you are given an integer array 'height' of length 'n'. there are 'n' vertical
 * lines drawn such that two endpoints of the i'th line are '(i, 0)' and '(i,
 * height[i])'. find two lines that together with the x-axis form a container
 * such that the container contains the most water. return the maximum amount of
 * water a container can store. notice that you may not slant the container.
 */

int maxArea(int *height, int heightSize) {
  int left = 0, right = heightSize - 1, ans = 0;
  while (left < right) {
    int curr = fmin(height[left], height[right]) * (right - left);
    ans = fmax(ans, curr);
    if (height[left] < height[right])
      left++;
    else
      right--;
  }
  return ans;
}

int main() {
  int h1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7}, h2[] = {1, 1};
  printf("%d\n", maxArea(h1, ARRAY_SIZE(h1))); // expect: 49
  printf("%d\n", maxArea(h2, ARRAY_SIZE(h2))); // expect: 1
}
