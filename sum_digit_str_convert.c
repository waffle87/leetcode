// 1945. Sum of Digits of String After Convert
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters, and an
 * integer 'k'. first, convert 's' into an integer by replacing each letter with
 * its position in the alphabet (ie. replace 'a' with 1, 'b' with 2, and so on).
 * then, transform the integer by replacing it with the sum of its digits.
 * repeat the transform operation 'k' times in total. return the resulting
 * integer after performing the operations described above
 */

int transform(int sum, int k) {
  int res;
  for (int i = 1; i < k; i++) {
    res = 0;
    while (sum) {
      int m = sum % 10;
      res += m;
      sum /= 10;
    }
    sum = res;
  }
  return res;
}

int getLucky(char *s, int k) {
  int n = strlen(s), arr[n], ans = 0, pos = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    char curr = s[i];
    pos = curr - 96;
    arr[i] = pos;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] <= 9)
      sum += arr[i];
    else {
      int x = arr[i] % 10, y = arr[i] / 10;
      sum += (x + y);
    }
  }
  ans = k == 1 ? sum : transform(sum, k);
  return ans;
}

int main() {
  char *s1 = "iiii", *s2 = "leetcode", *s3 = "zbax";
  printf("%d\n", getLucky(s1, 1)); // expect: 36
  printf("%d\n", getLucky(s2, 2)); // expect: 6
  printf("%d\n", getLucky(s3, 2)); // expect: 8
}
