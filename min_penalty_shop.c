// 2483. Minimum Penalty for a Shop
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 You are given the customer visit log of a shop represented by a 0-indexed
string customers consisting only of characters 'N' and 'Y':

    if the ith character is 'Y', it means that customers come at the ith hour
    whereas 'N' indicates that no customers come at the ith hour.

If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as
follows:

    For every hour when the shop is open and no customers come, the penalty
increases by 1. For every hour when the shop is closed and customers come, the
penalty increases by 1.

Return the earliest hour at which the shop must be closed to incur a minimum
penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the
hour j.
*/

int bestClosingTime(char *customers) {
  int n = strlen(customers);
  int *pre_n = malloc((n + 1) * sizeof(int));
  int *suf_y = malloc((n + 1) * sizeof(int));
  pre_n[0] = 0;
  for (int i = 0; i < n; i++) {
    pre_n[i + 1] = pre_n[i];
    if (customers[i] == 'N')
      pre_n[i + 1]++;
  }
  suf_y[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suf_y[i] = suf_y[i + 1];
    if (customers[i] == 'Y')
      suf_y[i]++;
  }
  int min = INT_MAX, min_id = 0;
  for (int i = 0; i <= n; i++) {
    int d = pre_n[i] + suf_y[i];
    if (d < min) {
      min = d;
      min_id = i;
    }
    if (!min)
      break;
  }
  free(pre_n), free(suf_y);
  return min_id;
}

int main() {
  char c1[] = {"YYNY"}, c2[] = {"NNNNN"}, c3[] = {"YYYY"};
  printf("%d\n", bestClosingTime(c1)); // expect: 2
  printf("%d\n", bestClosingTime(c2)); // expect: 0
  printf("%d\n", bestClosingTime(c3)); // expect: 4
}
