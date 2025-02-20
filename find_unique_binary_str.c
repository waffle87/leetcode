// 1980. Find Unique Binary String
#include "leetcode.h"

/*
 * given an array of strings 'nums' containing 'n' unique binary strings each of
 * length 'n', return a binary string of length 'n' that does not appear in
 * 'nums'. if there are multiple answers, you may return any of them.
 */

char *findDifferentBinaryString(char **nums, int numsSize) {
  char *ans = (char *)malloc((numsSize + 1) * sizeof(char));
  int j = 0;
  for (int i = 0; i < numsSize; i++)
    ans[j++] = nums[i][i] == '0' ? '1' : '0';
  ans[j] = '\0';
  return j ? ans : "";
}

int main() {
  char *n1[] = {"01", "10"}, *n2[] = {"00", "01"},
       *n3[] = {"111", "011", "001"};
  printf("%s\n",
         findDifferentBinaryString((char **)n1, ARRAY_SIZE(n1))); // expect: 11
  printf("%s\n",
         findDifferentBinaryString((char **)n2, ARRAY_SIZE(n2))); // expect: 11
  printf("%s\n",
         findDifferentBinaryString((char **)n3, ARRAY_SIZE(n3))); // expect: 101
}
