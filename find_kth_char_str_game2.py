# 3307. Find the K-th Character in String Game II

"""
alice and bob are playing a game. initially, alice has a string 'word = "a"'.
you are given a positive integer 'k'. you are also given an integer array
'operations' where 'operations[i]' represents the type of i'th operation. now
bob will ask alice to perform all operations in sequence: if 'operations[i]
== 0', append a copy of 'word' to itself. if 'operations[i] == 1', generate a
new string by changing each character in 'word' to its next character in the
english alphabet, and append it to the origin 'word'. return the value of the
k'th character in 'word' after performing all the operations.
"""


class Solution(object):
    def kthCharacter(self, k, operations):
        """
        :type k: int
        :type operations: List[int]
        :rtype: str
        """
        ans = (k - 1) & sum(v << i for i, v in enumerate(operations))
        return chr(ord("a") + ans.bit_count() % 26)


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthCharacter(k=5, operations=[0, 0, 0]))
    print(obj.kthCharacter(k=10, operations=[0, 1, 0, 1]))
