// 166. Fraction to Recurring Decimal
#include "leetcode.h"

/*
 * given two integers representing the 'numerator' and 'denominator' of a
 * fraction, reeturn the fraction in string format. if the fractional part is
 * repeating, enclose the repeating part in parentheses. if multiple answers are
 * possible, return any of them. it is guaranteed that the length of the answer
 * string is less than 10^4 for all the digits given inputs.
 */

struct visited {
  long key;
  int idx;
  UT_hash_handle hh;
};

char *fractionToDecimal(int numerator, int denominator) {
  if (!numerator) {
    char *ans = (char *)malloc(2 * sizeof(char));
    ans[0] = '0';
    ans[1] = '\0';
    return ans;
  }
  char *ans = (char *)malloc(10001 * sizeof(char));
  long n = numerator, d = denominator;
  int idx = 0, sign = n / labs(n) * d / labs(d);
  if (sign == -1)
    ans[idx++] = '-';
  n = labs(n);
  d = labs(d);
  long curr = n / d;
  n = 10 * (n - curr * d);
  if (curr) {
    char buffer[10];
    int buffer_idx = 0;
    while (curr) {
      int digit = curr - curr / 10 * 10;
      buffer[buffer_idx++] = '0' + digit;
      curr /= 10;
    }
    for (int i = buffer_idx - 1; i >= 0; --i)
      ans[idx++] = buffer[i];
  } else
    ans[idx++] = '0';
  if (!n) {
    ans[idx] = '\0';
    return ans;
  }
  ans[idx++] = '.';
  struct visited *hash_map = NULL;
  while (true) {
    if (!n)
      break;
    struct visited *node = NULL;
    HASH_FIND(hh, hash_map, &n, sizeof(long), node);
    if (node) {
      ans[idx++] = ')';
      int rep_start_idx = node->idx;
      for (int i = idx++ - 1; i >= rep_start_idx; --i)
        ans[i + 1] = ans[i];
      ans[rep_start_idx] = '(';
      break;
    } else {
      node = (struct visited *)malloc(sizeof(struct visited));
      node->key = n;
      HASH_ADD(hh, hash_map, key, sizeof(long), node);
      curr = n / d;
      n = 10 * (n - curr * d);
      ans[idx++] = '0' + curr;
    }
  }
  struct visited *del, *tmp;
  HASH_ITER(hh, hash_map, del, tmp) {
    HASH_DEL(hash_map, del);
    free(del);
  }
  ans[idx] = '\0';
  return ans;
}

int main() {
  char *ftd1 = fractionToDecimal(1, 2);
  char *ftd2 = fractionToDecimal(2, 1);
  char *ftd3 = fractionToDecimal(4, 333);
  printf("%s\n", ftd1); // expect: 0.5
  printf("%s\n", ftd2); // expect: 2
  printf("%s\n", ftd3); // expect: 0.(012)
  free(ftd1);
  free(ftd2);
  free(ftd3);
}
