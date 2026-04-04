// 2075. Decode the Slanted Ciphertext
#include "leetcode.h"

/*
 * a string 'originalText' is encoded using a slanted transposition cipher to a
 * string 'encodedText' with the help of a matrix having a fixed number of
 * 'rows'. given the encoded string 'encodedText' and a numbe of rows, return
 * the original string 'originalText'.
 */

char *decodeCiphertext(char *encodedText, int rows) {
  if (rows == 1)
    return strdup(encodedText);
  int n = strlen(encodedText), cols = n / rows, idx = 0;
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  for (int c = 0; c < cols; c++) {
    int r = 0, j = c;
    while (r < rows && j < cols) {
      ans[idx++] = encodedText[r * cols + j];
      r++;
      j++;
    }
  }
  while (idx > 0 && ans[idx - 1] == ' ')
    idx--;
  ans[idx] = '\0';
  return ans;
}

int main() {
  char *et1 = "ch   ie   pr";
  char *et2 = "iveo    eed   l te   olc";
  char *et3 = "coding";
  char *dc1 = decodeCiphertext(et1, 3);
  char *dc2 = decodeCiphertext(et2, 4);
  char *dc3 = decodeCiphertext(et3, 1);
  printf("%s\n", dc1);
  assert(!strcmp(dc1, "cipher"));
  printf("%s\n", dc2);
  assert(!strcmp(dc2, "i love leetcode"));
  printf("%s\n", dc3);
  assert(!strcmp(dc3, "coding"));
  free(dc1);
  free(dc2);
  free(dc3);
}
