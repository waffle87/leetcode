// 1700. Number of Students Unable to Eat Lunch
#include "leetcode.h"

/*
 * the school cafeteria offers circular and square sandwiches at lunch break,
 * referred to by numbers 0 and 1, respectively. all students stand in a queue.
 * each student either prefers square or circular sandwiches. the number of
 * sandwiches in the cafeteria is equal to the number of students.
 */

int countStudents(int *students, int studentsSize, int *sandwiches,
                  int sandwichesSize) {
  int n = studentsSize, one_cnt = 0, zero_cnt = 0;
  for (int i = 0; i < n; i++)
    if (students[i])
      one_cnt++;
  zero_cnt = n - one_cnt;
  for (int i = 0; i < n; i++) {
    if (sandwiches[i]) {
      if (one_cnt)
        one_cnt--;
      else
        return n - i;
    } else {
      if (zero_cnt)
        zero_cnt--;
      else
        return n - i;
    }
  }
  return 0;
}

int main() {
  int st1[] = {1, 1, 0, 0}, sa1[] = {0, 1, 0, 1}, st2[] = {1, 1, 1, 0, 0, 1},
      sa2[] = {1, 0, 0, 0, 1, 1};
  printf("%d\n", countStudents(st1, ARRAY_SIZE(st1), sa1,
                               ARRAY_SIZE(sa1))); // expect: 0
  printf("%d\n", countStudents(st2, ARRAY_SIZE(st2), sa2,
                               ARRAY_SIZE(sa2))); // expect: 3
}
