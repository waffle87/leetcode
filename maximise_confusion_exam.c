// 2024. Maximize the Confusion of an Exam
#include <math.h>
#include <stdio.h>
#include <string.h>

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

int maxConsecutiveAnswers(char *answer_key, int k) {
  int n = strlen(answer_key), left = 0, right = 0, t = 0, f = 0, ans = 0;
  while (right < n) {
    if (answer_key[right] == 'T') {
      t++;
      ans = fmax(ans, t);
    } else {
      f++;
      ans = fmax(ans, f);
    }
    right++;
    if ((right - left) > ans + k) {
      if (answer_key[left] == 'T')
        t--;
      else
        f--;
      left++;
    }
  }
  return right - left;
}

int main() {
  char ak1[] = {"TTFF"}, ak2[] = {"TFFT"}, ak3[] = {"TTFTTFTT"};
  printf("%d\n", maxConsecutiveAnswers(ak1, 2)); // expect: 4
  printf("%d\n", maxConsecutiveAnswers(ak2, 1)); // expect: 3
  printf("%d\n", maxConsecutiveAnswers(ak3, 1)); // expect: 5
}
