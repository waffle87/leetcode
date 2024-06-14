// 1396. Design Underground System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 */

typedef struct {
  int id;
  int s;
  int e;
  char depart[11];
  char destina[11];
} TravelInfo;

typedef struct {
  TravelInfo data[20000];
  int custom;
} UndergroundSystem;

UndergroundSystem *undergroundSystemCreate() {
  UndergroundSystem *obj =
      (UndergroundSystem *)malloc(sizeof(UndergroundSystem));
  memset(obj->data, 0, sizeof(TravelInfo) * 2000);
  obj->custom = 0;
  return obj;
}

void undergroundSystemCheckIn(UndergroundSystem *obj, int id,
                              char *station_name, int t) {
  obj->data[obj->custom].id = id;
  strncpy(obj->data[obj->custom].depart, station_name, strlen(station_name));
  obj->data[obj->custom].depart[strlen(station_name)] = NULL;
  obj->data[obj->custom].s = t;
  obj->data[obj->custom].destina[0] = NULL;
  obj->data[obj->custom].e = 0;
  obj->custom++;
}

void undergroundSystemCheckOut(UndergroundSystem *obj, int id,
                               char *station_name, int t) {
  for (int i = 0; i < obj->custom; i++)
    if (obj->data[i].id == id && !obj->data[i].e) {
      strncpy(obj->data[i].destina, station_name, strlen(station_name));
      obj->data[obj->custom].destina[strlen(station_name)] = NULL;
      obj->data[i].e = t;
      break;
    }
}

double undergroundSystemGetAverageTime(UndergroundSystem *obj,
                                       char *start_station, char *end_station) {
  double res = 0, cnt = 0;
  for (int i = 0; i < obj->custom; i++)
    if (!strcmp(obj->data[i].depart, start_station) &
        !strcmp(obj->data[i].destina, end_station)) {
      cnt++;
      res += (obj->data[i].e - obj->data[i].s);
    }
  return res / cnt;
}

void undergroundSystemFree(UndergroundSystem *obj) { free(obj); }

int main() {
  UndergroundSystem *obj = undergroundSystemCreate();
  undergroundSystemCheckIn(obj, 45, "Leyton", 3);
  undergroundSystemCheckIn(obj, 32, "Paradise", 8);
  undergroundSystemCheckOut(
      obj, 45, "Waterloo",
      15); // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
  undergroundSystemCheckOut(
      obj, 27, "Waterloo",
      20); // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
  undergroundSystemCheckOut(
      obj, 32, "Cambridge",
      22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
  printf("%f\n", undergroundSystemGetAverageTime(
                     obj, "Paradise",
                     "Cambridge")); // return 14.00000. One trip "Paradise" ->
                                    // "Cambridge", (14) / 1 = 14
  printf("%f\n",
         undergroundSystemGetAverageTime(
             obj, "Leyton", "Waterloo")); // return 11.00000. Two trips "Leyton"
                                          // -> "Waterloo", (10 + 12) / 2 = 11
  undergroundSystemCheckIn(obj, 10, "Leyton", 24);
  printf("%f\n", undergroundSystemGetAverageTime(
                     obj, "Leyton", "Waterloo")); // return 11.00000
  undergroundSystemCheckOut(
      obj, 10, "Waterloo",
      38); // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
  printf("%f\n", undergroundSystemGetAverageTime(
                     obj, "Leyton",
                     "Waterloo")); // return 12.00000. Three trips "Leyton" ->
                                   // "Waterloo", (10 + 12 + 14) / 3 = 12
}
