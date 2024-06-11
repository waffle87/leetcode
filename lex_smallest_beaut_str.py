# 2663. Lexicographically Smallest Beautiful String

"""
a string is beautiful if it consists of the first 'k' letters of the english
lowercase alphabet, it does not contain a palindrome of length 2 or more
which is a palindrome. you are given a beautiful string 's' of length 'n',
and a positive integer 'k'. return the lexicographically smallest string of
length 'n' which is larger than 's', and is beautiful. if there is no such
string, return an empty string.
"""


class Solution(object):
    def smallestBeautifulString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        ans = [ord(c) - ord("a") for c in s]
        n = len(ans) - 1
        while n >= 0:
            ans[n] += 1
            if ans[n] == k:
                n -= 1
            elif ans[n] not in ans[max(n - 2, 0) : n]:
                for j in range(n + 1, len(ans)):
                    ans[j] = min({0, 1, 2} - set(ans[max(0, j - 2) : j]))
                return "".join(chr(ord("a") + i) for i in ans)
        return ""


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestBeautifulString(s="abcz", k=26))
    print(obj.smallestBeautifulString(s="dc", k=4))
