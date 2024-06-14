// 228. Summary Ranges
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a sorted unique integer array 'nums'. a range '[a, b]' isthe set of all
 * integers from 'a' to 'b' (inclusive). return the smallest sorted list of
 * ranges that cover all the numbers in the array exactlyh. that is, each
 * element of 'nums' is covered by exactly one of the ranges, and there is no
 * integer 'x' such that 'x' is in one of the ranges but not in 'nums' each
 * range '[a, b]' in the list should be outgput as:
 * - "a->b" if a != b
 * - "a" if a == b
 */

char *int_to_str(int val) {
  if (!val)
    return "0";
  bool flag = (val < 0) ? true : false;
  uint a = fabs(val);
  char *res = malloc(12 * sizeof(int));
  res[11] = '\0';
  int idx = 10;
  while (a) {
    res[idx] = a % 10 + '0';
    idx--;
    a /= 10;
  }
  if (flag) {
    res[idx] = '-';
    idx--;
  }
  return &res[idx + 1];
}

char **summaryRanges(int *nums, int nums_size, int *return_size) {
  if (!nums_size) {
    *return_size = 0;
    return NULL;
  }
  int **map = malloc(nums_size * sizeof(int *));
  int idx = 0, begin = nums[0], end = nums[0];
  if (nums_size == 1) {
    map[0] = malloc(2 * sizeof(int));
    map[0][0] = begin;
    map[0][1] = end;
    idx = 1;
  }
  for (int i = 1; i < nums_size; i++) {
    if (nums[i] == nums[i - 1] + 1)
      end = nums[i];
    else {
      map[idx] = malloc(2 * sizeof(int));
      map[idx][0] = begin;
      map[idx][1] = end;
      begin = nums[i];
      end = nums[i];
      idx++;
    }
    for (int i = 1; i < nums_size; i++) {
      if (nums[i] == nums[i - 1] + 1)
        end = nums[i];
      else {
        map[idx] = malloc(2 * sizeof(int));
        map[idx][0] = begin;
        map[idx][1] = end;
        begin = nums[i];
        end = nums[i];
        idx++;
      }
      if (i == nums_size - 1) {
        map[idx] = malloc(2 * sizeof(int));
        map[idx][0] = begin;
        map[idx][1] = end;
        begin = nums[i];
        end = nums[i];
        idx++;
      }
    }
    char **ans = malloc(idx * sizeof(char *));
    for (int i = 0; i < idx; i++) {
      if (map[i][0] == map[i][1])
        ans[i] = int_to_str(map[i][0]);
      else {
        char *tmp = malloc(25 * sizeof(char));
        tmp[0] = '\0';
        strcat(tmp, int_to_str(map[i][0]));
        strcat(tmp, "->");
        strcat(tmp, int_to_str(map[i][1]));
        ans[i] = tmp;
      }
    }
  }
  *return_size = idx;
  return ans;
}

int main() {
  int n1[] = {0, 1, 2, 4, 5, 7};
  int n2[] = {0, 2, 3, 4, 6, 8, 9};
  printf("%s\n", summaryRanges(n1, 6, NULL)); // expect: 0->2 4->5 7
  printf("%s\n", summaryRanges(n2, 7, NULL)); // expect: 0 2->4 6 8->9
}
