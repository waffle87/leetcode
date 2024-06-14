# 1813. Sentence Similarity III

"""
a sentence is a list of words that are separated by a single space with no
leading or trailing spaces. for example, "hello world", "hello", and
"hellohello world world" are all sentences. words consist of only uppercase
and lowercase english letters. two sentences 's1' and 's2' are similar if it
is possible to insert an arbitrary sentence possibly empty inside one of
these sentences such that the two sentences become equal. given two sentences
's1' and 's2', return true if 's1' and 's2' are similar, otherwise return
false.
"""


class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        while s1:
            if s2[0] == s1[0]:
                s2.pop(0)
                s1.pop(0)
            elif s2[-1] == s1[-1]:
                s2.pop()
                s1.pop()
            else:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.areSentencesSimilar(sentence1="My name is Haley", sentence2="My Haley"))
    print(obj.areSentencesSimilar(sentence1="of", sentence2="A lot of words"))
    print(obj.areSentencesSimilar(sentence1="Eating right now", sentence2="Eating"))
