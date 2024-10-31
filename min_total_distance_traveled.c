// 2463. Minimum Total Distance Traveled
#include "leetcode.h"

/*
 * there are some robots and factories on the x-axis. you are given an integer
 * array 'robot' where 'robot[i]' is the position of the i'th robot. you are
 * also given a 2d integer array 'factory' where 'factory[j] = [position_i,
 * limit_i]' indicates that 'position[j]' is the position of the j'th factory
 * and that the j'th factory can repair at most 'limit[j]' robots. the positions
 * of each robot are unique. note that a robot can be in the same position as a
 * factory initially. all the robots are initially broke; they keep moving in
 * one direction. the direction could be the negative or positive direction of
 * the x-axis. when a robot reaches a factory that did not reach its limit, the
 * factory repairs the robot and it stops moving. return the minimum total
 * distance traveled by all the robots. the test cases are generated as such
 * that all the robots can be repaired.
 */

struct robot {
  bool to_left;
  int right;
  int left;
};

struct factory {
  int *robot_num;
  int point;
  int count;
};

int cmp_r(const void *a, const void *b) {
  return *(int *)a > *(int *)b ? 1 : -1;
}

int cmp_f(const void **a, const void **b) {
  return (*(int **)a)[0] > (*(int **)b)[0] ? 1 : -1;
}

int cost_r(int **factory, int factorySize, struct factory *f_list,
           int right_factory) {
  int right = 0;
  if (right_factory == factorySize)
    return INT_MAX;
  while (factory[right_factory][1] <= f_list[right_factory].count) {
    right += factory[right_factory][0] - factory[right_factory - 1][0];
    right_factory++;
    if (right_factory == factorySize)
      return INT_MAX;
  }
  right += factory[right_factory][0] - factory[right_factory - 1][0];
  return right;
}

void cost_f(int *robot, int **factory, struct robot *r_list,
            struct factory *f_list, int curr, int left_factory, bool *to_left,
            int *l, int r) {
  if (left_factory == -1) {
    r_list[curr].left = -1;
    return;
  }
  *l += robot[curr] - factory[left_factory][0];
  if (factory[left_factory][1] <= f_list[left_factory].count) {
    int replace = f_list[left_factory].robot_num[f_list[left_factory].point];
    *l -= r_list[replace].to_left ? robot[replace] - factory[left_factory][0]
                                  : factory[left_factory][0] - robot[replace];
    cost_f(robot, factory, r_list, f_list, replace, r_list[replace].left,
           to_left, l, r);
    if (*to_left)
      f_list[left_factory].point++;
  } else {
    if (*l <= r)
      *to_left = true;
  }
  if (*to_left) {
    r_list[curr].to_left = true;
    r_list[curr].left = left_factory - 1;
    f_list[left_factory].robot_num[f_list[left_factory].count] = curr;
    f_list[left_factory].count++;
  }
  return;
}

void to_r_change(int **factory, struct robot *r_list, struct factory *f_list,
                 int curr, int right_factory) {
  if (factory[right_factory][1] <= f_list[right_factory].count) {
    int replace = f_list[right_factory].robot_num[f_list[right_factory].point];
    to_r_change(factory, r_list, f_list, replace, r_list[replace].left);
    f_list[right_factory].point++;
  }
  r_list[curr].right = right_factory + 1;
  f_list[right_factory].robot_num[f_list[right_factory].count] = curr;
  f_list[right_factory].count++;
  return;
}

long long minimumTotalDistance(int *robot, int robotSize, int **factory,
                               int factorySize, int *factoryColSize) {
  qsort(robot, robotSize, sizeof(int), cmp_r);
  qsort(factory, factorySize, sizeof(int *), cmp_f);
  struct robot *r_list =
      (struct robot *)malloc(robotSize * sizeof(struct robot));
  struct factory *f_list =
      (struct factory *)calloc(factorySize, sizeof(struct factory));
  int point = 0, head = 0;
  long long ans = 0;
  for (int i = 0; i < robotSize; i++) {
    while (point < factorySize && factory[point][0] < robot[i])
      point++;
    r_list[i].right = point;
    r_list[i].left = point - 1;
  }
  for (int i = 0; i < factorySize; i++)
    f_list[i].robot_num = (int *)malloc(robotSize * sizeof(int));
  while (head < robotSize && r_list[head].left == -1) {
    while (factory[r_list[head].right][1] == f_list[r_list[head].right].count)
      r_list[head].right++;
    ans += factory[r_list[head].right][0] - robot[head];
    r_list[head].to_left = false;
    f_list[r_list[head].right].robot_num[f_list[r_list[head].right].count] =
        head;
    f_list[r_list[head].right].count++;
    head++;
  }
  while (head < robotSize) {
    int left = r_list[head].left == -1
                   ? INT_MAX
                   : robot[head] - factory[r_list[head].left][0];
    int right = r_list[head].right == factorySize
                    ? INT_MAX
                    : factory[r_list[head].right][0] - robot[head];
    int right_factory = r_list[head].right;
    bool to_left = false;
    if (right_factory < factorySize) {
      while (!factory[right_factory][1]) {
        right_factory++;
        if (right_factory == factorySize) {
          right = INT_MAX;
          break;
        } else
          right = factory[right_factory][0] - robot[head];
      }
      if (right_factory < factorySize &&
          factory[right_factory][1] <= f_list[right_factory].count) {
        r_list[head].to_left = false;
        ans += right;
        f_list[right_factory].robot_num[f_list[right_factory].count] = head;
        f_list[right_factory].count++;
        int replace =
            f_list[right_factory].robot_num[f_list[right_factory].point];
        f_list[right_factory].point++;
        if (r_list[replace].left == -1) {
          r_list[head].left = -1;
          right_factory++;
          ans += factory[right_factory][0] - factory[right_factory - 1][0];
          while (factory[right_factory][1] <= f_list[right_factory].count) {
            f_list[right_factory].robot_num[f_list[right_factory].count] =
                replace;
            replace =
                f_list[right_factory].robot_num[f_list[right_factory].point];
            f_list[right_factory].count++;
            f_list[right_factory].point++;
            right_factory++;
            ans += factory[right_factory][0] - factory[right_factory - 1][0];
          }
          f_list[right_factory].robot_num[f_list[right_factory].count] =
              replace;
          f_list[right_factory].count++;
          f_list[right_factory].point++;
        } else {
          right = cost_r(factory, factorySize, f_list, right_factory + 1);
          left = robot[replace] - factory[right_factory][0];
          cost_f(robot, factory, r_list, f_list, replace, r_list[replace].left,
                 &to_left, &left, right);
          if (to_left)
            ans += left;
          else {
            ans += right;
            to_r_change(factory, r_list, f_list, replace,
                        r_list[replace].right);
          }
        }
        head++;
        continue;
      }
    }
    int left_factory = r_list[head].left;
    while (!factory[left_factory][1]) {
      left_factory--;
      if (left_factory >= 0) {
        left = robot[head] - factory[left_factory][0];
        r_list[head].left = left_factory;
      } else {
        left = INT_MAX;
        r_list[head].left = left_factory;
        break;
      }
    }
    if (left_factory >= 0 &&
        factory[left_factory][1] <= f_list[left_factory].count) {
      int replace = f_list[left_factory].robot_num[f_list[left_factory].point];
      left -= r_list[replace].to_left
                  ? robot[replace] - factory[left_factory][0]
                  : factory[left_factory][0] - robot[replace];
      cost_f(robot, factory, r_list, f_list, replace, r_list[replace].left,
             &to_left, &left, right);
      if (to_left)
        f_list[left_factory].point++;
    } else {
      if (left <= right)
        to_left = true;
    }
    if (to_left) {
      ans += left;
      r_list[head].to_left = true;
      r_list[head].left = left_factory - 1;
      f_list[left_factory].robot_num[f_list[left_factory].count] = head;
      f_list[left_factory].count++;
    } else {
      ans += right;
      r_list[head].to_left = false;
      f_list[right_factory].robot_num[f_list[right_factory].count] = head;
      f_list[right_factory].count++;
    }
    head++;
  }
  for (int i = 0; i < factorySize; i++)
    free(f_list[i].robot_num);
  free(f_list), free(r_list);
  return ans;
}

int main() {
  int r1[] = {0, 4, 6}, f1i[2][2] = {{2, 2}, {6, 2}};
  int r2[] = {1, -1}, f2i[2][2] = {{-2, 1}, {2, 1}};
  struct two_d_arr f1, f2;
  two_d_arr_init(&f1, 2, 2, f1i);
  two_d_arr_init(&f2, 2, 2, f2i);
  printf("%lld\n", minimumTotalDistance(r1, ARRAY_SIZE(r1), f1.arr, f1.row_size,
                                        f1.col_size)); // expect: 4

  printf("%lld\n", minimumTotalDistance(r2, ARRAY_SIZE(r2), f2.arr, f2.row_size,
                                        f2.col_size)); // expect: 2
  two_d_arr_free(&f1);
  two_d_arr_free(&f2);
}
