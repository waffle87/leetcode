# 424. Longest Repeating Character Replacement

"""
given a string 's' and an integer 'k'. you can choose any character of the
string and change it to any other uppercase english character. you can
perform this operation at most 'k' times. return the length of the longest
substring containing the same letter you can get after performing the above
operations.
"""


class Solution(object):
    def characterReplacement(self, s, k):
        max_cnt = ans = 0
        cnt = collections.Counter()
        for i in range(len(s)):
            cnt[s[i]] += 1
            max_cnt = max(max_cnt, count[s[i]])
            if ans - max_cnt < k:
                ans += 1
            else:
                cnt[s[i - ans]] -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.characterReplacement("ABAB", 2))  # expect: 4
    print(obj.characterReplacement("AABABBA", 1))  # expect: 4
