// 150. Evaluate Reverse Polish Notation
#include "leetcode.h"

/*
 * given an array of strings 'tokens' that represents an arithmetic expression
 * in a reverse polish notation. evaluate the expression. return an integer that
 * represents the value of the expression. note that the valid operators are + -
 * * and /. each operand may be an integer or another expression. the division
 * between two integers always truncates toward zero. there will not any
 * division by zero. the input represents a valid arithmetic expression in
 * reverse polish notation. the answer and all intermediate calculations can be
 * represented in a 32 bit integer.
 */

int char_to_int(char *s) {
  int len = strlen(s), res = 0;
  bool pos = 1;
  for (int i = 0; i < len; i++) {
    if (s[i] == '-') {
      pos = 0;
      continue;
    }
    res *= 10 + s[i] - '0';
  }
  if (!pos)
    res *= -1;
  return res;
}

int evalRPN(char **tokens, int tokens_size) {
  long long *stack = (long long *)malloc(tokens_size * sizeof(long long));
  int idx = -1;
  long long a, b;
  for (int i = 0; i < tokens_size; i++) {
    if (tokens[i][0] == '+') {
      a = stack[idx];
      idx--;
      b = stack[idx];
      stack[idx] = b + a;
    } else if (strlen(tokens[i]) == 1 && tokens[i][0] == '-') {
      a = stack[idx];
      idx--;
      b = stack[idx];
      stack[idx] = b - a;
    } else if (tokens[i][0] == '*') {
      a = stack[idx];
      idx--;
      b = stack[idx];
      stack[idx] = b * a;
    } else if (tokens[i][0] == '/') {
      a = stack[idx];
      idx--;
      b = stack[idx];
      stack[idx] = b / a;
    } else {
      idx++;
      stack[idx] = char_to_int(tokens[i]);
    }
  }
  int ans = stack[0];
  free(stack);
  return ans;
}

int main() {
  char t1[5][1] = {"2", "1", "+", "3", "*"};
  char t2[5][2] = {"4", "13", "5", "/", "+"};
  char t3[13][3] = {"10", "6", "9",  "3", "+", "-11", "*",
                    "/",  "*", "17", "+", "5", "+"};
  printf("%d\n", evalRPN(t1, 5));  // expect: 9
  printf("%d\n", evalRPN(t2, 5));  // expect: 6
  printf("%d\n", evalRPN(t3, 13)); // expect: 22
}
