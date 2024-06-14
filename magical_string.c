// 481. Magical String
#include <stdio.h>
#include <stdlib.h>

/*
 * a magical string 's' consists of only '1' & '2' and obeys the following rules
 * the string 's' is magical because concatenating the number of contiguous
 * occurences of characters '1' & '2' generates the string 's' itself. given
 * integer 'n', return the number of 1's in the first 'n' number in the magical
 * string 's'.
 */

int magicalString(int n) {
  char *s = malloc(sizeof(char) * (n + 1));
  s[0] = '1';
  s[1] = '2';
  s[2] = '2';
  int i = 2, cnt = 0, k = i;
  while (k < n - 1) {
    int c_i = s[i] - '0';
    char ch = s[k];
    for (int j = 0; j < c_i; j++) {
      s[k + 1] = ch ^ 3;
      k++;
    }
    i++;
  }
  s[k + 1] = '\0';
  for (i = 0; i < n; i++)
    if (s[i] == '1')
      cnt++;
  return cnt;
}

int main() {
  printf("%d\n", magicalString(6)); // expect: 3
  printf("%d\n", magicalString(1)); // expect: 1
}
