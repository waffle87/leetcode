#include "leetcode.h"

class TimeMap {
public:
  unordered_map<string, vector<pair<int, string>>> umvp;
  TimeMap() {}
  void set(string key, string value, int timestamp) {
    umvp[key].push_back({timestamp, value});
  }
  string get(string key, int timestamp) {
    if (!umvp.count(key))
      return "";
    int start = 0, end = umvp[key].size();
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (umvp[key][mid].first > timestamp)
        end = mid;
      else
        start = mid + 1;
    }
    return start > 0 && start <= umvp[key].size() ? umvp[key][start - 1].second
                                                  : "";
  }
};

int main() {
  string key, value;
  int timestamp;
  TimeMap *obj = new TimeMap();
  obj->set(key, value, timestamp);
  string param_2 = obj->get(key, timestamp);
}
