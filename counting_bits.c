// 338. Counting Bits
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer 'n', return an array 'ans' of length 'n + 1' such that for
 * each 'i (0 <= i <= n)', 'ans[i]' is the number of 1's inthe binary
 * representation of 'i'
 */

int *countBits(int n, int *return_size) {
  *return_size = n + 1;
  int *ans = (int *)malloc((n + 1) * sizeof(int));
  int org = 1, dis = 1, ptr = 2, post = 3, idx = 4;
  ans[0] = 0;
  if (!n)
    return ans;
  ans[1] = 1;
  if (n == 1)
    return ans;
  ans[2] = 1;
  if (n == 2)
    return ans;
  ans[3] = 2;
  if (n == 3)
    return ans;
  while (idx <= n) {
    dis = org = org * 2;
    while (ptr != post) {
      for (int i = ptr; i <= post; i++) {
        ans[idx] = ans[i];
        if (idx == n)
          return ans;
        idx++;
      }
      dis /= 2;
      ptr += dis;
    }
    ans[idx] = ans[idx - 1];
    if (idx == n)
      break;
    idx++;
    ans[idx] = ans[idx - 1] + 1;
    if (idx == n)
      break;
    idx++;
    ptr = post + 1;
    post = idx - 1;
  }
  return ans;
}

int main() {
  int rs1[] = {}, rs2[] = {};
  int *cb1 = countBits(2, rs1), *cb2 = countBits(5, rs2);
  for (int i = 0; i < 3; i++)
    printf("%d ", cb1[i]); // expect: 0 1 1
  printf("\n");
  for (int i = 0; i < 6; i++)
    printf("%d ", cb2[i]); // expect: 0 1 1 2 1 2
  printf("\n");
}
