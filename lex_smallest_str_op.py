# 1625. Lexicographically Smallest String After Applying Operations

"""
you are given a string 's' of even length consisting of digits from 0 to 9,
and two integers 'a' and 'b'. you can apply either of the following two
operations any number of times in any order on 's': add 'a' to all odd
indices of 's', or rotate 's' to the right by 'b' positions. return the
lexicographically smallest string you can obtain by applying the above
operations. a string 'a' is lexicographically smaller than a string 'b' if in
the first position where 'a' and 'b' differ, string 'a' has a letter that
appears earlier in the alphabet than the corresponding letter in 'b'.
"""


class Solution(object):
    def findLexSmallestString(self, s, a, b):
        """
        :type s: str
        :type a: int
        :type b: int
        :rtype: str
        """
        n, ans = len(s), s
        vis = [False] * n
        s, i = s + s, 0
        while not vis[i]:
            vis[i] = True
            for j in range(10):
                lim = 0 if b % 2 == 0 else 9
                for k in range(lim + 1):
                    tmp = list(s[i : i + n])
                    for p in range(1, n, 2):
                        tmp[p] = str((int(tmp[p]) + j * a) % 10)
                    for p in range(0, n, 2):
                        tmp[p] = str((int(tmp[p]) + k * a) % 10)
                    tmp_str = "".join(tmp)
                    if tmp_str < ans:
                        ans = tmp_str
            i = (i + b) % n
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLexSmallestString(s="5525", a=9, b=2))
    print(obj.findLexSmallestString(s="74", a=5, b=1))
    print(obj.findLexSmallestString(s="0011", a=4, b=2))
