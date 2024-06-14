# 648. Replace Words
from collections import defaultdict

"""
in english we have a concept called root, which can be followed by some other
word to form another longer word lets call this word derivative. for example
when the root "help" is followed by the word "ful" we can form a derivative
"helpful". given a dictionary consisting of many roots and a 'sentence'
consisting of words separated by spaces, replace all the derivatives in the
sentence with the root forming it. if a derivative can be replaced by more
than one root, replace it with the root that has the shortest length. return
the 'sentence' after the replacement
"""


class Solution(object):
    def replaceWords(self, dictionary, sentence):
        """
        :type dictionary: List[str]
        :type sentence: str
        :rtype: str
        """
        _trie = lambda: defaultdict(_trie)
        trie = _trie()
        end = True
        for w in dictionary:
            curr = trie
            for l in w:
                curr = curr[l]
            curr[end] = w

        def replace(word):
            curr = trie
            for l in word:
                if l not in curr:
                    break
                curr = curr[l]
                if end in curr:
                    return curr[end]
            return word

        return "".join(map(replace, sentence.split()))


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.replaceWords(
            dictionary=["cat", "bat", "rat"],
            sentence="the cattle was rattled by the battery",
        )
    )
    print(
        obj.replaceWords(
            dictionary=["a", "b", "c"], sentence="aadsfasf absbs bbab cadsfafs"
        )
    )
