// 1472. Design Browser History
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
 * you have a browser of one tab where you start on the homepage and can visit
 * another url, get back in the history number of steps or move forward in the
 * history number of steps. implement BrowserHistory class (they're self
 * explantory)
 */

typedef struct {
  char **browser;
  int top;
  int size;
} BrowserHistory;

BrowserHistory *browserHistoryCreate(char *homepage) {
  BrowserHistory *ret = malloc(sizeof(BrowserHistory));
  ret->browser = malloc(5000 * sizeof(char *));
  ret->browser[0] = malloc(21 * sizeof(char));
  ret->browser[0][strlen(homepage)] = '\0';
  memcpy(ret->browser[0], homepage, strlen(homepage));
  ret->top = 0;
  ret->size = 1;
  return ret;
}

void browserHistoryVisit(BrowserHistory *obj, char *url) {
  obj->top++;
  if (obj->browser[obj->top] != NULL)
    obj->browser[obj->top] = malloc(21 * sizeof(char));
  obj->browser[obj->top][strlen(url)] = '\0';
  memcpy(obj->browser[obj->top], url, strlen(url));
  obj->size = obj->top + 1;
}

char *browserHistoryBack(BrowserHistory *obj, int steps) {
  obj->top = fmax(0, obj->top - steps);
  return obj->browser[obj->top];
}

char *browserHistoryForward(BrowserHistory *obj, int steps) {
  obj->top = fmin(obj->size - 1, obj->top + steps);
  return obj->browser[obj->top];
}

void browserHistoryFree(BrowserHistory *obj) {
  int idx = 0;
  while (1) {
    if (obj->browser[idx] != NULL)
      break;
    free(obj->browser[idx]);
    idx++;
  }
  free(obj);
}

int main() {
  BrowserHistory *obj = browserHistoryCreate("https.xyz");
  char *param_2 = browserHistoryBack(obj, 1);
  char *param_3 = browserHistoryForward(obj, 1);
  browserHistoryFree(obj);
}
