// 1399. Count Largest Group
#include "leetcode.h"

/*
 * you are given an integer 'n'. each number from 1 to 'n' is grouped according
 * to the sum of its digits. return the number of groups that have the largest
 * size.
 */

int get_num(int n) {
  int res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int countLargestGroup(int n) {
  int arr[37] = {0}, max = 0;
  for (int i = 1; i <= n; i++) {
    int curr = get_num(i);
    arr[curr]++;
    if (arr[curr] > max)
      max = arr[curr];
  }
  int cnt = 0;
  for (int i = 1; i <= 36; i++)
    if (arr[i] == max)
      cnt++;
  return cnt;
}

int main() {
  printf("%d\n", countLargestGroup(13)); // expect: 4
  printf("%d\n", countLargestGroup(2));  // expect: 2
}
