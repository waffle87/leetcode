// 3005. Count Elements With Maximum Frequency
#include "leetcode.h"

/*
 * given an array 'nums' consisting of positive integers. return the total
 * frequencies of elements in 'nums' such that those elements all have the
 * maximum frequency. the frequency of an element is the number of occurences of
 * that in the array
 */

int maxFrequencyElements(int *nums, int nums_size) {
  int *u_map = (int *)calloc(101, sizeof(int)), max_freq = 0, cnt = 0;
  for (int i = 0; i < nums_size; i++)
    u_map[nums[i]]++;
  for (int i = 0; i < 101; ++i)
    if (u_map[i] > max_freq)
      max_freq = u_map[i];
  for (int i = 0; i < 101; i++)
    if (u_map[i] == max_freq)
      cnt += u_map[i];
  free(u_map);
  return cnt;
}

int main() {
  int n1[] = {1, 2, 2, 3, 1, 4}, n2[] = {1, 2, 3, 4, 5};
  printf("%d\n", maxFrequencyElements(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", maxFrequencyElements(n2, ARRAY_SIZE(n2))); // expect: 5
}
