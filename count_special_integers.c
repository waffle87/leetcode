// 2376. Count Special Integers

#include "leetcode.h"

/*
 * we call a positive integer special if all of its digits are distinct. given a
 * positive integer 'n', return the number of special integers that belong to
 * the interval '[1, n]'
 */

int countSpecialNumbers(int n) {
  if (n <= 10)
    return n;
  int ans = 0, k = 9, choose = 9, list[10], curr = 0;
  list[curr] = n % 10;
  n /= 10;
  while (n) {
    curr++;
    ans += k;
    k *= choose;
    choose--;
    list[curr] = n % 10;
    n /= 10;
  }
  k /= 9;
  bool used[10] = {0};
  choose = 9;
  if (curr) {
    used[list[curr]] = 1;
    ans += k * (list[curr] - 1);
    k /= choose;
    curr--;
  }
  while (curr) {
    int first_choose = 0;
    for (int i = 0; i < list[curr]; i++)
      if (!used[i])
        first_choose++;
    curr--;
    ans += first_choose * k;
    choose--;
    k /= choose;
    if (used[list[curr + 1]])
      return ans;
    else
      used[list[curr + 1]] = 1;
    ;
  }
  for (int i = 0; i <= list[curr]; i++)
    if (!used[i])
      ans++;
  return ans;
}

int main() {
  printf("%d\n", countSpecialNumbers(20));  // expect: 19
  printf("%d\n", countSpecialNumbers(5));   // expect: 5
  printf("%d\n", countSpecialNumbers(135)); // expect: 110
}
