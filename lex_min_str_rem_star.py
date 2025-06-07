# 3170. Lexicographically Minimum String After Removing Stars
from queue import PriorityQueue

"""
you are given a string 's'. it may contain any number of '' characters. your
task to remove all '' characters. while there is a '' character, do the
following: delete the leftmost '' and the smallest non-'' character to its
left. if there are several smallest characters, you can delete any of them.
return the lexicographically smallest resulting string after removing all ''
characters.
"""


class Solution(object):
    def clearStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        pq = PriorityQueue()
        idx = [[] for i in range(26)]
        remove_set = set()
        for i in range(len(s)):
            if s[i] == "*":
                remove_set.add(i)
                c = pq.get()
                pq.put(c)
                remove_set.add(idx[ord(c) - ord("a")][-1])
                del idx[ord(c) - ord("a")][-1]
                if len(idx[ord(c) - ord("a")]) == 0:
                    pq.get()
                continue
            if len(idx[ord(s[i]) - ord("a")]) == 0:
                pq.put(s[i])
            idx[ord(s[i]) - ord("a")].append(i)
        ans = ""
        for i in range(len(s)):
            if i not in remove_set:
                ans += str(s[i])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.clearStars(s="aaba*"))
    print(obj.clearStars(s="abc"))
