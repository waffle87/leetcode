// 726. Number of Atoms
#include "leetcode.h"

/*
 * given a string 'formula' representing a chemical formula, return the count of
 * each atom. the atomic element always stats with an uppercase character, then
 * zer or more lowercase letters, representing the name. one or more digits
 * representing that element's count may follow if the count is greater than 1.
 * if the count is 1, no digits will follow. return the count of all elements as
 * a string in the following form: the first name, followed by its count,
 * followed by the second name, followed by its count, and so on.
 */

class Solution {
public:
  string countOfAtoms(string formula) {
    string ans;
    const int n = formula.size();
    int i = 0;
    map<string, int> cnts = parse_formula(formula, i);
    for (pair<string, int> p : cnts) {
      ans += p.first;
      if (p.second > 1)
        ans += to_string(p.second);
    }
    return ans;
  }

private:
  map<string, int> parse_formula(string &s, int &i) {
    map<string, int> cnts;
    const int n = s.size();
    while (i < n && s[i] != ')') {
      map<string, int> cnt = parse_unit(s, i);
      merge(cnts, cnt, 1);
    }
    return cnts;
  }
  map<string, int> parse_unit(string &s, int &i) {
    map<string, int> cnts;
    const int n = s.size();
    if (s[i] == '(') {
      map<string, int> cnt = parse_formula(s, ++i);
      int digits = parse_digits(s, ++i);
      merge(cnts, cnt, digits);
    } else {
      int i0 = i++;
      while (i < n && islower(s[i]))
        i++;
      string atom = s.substr(i0, i - i0);
      int digits = parse_digits(s, i);
      cnts[atom] += digits;
    }
    return cnts;
  }
  int parse_digits(string &s, int &i) {
    int i0 = i;
    while (i < s.size() && isdigit(s[i]))
      i++;
    int digits = i == i0 ? 1 : stoi(s.substr(i0, i - i0));
    return digits;
  }
  void merge(map<string, int> &cnts, map<string, int> &cnt, int times) {
    for (pair<string, int> p : cnt)
      cnts[p.first] += p.second * times;
  }
};

int main() {
  Solution obj;
  char f1[] = "H2O", f2[] = "Mg(OH)2", f3[] = "K4(ON(SO3)2)2";
  cout << obj.countOfAtoms(f1) << endl; // expect: H2O
  cout << obj.countOfAtoms(f2) << endl; // expect: H2MgO2
  cout << obj.countOfAtoms(f3) << endl; // expect: K4N2O14S4
}
