// 554. Brick Wall
#include "leetcode.h"

/*
 * there is a rectangular brick wall in front of you with 'n' rows of bricks.
 * the i'throw has some number of bricks each of the same height (ie. one unit)
 * butthey can be of different widths. the total width of each row is the same.
 * draw a vertical line from the top to the bottom and cross the least bricks.
 * if your line goes through the edge of a brick, then the brick is not
 * considered as crossed. you cannot draw a line just along one of the two
 * vertical edges of the wall, in which case the line will obviously cross no
 * bricks. given the 2d array 'wall' that contains the information about the
 * wall, return the minimum number of cross bricks after drawing such a vertical
 * line
 */

#define MOD 1009

struct item {
  struct item *next;
  int key;
  int freq;
};

static struct item *hash[MOD];

void hash_init(void) { memset((void *)hash, 0, sizeof(hash)); }

int hash_get(int key, int *freq) {
  int idx = key % MOD;
  for (struct item *header = hash[idx]; header; header = header->next)
    if (header->key == key) {
      *freq = header->freq;
      return 0;
    }
  return -1;
}

void hash_set(int key, int freq) {
  struct item *i = (struct item *)malloc(sizeof(struct item));
  i->key = key;
  i->freq = freq;
  i->next = hash[key % MOD];
  hash[key % MOD] = i;
}

void hash_free(void) {
  for (int i = 0; i < MOD; i++)
    for (struct item *header = hash[i], *delete; header;) {
      delete = header;
      header = header->next;
      free(delete);
    }
}

int leastBricks(int **wall, int wallSize, int *wallColSize) {
  int ans = 0, freq;
  hash_init();
  for (int i = 0; i < wallSize; i++)
    for (int j = 0, end = 0; j < wallColSize[i] - 1; j++) {
      end += wall[i][j];
      if (hash_get(end, &freq) == -1)
        freq = 1;
      else
        freq++;
      hash_set(end, freq);
      if (freq > ans)
        ans = freq;
    }
  hash_free();
  return wallSize - ans;
}

int main() {
  int w1i[6][4] = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                   {2, 4},       {3, 1, 2}, {1, 3, 1, 1}},
      w2i[3][1] = {{1}, {1}, {1}};
  struct two_d_arr w1, w2;
  two_d_arr_init(&w1, 6, 4, w1i);
  two_d_arr_init(&w2, 3, 1, w2i);
  printf("%d\n", leastBricks(w1.arr, w1.row_size, w1.col_size)); // expect: 2
  printf("%d\n", leastBricks(w2.arr, w2.row_size, w2.col_size)); // expect: 3
  two_d_arr_free(&w1);
  two_d_arr_free(&w2);
}
