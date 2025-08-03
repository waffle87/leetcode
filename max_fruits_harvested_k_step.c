// 2106. Maximum Fruits Harvested After at Most K Steps
#include "leetcode.h"

/*
 * fruits are available at some positions on an infinite x-axis. you are given a
 * 2d integer array 'fruits' where 'fruits[i] = [positions[i], amount[i]]'
 * depicts 'amount[i]' fruits at the position 'position[i]'. 'fruits' is already
 * sorted by 'position[i]' in ascending order, and eash 'position[i]' is unique.
 * you are also given an integer 'startPos' and an integer 'k'. initially, y-u
 * are at the position 'startPos'. from any position, you can either walk to the
 * left or right. it takes one step to move one unit on the x-axis, and you can
 * walk at most 'k' steps in total. for every position you reach, you harvest
 * all the fruits at that position, and the fruits will dsiappear from that
 * position.
 */

void bfs(int **fruits, int fruitsSize, int start, int *left, int *right) {
  *left = 0;
  *right = fruitsSize - 1;
  while (*left <= *right) {
    int mid = (*left + *right) / 2;
    if (fruits[mid][0] < start)
      *left = mid + 1;
    else if (fruits[mid][0] > start)
      *right = mid - 1;
    else {
      *left = mid;
      *right = mid;
      break;
    }
  }
}

int find_max_right(int **fruits, int fruitsSize, int curr, int k) {
  int startPos = curr, max_left = curr - 1, sum_left = 0, max = 0,
      sum_right = 0;
  for (; max_left >= 0; max_left--) {
    if ((fruits[curr][0] - fruits[max_left][0]) < k)
      sum_left += fruits[max_left][1];
    else {
      max_left++;
      break;
    }
  }
  if (max_left == -1)
    max_left++;
  while (1) {
    sum_right += fruits[curr][1];
    if (sum_right + sum_left > max)
      max = sum_right + sum_left;
    if (curr == fruitsSize - 1)
      break;
    else {
      curr++;
      k -= fruits[curr][0] - fruits[curr - 1][0];
      if (k < 0)
        break;
      else if (k > fruits[curr][0] - fruits[startPos][0]) {
        while (max_left < startPos &&
               fruits[curr][0] - fruits[max_left][0] > k) {
          sum_left -= fruits[max_left][1];
          max_left++;
        }
      } else
        sum_left = 0;
    }
  }
  return max;
}

int find_max_left(int **fruits, int fruitsSize, int curr, int k) {
  int startPos = curr, max_right = curr + 1, sum_right = 0, max = 0,
      sum_left = 0;
  for (; max_right < fruitsSize; max_right++) {
    if (fruits[max_right][0] - fruits[curr][0] <= k)
      sum_right += fruits[max_right][1];
    else {
      max_right--;
      break;
    }
  }
  if (max_right == fruitsSize)
    max_right--;
  while (1) {
    sum_left += fruits[curr][1];
    if (sum_right + sum_left > max)
      max = sum_right + sum_left;
    if (!curr)
      break;
    else {
      curr--;
      k -= fruits[curr + 1][0] - fruits[curr][0];
      if (k < 0)
        break;
      else if (k > fruits[startPos][0] - fruits[curr][0]) {
        while (max_right > startPos &&
               fruits[max_right][0] - fruits[curr][0] > k) {
          sum_right -= fruits[max_right][1];
          max_right--;
        }
      } else
        sum_right = 0;
    }
  }
  return max;
}

int maxTotalFruits(int **fruits, int fruitsSize, int *fruitsColSize,
                   int startPos, int k) {
  int left = -1, right = -1;
  bfs(fruits, fruitsSize, startPos, &right, &left);
  if (right < fruitsSize) {
    int new_k = k - (fruits[right][0] - startPos);
    right = new_k >= 0 ? find_max_right(fruits, fruitsSize, right, new_k) : 0;
  } else
    right = 0;
  if (left > -1) {
    int new_k = k - (startPos - fruits[left][0]);
    left = new_k >= 0 ? find_max_left(fruits, fruitsSize, left, new_k) : 0;
  } else
    left = 0;
  return left > right ? left : right;
}

int main() {
  int f1i[3][2] = {{2, 8}, {6, 3}, {8, 6}},
      f2i[6][2] = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}},
      f3i[3][2] = {{0, 3}, {6, 4}, {8, 5}};
  struct two_d_arr f1, f2, f3;
  two_d_arr_init(&f1, ARRAY_SIZE(f1i), ARRAY_SIZE(f1i[0]), f1i);
  two_d_arr_init(&f2, ARRAY_SIZE(f2i), ARRAY_SIZE(f2i[0]), f2i);
  two_d_arr_init(&f3, ARRAY_SIZE(f3i), ARRAY_SIZE(f3i[0]), f3i);
  printf("%d\n",
         maxTotalFruits(f1.arr, f1.row_size, f1.col_size, 5, 4)); // expect: 9
  printf("%d\n",
         maxTotalFruits(f2.arr, f2.row_size, f2.col_size, 5, 4)); // expect: 14
  printf("%d\n",
         maxTotalFruits(f3.arr, f3.row_size, f3.col_size, 3, 2)); // expect: 0
  two_d_arr_free(&f1);
  two_d_arr_free(&f2);
  two_d_arr_free(&f3);
}
