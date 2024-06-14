// 38. Count and Say
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * the count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * - countAndSay(1) = "1"
 * - countAndSay(n) is the way you would "say" the digit string from
 * 'countAndSay(n - 1)', which is then converted into a different digit string
 * to determine how you "say" a digit string, split it into minimal number of
 * substrings such that each substring contains exactly one unique digit. then
 * for each substring, say the number of digits, then say the digit, finally,
 * concatenate every said digit. given a positive integer 'n', return the n'th
 * term of the count and say sequence.
 */

char *int_to_char(int n) {
  char *res = malloc(11);
  res[10] = '\0';
  int idx = 9;
  while (n) {
    res[idx] = '0' + n % 10;
    n /= 10;
    idx--;
  }
  return &res[idx + 1];
}

char *countAndSay(int n) {
  char *curr = malloc(5000), *post = malloc(5000);
  curr[0] = '1';
  curr[1] = '\0';
  if (n == 1)
    return curr;
  for (int i = 2; i <= n; i++) {
    int curr_len = strlen(curr), idx = 0, cnt = 1, pos = 0;
    char *tmp;
    for (int j = 1; j < curr_len; j++) {
      if (curr[j] == curr[j - 1])
        cnt++;
      else {
        tmp = int_to_char(cnt);
        strncpy(&post[pos], tmp, strlen(tmp));
        pos += strlen(tmp);
        post[pos] = curr[j - 1];
        pos++;
        cnt = 1;
      }
    }
    tmp = int_to_char(cnt);
    strncpy(&post[pos], tmp, strlen(tmp));
    pos += strlen(tmp);
    post[pos] = curr[curr_len - 1];
    pos++;
    post[pos] = '\0';
    tmp = curr;
    curr = post;
    post = tmp;
  }
  return curr;
}

int main() {
  printf("%s\n", countAndSay(1)); // expect: 1
  printf("%s\n", countAndSay(4)); // expect: 1211
}
