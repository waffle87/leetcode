# 466. Count The Repetitions

"""
we define 'str = [s, n]' as the string 'str' which consists of the string 's'
concatenated 'n' times. for example 'str == ["abc", 3] = "abcabcabc'. we
define that strng 's1' can be obtained from string 's2' if we can remove some
characters from 's2' such that it becomes 's1'. you are given two strings
's1' and 's2' and two integers 'n1' and 'n2'. you have the two strings 'str1
= [s1, n1]' and 'str2 = [s2, n2]'. return the maximum integer 'm' such that
'str = [str2, m]' can be obtained from 'str1'
"""


class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        start = {}
        s1r, s2r, s2_idx = 0, 0, 0
        while s1r < n1:
            s1r += 1
            for ch in s1:
                if ch == s2[s2_idx]:
                    s2_idx += 1
                    if s2_idx == len(s2):
                        s2r += 1
                        s2_idx = 0
            if s2_idx in start:
                prev_s1r, prev_s2r = start[s2_idx]
                circle_s1r, circle_s2r = s1r - prev_s1r, s2r - prev_s2r
                ans = n1 - prev_s1r
                left_s1r = (n1 - prev_s1r) % circle_s1r + prev_s1r
                for key in start:
                    val = start[key]
                    if val[0] == left_s1r:
                        ans += val[1]
                        break
                return ans
            else:
                start[s2_idx] = (s1r, s2r)
        return s2r


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMaxRepetitions(s1="acb", n1=4, s2="ab", n2=2))
    print(obj.getMaxRepetitions(s1="acb", n1=1, s2="acb", n2=1))
