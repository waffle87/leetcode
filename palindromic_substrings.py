# 647. Palindromic Substrings

"""
given a string 's', return the number of palindromic substrings in it. a
string is a palindrome when it reads the same backward as forward. a
substring is a contiguous sequence of charcters within the string.
"""


class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, ans = len(s), 0

        def palindrome_count(left, right):
            cnt = 0
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                cnt += 1
            return cnt

        for i in range(n):
            even = palindrome_count(i, i + 1)
            odd = palindrome_count(i, i)
            ans += even + odd
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubstrings("abc"))
    print(obj.countSubstrings("aaa"))
