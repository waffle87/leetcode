// 1642. Furthest Building You Can Reach
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'heights' representing the heights of buildings, some
 * 'bricks' and some 'ladders'. you start your journey from building 0 and move
 * to the next building by possibly using bricks or ladders. while moving from
 * building 'i' to building 'i + 1' (0-indexed):
 * - if the current building's height is greater than or equal to the height of
 * next building, you do not need a ladder or bricks
 * - if the current building's height is less than the next building's height,
 * you can either use one ladder or '(h[i + 1] - h[i])' bricks return the
 * furthest building index (0-indexed) you can reach if you use the given
 * ladders and bricks optimally
 */

int heap[100000], heap_cnt;

void insert(int val) {
  int now = heap_cnt;
  heap[now] = val;
  heap_cnt++;
  while (now >= 1) {
    int p = (now - 1) / 2;
    if (heap[now] < heap[p]) {
      int tmp = heap[now];
      heap[now] = heap[p];
      heap[p] = tmp;
      now = p;
    } else
      break;
  }
}

int pop() {
  int res = heap[0], now = 0;
  heap[0] = heap[--heap_cnt];
  while (now * 2 + 1 < heap_cnt) {
    int tmp, next_pos = now;
    if (heap[now] > heap[now * 2 + 1])
      next_pos = now * 2 + 1;
    if (now * 2 + 2 < heap_cnt && heap[next_pos] > heap[now * 2 + 2])
      next_pos = now * 2 + 2;
    if (now == next_pos)
      break;
    tmp = heap[now];
    heap[now] = heap[next_pos];
    heap[next_pos] = tmp;
    now = next_pos;
  }
  return res;
}

int furthestBuilding(int *heights, int heights_size, int bricks, int ladders) {
  int cnt = 0;
  heap_cnt = 0;
  for (int i = 0; i < heights_size - 1; i++) {
    if (heights[i] > heights[i + 1])
      continue;
    insert(heights[i + 1] - heights[i]);
    if (cnt < ladders)
      cnt++;
    else {
      int min = pop();
      if (min > bricks)
        return i;
      bricks -= min;
    }
  }
  return heights_size - 1;
}

int main() {
  int h1[] = {4, 2, 7, 6, 9, 14, 12}, h2[] = {4, 12, 2, 7, 3, 18, 20, 3, 19},
      h3[] = {14, 3, 19, 3};
  printf("%d\n", furthestBuilding(h1, 7, 5, 1));  // expect: 4
  printf("%d\n", furthestBuilding(h2, 9, 10, 2)); // expect: 7
  printf("%d\n", furthestBuilding(h3, 4, 17, 0)); // expect: 3
}
