// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool winnerOfGame(char *colours) {
  int n = strlen(colours);
  int grpa = 0, grpb = 0, cnt = 1;
  for (int i = 1; i < n; i++) {
    if (colours[i] == colours[i - 1])
      cnt++;
    else {
      if (cnt > 2) {
        if (colours[i - 1] == 'A')
          grpa += cnt - 2;
        else
          grpb += cnt - 2;
      }
      cnt = 1;
    }
  }
  if (cnt > 2) {
    if (colours[n - 1] == 'A')
      grpa += cnt - 2;
    else
      grpb += cnt - 2;
  }
  return grpa > grpb;
}

int main() {
  char c1[] = {"AAABABB"}, c2[] = {"AA"}, c3[] = {"ABBBBBBBAAA"};
  printf("%d\n", winnerOfGame(c1)); // expect: 1
  printf("%d\n", winnerOfGame(c2)); // expect: 0
  printf("%d\n", winnerOfGame(c3)); // expect: 0
}
