// 460. LFU Cache
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// https://en.wikipedia.org/wiki/Least_frequently_used
// http://dhruvbird.com/lfu.pdf

struct Node {
  int value;
  list<int>::iterator itr;
};

class LFUCache {
private:
  unordered_map<int, Node> umVal;
  unordered_map<int, int> umCount;
  unordered_map<int, list<int>> umlCountKey;
  int lowFreq, maxCap;

public:
  LFUCache(int capacity) {
    maxCap = capacity;
    lowFreq = 0;
  }
  int get(int key) {
    if (umVal.find(key) == umVal.end() || maxCap <= 0)
      return -1;
    put(key, umVal[key].value);
    return umVal[key].value;
  }
  void put(int key, int value) {
    if (maxCap <= 0)
      return;
    if (umVal.find(key) == umVal.end()) {
      if (umVal.size() == maxCap) {
        int del = umlCountKey[lowFreq].back();
        umlCountKey[lowFreq].pop_back();
        if (umlCountKey[lowFreq].empty())
          umlCountKey.erase(lowFreq);
        umVal.erase(del);
        umCount.erase(del);
      }
      umVal[key].value = value;
      umCount[key] = 0;
      lowFreq = 0;
      umlCountKey[umCount[key]].push_front(key);
      umVal[key].itr = umlCountKey[0].begin();
    } else {
      umlCountKey[umCount[key]].erase(umVal[key].itr);
      if (umlCountKey[umCount[key]].empty()) {
        if (lowFreq == umCount[key])
          lowFreq++;
        umlCountKey.erase(umCount[key]);
      }
      umVal[key].value = value;
      umCount[key]++;
      umlCountKey[umCount[key]].push_front(key);
      umVal[key].itr = umlCountKey[umCount[key]].begin();
    }
  }
};

int main() {
  int capacity, key, value;
  LFUCache *obj = new LFUCache(capacity);
  int param_1 = obj->get(key);
  obj->put(key, value);
}
