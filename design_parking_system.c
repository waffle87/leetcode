// 1603. Design Parking System
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * design a parking system for a parking lot. the parking lot has three kinds of
 * parking spaces: big, medium, and small. with a fixed number of slots for each
 * size. implement the 'ParkingSystem' class:
 * - 'ParkingSystem(big, medium, small)' initialises object of the
 * 'ParkingSystem' class the number of slots for each parking space are given as
 * part of the constructor
 * - 'bool addCar(car_type)' checks whether there is a parking space of
 * 'car_type' for the car that wants to get into the parking lot. 'car_type' can
 * be of three kinds: big, medium, or small, which are represented by 1, 2, or
 * 3, respectively. a car can only park in a parking space of its 'car_type'. if
 * there is no space available, return false, else park the car in that size
 * space and return true
 */

typedef struct {
  int b;
  int m;
  int s;
} ParkingSystem;

ParkingSystem *parkingSystemCreate(int big, int medium, int small) {
  ParkingSystem *obj = malloc(sizeof(ParkingSystem));
  obj->b = big;
  obj->m = medium;
  obj->s = small;
  return obj;
}

bool parkingSystemAddCar(ParkingSystem *obj, int car_type) {
  if (car_type == 1)
    return obj->b-- > 0;
  if (car_type == 2)
    return obj->m-- > 0;
  return obj->s-- > 0;
}

void parkingSystemFree(ParkingSystem *obj) { free(obj); }

int main() {
  ParkingSystem *obj = parkingSystemCreate(1, 1, 0);
  printf("%d\n", parkingSystemAddCar(obj, 1)); // expect: 1
  printf("%d\n", parkingSystemAddCar(obj, 2)); // expect: 1
  printf("%d\n", parkingSystemAddCar(obj, 3)); // expect: 0
  printf("%d\n", parkingSystemAddCar(obj, 1)); // expect: 0
}
