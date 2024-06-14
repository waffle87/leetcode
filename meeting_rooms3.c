// 2402. Meeting Rooms III
#include "leetcode.h"

/*
 * you are given an integer 'n', there are 'n' rooms numbered 0 to 'n - 1'.
 * guven a 2d integer array 'meetings', where 'meetings[i] = start[i], end[i]'
 * means that a meeting will be held during the half closed time interval
 * '[start[i], end[i]]'. all thevalues of 'start[i]' are unique. meetings are
 * allocated to rooms in the following manner: each meeting will take place in
 * the unused room with the lowest number. if there are no available rooms, the
 * meeting will be delayed until a room becoms free. the dleayed meeting should
 * have the same duration as the original meeting. when a room becoms unused,
 * meetings that have an earlier original start time should be given the room,
 * return the number of the room that held the most meetings. if there are
 * multiple rooms, return the room with the lowest number. a half closed
 * interval '[a, b)' is the interval between 'a' and 'b' including 'a' and not
 * including 'b'.
 */

void heapdown(int **room, int *heap, int heapsize) {
  int curr = 1;
  int child = curr << 1;
  while (child <= heapsize) {
    if (child + 1 <= heapsize &&
        room[heap[child + 1]][0] < room[heap[child]][0])
      child++;
    if (room[heap[child]][0] >= room[heap[curr]][0])
      break;
    heap[curr] ^= heap[child];
    heap[child] ^= heap[curr];
    heap[curr] ^= heap[child];
    curr = child;
    child <<= 1;
  }
}
void heapup(int **room, int *heap, int heapidx, int roomidx) {
  int curr = heapidx;
  int father = curr >> 1;
  while (father >= 1) {
    if (room[heap[father]][0] <= room[roomidx][0])
      break;
    heap[curr] = heap[father];
    curr = father;
    father >>= 1;
  }
  heap[curr] = roomidx;
}
int cmp(const void *a, const void *b) {
  return (*(int **)a)[0] - (*(int **)b)[0];
}
int mostBooked(int n, int **meetings, int meetingsSize, int *meetingsColSize) {
  long long **room = malloc(n * sizeof(long long *));
  for (int i = 0; i < n; i++) {
    room[i] = malloc(4 * sizeof(long long));
    room[i][0] = i;
    room[i][1] = i;
    room[i][2] = -1;
    room[i][3] = 0;
  }
  qsort(meetings, meetingsSize, sizeof(meetings[0]), cmp);
  int *nonbook = malloc((n + 1) * sizeof(int));
  int *booked = malloc((n + 1) * sizeof(int));
  int nonbookidx = 0; // 1~n
  int bookidx = 0;    // 1~n
  for (int i = 0; i < n; i++) {
    heapup(room, nonbook, i + 1, nonbookidx++);
  }
  for (int i = 0; i < meetingsSize; i++) {
    long long poptime = meetings[i][0];
    int target = 0;
    if (nonbookidx == 0)
      poptime = fmax(poptime, room[booked[1]][0]);
    // booked ->nonbooked
    while (bookidx > 0 && room[booked[1]][0] <= poptime) {
      target = booked[1];
      room[target][0] = room[target][1];
      heapup(room, nonbook, ++nonbookidx, target);
      booked[1] = booked[bookidx--];
      heapdown(room, booked, bookidx);
    }
    // nonbooked ->booked
    target = nonbook[1];
    room[target][2] = (room[target][2] <= meetings[i][0])
                          ? meetings[i][1]
                          : room[target][2] + meetings[i][1] - meetings[i][0];
    room[target][3] += 1;
    room[target][0] = room[target][2];
    heapup(room, booked, ++bookidx, target);
    nonbook[1] = nonbook[nonbookidx--];
    heapdown(room, nonbook, nonbookidx);
  }
  int ans = 0;
  int count = -1;
  for (int i = 0; i < n; i++) {
    if (room[i][3] > count) {
      count = room[i][3];
      ans = i;
    }
  }

  return ans;
}

int main() {
  int m1[5][2] = {{0, 10}, {1, 5}, {2, 7}, {3, 4}},
      m2[5][2] = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}, *mcs1, *mcs2;
  printf("%d\n", mostBooked(2, (int **)m1, 5, mcs1)); // expect: 0
  printf("%d\n", mostBooked(3, (int **)m2, 5, mcs2)); // expect: 1
}
