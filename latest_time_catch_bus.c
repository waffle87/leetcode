// 2332. The Latest Time to Catch a Bus
#include "leetcode.h"

/*
 * given a 0-indexed array 'buses' of length 'n' where 'buses[i]' represents the
 * departure time of the i'th bus. you are also given a 0-indexed array
 * 'passengers' of length 'm' where 'passengers[j]' represents the arrival time
 * of the j'th passenger. all bus departure times are unique. all passenger
 * arrival times are unique. return the latest time you may arrive at the bus
 * station to catch a bus. you cannot arrive at the same time as another
 * passenger.
 */

int cmp(const void *a, const void *b) {
  if (*(int *)a == *(int *)b)
    return 0;
  return *(int *)a < *(int *)b ? -1 : 1;
}

int latestTimeCatchTheBus(int *buses, int busesSize, int *passengers,
                          int passengersSize, int capacity) {
  qsort(buses, busesSize, sizeof(int), cmp);
  qsort(passengers, passengersSize, sizeof(int), cmp);
  int p = 0, last_board = -1, last_bus = busesSize - 1, j;
  for (int i = 0; i < busesSize; i++)
    for (j = 0; j < capacity && p < passengersSize && passengers[p] <= buses[i];
         j++) {
      last_board = i;
      p++;
    }
  if (last_board != last_bus)
    return buses[last_bus];
  p--;
  if (j < capacity && passengers[p] + 1 <= buses[last_board])
    return buses[last_board];
  while (p && passengers[p] - 1 == passengers[p - 1])
    p--;
  return passengers[p] - 1;
}

int main() {
  int b1[] = {10, 20}, p1[] = {2, 17, 18, 19}, b2[] = {20, 30, 10},
      p2[] = {19, 13, 26, 4, 25, 11, 21};
  printf("%d\n", latestTimeCatchTheBus(b1, ARRAY_SIZE(b1), p1, ARRAY_SIZE(p1),
                                       2)); // expect: 16
  printf("%d\n", latestTimeCatchTheBus(b2, ARRAY_SIZE(b2), p2, ARRAY_SIZE(p2),
                                       2)); // expect: 20
}
