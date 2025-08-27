// 3342. Find Minimum Time to Reach Last Room II
#include "leetcode.h"

/*
 * there is a dungeon with 'n x m' rooms arranged as a grid. you are given a 2d
 * array 'moveTime' of size 'n x m' where 'moveTime[i][j]' represents the
 * minimum time in seconds when you can start moving to that room. you start
 * from the room '(0, 0)' at time 't = 0' and can move to an adjacent room.
 * moving between adjacent rooms takes one second for one move and two seconds
 * for the next, alternating between the two. return the minimum time to reach
 * the room '(n - 1, m - 1)'.
 */

#define VIS 0x80000000
#define MASK 0x7FFFFFFF

struct grid {
  int row;
  int col;
};

void heap_down(struct grid *start, struct grid *end, struct grid *curr,
               int **moveTime) {
  struct grid *child = 1 + start + ((curr - start) << 1);
  if (child <= end) {
    if (child < end) {
      struct grid *next = child + 1;
      if ((MASK & moveTime[child->row][child->col]) <
          (MASK & moveTime[curr->row][curr->col]))
        child++;
    }
    if ((MASK & moveTime[child->row][child->col]) <
        (MASK & moveTime[curr->row][curr->col])) {
      child->col ^= curr->col;
      curr->col ^= child->col;
      child->col ^= curr->col;
      child->row ^= curr->row;
      curr->row ^= child->row;
      child->row ^= curr->row;
      heap_down(start, end, child, moveTime);
    }
  }
}

void heap_up(struct grid *start, struct grid *curr, int **moveTime) {
  if (start < curr) {
    struct grid *parent = start + ((curr - 1 - start) >> 1);
    if ((MASK & moveTime[curr->row][curr->col]) <
        (MASK & moveTime[parent->row][parent->col])) {
      curr->col ^= parent->col;
      parent->col ^= curr->col;
      curr->col ^= parent->col;
      curr->row ^= parent->row;
      parent->row ^= curr->row;
      curr->row ^= parent->row;
      heap_up(start, parent, moveTime);
    }
  }
}

int minTimeToReach(int **moveTime, int moveTimeSize, int *moveTimeColSize) {
  struct grid ast[moveTimeSize * (*moveTimeColSize)], *pst = ast;
  pst->col = 0;
  (pst++)->row = 0;
  moveTime[0][0] = VIS;
  int ans = 0;
  int n = moveTimeSize - 1, m = *moveTimeColSize - 1;
  while (ast < pst) {
    char move = (ast->col + ast->row) % 2 ? 2 : 1;
    int time = MASK & moveTime[ast->row][ast->col];
    if (ast->row) {
      int next = ast->row - 1, *curr = ast->col + moveTime[next];
      if (0 <= *curr) {
        if (time > *curr)
          *curr = time;
        *curr += move;
        *curr |= VIS;
        pst->col = ast->col;
        pst->row = next;
        heap_up(ast, pst++, moveTime);
      }
    }
    if (ast->col) {
      int next = ast->col - 1, *curr = next + moveTime[ast->row];
      if (0 <= *curr) {
        if (time > *curr)
          *curr = time;
        *curr += move;
        *curr |= VIS;
        pst->col = next;
        pst->row = ast->row;
        heap_up(ast, pst++, moveTime);
      }
    }
    if (m > ast->col) {
      int next = ast->col + 1, *curr = next + moveTime[ast->row];
      if (0 <= *curr) {
        if (time > *curr)
          *curr = time;
        *curr += move;
        if (m == next && n == ast->row) {
          ans = *curr;
          break;
        }
        *curr |= VIS;
        pst->col = next;
        pst->row = ast->row;
        heap_up(ast, pst++, moveTime);
      }
    }
    if (n > ast->row) {
      int next = ast->row + 1, *curr = ast->col + moveTime[next];
      if (0 <= *curr) {
        if (time > *curr)
          *curr = time;
        *curr += move;
        if (n == next && m == ast->col) {
          ans = *curr;
          break;
        }
        *curr |= VIS;
        pst->col = ast->col;
        pst->row = next;
        heap_up(ast, pst++, moveTime);
      }
    }
    ast->col = (--pst)->col;
    ast->row = pst->row;
    heap_down(ast, pst - 1, ast, moveTime);
  }
  return ans;
}

int main() {
  int mt1i[2][2] = {{0, 4}, {4, 4}}, mt2i[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}},
      mt3i[2][2] = {{0, 1}, {1, 2}};
  struct two_d_arr *mt1 =
      two_d_arr_init(ARRAY_SIZE(mt1i), ARRAY_SIZE(mt1i[0]), mt1i);
  struct two_d_arr *mt2 =
      two_d_arr_init(ARRAY_SIZE(mt2i), ARRAY_SIZE(mt2i[0]), mt2i);
  struct two_d_arr *mt3 =
      two_d_arr_init(ARRAY_SIZE(mt3i), ARRAY_SIZE(mt3i[0]), mt3i);
  printf("%d\n",
         minTimeToReach(mt1->arr, mt1->row_size, mt1->col_size)); // expect: 7
  printf("%d\n",
         minTimeToReach(mt2->arr, mt2->row_size, mt2->col_size)); // expect: 6
  printf("%d\n",
         minTimeToReach(mt3->arr, mt3->row_size, mt3->col_size)); // expect: 4
  two_d_arr_free(mt1);
  two_d_arr_free(mt2);
  two_d_arr_free(mt3);
}
