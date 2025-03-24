// 394. Decode String
#include "leetcode.h"

/*
 * given an encoded string, return its decoded string. the encoding rule is
 * 'k[encoded_string]' where the 'encoded_string' inside the square brackets is
 * being repeated exactly 'k' times. note that 'k' is guaranteed to be a
 * positive integer. you may assume that the input string is always valid; there
 * are no extra white spaces, square brackets are well-formed, etc. furthermore,
 * you may assume that the original data does not contain any digits, and that
 * digits are only for those repeat numbers, 'k'. the test cases are generated
 * such that the output will never exceed '10^5'.
 */

struct node_time {
  int times;
  struct node_time *next;
};

struct node_char {
  char c;
  struct node_char *next;
};

void push_int(struct node_time **head, int val) {
  struct node_time *new = (struct node_time *)malloc(sizeof(struct node_time));
  new->times = val;
  new->next = *head;
  *head = new;
}

void push_char(struct node_char **head, char c) {
  struct node_char *new = (struct node_char *)malloc(sizeof(struct node_char));
  new->c = c;
  new->next = *head;
  *head = new;
}

int pop_int(struct node_time **head) {
  struct node_time *tmp = *head;
  int res = tmp->times;
  *head = (*head)->next;
  free(tmp);
  return res;
}

char pop_char(struct node_char **head) {
  struct node_char *tmp = *head;
  char res = tmp->c;
  *head = (*head)->next;
  free(tmp);
  return res;
}

int word_size(struct node_char *head) {
  int n = 0;
  while (head) {
    if (head->c == '[')
      break;
    n++;
    head = head->next;
  }
  return n;
}

char *decodeString(char *s) {
  struct node_time *int_stk = NULL;
  struct node_char *char_stk = NULL;
  int i = 0, n, k;
  while (s[i]) {
    if (s[i] >= '0' && s[i] <= '9') {
      int num = atoi(&s[i]);
      while (s[i] >= '0' && s[i] <= '9')
        i++;
      push_int(&int_stk, num);
    } else if (s[i] > '9' && s[i] != ']') {
      push_char(&char_stk, s[i]);
      i++;
    } else if (s[i] == '[') {
      push_char(&char_stk, '[');
      i++;
    } else if (s[i] == ']') {
      n = word_size(char_stk);
      int times = pop_int(&int_stk);
      char *word = (char *)malloc(n * sizeof(char));
      for (k = 0; k < n; k++)
        word[k] = pop_char(&char_stk);
      pop_char(&char_stk);
      for (; times; times--)
        for (k = n - 1; k >= 0; k--)
          push_char(&char_stk, word[k]);
      free(word);
      i++;
    }
  }
  n = word_size(char_stk);
  char *ans = (char *)calloc(n + 1, sizeof(char));
  for (k = n - 1; k >= 0; k--)
    ans[k] = pop_char(&char_stk);
  return ans;
}

int main() {
  char *s1 = "3[a]2[bc]", *s2 = "3[a2[c]]", *s3 = "2[abc]3[cd]ef";
  char *ds1 = decodeString(s1);
  char *ds2 = decodeString(s2);
  char *ds3 = decodeString(s3);
  printf("%s\n", ds1); // expect: aaabcbc
  printf("%s\n", ds2); // expect: accaccacc
  printf("%s\n", ds2); // expect: abcabccdcdcdef
  free(ds1);
  free(ds2);
  free(ds3);
}
