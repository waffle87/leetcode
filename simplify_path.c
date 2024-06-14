// 71. Simplify Path
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// given a string 'path', which is an absolute path (starting with a slash) to a
// file or directory in a unix-style file system, convert it to the simplified
// canonical path

char *go_upper(char *head, char *tail) {
  for (; *tail != '/' && tail != head; tail--)
    ;
  if (tail == head) {
    *head = '/';
    tail++;
  }
  *tail = '\0';
  return tail;
}

char *go_lower(char *tail, char *level) {
  while ((*tail++ = *level++) != '\0')
    ;
  return tail - 1;
}

char *next_level(char **level, char *path) {
  *level = malloc(sizeof(char) * 200);
  int l = 0;
  (*level)[l++] = *path++;
  for (; *path == '/'; path++)
    ;
  for (; *path != '/' && *path != '\0'; path++)
    (*level)[l++] = *path;
  (*level)[l] = '\0';
  return path;
}

char *simplifyPath(char *path) {
  char *head = malloc(sizeof(char) * strlen(path));
  char *tail = head, *level;
  *tail++ = '/';
  while (*path != '\0') {
    path = next_level(&level, path);
    if (!strcmp(level, "/.") || !strcmp(level, "/"))
      continue;
    else if (!strcmp(level, "/.."))
      tail = go_upper(head, tail);
    else
      tail = go_lower(tail, level);
    free(level);
  }
  while (*(head + 1) == '/')
    head++;
  return head;
}

int main() {
  char p1[] = {"/home/"}, p2[] = {"/../"}, p3[] = {"/home//foo/"};
  printf("%s\n", simplifyPath(p1)); // expect: /home
  printf("%s\n", simplifyPath(p2)); // expect: /
  printf("%s\n", simplifyPath(p3)); // expect: /home/foo
}
