// 1021. Remove Outermost Parentheses
#include "leetcode.h"

/*
 * a valid parentheses string is either "", "( + A + )", or 'A + B' where 'A'
 * and 'B' re valid parentheses strings and '+' represents string concatenation.
 * a valid parentheses string 's' is pimitive if it is non empyt and there does
 * not exist a way to split it into 's = A + B' with 'A' and 'B' nonempty valid
 * parentheses strings. given a valid parentheses string 's' consider its
 * primitive decomposition. return 's' after removing the outermost parentheses
 * of every primitve string in the primitve decomposition of 's'.
 */

char *removeOuterParentheses(char *s) {
  int n = strlen(s), cnt = 0;
  char *ans = (char *)calloc(n, sizeof(char));
  for (int j = 0, i = 0; j < n; j++) {
    if (s[j] == '(')
      cnt++;
    if (s[j] == ')')
      cnt--;
    if (!cnt) {
      for (int k = i + 1, l = 0; k < j; k++)
        ans[l++] = s[k];
      i = j + 1;
    }
  }
  return ans;
}

int main() {
  char *s1 = "(()())(())", *r1 = "()()()";
  char *s2 = "(()())(())(()(()))", *r2 = "()()()()(())";
  char *s3 = "()()", *r3 = "";
  char *rop1 = removeOuterParentheses(s1);
  char *rop2 = removeOuterParentheses(s2);
  char *rop3 = removeOuterParentheses(s3);
  printf("%s\n", rop1);
  assert(!strcmp(rop1, r1));
  printf("%s\n", rop2);
  assert(!strcmp(rop2, r2));
  printf("%s\n", rop3);
  assert(!strcmp(rop3, r3));
  free(rop1);
  free(rop2);
  free(rop3);
}
