// 1138. Alphabet Board Path
#include <stdio.h>
#include <stdlib.h>

/*
 * on an alphabet board, we start position [0,0], corresponding to character
 * 'board[0][0]'. here, 'board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy",
 * "z"]' as show in the diagram (see page). return a sequence of moves that
 * makes our answer equal to 'target' in the minimum numbe of moves. (in any
 * order/path)
 */

char *alphabetBoardPath(char *target) {
  char map[26][2] = {0};
  int i;
  for (i = 0; i < 26; i++) {
    map[i][0] = i % 5;
    map[i][1] = i / 5;
  }
  char *curr, *prev;
  curr = "a";
  prev = target;
  char *ans = (char *)malloc(100 * sizeof(char));
  int ans_size = 100;
  i = 0;
  while (*prev) {
    if (ans_size - i < 11) {
      ans_size += 11;
      char *new_ans = (char *)realloc(ans, ans_size * sizeof(char));
      if (new_ans)
        ans = new_ans;
    }
    int j = (int)(*prev) - (int)('a');
    int k = (int)(*curr) - (int)('a');
    int dx = map[j][0] - map[k][0];
    int dy = map[j][1] - map[k][1];
    if (dx < 0)
      while (dx) {
        ans[i++] = 'L';
        dx++;
      }
    if (dy > 0)
      while (dy) {
        ans[i++] = 'D';
        dy--;
      }
    if (dy < 0)
      while (dy) {
        ans[i++] = 'U';
        dy++;
      }
    if (dx > 0)
      while (dx) {
        ans[i++] = 'R';
        dx--;
      }
    ans[i++] = '!';
    curr = prev;
    prev++;
  }
  ans[i] = '\0';
  return ans;
}

int main() {
  char *t1 = "leet";
  char *t2 = "code";
  printf("%s\n", alphabetBoardPath(t1)); // expect: DDR!UURRR!!DDD!
  printf("%s\n", alphabetBoardPath(t2)); // expect: RR!DDRR!UUL!R!
}
