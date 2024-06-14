// 6. Zigzag Conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * the string "PAYPALISHIRING" is written in zigzag pattern on a given number
 * of rows like this:
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * and then read line by line: "PAHNAPLSIIGYIR". write function that will take
 * a string and mak this conversion give a number of rows.
 */

char *convert(char *s, int numRows) {
  const int len = strlen(s);
  if (numRows == 1 || len == 1)
    return s;
  int sub_len;
  if (numRows == 2)
    sub_len = len / 2 + len % 2;
  else
    sub_len = len / (numRows - 1);
  int *id = calloc(numRows, sizeof(int));
  char **substr = malloc(numRows * sizeof(char *));
  for (int i = 0; i < numRows; i++)
    substr[i] = malloc((sub_len + 1) * sizeof(char));
  substr[0][0] = s[0];
  id[0] = 1;
  int state = 1, pos;
  while (state < len) {
    // down
    for (int i = 1; i < numRows && state < len; i++) {
      pos = id[i];
      substr[i][pos] = s[state];
      state++;
      id[i]++;
    }
    // up
    for (int i = numRows - 2; i >= 0 && state < len; i--) {
      pos = id[i];
      substr[i][pos] = s[state];
      state++;
      id[i]++;
    }
  }
  pos = 0;
  for (int i = 0; i < numRows; i++) {
    strncpy(&s[pos], substr[i], id[i]);
    pos += i;
  }
  for (int i = 0; i < numRows; i++)
    free(substr[i]);
  free(substr);
  free(id);
  return s;
}

int main() {
  char s1_2[] = "PAYPALISHIRING", s3[] = "A";
  printf("%s\n", convert(s1_2, 3)); // expect: PAHNAPLSIIGYIR
  printf("%s\n", convert(s1_2, 4)); // expect: PINALSIGYAHRPI
  printf("%s\n", convert(s3, 1));   // expect: A
}
