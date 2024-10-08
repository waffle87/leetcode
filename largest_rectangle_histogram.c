// 84. Largest Rectangle in Histogram
#include "leetcode.h"

/*
 * given an array of integers 'heights' representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 */

int area(int height, int width) { return height * width; }

int largestRectangleArea(int *heights, int heightsSize) {
  int *stack = (int *)malloc((heightsSize + 1) * sizeof(int));
  int stack_size = 0, max_area = 0;
  for (int i = 0; i <= heightsSize; i++) {
    int curr = i == heightsSize ? 0 : heights[i];
    while (stack_size && curr < heights[stack[stack_size - 1]]) {
      int pop_idx = stack[--stack_size];
      int pop_height = heights[pop_idx];
      int width = !stack_size ? i : i - stack[stack_size - 1] - 1;
      max_area = fmax(max_area, area(pop_height, width));
    }
    stack[stack_size++] = i;
  }
  free(stack);
  return max_area;
}

int main() {
  int h1[] = {2, 1, 5, 6, 2, 3}, h2[] = {2, 4};
  printf("%d\n", largestRectangleArea(h1, ARRAY_SIZE(h1))); // expect: 10
  printf("%d\n", largestRectangleArea(h2, ARRAY_SIZE(h2))); // expect: 4
}
