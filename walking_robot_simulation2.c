// 2069. Walking Robot Simulation II
#include "leetcode.h"

typedef struct {
  int pos;
  int len;
  int height;
  int width;
  int c1;
  int c2;
  int c3;
  int c4;
  bool init;
} Robot;

Robot *robotCreate(int width, int height) {
  Robot *obj = (Robot *)malloc(sizeof(Robot));
  obj->pos = 0;
  obj->len = (height + width - 2) * 2;
  obj->width = width - 1;
  obj->height = height - 1;
  obj->c1 = width - 1;
  obj->c2 = width + height - 2;
  obj->c3 = width * 2 + height - 3;
  obj->c4 = (width + height - 2) * 2;
  obj->init = true;
  return obj;
}

void robotStep(Robot *obj, int num) {
  obj->pos = (obj->pos + num) % obj->len;
  if (num > 0)
    obj->init = false;
}

int *robotGetPos(Robot *obj, int *retSize) {
  int *pos = (int *)malloc(2 * sizeof(int));
  *retSize = 2;
  if (obj->pos <= obj->c1) {
    pos[0] = obj->pos;
    pos[1] = 0;
  } else if (obj->pos <= obj->c2) {
    pos[0] = obj->width;
    pos[1] = obj->pos - obj->c1;
  } else if (obj->pos <= obj->c3) {
    pos[0] = obj->c3 - obj->pos;
    pos[1] = obj->height;
  } else {
    pos[0] = 0;
    pos[1] = obj->c4 - obj->pos;
  }
  return pos;
}

char *robotGetDir(Robot *obj) {
  char *dir = (char *)malloc(6 * sizeof(char));
  if (!obj->pos && obj->init) {
    strcpy(dir, "East");
    return dir;
  }
  if (!obj->pos) {
    strcpy(dir, "South");
    return dir;
  }
  if (obj->pos <= obj->c1)
    strcpy(dir, "East");
  else if (obj->pos <= obj->c2)
    strcpy(dir, "North");
  else if (obj->pos <= obj->c3)
    strcpy(dir, "West");
  else
    strcpy(dir, "South");
  return dir;
}

void robotFree(Robot *obj) { free(obj); }

int main() {
  Robot *obj = robotCreate(6, 3);
  robotStep(obj, 2);
  robotStep(obj, 2);
  int r1[] = {4, 0}, rs1, *rgp1 = robotGetPos(obj, &rs1);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", rgp1[i]);
    assert(rgp1[i] == r1[i]);
  }
  printf("\n");
  char *r2 = "East", *rgd1 = robotGetDir(obj);
  printf("%s\n", rgd1);
  assert(!strcmp(rgd1, r2));
  robotStep(obj, 2);
  robotStep(obj, 1);
  robotStep(obj, 4);
  int r3[] = {1, 2}, rs2, *rgp2 = robotGetPos(obj, &rs2);
  for (int i = 0; i < rs2; i++) {
    printf("%d ", rgp2[i]);
    assert(rgp2[i] == r3[i]);
  }
  printf("\n");
  char *r4 = "West", *rgd2 = robotGetDir(obj);
  printf("%s\n", rgd2);
  assert(!strcmp(rgd2, r4));
  free(rgd1);
  free(rgd2);
  free(rgp1);
  free(rgp2);
  robotFree(obj);
}
