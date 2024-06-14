// 1845. Seat Reservation Manager
#include "leetcode.h"

/*
 * design a system that manages the reservation state of 'n' seats that are
 * numbered 1 to 'n'. implement the 'SeatManager' class
 * - seatManagerCreate(int n) initalises a SeatManager object that will manage
 * 'n' seats numbered from 1 to 'n'. all seats are initially available
 * - seatManagerReserve() fetches the smallest-numbered unreserved seat,
 * reserves it, and returns its number
 * - seatManagerUnreserve(int seat_num) unreserves the seat with the given
 * 'seat_num'
 */

typedef struct {
  int *un_array;
  int un_size;
  int curr;
} SeatManager;

SeatManager *seatManagerCreate(int n) {
  SeatManager *res = malloc(sizeof(SeatManager));
  res->un_size = 0;
  res->curr = 0;
  res->un_array = (int *)malloc(n * sizeof(int));
  return res;
}

int seatManagerReserve(SeatManager *obj) {
  if (!obj->un_size) {
    obj->curr++;
    return obj->curr;
  } else {
    int min = obj->un_array[0], min_id = 0;
    for (int i = 1; i < obj->un_size; i++)
      if (obj->un_array[i] < min) {
        min = obj->un_array[i];
        min_id = i;
      }
    int tmp = obj->un_array[min_id];
    obj->un_array[min_id] = obj->un_array[obj->un_size - 1];
    return tmp;
  }
}

void seatManagerUnreserve(SeatManager *obj, int seat_num) {
  obj->un_size++;
  obj->un_array[obj->un_size - 1] = seat_num;
}

void seatManagerFree(SeatManager *obj) {
  free(obj->un_array);
  free(obj);
}

int main() {
  SeatManager *obj = seatManagerCreate(5);
  printf("%d\n", seatManagerReserve(obj)); // expect: 1
  printf("%d\n", seatManagerReserve(obj)); // expect: 2
  seatManagerUnreserve(obj, 2);
  printf("%d\n", seatManagerReserve(obj)); // expect: 2
  printf("%d\n", seatManagerReserve(obj)); // expect: 3
  printf("%d\n", seatManagerReserve(obj)); // expect: 4
  printf("%d\n", seatManagerReserve(obj)); // expect: 5
  seatManagerUnreserve(obj, 5);
}
