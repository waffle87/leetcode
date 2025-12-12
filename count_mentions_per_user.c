// 3433. Count Mentions Per User
#include "leetcode.h"

/*
 * you are given an integer 'numberOfUsers' representing the total number of
 * users and an array 'events' of size 'n x 3'. each 'events[i]' can be either
 * of the following types: message event indicates that a set of users was
 * mentioned in a message at 'timestamp' offline even indicates that the user
 * 'id_i' has become offline at 'timestamp_i' for 60 time units. the user will
 * automatically be online again at time 'timestamp_i + 60'. return an array
 * 'mentions' that represents the number of mentions the user with id 'i' has
 * across all 'MESSAGE' events. all users are initially online, and if a user
 * goes offline or comes back online, their status change is processed before
 * handling any message event that occurs at the same timestamp
 */

int str_to_num(char *s) {
  int n = 0;
  for (int i = 0; i < strlen(s); i++) {
    n *= 10;
    n += (int)(s[i] - '0');
  }
  return n;
}

int *countMentions(int numberOfUsers, char ***events, int eventsSize,
                   int *eventsColSize, int *returnSize) {
  int *time = (int *)malloc(eventsSize * sizeof(int));
  int *order = (int *)malloc(eventsSize * sizeof(int));
  for (int i = 0; i < eventsSize; i++)
    time[i] = str_to_num(events[i][1]);
  for (int i = 0; i < eventsSize; i++)
    order[i] = i;
  for (int i = eventsSize - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (time[order[j + 1]] < time[order[j]] ||
          (time[order[j + 1]] == time[order[j]] &&
           events[order[j + 1]][0][0] == 'O')) {
        int curr_time = order[j];
        order[j] = order[j + 1];
        order[j + 1] = curr_time;
      }
  int *online = (int *)calloc(numberOfUsers, sizeof(int));
  int *mention = (int *)calloc(numberOfUsers, sizeof(int));
  *returnSize = numberOfUsers;
  for (int n = 0; n < eventsSize; n++) {
    int i = order[n];
    if (events[i][0][0] == 'M') {
      if (events[i][2][0] == 'A') {
        for (int j = 0; j < numberOfUsers; j++)
          mention[j] += 1;
      } else if (events[i][2][0] == 'H') {
        int curr_time = str_to_num(events[i][1]);
        for (int j = 0; j < numberOfUsers; j++) {
          if (online[j] == 0)
            mention[j] += 1;
          else if (online[j] <= curr_time) {
            online[j] = 0;
            mention[j] += 1;
          }
        }
      } else {
        char t_id[10];
        char *prev = &(events[i][2][0]), *space = strchr(events[i][2], ' ');
        while (true) {
          memset(t_id, '\0', sizeof(t_id));
          if (!space) {
            strcpy(t_id, prev + 2);
            mention[str_to_num(t_id)] += 1;
            break;
          } else {
            strncpy(t_id, prev + 2, (int)(space - prev - 2));
            mention[str_to_num(t_id)] += 1;
            prev = space + 1;
            space = strchr(prev, ' ');
          }
        }
      }
    } else if (events[i][0][0] == 'O')
      online[str_to_num(events[i][2])] = str_to_num(events[i][1]) + 60;
  }
  free(time);
  free(order);
  free(online);
  free(mention);
  return mention;
}

int main() {
  char *e1[3][3] = {{"MESSAGE", "10", "id1 id0"},
                    {"OFFLINE", "11", "0"},
                    {"MESSAGE", "71", "HERE"}};
  char *e2[3][3] = {{"MESSAGE", "10", "id1 id0"},
                    {"OFFLINE", "11", "0"},
                    {"MESSAGE", "12", "ALL"}};
  char *e3[2][3] = {{"OFFLINE", "10", "0"}, {"MESSAGE", "12", "HERE"}};
  int ecs1 = ARRAY_SIZE(e1[0]), rs1;
  int ecs2 = ARRAY_SIZE(e2[0]), rs2;
  int ecs3 = ARRAY_SIZE(e3[0]), rs3;
  int *cm1 = countMentions(2, (char ***)e1, ARRAY_SIZE(e1), &ecs1, &rs1);
  int *cm2 = countMentions(2, (char ***)e2, ARRAY_SIZE(e2), &ecs2, &rs2);
  int *cm3 = countMentions(2, (char ***)e3, ARRAY_SIZE(e3), &ecs3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cm1[i]); // expect: 2 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cm2[i]); // expect: 2 2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", cm3[i]); // expect: 0 1
  printf("\n");
  free(cm1);
  free(cm2);
  free(cm3);
}
