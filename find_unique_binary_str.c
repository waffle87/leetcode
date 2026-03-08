// 1980. Find Unique Binary String
#include "leetcode.h"

/*
 * given an array of strings 'nums' containing 'n' unique binary strings each of
 * length 'n', return a binary string of length 'n' that does not appear in
 * 'nums'. if there are multiple answers, you may return any of them.
 */

char *findDifferentBinaryString(char **nums, int numsSize) {
  char *ans = (char *)malloc((numsSize + 1) * sizeof(char));
  for (int i = 0; i < numsSize; i++)
    ans[i] = nums[i][i] == '0' ? '1' : '0';
  ans[numsSize] = '\0';
  return ans;
}

int main() {
  char *n1[] = {"01", "10"};
  char *n2[] = {"00", "01"};
  char *n3[] = {"111", "011", "001"};
  char *r1 = findDifferentBinaryString((char **)n1, ARRAY_SIZE(n1));
  char *r2 = findDifferentBinaryString((char **)n2, ARRAY_SIZE(n2));
  char *r3 = findDifferentBinaryString((char **)n3, ARRAY_SIZE(n3));
  printf("%s\n", r1); // expect: 11
  assert(!strcmp(r1, "11"));
  printf("%s\n", r2); // expect: 10
  assert(!strcmp(r2, "10"));
  printf("%s\n", r3); // expect: 000
  assert(!strcmp(r3, "000"));
  free(r1);
  free(r2);
  free(r3);
}
