// 2088. Count Fertile Pyramids in a Land
#include "leetcode.h"

#pragma GCC optimize("03")
#pragma GCC target("avx2")

/*
 * a farmer has a rectangular grid of land with 'm' rows and 'n' columns that
 * can be divided into unit cells. each cell is either fertile (represented by a
 * 1) or barren (represented by a 0). all cells outside the grid are considered
 * barren. a pyamidal plot of land can be defined as a set of cells with the
 * following criteria: the number of cells in the set has to be greater than 1
 * and all cells must be fertile, and the apex of the pyramid is the topmost
 * cell of the pyramid. the height of a pyramid is the number of rows it covers.
 * let '(r, c)' be the apex of the pyramid and its height be 'h'. given a
 * 0-indexed 'm x n' binary matrix 'grid' representing the farmland, return the
 * total number of pyramidal and inverse pyramidal plots that can be found in
 * 'grid'.
 */

uint32_t rows = 0, cols = 0;

typedef struct __attribute__((packed, aligned(32))) {
  uint64_t data[16 * 1024];
} bit_plane;

static inline void bit_plane_and(bit_plane *dest, const bit_plane *restrict s1,
                                 const bit_plane *restrict s2) {
  for (uint32_t r = 0; r < rows; r++)
    for (uint32_t c = 0; c < cols; c += 4) {
      uint32_t idx = r * 16 + c;
      dest->data[idx] = s1->data[idx] & s2->data[idx];
      dest->data[idx + 1] = s1->data[idx + 1] & s2->data[idx + 1];
      dest->data[idx + 2] = s1->data[idx + 2] & s2->data[idx + 2];
      dest->data[idx + 3] = s1->data[idx + 3] & s2->data[idx + 3];
    }
}

static inline void bit_plane_shift_r(bit_plane *dest,
                                     const bit_plane *restrict s1,
                                     uint32_t steps) {
  for (uint32_t r = 0; r < rows; r++)
    for (uint32_t c = 0; c < rows; c++) {
      uint32_t idx = r * 16 + c;
      dest->data[idx] =
          (s1->data[idx] >> steps) | (s1->data[idx + 1] << (64 - steps));
    }
}

static inline void bit_plane_shift_l(bit_plane *dest,
                                     const bit_plane *restrict s1,
                                     uint32_t steps) {
  dest->data[0] = s1->data[0] << steps;
  for (uint32_t c = 1; c < cols; c++)
    dest->data[c] = (s1->data[c] << steps) | (s1->data[c - 1] >> (64 - steps));
  for (uint32_t r = 1; r < rows; r++)
    for (uint32_t c = 0; c < cols; c++) {
      uint32_t idx = r * 16 + c;
      dest->data[idx] =
          (s1->data[idx] << steps) | (s1->data[idx - 1] >> (64 - steps));
    }
}

static inline void bit_plane_shift_u(bit_plane *restrict dest,
                                     const bit_plane *restrict src,
                                     uint32_t steps) {
  __builtin_memcpy(dest->data, src->data + steps * 16,
                   16 * (rows - steps) * sizeof(uint64_t));
  __builtin_memset(dest->data + (rows - steps) * 16, 0, steps * 16);
}

static inline void bit_plane_shift_d(bit_plane *restrict dest,
                                     const bit_plane *restrict src,
                                     uint32_t steps) {
  __builtin_memset(dest->data, 0, steps * 16);
  __builtin_memcpy(dest->data + steps * 16, src->data,
                   16 * (rows - steps) * sizeof(uint64_t));
}

static inline uint32_t bit_plane_popcount(const bit_plane *self) {
  uint32_t sum = 0;
  for (uint32_t r = 0; r < rows; r++)
    for (uint32_t c = 0; c <= ((cols - 1) >> 6); c++)
      sum += __builtin_popcountll(self->data[r * 16 + c]);
  return sum;
}

void bit_plane_print(const bit_plane *b) {
  for (uint32_t r = 0; r < rows; r++) {
    for (uint32_t c = (cols - 1) >> 6; ~c; c--)
      printf("%064lb", b->data[r * 16 + c]);
    printf("\n");
  }
}

int countPyramids(int **grid, int gridSize, int *gridColSize) {
  cols = *gridColSize;
  rows = gridSize;
  bit_plane org[1] = {0};
  for (uint32_t r = 0; r < rows; r++)
    for (uint32_t c = 0; c < cols; c++)
      org->data[r * 16U + (c >> 6U)] = (uint64_t)grid[r][c] << (c & 0x3F);
  bit_plane curr[1] = {org[0]}, shr[1] = {0}, shu[1] = {0}, shd[1] = {0},
            shl[1] = {0}, tmpl[1] = {0}, tmpr[1] = {0}, mid[1] = {0};
  uint32_t cnt = 0, sqr = -1;
  for (uint32_t i = 1; sqr && i < fmin(rows, cols); i++) {
    bit_plane_shift_l(shl, curr, 1);
    bit_plane_shift_r(shr, curr, 1);
    bit_plane_and(tmpl, curr, shl);
    bit_plane_and(tmpr, curr, shr);
    bit_plane_and(mid, tmpl, tmpr);
    bit_plane_shift_u(shu, mid, 1);
    bit_plane_and(curr, shu, curr);
    cnt += sqr = bit_plane_popcount(curr);
  }
  sqr = -1;
  for (uint32_t i = 1; sqr && i < fmin(rows, cols); i++) {
    bit_plane_shift_l(shl, org, 1);
    bit_plane_shift_r(shr, org, 1);
    bit_plane_and(tmpl, org, shl);
    bit_plane_and(tmpr, org, shr);
    bit_plane_and(mid, tmpl, tmpr);
    bit_plane_shift_d(shd, mid, 1);
    bit_plane_and(org, shd, org);
    cnt += sqr = bit_plane_popcount(org);
  }
  return (int)cnt;
}

int main() {
  int g1i[2][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}},
      g2i[3][3] = {{1, 1, 1}, {1, 1, 1}},
      g3i[3][5] = {{1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  struct two_d_arr *g1 = two_d_arr_init(2, 4, g1i);
  struct two_d_arr *g2 = two_d_arr_init(3, 3, g2i);
  struct two_d_arr *g3 = two_d_arr_init(3, 5, g3i);
  printf("%d\n",
         countPyramids(g1->arr, g1->row_size, g1->col_size)); // expect: 2
  printf("%d\n",
         countPyramids(g2->arr, g2->row_size, g2->col_size)); // expect: 2
  printf("%d\n",
         countPyramids(g3->arr, g3->row_size, g3->col_size)); // expect: 13
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
}
