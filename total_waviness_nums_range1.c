// 3751. Total Waviness of Numbers in Range I
#include "leetcode.h"

/*
 * you are given two integers 'num1' and 'num2' representing an inclusive range
 * '[num1, num2]'. the waviness of a number is defined as the total count of its
 * peaks and valleys. a digit is a peak if it is strictly greater than both its
 * immediate neighbours. a digit is a valley if it is strictly less than both of
 * its immediate neighbours. the first and last digits of a number cannot be
 * peaks or valleys. any number with fewer than 3 digits has a waviness of 0.
 * return the total sum of waviness for all numbers in the range '[num1, num2]'.
 */

struct result {
  long long cnt;
  long long sum;
};

struct result dfs(const char *s, int n, long long memo_cnt[16][10][10],
                  long long memo_sum[16][10][10], int pos, int prev, int curr,
                  int limit, int leading) {
  if (pos == n)
    return (struct result){1, 0};
  long long cnt = memo_cnt[pos][prev][curr];
  long long sum = memo_sum[pos][prev][curr];
  if (!limit && !leading && prev >= 0 && curr >= 0)
    if (memo_cnt[pos][prev][curr] != -1)
      return (struct result){cnt, sum};
  int up = limit ? (s[pos] - '0') : 9;
  for (int digit = 0; digit <= up; ++digit) {
    int new_leading = leading && (!digit);
    int new_prev = curr;
    int new_curr = new_leading ? -1 : digit;
    struct result sub = dfs(s, n, memo_cnt, memo_sum, pos + 1, new_prev,
                            new_curr, limit && (digit == up), new_leading);
    if (!new_leading && prev >= 0 && curr >= 0)
      if ((prev < curr && curr > digit) || (prev > curr && curr < digit))
        sum += sub.cnt;
    cnt += sub.cnt;
    sum += sub.sum;
  }
  if (!limit && !leading && prev >= 0 && curr >= 0) {
    memo_cnt[pos][prev][curr] = cnt;
    memo_sum[pos][prev][curr] = sum;
  }
  return (struct result){cnt, sum};
}

long long solve(long long n) {
  if (n < 100)
    return 0;
  char s[16];
  sprintf(s, "%lld", n);
  int m = strlen(s);
  long long memo_cnt[16][10][10], memo_sum[16][10][10];
  memset(memo_cnt, -1, sizeof(memo_cnt));
  memset(memo_sum, -1, sizeof(memo_sum));
  struct result res = dfs(s, m, memo_cnt, memo_sum, 0, -1, -1, 1, 1);
  return res.sum;
}

int totalWaviness(int num1, int num2) {
  return (int)(solve(num2) - solve(num1) - 1);
}

int main() {
  int r1 = totalWaviness(120, 130);
  int r2 = totalWaviness(198, 202);
  int r3 = totalWaviness(4848, 4848);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 2);
}
