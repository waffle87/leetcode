# 1177. Can Make Palindrome from Substring

"""
you are given a string 's' and array 'queries' where 'queries[i] = [left_i,
right_i, k_i]'. we may rearrange the substring 's[left_i, ..., right_i]' for
each query and then choose up to 'k_i' f them to replace with any lowercase
english letter. if the substring is possible to be a palindrome string after
the operations above, the result of the query is 'true'. otherwise, the
result is 'false'. return a boolean array 'answer' where 'answer[i]' is the
result of the i'th query 'queries[i]'. note that each letter replacement is
counted individualy for replacement, so if, for example 's[left_i, ...,
right_i] = "aaa"', and 'k_i = 2', we can only replace two of the letters.
also note that no query modifies the initial string 's'.
"""


class Solution(object):
    def canMakePaliQueries(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        n, m = 26, len(s) + 1
        ints = list(map(lambda x: ord(x) - ord("a"), s))
        dp = [0] * m
        for i in range(1, m):
            dp[i] = dp[i - 1] ^ (1 << ints[i - 1])
        ones = lambda x: bin(x).count("1")
        return [ones(dp[r + 1] ^ dp[l]) >> 1 <= k for l, r, k in queries]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.canMakePaliQueries(
            s="abcda", queries=[[3, 3, 0], [1, 2, 0], [0, 3, 1], [0, 3, 2], [0, 4, 1]]
        )
    )
    print(obj.canMakePaliQueries(s="lyb", queries=[[0, 1, 0], [2, 2, 1]]))
