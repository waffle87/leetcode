// 1491. Average Salary Excluding the Minimum and Maximum Salary
#include <float.h>
#include <stdio.h>

/*
 * given an array of unique integers 'salary' where 'salary[i]' is the salaray
 * of the i'th employee. return the average salary of employees excluding the
 * minimum and maximum salary. answer within 10^-5 of actual answer
 */

double average(int *salary, int salary_size) {
  double max = DBL_MIN, min = DBL_MAX, sum = 0;
  for (int i = 0; i < salary_size; i++) {
    sum += salary[i];
    if (salary[i] < min)
      min = salary[i];
    if (salary[i] > max)
      max = salary[i];
  }
  sum = sum - min - max;
  return sum / (salary_size - 2);
}

int main() {
  int s1[] = {4000, 3000, 1000, 2000};
  int s2[] = {1000, 2000, 3000};
  printf("%f\n", average(s1, 4)); // expect: 2500.00000
  printf("%f\n", average(s2, 3)); // expect: 2000.00000
}
