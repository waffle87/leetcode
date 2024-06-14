#include "leetcode.h"

class UndergroundSystem {
public:
  unordered_map<int, pair<string, int>> checkIns;
  unordered_map<string, pair<int, int>> routes;
  UndergroundSystem() {}
  void checkIn(int id, string stationName, int t) {
    checkIns[id] = {stationName, t};
  }
  void checkOut(int id, string stationName, int t) {
    auto [stn, start] = checkIns[id];
    checkIns.erase(id);
    string route = stn + "," + stationName;
    routes[route].first++;
    routes[route].second += t - start;
  }
  double getAverageTime(string startStation, string endStation) {
    auto &[count, sum] = routes[startStation + "," + endStation];
    return (double)sum / count;
  }
};

int main() {}
