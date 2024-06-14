// 2129. Capitalize the Title
#include "leetcode.h"

/*
 * given a string 'title' consisting of one or more words separated by a single
 * space. where each word consists of english letters. capitalise the string by
 * changing the capitalisation of each word such that if the length of the word
 * is 1 or 2 letters, change all letters to lowercase. otherwise,change the
 * first letter to uppercase and the remaining letters to lowercase. return the
 * capitalised title.
 */

void process(char *dest, char *src) {
  int n = strlen(src);
  if (n < 3)
    for (int i = 0; i < n; i++)
      dest[i] = tolower(src[i]);
  else {
    dest[0] = toupper(src[0]);
    for (int i = 1; i < n; i++)
      dest[i] = tolower(src[i]);
  }
}

char *capitalizeTitle(char *title) {
  int n = strlen(title), begin = 0;
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  ans[n] = '\0';
  for (int i = 0; i < n; i++)
    if (title[i] == ' ') {
      title[i] = '\0';
      process(&ans[begin], &title[begin]);
      ans[i] = ' ';
      begin = i + 1;
    }
  process(&ans[begin], &title[begin]);
  return ans;
}

int main() {
  char *t1 = "capiTalIze tHe titLe", *t2 = "First leTTeR of EACH Word",
       *t3 = "i lOve leetcode";
  char *ct1 = capitalizeTitle(t1);
}
