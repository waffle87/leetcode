#include "leetcode.h"

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
  int param_1 = obj->next(price);
}
