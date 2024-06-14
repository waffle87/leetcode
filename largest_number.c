// 179. Largest Number
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a list of non-negative integers 'nums', arrange them such that they
 * form the larget number and return it. since the result may be very large, so
 * you need to return a string instead of an integer.
 */

int check_digit(int val) {
  int digit = 0;
  while (val) {
    digit++;
    val /= 10;
  }
  return digit;
}

char *int_to_str(int val) {
  if (!val)
    return "0";
  int digit = check_digit(val);
  char *res = malloc(digit + 1);
  res[digit] = '\0';
  int idx = digit - 1;
  while (val) {
    res[idx] = val % 10 + '0';
    val /= 10;
    idx--;
  }
  return res;
}

int cmp(const void *a, const void *b) {
  char *aa = *(char **)a;
  char *bb = *(char **)b;
  int n = strlen(aa) + strlen(bb);
  char *ab = malloc(n + 1), *ba = malloc(n + 1);
  ab[n] = '\0';
  ba[n] = '\0';
  strcpy(ab, aa);
  strcpy(&ab[strlen(aa)], bb);
  strcpy(ba, bb);
  strcpy(&ba[strlen(bb)], aa);
  for (int i = 0; i < n; i++) {
    if (ab[i] == ba[i])
      continue;
    return ba[i] - ab[i];
  }
  return 0;
}

char *largestNumber(int *nums, int nums_size) {
  int n = nums_size, len = 0;
  char **data = malloc(n * sizeof(char *));
  bool zero = true;
  for (int i = 0; i < n; i++) {
    data[i] = int_to_str(nums[i]);
    len += strlen(data[i]);
    if (nums[i])
      zero = false;
  }
  if (zero)
    return "0";
  qsort(data, n, sizeof(char *), cmp);
  char *ans = malloc(len + 1);
  int p = 0;
  for (int i = 0; i < n; i++) {
    strcpy(&ans[p], data[i]);
    p += strlen(data[i]);
  }
  return ans;
}

int main() {
  int n1[] = {10, 2}, n2[] = {3, 30, 34, 5, 9};
  printf("%s\n", largestNumber(n1, 2)); // expect: 210
  printf("%s\n", largestNumber(n2, 5)); // expect: 9534330
}
