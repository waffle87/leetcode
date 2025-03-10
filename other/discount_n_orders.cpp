#include "leetcode.h"

class Cashier {
public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices) {
    count = 0, mod = n, pct = (100.0 - discount) / 100.0;
    for (int i = 0; i < products.size(); ++i)
      tags[products[i]] = prices[i];
  }
  double getBill(vector<int> product, vector<int> amount) {
    count++;
    double ans(0.0);
    for (int i = 0; i < product.size(); ++i)
      ans += tags[product[i]] * amount[i];
    return count % mod ? ans : ans * pct;
  }

private:
  unordered_map<int, int> tags;
  int count, mod;
  double pct;
};

int main() {
  Cashier *obj = new Cashier(n, discount, products, prices);
  double param_1 = obj->getBill(product, amount);
}
