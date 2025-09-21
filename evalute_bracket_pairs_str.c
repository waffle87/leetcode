// 1807. Evaluate the Bracket Pairs of a String
#include "leetcode.h"

/*
 * you are given a string 's' that contains some bracket pairs, with each pair
 * containing a non-empty key. you know the values of a wide range of keys.
 * thiis represented by a 2d string array 'knowledge' where each 'knowledge[i] =
 * [key_i, value_i]' indicates that key 'key_i' has a value of 'value_i'. you
 * are tasked evaluate a bracket pair that contains some key 'key_i' you will
 * replace 'key_i' and the bracket pair with the key's corresponding 'value_i'.
 * if you do not know the value of the key you will replace 'key_i' and the
 * bracket pair with a question mark. return the resulting string after
 * evaluting all of the bracket pairs.
 */

struct hash {
  char key[16];
  char *val;
  UT_hash_handle hh;
};

char *evaluate(char *s, char ***knowledge, int knowledgeSize,
               int *knowledgeColSize) {
  struct hash *hash_table = NULL, *elim;
  for (int i = 0; i < knowledgeSize; i++) {
    elim = (struct hash *)malloc(sizeof(struct hash));
    strcpy(elim->key, knowledge[i][0]);
    elim->val = knowledge[i][1];
    HASH_ADD_STR(hash_table, key, elim);
  }
  int start_b, end_b, cursor = 0, n = strlen(s) + 1, iter = n, hash_len = 0;
  char search_key[16] = {0}, *ans = (char *)calloc(n, sizeof(char));
  for (int i = 0; i < iter; i++) {
    if (s[i] == '(') {
      start_b = i + 1;
      while (s[i] != ')')
        i++;
      end_b = i - 1;
      strncpy(search_key, &(s[start_b]), end_b - start_b + 1);
      search_key[end_b - start_b + 1] = 0;
      HASH_FIND_STR(hash_table, search_key, elim);
      if (elim) {
        hash_len = strlen(elim->val);
        if (cursor + hash_len > n) {
          n += hash_len + 1;
          ans = (char *)realloc(ans, n * sizeof(char));
        }
        strncpy(&(ans[cursor]), elim->val, hash_len);
        cursor += hash_len;
      } else
        ans[cursor++] = '?';
      continue;
    }
    ans[cursor++] = s[i];
    if (cursor + 2 > n) {
      n += n;
      ans = (char *)realloc(ans, n * sizeof(char));
    }
  }
  ans[cursor] = '\0';
  return ans;
}

int main() {
  char *s1 = "(name)is(age)yearsold",
       *k1[2][2] = {{"name", "bob"}, {"age", "two"}};
  char *s2 = "hi(name)", *k2[1][2] = {{"a", "b"}};
  char *s3 = "(a)(a)(a)aaa", *k3[1][2] = {{"a", "yes"}};
  char *e1 =
      evaluate(s1, (char ***)k1, ARRAY_SIZE(k1), (int *)ARRAY_SIZE(k1[0]));
  char *e2 =
      evaluate(s2, (char ***)k2, ARRAY_SIZE(k2), (int *)ARRAY_SIZE(k2[0]));
  char *e3 =
      evaluate(s3, (char ***)k3, ARRAY_SIZE(k3), (int *)ARRAY_SIZE(k3[0]));
  printf("%s\n", e1); // expect: bobistwoyearsold
  printf("%s\n", e2); // expect: hi?
  printf("%s\n", e3); // expect: yesyesyesaaa
  free(e1);
  free(e2);
  free(e3);
}
