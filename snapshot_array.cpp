// 1146. Snapshot Array
#include "leetcode.h"

/*
 * implement a 'SnapshotArray' class that supports the following interface
 * - 'SnapshotArray(int length)' initialises an array-like data structure with
 * the given length. initially, each element equals zero.
 * - 'void set(index, val)' sets the element at the given 'index' to be equal to
 * 'val'
 * - 'int snap()' takes a snapshot of the array and retusn the 'snap_id': the
 * total number of times we called 'snap()' minus 1
 * - 'int get(index, snap_id)' returns the value at the given 'index', at the
 * time we took the snapshot with the given 'snap_id'
 */

class SnapshotArray {
  int curr_snap = 0;
  vector<vector<pair<int, int>>> vvp;

public:
  SnapshotArray(int length) { vvp = vector<vector<pair<int, int>>>(length); }
  void set(int index, int val) {
    if (vvp[index].empty() || vvp[index].back().first != curr_snap)
      vvp[index].push_back({curr_snap, val});
    else
      vvp[index].back().second = val;
  }
  int snap() { return curr_snap++; }
  int get(int index, int snap_id) {
    auto i = upper_bound(begin(vvp[index]), end(vvp[index]),
                         pair<int, int>(snap_id, INT_MAX));
    return i == begin(vvp[index]) ? 0 : prev(i)->second;
  }
};

int main() {
  SnapshotArray *obj = new SnapshotArray(3);
  obj->set(0, 5);
  printf("%d\n", obj->snap()); // expect: 0
  obj->set(0, 6);
  printf("%d\n", obj->get(0, 0)); // expect: 5
}
