# 451. Sort Characters By Frequency

"""
given a string 's', sort it in decreasing order based on the frequency of the
characters. the frequenc of a character is the number of times itappears in
the string. return the sorted string. if there are multiple answers, return
any of them
"""


class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = Counter(s)
        s = list(s)
        s.sort(key=lambda x: (-cnt[x], x))
        return "".join(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.frequencySort("tree"))
    print(obj.frequencySort("cccaaa"))
    print(obj.frequencySort("Aabb"))
