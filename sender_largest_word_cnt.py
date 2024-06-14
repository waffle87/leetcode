# 2284. Sender With Largest Word Count
from collections import defaultdict

"""
you have a chat log of 'n' messages. you are given two string arrays
'messages' and 'senders' where 'messages[i]' is a message sent by
'senders[i]'. a message is a list of words that are separated by a single
space with no leading or trailing spaces. the word count of a sender is the
total number of words sent by the sender. note that a sender may send more
than one message. return the sender with the largest word count. if there is
more than one sender with the largest word count, return the one with the
lexicographically largest name
"""


class Solution(object):
    def largestWordCount(self, messages, senders):
        word_cnt = defaultdict(int)
        for m, person in zip(messages, senders):
            word_cnt[person] += len(m.split())
        max_len = max(word_cnt.values())
        names = sorted(
            [name for name, words in word_cnt.items() if words == max_len], reverse=True
        )
        return names[0]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.largestWordCount(
            [
                "Hello userTwooo",
                "Hi userThree",
                "Wonderful day Alice",
                "Nice day userThree",
            ],
            ["Alice", "userTwo", "userThree", "Alice"],
        )
    )  # expect: Alice
    print(
        obj.largestWordCount(
            ["How is leetcode for everyone", "Leetcode is useful for practice"],
            ["Bob", "Charlie"],
        )
    )  # expect: Charlie
