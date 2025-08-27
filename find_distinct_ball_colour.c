// 3160. Find the Number of Distinct Colors Among the Balls
#include "leetcode.h"

/*
 * you are given an integer 'limit' and a 2d array 'queries' of size 'n x 2'.
 * there are 'limit + 1' balls with distinct labels in the range '[0, limit]'.
 * initially, all balls are uncoloured. for every query in 'queries' that is of
 * the form '[x, y]', you makr ball 'x' with the colour 'y'. after each query,
 * you need to find the number of distinct colours among the balls. return an
 * array 'result' of length 'n' where 'result[i]' denotes the number of distinct
 * colours after the i'th query.
 */

#define MOD 1009

struct item {
  int colour;
  int freq;
  struct item *next;
};

struct ball {
  int id;
  int colour;
  struct ball *next;
};

struct item *hash[MOD];
struct ball *ball[MOD];

void ball_init(void) { memset((void *)ball, 0, sizeof(ball)); }

void ball_set(int id, int colour) {
  int key = id % MOD;
  for (struct ball *header = ball[key]; header; header = header->next)
    if (header->id == id) {
      header->colour = colour;
      return;
    }
  struct ball *new = (struct ball *)malloc(sizeof(struct ball));
  new->id = id;
  new->colour = colour;
  new->next = ball[key];
  ball[key] = new;
}

int ball_get(int id, int *colour) {
  int key = id % MOD;
  for (struct ball *header = ball[key]; header; header = header->next)
    if (header->id == id) {
      *colour = header->colour;
      return 0;
    }
  return -1;
}

void ball_free(void) {
  for (int i = 0; i < MOD; i++)
    for (struct ball *header = ball[i], *del; header;) {
      del = header;
      header = header->next;
      free(del);
    }
}

void hash_init() { memset((void *)hash, 0, sizeof(hash)); }

int hash_get(int colour, int *freq) {
  int key = colour % MOD;
  for (struct item *header = hash[key]; header; header = header->next)
    if (header->colour == colour) {
      *freq = header->freq;
      return 0;
    }
  return -1;
}

void hash_set(int colour, int freq) {
  int key = colour % MOD;
  for (struct item *header = hash[key]; header; header = header->next)
    if (header->colour == colour) {
      header->freq = freq;
      return;
    }
  struct item *new = (struct item *)malloc(sizeof(struct item));
  new->colour = colour;
  new->freq = freq;
  new->next = hash[key];
  hash[key] = new;
}

void hash_free(void) {
  for (int i = 0; i < MOD; i++)
    for (struct item *header = hash[i], *del; header;) {
      del = header;
      header = header->next;
      free(del);
    }
}

int *queryResults(int limit, int **queries, int queriesSize,
                  int *queriesColSize, int *returnSize) {
  int distinct = 0, *ans = (int *)malloc(queriesSize * sizeof(int));
  hash_init();
  ball_init();
  for (int i = 0; i < queriesSize; i++) {
    int freq, ball_colour = 0;
    ball_get(queries[i][0], &ball_colour);
    if (ball_colour) {
      hash_get(ball_colour, &freq);
      freq--;
      hash_set(ball_colour, freq);
      if (!freq)
        distinct--;
    }
    ball_set(queries[i][0], queries[i][1]);
    freq = 0;
    hash_get(queries[i][1], &freq);
    freq++;
    if (freq == 1)
      distinct++;
    hash_set(queries[i][1], freq);
    ans[i] = distinct;
  }
  hash_free();
  ball_free();
  *returnSize = queriesSize;
  return ans;
}

int main() {
  int q1i[4][2] = {{1, 4}, {2, 5}, {1, 3}, {3, 4}}, rs1;
  int q2i[5][2] = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}}, rs2;
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int *qr1 = queryResults(4, q1->arr, q1->row_size, q1->col_size, &rs1);
  int *qr2 = queryResults(4, q2->arr, q2->row_size, q2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", qr1[i]); // expect: 1 2 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", qr2[i]); // expect: 1 2 2 3 4
  printf("\n");
  free(qr1);
  free(qr2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
