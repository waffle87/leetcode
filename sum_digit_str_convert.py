# 1945. Sum of Digits of String After Convert

"""
you are given a string 's' consisting of lowercase english letters, and an
integer 'k'. first, convert 's' into an integer by replacing each letter with
its position in the alphabet (ie. replace 'a' with 1, 'b' with 2, and so on).
then, transform the integer by replacing it with the sum of its digits.
repeat the transform operation 'k' times in total. return the resulting
integer after performing the operations described above
"""


class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        s = "".join(str(ord(i) - ord("a") + 1) for i in s)
        for _ in range(k):
            s = str(sum(int(i) for i in s))
        return int(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getLucky(s="iiii", k=1))
    print(obj.getLucky(s="leetcode", k=2))
    print(obj.getLucky(s="zbax", k=2))
