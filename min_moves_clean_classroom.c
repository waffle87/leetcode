// 3568. Minimum Moves to Clean the Classroom
#include "leetcode.h"

/*
 * you are given an 'm x n' grid 'classroom' where a student volunteer is taked
 * with cleaning up litter scattered around the room. each cell in the grid is
 * one of the following: 'S': starting position, 'L': litter that must be
 * collected, 'R': reset area that restores the student's energy to full, 'X':
 * obstacle that the student cannot pass through, and '.': empty space. you are
 * also given an integer 'energy' representing the student's maximum energy
 * capacity. the student starts with this energy from the starting position 'S'.
 * each move to an adjacent cell costs 1 unit of energy. return the minimum
 * number of moves requiresto collect all litter items, or -1 if it is
 * impossible.
 */

struct state {
  int r;
  int c;
  int mask;
  int energy;
  int moves;
};

int minMoves(char **classroom, int classroomSize, int energy) {
  int m = classroomSize, n = strlen(classroom[0]);
  int **litter_id = (int **)malloc(m * sizeof(int *));
  for (int r = 0; r < m; r++) {
    litter_id[r] = (int *)malloc(n * sizeof(int));
    for (int c = 0; c < n; c++)
      litter_id[r][r] = -1;
  }
  int k = 0, sr = 0, sc = 0;
  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      if (classroom[r][c] == 'S') {
        sr = r;
        sc = c;
      } else if (classroom[r][c] == 'L')
        litter_id[r][c] = k++;
    }
  }
  if (!k) {
    for (int r = 0; r < m; r++)
      free(litter_id[r]);
    free(litter_id);
    return 0;
  }
  int mask = 1 << k, full_mask = mask - 1;
  int ***best = (int ***)malloc(m * sizeof(int **));
  for (int r = 0; r < m; r++) {
    best[r] = (int **)malloc(n * sizeof(int *));
    for (int c = 0; c < n; c++) {
      best[r][c] = (int *)malloc(mask * sizeof(int));
      for (int m = 0; m < mask; m++)
        best[r][c][m] = -1;
    }
  }
  int capacity = 1024, front = 0, back = 0;
  struct state *queue = (struct state *)malloc(capacity * sizeof(struct state));
  best[sr][sc][0] = energy;
  queue[back++] = (struct state){sr, sc, 0, energy, 0};
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (front < back) {
    struct state curr = queue[front++];
    for (int d = 0; d < 4; d++) {
      int nr = curr.r + dirs[d][0];
      int nc = curr.c + dirs[d][1];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n)
        continue;
      if (classroom[nr][nc] == 'X')
        continue;
      int ne = curr.energy - 1;
      if (ne < 0)
        continue;
      int nm = curr.mask;
      if (classroom[nr][nc] == 'R')
        ne = energy;
      if (classroom[nr][nc] == 'L')
        nm |= 1 << litter_id[nr][nc];
      if (nm == full_mask) {
        for (int r = 0; r < m; r++) {
          for (int c = 0; c < n; c++)
            free(best[r][c]);
          free(best[r]);
          free(litter_id[r]);
        }
        free(best);
        free(litter_id);
        free(queue);
        return curr.moves + 1;
      }
      if (ne <= best[nr][nc][nm])
        continue;
      best[nr][nc][nm] = ne;
      if (back == capacity) {
        capacity *= 2;
        queue = (struct state *)realloc(queue, capacity * sizeof(struct state));
      }
      queue[back++] = (struct state){nr, nc, nm, ne, curr.moves + 1};
    }
  }
  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++)
      free(best[r][c]);
    free(best[r]);
    free(litter_id[r]);
  }
  free(best);
  free(litter_id);
  free(queue);
  return -1;
}

int main() {
  char *c1[] = {"S.", "XL"};
  char *c2[] = {"LS", "RL"};
  char *c3[] = {"L.S", "RXL"};
  int r1 = minMoves(c1, ARRAY_SIZE(c1), 2);
  int r2 = minMoves(c2, ARRAY_SIZE(c2), 4);
  int r3 = minMoves(c3, ARRAY_SIZE(c3), 3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == -1);
}
