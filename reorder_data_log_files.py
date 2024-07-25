# 937. Reorder Data in Log Files

"""
given an array of 'logs'. each log is a space delimited sting of words where
the first word is the identifier. there are two types of logs. letter logs
where all words consist of lowercase english letters, and digit logs where
all words consist of digits. reorder thesse logs so that the letter logs come
before the digit logs, the letter logs are sorted lexicographically by their
contents. if their contents are the same, then sort them lexicographically by
their identifiers, the digit logs maintain their relative order. return the
final order of the logs.
"""


class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        digits, letters = [], []
        for l in logs:
            if l.split()[1].isdigit():
                digits.append(l)
            else:
                letters.append(l)
        letters.sort(key=lambda x: x.split()[1])
        letters.sort(key=lambda x: x.split()[1:])
        ans = letters + digits
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.reorderLogFiles(
            logs=[
                "dig1 8 1 5 1",
                "let1 art can",
                "dig2 3 6",
                "let2 own kit dig",
                "let3 art zero",
            ]
        )
    )
    print(
        obj.reorderLogFiles(
            logs=[
                "a1 9 2 3 1",
                "g1 act car",
                "zo4 4 7",
                "ab1 off key dog",
                "a8 act zoo",
            ]
        )
    )
