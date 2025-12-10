# 3577. Count the Number of Computer Unlocking Permutations

"""
you are given an array 'complexity' of length 'n'. there are 'n' computers
locked in a room with labels from 0 to 'n - 1', each with its own unique
password. the password of the computer 'i' has a complexity 'complexity[i]'.
the password for the computer labeled 0 is already decrypted and serves as
the root. all other computers must be unlocked using it or another previously
unlocked computer. you can decrypt the password for the computer 'i' using
the password for computer 'j' where 'j' is any integer less than 'i' with a
lower complexity. to decrypt the password for computer 'i', you must already
unlocked computer 'j'. find the number of permutations that represent a valid
order in which the computers can be unlocked.
"""


class Solution(object):
    def countPermutations(self, complexity):
        """
        :type complexity: List[int]
        :rtype: int
        """
        n, ans = len(complexity), 1
        mod = 10**9 + 7
        for i in range(1, n):
            if complexity[i] <= complexity[0]:
                return 0
            else:
                ans = (ans * i) % mod
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPermutations(complexity=[1, 2, 3]))
    print(obj.countPermutations(complexity=[3, 3, 3, 4, 4, 4]))
