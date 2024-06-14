# 2037. Minimum Number of Moves to Seat Everyone

"""
there are 'n' seats and 'n' students in a room. you are given an array
'seats' of length 'n' where 'seats[i]' is the position of the i'th seat. you
are also given the array 'students' of length 'n' where 'students[j]' is the
position of the j'th student. you may perform the following move any number
of times. return the minimum number of moves required to move each student to
a seat such that no two students are in the same.
"""


class Solution(object):
    def minMovesToSeat(self, seats, students):
        """
        :type seats: List[int]
        :type students: List[int]
        :rtype: int
        """
        seats.sort()
        students.sort()
        return sum(abs(seat - student) for seat, student in zip(seats, students))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMovesToSeat(seats=[3, 1, 5], students=[2, 7, 4]))
    print(obj.minMovesToSeat(seats=[4, 1, 5, 9], students=[1, 3, 2, 6]))
    print(obj.minMovesToSeat(seats=[2, 2, 6, 6], students=[1, 3, 2, 6]))
