# 557. Reverse Words in a String III

"""
given a string 's', reverse the order of characters in each word within a
sentence while still preserving whitespace and initial word order
"""


class Solution(object):
    def reverseWords(self, s):
        return " ".join(map(lambda word: word[::-1], s.split()))


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseWords("Let's take Leetcode contest"))
    print(obj.reverseWords("God Ding"))
