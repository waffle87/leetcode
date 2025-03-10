// 2024. Maximize the Confusion of an Exam
#include "leetcode.h"

/*
 * a teacher is writing a test with 'n' true/false questions. with 'T' denoting
 * true, and 'F' denoting false. he wants to confuse the students by maximising
 * the number of consecutive questions with the same answer (multiple trues or
 * multiple falses in a row) you are given a string 'answer_key', where
 * 'answer_key[i]' is the original answer to the i'th question. in addition, you
 * are given an integer 'k', the following operation:
 * - change the answer key for any question to 'T' or 'F'
 * return the maximum number of consecutive 'T's or 'F's in the answer key after
 * performing the operation at most 'k' times
 */

class Solution {
public:
  int maxConsecutiveAnswers(string answer_key, int k) {
    int n = answer_key.size(), start = 0, end = 0, t = 0, f = 0, ans = 0;
    while (end < n) {
      t += (answer_key[end] == 'T');
      f += (answer_key[end] == 'F');
      while (t > k && f > k) {
        if (answer_key[start] == 'T')
          t--;
        else
          f--;
      }
      ans = max(ans, end - start + 1);
      end++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.maxConsecutiveAnswers("TTFF", 2));     // expect: 4
  printf("%d\n", obj.maxConsecutiveAnswers("TFFT", 1));     // expect: 3
  printf("%d\n", obj.maxConsecutiveAnswers("TTFTTFTT", 1)); // expect: 5
}
