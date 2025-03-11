# 1358. Number of Substrings Containing All Three Characters

"""
given a string 's' consisting only of characters 'a', 'b', and 'c'. return
the number of substrings containing at least one occurence of all these
characters 'a', 'b', and 'c'.
"""


class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = {c: 0 for c in "abc"}
        ans, i = 0, 0
        for j in range(len(s)):
            cnt[s[j]] += 1
            while all(cnt.values()):
                cnt[s[i]] -= 1
                i += 1
            ans += i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSubstrings(s="abcabc"))
    print(obj.numberOfSubstrings(s="aaacb"))
    print(obj.numberOfSubstrings(s="abc"))
