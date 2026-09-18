# 1520. Maximum Number of Non-Overlapping Substrings

"""
given a string 's' of lowercase letters, you need to find the maximum number
of non-empty substrings of 's' that meet the following conditions: the
substrings do not overlap, that is for any two substrings 's[i..j]' and
's[x..y]', either 'j < x' or 'i > y' is true, and a substring that contains a
certain character 'c' must also contain all occurrences of 'c'. find the
maximum number of substrings that meet the above conditions. if there are
multiple solutions with the same number of substrings, return the one with
minimum total length. it can be shown that there exists a unique solution of
minimum total length. notice that you can return the substrings in any order.
"""


class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        first = {j: i for i, j in reversed(list(enumerate(s)))}
        last = {j: i for i, j in enumerate(s)}
        ans, prev = [], -1
        for i in sorted(last.values()):
            left, right = first[s[i]], last[s[i]]
            j = right
            while j >= left > prev and right == i:
                left = min(left, first[s[j]])
                right = max(right, last[s[j]])
                j -= 1
            if left > prev and right == i:
                ans.append(s[left : right + 1])
                prev = right
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxNumOfSubstrings(s="adefaddaccc"))
    print(obj.maxNumOfSubstrings(s="abbaccd"))
