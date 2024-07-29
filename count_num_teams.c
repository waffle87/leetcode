// 1395. Count Number of Teams
#include "leetcode.h"

/*
 * there are 'n' soldiers standing in a line. each soldier is assigned a unique
 * 'rating' value. you have to form a team of 3 soldiers amongst them under the
 * following rules
 * - choose 3 soldiers with index '(i, j, k)' with rating '(rating[i],
 * rating[j], rating[k])'
 * - a team is valid if '(rating[i] < rating[j] < rating[k])' or '(rating[i] >
 * rating[j] > rating[k])' where '(0 <= i < j < k < n))' return the number of
 * teams you can form given the conditions (soldiers can be part of multiple
 * teams)
 */

int numTeams(int *rating, int rating_size) {
  int ans = 0, la, lb, ra, rb;
  for (int i = 1; i < rating_size - 1; i++) {
    la = 0, ra = 0;
    for (int j = 0; j < i; j++)
      if (rating[j] < rating[i])
        la++;
    lb = i - la;
    for (int k = i + 1; k < rating_size; k++)
      if (rating[i] < rating[k])
        ra++;
    rb = rating_size - 1 - i - ra;
    ans = ans + la * ra + lb * rb;
  }
  return ans;
}

int main() {
  int r1[] = {2, 5, 3, 4, 1}, r2[] = {2, 1, 3};
  printf("%d\n", numTeams(r1, 5)); // expect: 3
  printf("%d\n", numTeams(r2, 3)); // expect: 0
}
