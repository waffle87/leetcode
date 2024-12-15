// 1792. Maximum Average Pass Ratio
#include "leetcode.h"

/*
 * there is a school that has classes of student and each class will be having a
 * final exam. you are given a 2d integer array 'classes', where 'classes[i] =
 * [pass_i, total_i]'. you know beforehand that in the i'th class, there are
 * 'total_i' total students, but only 'pass_i' number of students will pass the
 * exam. you are also given an integer 'extraStudents'. there are another
 * 'extraStudents' brilliant students that are guaranteed to pass the exam of
 * any class they are assigned to. you want to assign each of the
 * 'extraStudents' to a class in a way that maximises the average pass ration
 * across all classes. return the maximum possible average pass ratio after
 * assigning the 'extraStudents'. answers within '10^-5' of the actual answer
 * will be accepted.
 */

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    double aa =
        (a.first + 1) / (double)(a.second + 1) - (a.first) / (double)a.second;
    double bb =
        (b.first + 1) / (double)(b.second + 1) - (b.first) / (double)b.second;
    return aa < bb;
  }
};

class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    double acc = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (vector<int> i : classes)
      pq.push(make_pair(i[0], i[1]));
    while (extraStudents--) {
      pair<int, int> curr = pq.top();
      pq.pop();
      curr.first++;
      curr.second++;
      pq.push(curr);
    }
    while (!pq.empty()) {
      pair<int, int> curr = pq.top();
      pq.pop();
      acc += curr.first / (double)curr.second;
    }
    return acc / (double)classes.size();
  }
};

int main() {
  Solution obj;
  vvd(int) c1 = {{1, 2}, {3, 5}, {2, 2}},
           c2 = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
  printf("%f\n", obj.maxAverageRatio(c1, 2)); // expect: 0.78333
  printf("%f\n", obj.maxAverageRatio(c2, 4)); // expect: 0.53485
}
