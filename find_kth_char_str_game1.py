# 3304. Find the K-th Character in String Game I

"""
alice and bob are playing a game. initially, alice has a string 'word = "a"'.
you are given a positive integer 'k'. now, bob will ask alice to perform the
following operation forwever: generate a new string by changing each
character in 'word' to its next character in the english alphabet and append
it to the original 'word'. return the value of the k'th character in 'word'
after enough operations have been done for 'word' to have at least 'k'
characters. note that character 'z' can be changed to 'a' in the operation.
"""


class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        return chr(ord("a") + (k - 1).bit_count())


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthCharacter(k=5))
    print(obj.kthCharacter(k=10))
