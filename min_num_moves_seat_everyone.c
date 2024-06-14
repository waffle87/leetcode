// 2037. Minimum Number of Moves to Seat Everyone
#include "leetcode.h"

/*
 * there are 'n' seats and 'n' students in a room. you are given an array
 * 'seats' of length 'n' where 'seats[i]' is the position of the i'th seat. you
 * are also given the array 'students' of length 'n' where 'students[j]' is the
 * position of the j'th student. you may perform the following move any number
 * of times. return the minimum number of moves required to move each student to
 * a seat such that no two students are in the same.
 */

int minMovesToSeat(int *seats, int seatsSize, int *students, int studentsSize) {
  int tmp, sum = 0;
  for (int i = 0; i < seatsSize; i++) {
    for (int j = i + 1; j < seatsSize; j++) {
      if (seats[i] > seats[j]) {
        tmp = seats[i];
        seats[i] = seats[j];
        seats[j] = tmp;
      }
      if (students[i] > students[j]) {
        tmp = students[i];
        students[i] = students[j];
        students[j] = tmp;
      }
    }
    sum += abs(students[i] - seats[i]);
  }
  return sum;
}

int main() {
  int seats1[] = {3, 1, 5}, seats2[] = {4, 1, 5, 9}, seats3[] = {2, 2, 6, 6};
  int students1[] = {2, 7, 4}, students2[] = {1, 3, 2, 6},
      students3[] = {1, 3, 2, 6};
  printf("%d\n", minMovesToSeat(seats1, ARRAY_SIZE(seats1), students1,
                                ARRAY_SIZE(students1))); // expect: 4
  printf("%d\n", minMovesToSeat(seats2, ARRAY_SIZE(seats2), students2,
                                ARRAY_SIZE(students2))); // expect: 4
  printf("%d\n", minMovesToSeat(seats3, ARRAY_SIZE(seats3), students3,
                                ARRAY_SIZE(students3))); // expect: 4
}
