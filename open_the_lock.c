// 752. Open the Lock
#include "leetcode.h"

/*
 * you have a lock in front of you with 4 circular wheels. each wheel has 10
 * slots 0-9. the wheels can rotate freely and wrap around. the lock initially
 * starts at 0000, a sting representing the state of the 4 wheels. given a list
 * of 'deadends', meaning the lock displays any of these codes, the wheels of
 * the lock will stop turning and you will be unable to open it. given 'target'
 * representing the value of the wheels that will unlock the lock, return the
 * minimum total number of turns required to open the lock, or -1 if it is
 * impossible
 */

#define SIZE 10000
char queue[SIZE][4] = {0};
int front = -1;
int tail = -1;

int is_empty() { return (tail == front) ? 1 : 0; }

void enqueue(char *wheel) {
  front++;
  if (front == SIZE)
    front = 0;
  memcpy(&queue[front][0], wheel, sizeof(char) * 4);
}

char *dequeue() {
  if (is_empty() == 1)
    return NULL;
  tail++;
  if (tail == SIZE)
    tail = 0;
  return &queue[tail][0];
}

int convert_wheels_to_int(char *wheels) {
  return (wheels[3] - '0') + (wheels[2] - '0') * 10 + (wheels[1] - '0') * 100 +
         (wheels[0] - '0') * 1000;
}

int openLock(char **deadends, int deadendsSIZE, char *target) {
  if (!convert_wheels_to_int(target))
    return 0;
  int visited[SIZE] = {0};
  int hop[SIZE] = {0};
  int deadends_int;
  front = -1;
  tail = -1;
  for (int d = 0; d < deadendsSIZE; d++) {
    deadends_int = convert_wheels_to_int(deadends[d]);
    if (!deadends_int)
      return -1;
    else
      visited[deadends_int] = 1;
  }
  int target_int = convert_wheels_to_int(target);
  enqueue("0000");
  hop[0] = 0;
  visited[0] = 1;
  hop[target_int] = -1;
  int current_wheel_int;
  char *current_wheel;
  char neighbour[4];
  while (is_empty() != 1) {
    if (hop[target_int] != -1)
      return hop[target_int];
    current_wheel = dequeue();
    current_wheel_int = convert_wheels_to_int(current_wheel);
    for (int i = 0; i < 4; i++) {
      memcpy(&neighbour[0], current_wheel, sizeof(char) * 4);
      neighbour[i] = neighbour[i] == '9' ? '0' : neighbour[i] + 1;
      if (visited[convert_wheels_to_int(neighbour)] == 0) {
        enqueue(neighbour);
        hop[convert_wheels_to_int(neighbour)] = hop[current_wheel_int] + 1;
        visited[convert_wheels_to_int(neighbour)] = 1;
      }
      memcpy(&neighbour[0], current_wheel, sizeof(char) * 4);
      neighbour[i] = neighbour[i] == '0' ? '9' : neighbour[i] - 1;
      if (visited[convert_wheels_to_int(neighbour)] == 0) {
        enqueue(neighbour);
        hop[convert_wheels_to_int(neighbour)] = hop[current_wheel_int] + 1;
        visited[convert_wheels_to_int(neighbour)] = 1;
      }
    }
  }
  return hop[target_int];
}
int main() {
  char *d1[5][4] = {"0201", "0101", "0102", "1212", "2002"};
  char *d2[8][4] = {"8887", "8889", "8878", "8898",
                    "8788", "8988", "7888", "9888"};
  char *t1 = "0202", *t2 = "8888";
  printf("%d\n", openLock((char **)d1, 5, t1)); // expect: 6
  printf("%d\n", openLock((char **)d2, 8, t2)); // expect: -1
}
