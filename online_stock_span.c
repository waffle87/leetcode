// 901. Online Stock Span
#include "leetcode.h"

/*
 * design an algorithm that collects daily price quotes for some stock and
 * returns the span of that stock's price for the current day. the span of the
 * stock's price in one day is the maximum number of consecutive days (starting
 * from that day and going backward) for which the stock price was less than or
 * equal to the price of that day. if the prices of the stock in the last four
 * days is '[7,34,1,2]' and the price of the stock today is 8, then the span of
 * today is 3 because starting from today, the price of the stock was less than
 * or equal 8 for 3 consecutive days.
 */

typedef struct {
  int first;
  int second;
} pair;

typedef struct {
  pair data;
  struct node *next;
} node;

typedef struct {
  node *top;
} StockSpanner;

node *create_node(pair data) {
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->next = NULL;
  return new;
}

StockSpanner *stockSpannerCreate() {
  StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));
  obj->top = NULL;
  return obj;
}

void push(StockSpanner *obj, pair data) {
  node *curr = create_node(data);
  curr->next = obj->top;
  obj->top = curr;
}

pair pop(StockSpanner *obj) {
  if (obj->top == NULL) {
    pair empty = {0, 0};
    return empty;
  }
  node *tmp = obj->top;
  pair data = tmp->data;
  obj->top = tmp->next;
  free(tmp);
  return data;
}

int stockSpannerNext(StockSpanner *obj, int price) {
  int cnt = 1;
  while (obj->top && obj->top->data.first <= price) {
    cnt += obj->top->data.second;
    pop(obj);
  }
  push(obj, (pair){price, cnt});
  return cnt;
}

void stockSpannerFree(StockSpanner *obj) {
  while (obj->top)
    pop(obj);
  free(obj);
}

int main() {
  StockSpanner *obj = stockSpannerCreate();
  printf("%d\n", stockSpannerNext(obj, 100)); // expect: 1
  printf("%d\n", stockSpannerNext(obj, 80));  // expect: 1
  printf("%d\n", stockSpannerNext(obj, 60));  // expect: 1
  printf("%d\n", stockSpannerNext(obj, 70));  // expect: 2
  printf("%d\n", stockSpannerNext(obj, 60));  // expect: 1
  printf("%d\n", stockSpannerNext(obj, 75));  // expect: 4
  printf("%d\n", stockSpannerNext(obj, 85));  // expect: 6
}
