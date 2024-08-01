// 2678. Number of Senior Citizens
#include "leetcode.h"

/*
 * you are given a 0-indexed array of strings 'details'. each element of
 * 'details' provides information about a given passenger compressed into a
 * string of length '15'. the system is such that the first ten characters of
 * the phone number of passengers, the next character denotes the gender of the
 * person, the following two characters are used to indicate the age of the
 * person, and the last two characters determine the seat allotted to that
 * person. return the number of passengers who are strictly more than 60 years
 * old
 */

int countSeniors(char **details, int detailsSize) {
  int age = 0, ans = 0;
  for (int i = 0; i < detailsSize; i++) {
    age = 10 * (details[i][11] - '0') + details[i][12] - '0';
    if (age > 60)
      ans++;
  }
  return ans;
}

int main() {
  char *d1[] = {"7868190130M7522", "5303914400F9211", "9273338290F4010"},
       *d2[] = {"1313579440F2036", "2921522980M5644"};
  printf("%d\n", countSeniors((char **)d1, ARRAY_SIZE(d1))); // expect: 2
  printf("%d\n", countSeniors((char **)d2, ARRAY_SIZE(d2))); // expect: 0
}
