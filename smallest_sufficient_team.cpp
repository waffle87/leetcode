// 1125. Smallest Sufficient Team
#include "leetcode.h"

/*
 * in a project, you have a list of required required skills ' req_skills' and a
 * list of people. the i'th person 'people[i]' contains a list of skills that
 * the person has. consider a sufficient team: a set of people such that for
 * every required skill in 'req_skills', there is at least one person in the
 * tema who has that skill. we can represent these teams by the index of each
 * person. return any sufficient team of the smallest possible size, represented
 * by the index of each person. you may return the answer in any order. it is
 * guaranteed an answer exists
 */

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vvd(string) & people) {
    int n = req_skills.size();
    unordered_map<int, vector<int>> ans;
    ans.reserve(1 << n);
    ans[0] = {};
    unordered_map<string, int> skill_map;
    for (int i = 0; i < n; i++)
      skill_map[req_skills[i]] = i;
    for (int i = 0; i < people.size(); i++) {
      int curr = 0;
      for (int j = 0; j < people[i].size(); j++)
        curr |= 1 << skill_map[people[i][j]];
      for (auto k = ans.begin(); k != ans.end(); k++) {
        int com = k->first | curr;
        if (ans.find(com) == ans.end() ||
            ans[com].size() > 1 + ans[k->first].size()) {
          ans[com] = k->second;
          ans[com].push_back(i);
        }
      }
    }
    return ans[(1 << n) - 1];
  }
};

int main() {
  Solution obj;
  vector<string> rs1 = {"java", "nodejs", "reactjs"};
  vvd(string) p1 = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  vector<string> rs2 = {"algorithms", "math",   "java",
                        "reactjs",    "csharp", "aws"};
  vvd(string) p2 = {{"algorithms", "math", "java"},
                    {"algorithms", "math", "reactjs"},
                    {"java", "csharp", "aws"},
                    {"reactjs", "csharp"},
                    {"csharp", "math"},
                    {"aws", "java"}};
  for (auto i : obj.smallestSufficientTeam(rs1, p1))
    printf("%d ", i); // expect: 0 2
  printf("\n");
  for (auto i : obj.smallestSufficientTeam(rs2, p2))
    printf("%d ", i); // expect: 1 2
  printf("\n");
}
