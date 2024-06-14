# 1441. Build an Array With Stack Operations

"""
given an integer array 'target' and an integer 'n'. you have an empty stack
with the two following operations: 'push': pushes an integer to the top of
the stack. 'pop' removes the integer on the top of the stack. you have have a
stream of the integers in the range '[1, n]'. use the two stack operations to
make the numbers in the stack (from the bottom to the top) equal to 'target'.
you should follow the following rules:
- if the stream of the integers is not empty, pick the next integer from the
stream and push it to the top of the stack
- if the stack is not empty pop the integer at the top of the stack
- if at any moment the elements in the stack from the bottom to the top are
equal to 'target' do not read new integers from the stream and do not do more
operations on the stack. return the stack operations needed to build 'target'
following the mentioned rules. if there are multiple valid answers, return
any of them.
"""


class Solution(object):
    def buildArray(self, target, n):
        ans = []
        s = set(target)
        for i in range(1, target[-1] + 1):
            ans.append("Push")
            if i not in s:
                ans.append("Pop")
        return ans
