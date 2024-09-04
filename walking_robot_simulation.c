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
  int c1[] = {4, -1, 3}, o1[1][0] = {{}}, ocs1[] = {1};
  int c2[] = {4, -1, 4, -2, 4}, o2[1][2] = {{2, 4}}, ocs2[] = {1};
  int c3[] = {6, -1, -1, 6}, o3[1][0] = {{}}, ocs3[] = {1};
  printf("%d\n", robotSim(c1, ARRAY_SIZE(c1), (int **)o1, ARRAY_SIZE(o1),
                          ocs1)); // expect: 25
  printf("%d\n", robotSim(c2, ARRAY_SIZE(c2), (int **)o2, ARRAY_SIZE(o2),
                          ocs2)); // expect: 65
  printf("%d\n", robotSim(c3, ARRAY_SIZE(c3), (int **)o3, ARRAY_SIZE(o3),
                          ocs3)); // expect: 36
}
