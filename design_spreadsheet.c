// 3484. Design Spreadsheet
#include "leetcode.h"

/*
 * a spreadsheet is a grid with 26 columns labeled from 'A' to 'Z' and a given
 * number of 'rows'. each cell in the spreadsheet can hold an integer value
 * between 0 and 10^5. note: if 'spreadsheetGetValue' references a cell that has
 * not been explicitly set using 'spreadsheetSetCell', its value is considered
 * to be 0.
 */

typedef struct {
  int rows;
  int size;
  int capacity;
  int *values;
  char **keys;
} Spreadsheet;

Spreadsheet *spreadsheetCreate(int rows) {
  Spreadsheet *obj = (Spreadsheet *)malloc(sizeof(Spreadsheet));
  obj->rows = rows;
  obj->size = 0;
  obj->capacity = 100;
  obj->values = (int *)malloc(obj->capacity * sizeof(int));
  obj->keys = (char **)malloc(obj->capacity * sizeof(char *));
  return obj;
}

void spreadsheetSetCell(Spreadsheet *obj, char *cell, int value) {
  for (int i = 0; i < obj->size; ++i)
    if (!strcmp(obj->keys[i], cell)) {
      obj->values[i] = value;
      return;
    }
  if (obj->size == obj->capacity) {
    obj->capacity *= 2;
    obj->values = (int *)realloc(obj->values, obj->capacity * sizeof(int));
    obj->keys = (char **)realloc(obj->keys, obj->capacity * sizeof(char *));
  }
  obj->keys[obj->size] = strdup(cell);
  obj->values[obj->size] = value;
  obj->size++;
}

void spreadsheetResetCell(Spreadsheet *obj, char *cell) {
  for (int i = 0; i < obj->size; ++i)
    if (!strcmp(obj->keys[i], cell)) {
      free(obj->keys[i]);
      for (int j = i; j < obj->size - 1; ++j) {
        obj->keys[j] = obj->keys[j + 1];
        obj->values[j] = obj->values[j + 1];
      }
      obj->size--;
      return;
    }
}

int get_val(Spreadsheet *obj, char *str) {
  for (int i = 0; str[i]; i++)
    if (!isdigit(str[i])) {
      for (int j = 0; j < obj->size; ++j)
        if (!strcmp(obj->keys[j], str))
          return obj->values[j];
      return 0;
    }
  return atoi(str);
}

int spreadsheetGetValue(Spreadsheet *obj, char *formula) {
  formula++;
  char *plus = strchr(formula, '+');
  *plus = '\0';
  char *a = formula, *b = plus + 1;
  return get_val(obj, a) + get_val(obj, b);
}

void spreadsheetFree(Spreadsheet *obj) {
  for (int i = 0; i < obj->size; ++i)
    free(obj->keys[i]);
  free(obj->keys);
  free(obj->values);
  free(obj);
}

int main() {
  Spreadsheet *obj = spreadsheetCreate(3);
  char *f1 = "=5+7", *f2 = "=A1+6", *f3 = "=A1+B2", *f4 = "=A1+B2";
  char *c1 = "A1", *c2 = "B2";
  printf("%d\n", spreadsheetGetValue(obj, f1)); // expect: 12
  spreadsheetSetCell(obj, c1, 10);
  printf("%d\n", spreadsheetGetValue(obj, f2)); // expect: 16
  spreadsheetSetCell(obj, c2, 15);
  printf("%d\n", spreadsheetGetValue(obj, f3)); // expect: 25
  spreadsheetResetCell(obj, c1);
  printf("%d\n", spreadsheetGetValue(obj, f4)); // expect: 15
  spreadsheetFree(obj);
}
