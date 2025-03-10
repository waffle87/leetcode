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

class StockSpanner {
public:
  stack<pair<int, int>> storage;
  int idx = 0;
  int next(int price) {
    if (storage.empty()) {
      storage.push({price, idx++});
      return 1;
    } else {
      while (!storage.empty() && price >= storage.top().first)
        storage.pop();
      int ans = 0;
      ans = storage.empty() ? idx + 1 : idx - storage.top().second;
      storage.push({price, idx++});
      return ans;
    }
  }
};

int main() {
  StockSpanner *obj = new StockSpanner();
  printf("%d\n", obj->next(100)); // expect: 1
  printf("%d\n", obj->next(80));  // expect: 1
  printf("%d\n", obj->next(60));  // expect: 1
  printf("%d\n", obj->next(70));  // expect: 2
  printf("%d\n", obj->next(60));  // expect: 1
  printf("%d\n", obj->next(75));  // expect: 4
  printf("%d\n", obj->next(85));  // expect: 6
}
