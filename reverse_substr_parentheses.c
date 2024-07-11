// 1190. Reverse Substrings Between Each Pair of Parentheses
#include "leetcode.h"

/*
 * you are given a string 's' that consists of lower case english letters and
 * brackets. reverse the strings in each pair of matching parentheses, starting
 * from the innermost one. your result should not contain any brackets.
 */

struct node {
  int index;
  struct node *next;
};

void qpush(struct node **top, int idx) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->index = idx;
  n->next = NULL;
  if (!(*top)) {
    *top = n;
    return;
  }
  n->next = *top;
  *top = n;
  return;
}

int qpop(struct node **top) {
  if (!(*top))
    return 0;
  int x = (*top)->index;
  *top = (*top)->next;
  return x;
}

char *reverseParentheses(char *s) {
  if (!s)
    return "";
  struct node *top = NULL;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(')
      qpush(&top, i);
    else if (s[i] == ')') {
      int beg = qpop(&top), end = i - 1;
      s[beg] = ' ';
      beg++;
      while (beg < end) {
        char c = s[beg];
        s[beg] = s[end];
        s[end] = c;
        beg++, end--;
      }
      s[i] = ' ';
    }
  }
  int j = 0;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] != ' ')
      s[j++] = s[i];
  s[j] = '\0';
  return s;
}

int main() {
  char s1[] = "(abcd)", s2[] = "(u(love)i)", s3[] = "(ed(et(oc))el)";
  printf("%s\n", reverseParentheses(s1)); // expect: dcba
  printf("%s\n", reverseParentheses(s2)); // expect: iloveu
  printf("%s\n", reverseParentheses(s3)); // expect: leetcode
}
