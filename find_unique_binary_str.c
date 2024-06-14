// 1980. Find Unique Binary String
#include "leetcode.h"

/*
 * given an array of strings 'nums' containing 'n' unique binary strings each of
 * length 'n', return a binary string of length 'n' that does not appear in
 * 'nums'. if there are multiple answers, you may return any of them.
 */

// char *findDifferentBinaryString(char **nums, int nums_size) {
char *findDifferentBinaryString(int nums_size,
                                char nums[nums_size][nums_size]) {
  char *ans = malloc(nums_size + 1);
  int j = 0;
  for (int i = 0; i < nums_size; i++) {
    if (nums[i][i] == '0')
      ans[j++] = '1';
    else
      ans[j++] = '0';
  }
  ans[j] = '\0';
  return j ? ans : "";
}

int main() {
  char n1[2][2] = {{"01"}, {"10"}}, n2[2][2] = {{"00"}, {"01"}},
       n3[3][3] = {{"111"}, {"011"}, {"001"}};
  printf("%s\n", findDifferentBinaryString(2, n1)); // expect: 11
  printf("%s\n", findDifferentBinaryString(2, n2)); // expect: 11
  printf("%s\n", findDifferentBinaryString(3, n3)); // expect: 101
}
