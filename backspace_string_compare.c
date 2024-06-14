// 844. Backspace String Compare
#include "leetcode.h"

/*
 * given two strings 's' and 't', return 'true' if they are equal when both are
 * typed into empty text editors. '#' means a backspace character. note that
 * after backspacing an empty text, the text will continue empty.
 */

char *process(char *s) {
  int idx = 0, n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[idx] = s[i];
      idx++;
      continue;
    } else if (idx)
      idx--;
  }
  s[idx] = '\0';
  return s;
}

bool backspaceCompare(char *s, char *t) {
  char *a = process(s), *b = process(t);
  int na = strlen(a), nb = strlen(b);
  if (na != nb)
    return false;
  else {
    for (int i = 0; i < na; i++)
      if (a[i] != b[i])
        return false;
  }
  return true;
}

int main() {
  char s1[] = {"ab#c"}, t1[] = {"ad#c"};
  char s2[] = {"ab##"}, t2[] = {"c#d#"};
  char s3[] = {"a#c"}, t3[] = {"b"};
  printf("%d\n", backspaceCompare(s1, t1)); // expect: 1
  printf("%d\n", backspaceCompare(s2, t2)); // expect: 1
  printf("%d\n", backspaceCompare(s3, t3)); // expect: 0
}
