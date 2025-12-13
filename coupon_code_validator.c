// 3606. Coupon Code Validator
#include "leetcode.h"

/*
 * you are given three arrays of length 'n' that describe the properties of 'n'
 * coupons 'code', 'businessLine', and 'isActive'. the i'th coupon has a string
 * representing the coupon identifier, a string denoting the business category
 * of the coupon, a boolean indicating if the coupon is currently active. a
 * coupon is considered valid if all of the following conditions hold: 'code[i]'
 * is non-empty and consists of only alphanumeric characters and underscores,
 * 'businessLine[i]' is one of the categories electronics, grocery, pharmacy, or
 * restaurant, and 'isActive[i]' is true. return an array of the codes of all
 * valid coupons sorted first by their 'businessLine' order.
 */

void swap_str(char **s, int i, int j) {
  char *tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}

void swap_bool(bool *arr, int i, int j) {
  bool tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

bool alphanumeric(char *s) {
  while (*s) {
    if (!isalnum(*s) && *s != '_')
      return false;
    s++;
  }
  return true;
}

bool valid_category(char *s) {
  if (strcmp(s, "electronics") && strcmp(s, "grocery") &&
      strcmp(s, "pharmacy") && strcmp(s, "restaurant"))
    return false;
  return true;
}

char **validateCoupons(char **code, int codeSize, char **businessLine,
                       int businessLineSize, bool *isActive, int isActiveSize,
                       int *returnSize) {
  char **ans = (char **)malloc(codeSize * sizeof(char *));
  *returnSize = 0;
  for (int i = 0; i < businessLineSize; i++)
    for (int j = i + 1; j < businessLineSize; j++) {
      int cmp = strcmp(businessLine[i], businessLine[j]);
      if (cmp) {
        swap_str(businessLine, i, j);
        swap_str(code, i, j);
        swap_bool(isActive, i, j);
      } else if (!cmp && strcmp(code[i], code[j])) {
        swap_str(code, i, j);
        swap_bool(isActive, i, j);
      }
    }
  for (int i = 0; i < codeSize; i++)
    if (isActive[i] && alphanumeric(code[i]) && valid_category(businessLine[i]))
      ans[(*returnSize)++] = strdup(code[i]);
  return ans;
}

int main() {
  char *c1[] = {"SAVE20", "", "PHARMA5", "SAVE@20"},
       *b1[] = {"restaurant", "grocery", "pharmacy", "restaurant"};
  char *c2[] = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"},
       *b2[] = {"grocery", "electronics", "invalid"};
  bool ia1[] = {true, true, true, true}, ia2[] = {false, true, true};
  int rs1, rs2;
  char **vc1 = validateCoupons(c1, ARRAY_SIZE(c1), b1, ARRAY_SIZE(b1), ia1,
                               ARRAY_SIZE(ia1), &rs1);
  char **vc2 = validateCoupons(c2, ARRAY_SIZE(c2), b2, ARRAY_SIZE(b2), ia2,
                               ARRAY_SIZE(ia2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", vc1[i]); // expect: PHARMA5 SAVE20
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", vc2[i]); // expect: ELECTRONICS_50
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(vc1[i]);
  free(vc1);
  for (int i = 0; i < rs2; i++)
    free(vc2[i]);
  free(vc2);
}
