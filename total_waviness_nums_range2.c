// 3753. Total Waviness of Numbers in Range II
#include "leetcode.h"

/*
 * you are given two integers representing an inclusive range. the waviness of a
 * number is defined as the total count of its peaks and valleys. a digit is a
 * peak if it is strictly greater than both of its immediate neighbours. a digit
 * is a valley if it is strictly less than both of its immediate neighbours. the
 * first and last digits of a number cannot be peaks or valleys. any number with
 * fewer than 3 digits has a waviness of 0. return the total sum of waviness for
 * all numbers in the range.
 */

struct state {
  int prev, curr, tight, lead;
  long long cnt, sum;
};

long long solve(long long num) {
  if (num < 100)
    return 0;
  char s[20];
  sprintf(s, "%lld", num);
  int n = strlen(s), curr_size = 0;
  struct state curr_states[500];
  curr_states[curr_size++] = (struct state){10, 10, 1, 1, 1, 0};
  for (int pos = 0; pos < n; ++pos) {
    int limit = s[pos] - '0';
    long long cnt[2][2][11][11] = {0};
    long long sum[2][2][11][11] = {0};
    for (int i = 0; i < curr_size; ++i) {
      struct state st = curr_states[i];
      int max_digit = st.tight ? limit : 9;
      for (int digit = 0; digit <= max_digit; ++digit) {
        int new_lead = (st.lead && digit == 0) ? 1 : 0;
        int new_prev = st.curr;
        int new_curr = new_lead ? 10 : digit;
        int new_tight = (st.tight && digit == max_digit) ? 1 : 0;
        long long add = 0;
        if (!new_lead && st.prev != 10 && st.curr != 10)
          if ((st.prev < st.curr && st.curr > digit) ||
              (st.prev > st.curr && st.curr < digit))
            add = st.cnt;
        cnt[new_tight][new_lead][new_prev][new_curr] += st.cnt;
        sum[new_tight][new_lead][new_prev][new_curr] += st.sum + add;
      }
    }
    struct state next_states[500];
    int next_size = 0;
    for (int tight = 0; tight < 2; ++tight)
      for (int lead = 0; lead < 2; ++lead)
        for (int prev = 0; prev <= 10; ++prev)
          for (int curr = 0; curr <= 10; ++curr) {
            long long c = cnt[tight][lead][prev][curr];
            long long s_val = sum[tight][lead][prev][curr];
            if (c)
              next_states[next_size++] =
                  (struct state){prev, curr, tight, lead, c, s_val};
          }
    memcpy(curr_states, next_states, next_size * sizeof(struct state));
    curr_size = next_size;
  }
  long long res = 0;
  for (int i = 0; i < curr_size; ++i)
    res += curr_states[i].sum;
  return res;
}

long long totalWaviness(long long num1, long long num2) {
  return solve(num2) - solve(num1 - 1);
}

int main() {
  long long r1 = totalWaviness(120, 130);
  long long r2 = totalWaviness(198, 202);
  long long r3 = totalWaviness(4848, 4848);
  printf("%lld\n", r1);
  assert(r1 == 3);
  printf("%lld\n", r2);
  assert(r2 == 3);
  printf("%lld\n", r3);
  assert(r3 == 2);
}
