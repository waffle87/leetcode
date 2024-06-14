// 1386. Cinema Seat Allocation
#include <stdio.h>
#include <stdlib.h>

/*
 * a cinema has 'n' rows of seats, numbered from 1 to 'n' and there
 * are ten seats in each row, labelled from 1 to 10 as shown in
 * the figure above. given the array 'reserved_seats' containing
 * the number of seats already reserved, for example 'reserved_seats[i]
 * = [3,8]' means the seat located in row 3 and labelled with 8
 * is already reserved. return the maximum number of four-person
 * groups you can assign on the cinema seats. a four-person group
 * occupies four adjacent seats in one single row. seats across
 * an aisle are not considered to be adjacent, but there is an
 * exceptional case on which an aisle split a four-person group
 * in that case the aisle split a four-person group in the middle
 * which means to have two people on each side.
 */

int cmp(const void *a, const void *b) {
  int *new_a = *(int **)a, *new_b = *(int **)b;
  if (new_a[0] == new_b[0])
    return new_a[1] - new_b[1];
  return new_a[0] - new_b[0];
}

int maxNumberOfFamilies(int n, int **reserved_seats, int reserved_seats_size,
                        int *reserved_seats_col_size) {
  qsort(reserved_seats, reserved_seats_size, sizeof(int *), cmp);
  int hash[256] = {}, ans = 2 * n;
  hash[0] = 2;
  for (int i = 1; i < 256; i++) {
    int val = i;
    if (!(val & 0x0F))
      hash[i] = 1;
    else if (!(val & 0xF0))
      hash[i] = 1;
    else if (!(val & 0x3C))
      hash[i] = 1;
  }
  int val = 0, col = reserved_seats[0][1];
  if (col != 1 && col != 10)
    val |= 1 << (col - 2);
  for (int i = 1; i < reserved_seats_size; i++) {
    col = reserved_seats[i][1];
    if (reserved_seats[i][0] == reserved_seats[i - 1][0]) {
      if (col != 1 && col != 10)
        val |= 1 << (col - 2);
    } else {
      ans -= 2 - hash[val];
      val = 0;
      if (col != 1 && col != 10)
        val |= 1 << (col - 2);
    }
  }
  ans -= 2 - hash[val];
  return ans;
}

int main() {
  int n1 = 2, rs1[6][2] = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}},
      rss1 = 6, rscs1[] = {};
  int n2 = 4, rs2[3][2] = {{2, 1}, {1, 8}, {2, 6}}, rss2 = 3, rscs2[] = {};
  printf("%d\n", maxNumberOfFamilies(n1, rs1, rss1, rscs1));
  printf("%d\n", maxNumberOfFamilies(n2, rs2, rss2, rscs2));
}
