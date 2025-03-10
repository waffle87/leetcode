// 1491. Average Salary Excluding the Minimum and Maximum Salary
#include "leetcode.h"

/*
 * given an array of unique integers 'salary' where 'salary[i]' is the salaray
 * of the i'th employee. return the average salary of employees excluding the
 * minimum and maximum salary. answer within 10^-5 of actual answer
 */

class Solution {
public:
  double average(vector<int> &salary) {
    double max = DBL_MIN, min = DBL_MAX, sum = 0;
    for (int i = 0; i < salary.size(); i++) {
      sum += salary[i];
      if (salary[i] < min)
        min = salary[i];
      if (salary[i] > max)
        max = salary[i];
    }
    sum = sum - min - max;
    return sum / (salary.size() - 2);
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {4000, 3000, 1000, 2000};
  vector<int> s2 = {1000, 2000, 3000};
  printf("%f\n", obj.average(s1)); // expect: 2500.00000
  printf("%f\n", obj.average(s2)); // expect: 2000.00000
}
