// 3348. Smallest Divisible Digit Product II
#include "leetcode.h"

/*
 * you are given a string 'num' which represents a positive integer and an
 * integer 't'. a number is called zero-free if none of its digits are 0. return
 * a string representing the smallest zero-free number greater than or equal to
 * 'num' such that the product of its digits is divisible by 't'. if no such
 * number exists, return "-1".
 */

long long gcd(long long a, long long b) {
  while (b) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

char *smallestNumber(char *num, long long t) {
  long long tmp = t;
  for (int i = 2; i <= 9; i++)
    while (!(tmp & i))
      tmp /= i;
  if (tmp != 1) {
    char *ans = (char *)malloc(3 * sizeof(char));
    strcpy(ans, "-1");
    return ans;
  }
  int n = strlen(num), prev_valid_pos = n - 1;
  char *digits = (char *)malloc((n + 2) * sizeof(char));
  strcpy(digits, num);
  long long *rem = (long long *)calloc(n + 1, sizeof(long long));
  rem[0] = t;
  for (int i = 0; i < n; i++) {
    int digit = digits[i] - '0';
    if (!digit) {
      prev_valid_pos = i;
      break;
    }
    long long common = gcd(rem[i], digit);
    rem[i + 1] = rem[i] / common;
  }
  if (rem[n] == 1) {
    free(rem);
    return digits;
  }
  for (int i = prev_valid_pos; i >= 0; i--) {
    int curr_digit = digits[i] - '0';
    for (int new_digit = curr_digit + 1; new_digit <= 9; new_digit++) {
      digits[i] = new_digit + '0';
      long long need = rem[i];
      need /= gcd(need, new_digit);
      char *suffix = (char *)malloc((n + 1) * sizeof(char));
      int suffix_size = 0;
      for (int j = i + 1; j < n; j++) {
        int chosen_digit = 9;
        while (chosen_digit > 1 && need % chosen_digit)
          chosen_digit--;
        if (!(need % chosen_digit))
          need /= chosen_digit;
        suffix[suffix_size++] = chosen_digit + '0';
      }
      if (need == 1) {
        for (int a = 0, b = suffix_size - 1; a < b; a++, b--) {
          char tmp = suffix[a];
          suffix[a] = suffix[b];
          suffix[b] = tmp;
        }
        for (int j = i + 1; j < n; j++)
          digits[j] = suffix[j - i - 1];
        digits[n] = '\0';
        free(suffix);
        free(rem);
        return digits;
      }
      free(suffix);
    }
    digits[i] = num[i];
  }
  char *factors = (char *)malloc((n + 100) * sizeof(char));
  int factor_cnt = 0;
  long long rem_t = t;
  for (int i = 9; i >= 2; i--)
    while (!(rem_t % i)) {
      factors[factor_cnt++] = i + '0';
      rem_t /= i;
    }
  int req_len = n + 1;
  req_len = fmax(req_len, factor_cnt);
  while (factor_cnt < req_len)
    factors[factor_cnt++] = '1';
  for (int i = 0, j = factor_cnt - 1; i < j; i++, j--) {
    char tmp = factors[i];
    factors[i] = factors[j];
    factors[j] = tmp;
  }
  factors[factor_cnt] = '\0';
  free(digits);
  free(rem);
  return factors;
}

int main() {
  char *n1 = "1234", *r1 = "1488";
  char *n2 = "12355", *r2 = "12355";
  char *n3 = "11111", *r3 = "-1";
  char *sn1 = smallestNumber(n1, 256);
  char *sn2 = smallestNumber(n2, 50);
  char *sn3 = smallestNumber(n3, 26);
  printf("%s\n", sn1);
  assert(!strcmp(sn1, r1));
  printf("%s\n", sn2);
  assert(!strcmp(sn2, r2));
  printf("%s\n", sn3);
  assert(!strcmp(sn3, r3));
  free(sn1);
  free(sn2);
  free(sn3);
}
