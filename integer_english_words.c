// 273. Integer to English Words
#include "leetcode.h"

/*
 * convert a non-negative integer 'num' to its english words represetation.
 */

const char *below_twenty[] = {"",        "One",       "Two",      "Three",
                              "Four",    "Five",      "Six",      "Seven",
                              "Eight",   "Nine",      "Ten",      "Eleven",
                              "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char *tens[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                      "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char *thousands[] = {"", "Thousand", "Million", "Billion"};

char *helper(int num) {
  char *res = (char *)calloc(100, sizeof(char));
  if (!num)
    return "";
  else if (num < 20)
    strcat(res, below_twenty[num]);
  else if (num < 100) {
    strcat(res, tens[num / 10]);
    if (num % 10)
      strcat(res, " ");
    strcat(res, helper(num % 10));
  } else {
    strcat(res, below_twenty[num / 100]);
    strcat(res, " Hundred");
    if (num % 100)
      strcat(res, " ");
    strcat(res, helper(num % 100));
  }
  return res;
}

char *numberToWords(int num) {
  if (!num)
    return "Zero";
  char *ans = (char *)calloc(100, sizeof(char));
  int i = 0;
  while (num) {
    if (num % 1000) {
      char *seg = helper(num % 1000);
      if (i)
        strcat(seg, " ");
      strcat(seg, thousands[i]);
      if (strlen(ans))
        strcat(seg, " ");
      strcat(seg, ans);
      strcpy(ans, seg);
      free(seg);
    }
    num /= 1000;
    i++;
  }
  return ans;
}

int main() {
  printf("%s\n", numberToWords(123)); // expect: One Hundred Twenty Three
  printf(
      "%s\n",
      numberToWords(12345)); // expect: Twelve Thousand Three Hundred Forty Five
  printf("%s\n",
         numberToWords(1234567)); // expect: One Million Two Hundred Thirty Four
                                  // Thousand Five Hundred Sixty Seven
}
