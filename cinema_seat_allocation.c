// 1386. Cinema Seat Allocation
#include "leetcode.h"

/*
 * a cinema has 'n' rows of seats, numbered from 1 to 'n' and there
 * are ten seats in each row, labelled from 1 to 10 as shown in
 * the figure above. given the array 'reservedSeats' containing
 * the number of seats already reserved, for example 'reservedSeats[i]
 * = [3,8]' means the seat located in row 3 and labelled with 8
 * is already reserved. return the maximum number of four-person
 * groups you can assign on the cinema seats. a four-person group
 * occupies four adjacent seats in one single row. seats across
 * an aisle are not considered to be adjacent, but there is an
 * exceptional case on which an aisle split a four-person group
 * in that case the aisle split a four-person group in the middle
 * which means to have two people on each side.
 */

struct hash_entry {
  int key;
  uint8_t val;
};

int maxNumberOfFamilies(int n, int **reservedSeats, int reservedSeatsSize,
                        int *reservedSeatsColSize) {
  if (!reservedSeatsSize)
    return n * 2;
  uint8_t lut[256];
  lut[0] = 0;
  for (int i = 1; i < 256; i++) {
    lut[i] = 1;
    if ((i & 0b00001111) != 0 && (i & 0b00111100) != 0 && (i & 0b11110000) != 0)
      lut[i] = 2;
  }
  struct hash_entry *map = (struct hash_entry *)malloc(
      reservedSeatsSize * sizeof(struct hash_entry));
  int map_size = 0;
  for (int i = 0; i < reservedSeatsSize; i++) {
    int row = reservedSeats[i][0];
    int col = reservedSeats[i][1];
    uint8_t seat = (uint8_t)(col - 2);
    if (seat < 8) {
      int found_idx = -1;
      for (int j = 0; j < map_size; j++)
        if (map[j].key == row) {
          found_idx = j;
          break;
        }
      if (found_idx != -1)
        map[found_idx].val |= (1 << seat);
      else {
        map[map_size].key = row;
        map[map_size].val = (1 << seat);
        map_size++;
      }
    }
  }
  int ans = n * 2;
  for (int i = 0; i < map_size; i++)
    ans -= lut[map[i].val];
  free(map);
  return ans;
}

int main() {
  int rs1i[6][2] = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
  int rs2i[3][2] = {{2, 1}, {1, 8}, {2, 6}};
  int rs3i[4][2] = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
  struct two_d_arr *rs1 =
      two_d_arr_init(ARRAY_SIZE(rs1i), ARRAY_SIZE(rs1i), rs1i);
  struct two_d_arr *rs2 =
      two_d_arr_init(ARRAY_SIZE(rs2i), ARRAY_SIZE(rs2i), rs2i);
  struct two_d_arr *rs3 =
      two_d_arr_init(ARRAY_SIZE(rs3i), ARRAY_SIZE(rs3i), rs3i);
  int r1 = maxNumberOfFamilies(3, rs1->arr, rs1->row_size, rs1->col_size);
  int r2 = maxNumberOfFamilies(2, rs2->arr, rs2->row_size, rs2->col_size);
  int r3 = maxNumberOfFamilies(4, rs3->arr, rs3->row_size, rs3->col_size);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 5);
  free(rs1);
  free(rs2);
  free(rs3);
}
