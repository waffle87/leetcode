// 2375. Construct Smallest Number From DI String
#include "leetcode.h"

/*
 * you are given a 0-indexed string 'pattern' of length 'n' consisting of the
 * characters 'I' meaning increased and 'D' meaning decreased. a 0-indexed
 * string 'num' of length 'n + 1' is created using thhe following conditions:
 * 'num' consists of the digits 1 to 9, where each digit is used at most once,
 * if 'pattern[i] == I', then 'num[i] < num[i + 1]', and if 'pattern[i] == D',
 * thhen 'num[i] > num[i + 1]'. return the lexicographically smallest possible
 * string 'num' that meets the conditions.
 */

bool find_smallest(char *pattern, char *nums, int prev, int vis) {
  int new_vis, max_val, start_val;
  if (*pattern == 'I') {
    max_val = 10;
    start_val = prev + 1;
  } else {
    max_val = prev;
    start_val = 1;
  }
  for (int i = start_val; i < max_val; i++) {
    if (!((vis >> (i - 1)) & 1)) {
      *nums = i;
      new_vis = vis | (1 << (i - 1));
      if (!(*(pattern + 1)) ||
          find_smallest(pattern + 1, &(nums[1]), i, new_vis))
        return true;
    }
  }
  return false;
}

char *smallestNumber(char *pattern) {
  int n = strlen(pattern), vis;
  char *nums = (char *)malloc((n + 1) * sizeof(char));
  char *ans = (char *)malloc((n + 2) * sizeof(char));
  for (int i = 1; i < 10; i++) {
    vis = 1 << (i - 1);
    if (find_smallest(pattern, nums, i, vis)) {
      ans[0] = i + '0';
      break;
    }
  }
  for (int i = 0; i < n + 1; i++)
    ans[i + 1] = nums[i] + '0';
  ans[n + 1] = 0;
  free(nums);
  return ans;
}

int main() {
  char *p1 = "IIIDIDDD", *p2 = "DDD";
  printf("%s\n", smallestNumber(p1)); // expect: 123549876
  printf("%s\n", smallestNumber(p2)); // expect: 4321
}
