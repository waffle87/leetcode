// 874. Walking Robot Simulation
#include "leetcode.h"

/*
 * a robot on an infinite xy plane starts at point '(0, 0)' facing north. the
 * robot can receive a sequence of these three possible types of 'commands': -2
 * turn left 90 degree, -1 turn right 90 degrees, '1 <= k <= 9' move forward 'k'
 * units, one unit at a time. some of the grid squares are 'obstacles'. the i'th
 * obstacle is at grid point 'obstacles[i] = (xi, yi)'. if the robot runs into
 * an obstacle, then it will instead stay in its current location and move on to
 * the next command. return the maximum euclidean distance that the robot ever
 * gets from the origin squared.
 */

enum directions { NORTH, EAST, SOUTH, WEST, INVALID };

inline int change_direction(int old, int turn) {
  switch (old) {
  case NORTH:
    return turn == -2 ? WEST : EAST;
  case EAST:
    return turn == -2 ? NORTH : SOUTH;
  case SOUTH:
    return turn == -2 ? EAST : WEST;
  case WEST:
    return turn == -2 ? SOUTH : NORTH;
  default:
    break;
  }
  return INVALID;
}

inline void move_forward(int *pos, int dir, int steps) {
  switch (dir) {
  case NORTH:
    pos[1] += steps;
    break;
  case EAST:
    pos[0] += steps;
    break;
  case SOUTH:
    pos[1] -= steps;
    break;
  case WEST:
    pos[0] -= steps;
    break;
  default:
    break;
  }
}

int robotSim(int *commands, int commandsSize, int **obstacles,
             int obstaclesSize, int *obstaclesColSize) {
  int pos[2] = {0, 0}, dir = NORTH, max_dist = 0;
  for (int i = 0; i < commandsSize; i++) {
    if (commands[i] == -2 || commands[i] == -1)
      dir = change_direction(dir, commands[i]);
    else {
      int steps = commands[i], curr_dist = 0;
      for (int j = 0; j < obstaclesSize; j++) {
        if (dir == NORTH || dir == SOUTH) {
          int obst_dist = (int)abs(obstacles[j][1] - pos[1]);
          if ((obstacles[j][0] == pos[0]) &&
              ((dir == NORTH && obstacles[j][1] > pos[1]) ||
               (dir == SOUTH && obstacles[j][1] < pos[1])) &&
              (obst_dist <= steps)) {
            steps = obst_dist - 1;
            break;
          }
        } else {
          int obst_dist = (int)abs(obstacles[j][0] - pos[0]);
          if ((obstacles[j][1] == pos[1]) &&
              ((dir == EAST && obstacles[j][0] > pos[0]) ||
               (dir == WEST && obstacles[j][0] < pos[0])) &&
              (obst_dist <= steps)) {
            steps = obst_dist - 1;
            break;
          }
        }
      }
      move_forward(pos, dir, steps);
      curr_dist = (pos[0] * pos[0]) + (pos[1] * pos[1]);
      if (curr_dist > max_dist)
        max_dist = curr_dist;
    }
  }
  return max_dist;
}

int main() {
  int c1[] = {4, -1, 3}, o1i[1][0] = {{}};
  int c2[] = {4, -1, 4, -2, 4}, o2i[1][2] = {{2, 4}};
  int c3[] = {6, -1, -1, 6}, o3i[1][0] = {{}};
  struct two_d_arr *o1 =
      two_d_arr_init(ARRAY_SIZE(o1i), ARRAY_SIZE(o1i[0]), o1i);
  struct two_d_arr *o2 =
      two_d_arr_init(ARRAY_SIZE(o2i), ARRAY_SIZE(o2i[0]), o2i);
  struct two_d_arr *o3 =
      two_d_arr_init(ARRAY_SIZE(o3i), ARRAY_SIZE(o3i[0]), o3i);
  int r1 = robotSim(c1, ARRAY_SIZE(c1), o1->arr, o1->row_size, o1->col_size);
  int r2 = robotSim(c2, ARRAY_SIZE(c2), o2->arr, o2->row_size, o2->col_size);
  int r3 = robotSim(c3, ARRAY_SIZE(c3), o3->arr, o3->row_size, o3->col_size);
  printf("%d\n", r1); // expect: 25
  assert(r1 == 25);
  printf("%d\n", r2); // expect: 65
  assert(r3 == 65);
  printf("%d\n", r3); // expect: 36
  assert(r3 == 36);
  two_d_arr_free(o1);
  two_d_arr_free(o2);
  two_d_arr_free(o3);
}
