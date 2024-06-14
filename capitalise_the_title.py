# 2129. Capitalize the Title

"""
given a string 'title' consisting of one or more words separated by a single
space. where each word consists of english letters. capitalise the string by
changing the capitalisation of each word such that if the length of the word
is 1 or 2 letters, change all letters to lowercase. otherwise,change the
first letter to uppercase and the remaining letters to lowercase. return the
capitalised title.
"""


class Solution(object):
    def capitalizeTitle(self, title):
        """
        :type title: str
        :rtype: str
        """
        return " ".join(
            [word.lower() if len(word) < 3 else word.title() for word in title.split()]
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.capitalizeTitle(title="capiTalIze tHe titLe"))
    print(obj.capitalizeTitle(title="First leTTeR of EACH Word"))
    print(obj.capitalizeTitle(title="i lOve leetcode"))
