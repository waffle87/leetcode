# 1684. Count the Number of Consistent Strings

"""
you are given a string 'allowed' consisting of distinct characters and an
array of strings 'words'. a string is consistent if all characters in the
string appear in the string 'allowed'. return the number of consistent
strings in the array
"""


class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        allowed = set(allowed)
        cnt = 0
        for w in words:
            for l in w:
                if l not in allowed:
                    cnt += 1
                    break
        return len(words) - cnt


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countConsistentStrings(
            allowed="ab", words=["ad", "bd", "aaab", "baa", "badab"]
        )
    )
    print(
        obj.countConsistentStrings(
            allowed="abc", words=["a", "b", "c", "ab", "ac", "bc", "abc"]
        )
    )
    print(
        obj.countConsistentStrings(
            allowed="cad", words=["cc", "acd", "b", "ba", "bac", "bad", "ac", "d"]
        )
    )
