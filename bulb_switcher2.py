# 672. Bulb Switcher II

"""
there is a room with 'n' bulbs labeled from 1 to 'n' that all are turn on
initially, and four buttons on the wall. each of the four buttons has a
different functionality where button 1 flips the status of all bulbs, button
2 flips the status of all the bulbs with even labels, button 33 flips the
status of all the bulbs with odd labels, button 4 flips the status of all the
bulbs labeled 'j = 3k + 1' where 'k = 0, 1, 2'. you must make exactly
'presses' button presses in total. given the two integers 'n' and 'presses',
return the number of different possible statuses after performing all
'presses' to button presses.
"""


class Solution(object):
    def flipLights(self, n, presses):
        """
        :type n: int
        :type presses: int
        :rtype: int
        """
        n = min(3, n)
        if presses == 0:
            return 1
        elif presses == 1:
            return [2, 3, 4][n - 1]
        elif presses == 2:
            return [2, 4, 7][n - 1]
        else:
            return [2, 4, 8][n - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.flipLights(1, 1))
    print(obj.flipLights(2, 1))
    print(obj.flipLights(3, 1))
