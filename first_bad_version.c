// 278. First Bad Version
#include "leetcode.h"

/*
 * you are a product manager and currently leading a team to develop a new
 * product. unfortunately, the latest version of your product fails the quality
 * check. since each version is developed based on the previous version, all the
 * versions after a bad version are also bad. suppose you have 'n' versions '[1,
 * ,2, ..., n]' and you want to find out the first bad one, which causes all the
 * following ones to be bad. you are given an api 'bool isBadVersion(version)'
 * which returns whether 'version' is bad. implement a function to find the
 * first bad version. you should minimise the number of calls to the api.
 */

bool isBadVersion(int version);

int firstBadVersion(int n) {
  int start = 0, end = n;
  while (end - start > 1) {
    int mid = start + (end - start) / 2;
    if (isBadVersion(mid))
      end = mid;
    else
      start = mid;
  }
  return end;
}

int main() {
  printf("%d\n", firstBadVersion(5)); // expect: 4
  printf("%d\n", firstBadVersion(1)); // expect: 1
}
