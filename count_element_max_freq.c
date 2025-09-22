// 3005. Count Elements With Maximum Frequency
#include "leetcode.h"

/*
 * given an array 'nums' consisting of positive integers. return the total
 * frequencies of elements in 'nums' such that those elements all have the
 * maximum frequency. the frequency of an element is the number of occurences of
 * that in the array
 */

int maxFrequencyElements(int *nums, int numsSize) {
  int freq[101] = {0}, max_freq = 0, m = 0;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i];
    freq[curr]++;
    m += (freq[curr] == max_freq);
    if (freq[curr] > max_freq) {
      m = 1;
      max_freq = freq[curr];
    }
  }
  return m * max_freq;
}

int main() {
  int n1[] = {1, 2, 2, 3, 1, 4}, n2[] = {1, 2, 3, 4, 5};
  printf("%d\n", maxFrequencyElements(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", maxFrequencyElements(n2, ARRAY_SIZE(n2))); // expect: 5
}
