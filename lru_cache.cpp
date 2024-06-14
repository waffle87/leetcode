// 146. LRU Cache
#include "leetcode.h"

/*
 * design a data structure that follows the constraints of a least recently used
 * cache (LRU). implete the 'LRUCache' class. the functions 'get' and 'put' must
 * each run in O(1) average time complexity
 */

class LRUCache {
private:
  typedef list<int> li;
  typedef pair<int, li::iterator> pii;
  typedef unordered_map<int, pii> hipii;
  hipii cache;
  li used;
  int _capacity;
  void touch(hipii::iterator i) {
    int key = i->first;
    used.erase(i->second.second);
    used.push_front(key);
    i->second.second = used.begin();
  }

public:
  LRUCache(int capacity) { _capacity = capacity; }
  int get(int key) {
    auto i = cache.find(key);
    if (i == cache.end())
      return -1;
    touch(i);
    return i->second.first;
  }
  void put(int key, int value) {
    auto i = cache.find(key);
    if (i != cache.end())
      touch(i);
    else {
      if (cache.size() == _capacity) {
        cache.erase(used.back());
        used.pop_back();
      }
      used.push_front(key);
    }
    cache[key] = {value, used.begin()};
  }
};

int main() {
  LRUCache *obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  printf("%d\n", obj->get(1)); // expect: 1
  obj->put(3, 3);
  printf("%d\n", obj->get(2)); // expect: -1
  obj->put(4, 4);
  printf("%d\n", obj->get(1)); // expect: -1
  printf("%d\n", obj->get(3)); // expect: 3
  printf("%d\n", obj->get(4)); // expect: 4
}
