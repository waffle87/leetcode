// 849. Maximize Distance to Closest Person
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array representing a row of 'seats' where 'seats[i] = 1' represents
 * a person sitting in the i'th seat, and 'seats[i] = 0' represents that the
 * i'th seat is empty (0-indexed). there is at least one empty seat, and at
 * least one person sitting. alex wants to sit in the seat such that the
 * distance between him and the closest person to him is maximised. return that
 * maximum distance to the closest person.
 */

int maxDistToClosest(int *seats, int seats_size) {
  int n = seats_size, max = 0, cnt = 0, i;
  for (i = 0; i < n; i++) {
    if (!seats[i])
      cnt++;
    else
      break;
  }
  max = cnt;
  cnt = 0;
  for (int j = i; j < n; j++) {
    if (!seats[j])
      cnt++;
    else {
      max = fmax(max, (cnt + 1) / 2);
      cnt = 0;
    }
  }
  max = fmax(max, cnt);
  return max;
}

int main() {
  int s1[] = {1, 0, 0, 0, 1, 0, 1}, s2[] = {1, 0, 0, 0}, s3[] = {0, 1};
  printf("%d\n", maxDistToClosest(s1, 7)); // expect: 2
  printf("%d\n", maxDistToClosest(s2, 7)); // expect: 3
  printf("%d\n", maxDistToClosest(s3, 7)); // expect: 1
}
