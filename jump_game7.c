// 1871. Jump Game VII
#include "leetcode.h"

/*
 * you are given a 0-indexed binary string 's' and two integers 'minJump' and
 * 'maxJump'. in the beginning, you are standing at index '0', which is equal to
 * 0. you can move from index 'i' to index 'j' if the following conditions are
 * fulfilled: 'i + minJump <= j <= min(i + maxJump, s.length - 1)' and 's[j] ==
 * 0'. return true if you can reach index 's.length - 1' in 's' or false
 * otherwise.
 */

bool canReach(char *s, int minJump, int maxJump) {
  int n = strlen(s);
  int *f = (int *)malloc(n * sizeof(int));
  int *pre = (int *)malloc(n * sizeof(int));
  f[0] = 1;
  for (int i = 0; i < minJump; i++)
    pre[i] = 1;
  for (int i = minJump; i < n; i++) {
    int left = i - maxJump, right = i - minJump;
    if (s[i] == '0') {
      int total = pre[right];
      if (left > 0)
        total -= pre[left - 1];
      f[i] = total != 0 ? 1 : 0;
    }
    pre[i] = pre[i - 1] + f[i];
  }
  bool ans = (f[n - 1] == 1);
  free(f);
  free(pre);
  return ans;
}

int main() {
  char *s1 = "011010", *s2 = "01101110";
  bool r1 = canReach(s1, 2, 3);
  bool r2 = canReach(s2, 2, 3);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
