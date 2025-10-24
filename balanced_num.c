// 2048. Next Greater Numerically Balanced Number
#include "leetcode.h"

/*
 * an integer 'x' is numerically balanced if for every digit 'd' in the number
 * 'x', there are exactly 'd' occurences of that digit in 'x'. given an integer
 * 'n', return the smallest numerically balanced number strictly greater than
 * 'n'
 */

bool is_beautiful(int *cnt) {
  for (int i = 1; i <= 7; i++)
    if (cnt[i] != 0 && cnt[i] != i)
      return false;
  return true;
}

void generate(long num, int *cnt, int *res, int *res_size) {
  if (num > 0 && is_beautiful(cnt))
    res[(*res_size)++] = (int)num;
  if (num > 1224444)
    return;
  for (int i = 1; i <= 7; i++) {
    if (cnt[i] < i) {
      cnt[i]++;
      generate(num * 10 + i, cnt, res, res_size);
      cnt[i]--;
    }
  }
}

int nextBeautifulNumber(int n) {
  int res[2000], res_size = 0, cnt[10] = {0}, ans = -1;
  generate(0, cnt, res, &res_size);
  for (int i = 0; i < res_size; i++)
    if (res[i] > n && (ans == -1 || res[i] < ans))
      ans = res[i];
  return ans;
}

int main() {
  printf("%d\n", nextBeautifulNumber(1));    // expect: 22
  printf("%d\n", nextBeautifulNumber(1000)); // expect: 1333
  printf("%d\n", nextBeautifulNumber(3000)); // expect: 3133
}
