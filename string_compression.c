// 443. String Compression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given array of characters 'chars', compress it using following
 * algorithm: being with empty string 's'. for each group of
 * consecutive repeating characters in 'chars': if the group's
 * length is 1, append character to 's'. otherwise, append character
 * followed by the group's length. the compressed string 's' should
 * not be returned separately, but instead, be stored in input
 * character array 'chars'. note that group lengths are 10 or longer
 * will be split into multiple characters in 'chars'. return new
 * length of array. algorithm must be contant space complexity
 */

char *int2char(int n) {
  char *res = malloc(11);
  res[10] = '\0'; // null terminate
  int idx = 9;
  while (n) {
    res[idx] = '0' + n % 10;
    n /= 10;
    idx--;
  }
  return &res[idx + 1];
}

int compress(char *chars, int charsSize) {
  int idx = 0, cnt = 1;
  char target = chars[0];
  for (int i = 1; i < charsSize; i++) {
    if (chars[i] == chars[i - 1])
      cnt++;
    else {
      chars[idx] = target;
      idx++;
      if (cnt > 1) {
        char *tmp = int2char(cnt);
        strncpy(&chars[idx], tmp, strlen(tmp));
        idx += strlen(tmp);
      }
      cnt = 1;
      target = chars[i];
    }
  }
  chars[idx] = target;
  idx++;
  if (cnt > 1) {
    char *tmp = int2char(cnt);
    strncpy(&chars[idx], tmp, strlen(tmp));
    idx += strlen(tmp);
  }
  return idx;
}

int main() {
  char c1[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  char c2[] = {'a'};
  char c3[] = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  printf("%d\n", compress(c1, 7));  // expect: ["a","2","b","2","c","3"]
  printf("%d\n", compress(c2, 1));  // expect: ["a"]
  printf("%d\n", compress(c3, 13)); // expect: ["a","b","1","2"]
}
