// 17. Letter Combinations of a Phone Number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string containing digits 2 - 9 inclusive, return all possible letter
 * combinations that the number could represent. return the answer in any order.
 * a mapping of digits to letters (just like on the telephone buttons) is given
 * below [see image]. note that 1 does not map to any letters.
 */

char **letterCombinations(char *digits, int *return_size) {
  int len = strlen(digits);
  if (!len) {
    *return_size = 0;
    return NULL;
  }
  char pattern[10][5] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int *order = malloc(len * sizeof(int));
  int *curr = calloc(len, sizeof(int));
  curr[0] = -1;
  int l, size = 1, i, j;
  for (i = 0; i < len; i++) {
    l = strlen(pattern[digits[i] - '0']);
    size *= l;
    order[i] = l;
  }
  char **ans = (char **)malloc(size * sizeof(char *));
  for (i = 0; i < size; i++) {
    ans[i] = malloc((len + 1) * sizeof(char));
    curr[0]++;
    int id = 0;
    while (1) {
      if (curr[id] < order[id])
        break;
      else {
        curr[id + 1]++;
        curr[id] = curr[id] % order[id];
        id++;
      }
    }
    for (j = 0; j < len; j++)
      ans[i][j] = pattern[digits[j] - '0'][curr[j]];
    ans[i][len] = '\0';
  }
  *return_size = size;
  free(order), free(curr);
  return ans;
}

int main() {
  char d1[] = {"23"}, d2[] = {""}, d3[] = {"2"};
  int rs1[] = {}, rs2[] = {}, rs3[] = {};
  char **lc1 = letterCombinations(d1, rs1);
  char **lc2 = letterCombinations(d2, rs2);
  char **lc3 = letterCombinations(d3, rs3);
  for (int i = 0; i < 9; i++)
    printf("%s ",
           lc1[i]); // expect: "ad","ae","af","bd","be","bf","cd","ce","cf"
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%s ", lc2[i]); // expect: NULL
  printf("\n");
  for (int i = 0; i < 3; i++)
    printf("%s ", lc3[i]); // expect: "a","b","c"
  printf("\n");
}
