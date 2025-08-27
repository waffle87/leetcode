// 2581. Count Number of Possible Root Nodes
#include "leetcode.h"
#include <stdio.h>

bool check(int *nums, int nums_size, int k) {
  for (int i = 0; i < nums_size; i++)
    if (nums[i] == k)
      return true;
  return false;
}

void dfs(int **next, int *next_count, int **guess, int *guess_count, int from,
         int curr, int *correct) {
  for (int i = 0; i < next_count[curr]; i++) {
    if (next[curr][i] == from) {
      i++;
      while (i < next_count[curr]) {
        if (check(guess[curr], guess_count[curr], next[curr][i])) {
          *correct += 1;
        }
        dfs(next, next_count, guess, guess_count, curr, next[curr][i], correct);
        i++;
      }
    } else {
      if (check(guess[curr], guess_count[curr], next[curr][i])) {
        *correct += 1;
      }
      dfs(next, next_count, guess, guess_count, curr, next[curr][i], correct);
    }
  }
}

void change_root(int **next, int *next_count, int **guess, int *guess_count,
                 int from, int curr, int correct, int *ans) {
  for (int i = 0; i < next_count[curr]; i++) {
    if (next[curr][i] == from)
      continue;
    int count = correct;
    if (check(guess[curr], guess_count[curr], next[curr][i]))
      count--;
    if (check(guess[next[curr][i]], guess_count[next[curr][i]], curr))
      count++;
    if (count >= 0)
      (*ans)++;
    change_root(next, next_count, guess, guess_count, curr, next[curr][i],
                count, ans);
  }
}

int rootCount(int **edges, int edgesSize, int *edgesColSize, int **guesses,
              int guessesSize, int *guessesColSize, int k) {
  int m = edgesSize + 1, correct = 0, ans = 0;
  int **next = (int **)malloc(m * sizeof(int *));
  int *next_count = (int *)calloc(m, sizeof(int));
  int **guess = (int **)malloc(m * sizeof(int *));
  int *guess_count = (int *)calloc(m, sizeof(int));
  for (int i = 0; i < m; i++) {
    next[i] = malloc(sizeof(int) * 20);
    guess[i] = malloc(sizeof(int) * 20);
  }
  for (int i = 0; i < edgesSize; i++) {
    next[edges[i][0]][next_count[edges[i][0]]] = edges[i][1];
    next_count[edges[i][0]]++;
    next[edges[i][1]][next_count[edges[i][1]]] = edges[i][0];
    next_count[edges[i][1]]++;
  }
  for (int i = 0; i < guessesSize; i++) {
    guess[guesses[i][0]][guess_count[guesses[i][0]]] = guesses[i][1];
    guess_count[guesses[i][0]]++;
  }
  for (int i = 0; i < next_count[0]; i++) {
    if (check(guess[0], guess_count[0], next[0][i]))
      correct++;
    dfs(next, next_count, guess, guess_count, 0, next[0][i], &correct);
  }
  correct -= k;
  if (correct >= 0)
    ans++;
  change_root(next, next_count, guess, guess_count, -1, 0, correct, &ans);
  free(next_count), free(guess_count);
  for (int i = 0; i < m; i++)
    free(next[i]), free(guess[i]);
  free(next), free(guess);
  return ans;
}

int main() {
  int e1i[4][2] = {{0, 1}, {1, 2}, {1, 3}, {4, 2}},
      g1i[4][2] = {{1, 3}, {0, 1}, {1, 0}, {2, 4}};
  int e2i[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
      g2i[4][2] = {{1, 0}, {3, 4}, {2, 1}, {3, 2}};
  struct two_d_arr *e1 = two_d_arr_init(4, 2, e1i);
  struct two_d_arr *g1 = two_d_arr_init(4, 2, g1i);
  struct two_d_arr *e2 = two_d_arr_init(4, 2, e2i);
  struct two_d_arr *g2 = two_d_arr_init(4, 2, g2i);
  printf("%d\n", rootCount(e1->arr, e1->row_size, e1->col_size, g1->arr,
                           g1->row_size, g1->col_size, 3)); // expect: 3
  printf("%d\n", rootCount(e2->arr, e2->row_size, e2->col_size, g2->arr,
                           g2->row_size, g2->col_size, 1)); // expect: 5
  two_d_arr_free(e1);
  two_d_arr_free(g1);
  two_d_arr_free(e2);
  two_d_arr_free(g2);
}
