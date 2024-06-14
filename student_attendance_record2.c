// 552. Student Attendance Record II
#include "leetcode.h"

/*
 * an attendance record for a student can be represented as a string where each
 * character signifies whether the student was absent, late, or present on that
 * day. the record only contains the following three characters. 'a ': absent,
 * 'l': late, and 'p': present. any student is eligible for attendance award if
 * they meet both of the following criteria. the student was absent 'a' for
 * strictly fewer than 2 days total, and the student was never late 'l' for 3 or
 * more consecutive days. given an integer 'n', return the number of possible
 * attendance records of length 'n' that make a student eligible for attendance
 * award. return it mod 1e9+7.
 */

int checkRecord(int n) {
  long long mod = 1e9 + 7, dp[n + 3];
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 4;
  for (int i = 3; i <= n; i++)
    dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % mod;
  long long ans = dp[n];
  for (int i = 0; i < n; i++)
    ans = (ans + dp[i] * dp[n - i - 1]) % mod;
  return ans;
}

int main() {
  printf("%d\n", checkRecord(2));     // expect: 8
  printf("%d\n", checkRecord(1));     // expect: 3
  printf("%d\n", checkRecord(10101)); // expect: 183236316
}
