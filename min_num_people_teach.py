# 1733. Minimum Number of People to Teach

"""
on a social network consisting of 'm' users and some friendships between
users, two users can communicate with each other if they know a common
language. you are given an integer 'n', an array 'languages', and an array
'friendships' where there are 'n' languages numbered 1 through 'n',
'languages[i]' is the set of languages the i'th user knows, and
'friendships[i] = [ui, vi]' denotes a friendship between the users 'ui' and
'vi'. you can choose one language and teach it to some users so that all
friends can communicate with eachother. return the minimum number of users
you need to teach. note that friendships are not transitive, meaning if 'x'
is a friend of 'y' and 'y' is a friend of 'z', this doesn't guarantee 'x' is
a friend of 'z'.
"""


class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        """
        :type n: int
        :type languages: List[List[int]]
        :type friendships: List[List[int]]
        :rtype: int
        """
        need = set()
        for u, v in friendships:
            u -= 1
            v -= 1
            valid = False
            for i in languages[u]:
                if i in languages[v]:
                    valid = True
                    break
            if not valid:
                need.add(u)
                need.add(v)
        ans = len(languages) + 1
        for i in range(1, n + 1):
            candidate = 0
            for j in need:
                if i not in languages[j]:
                    candidate += 1
            ans = min(ans, candidate)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumTeachings(
            n=2, languages=[[1], [2], [1, 2]], friendships=[[1, 2], [1, 3], [2, 3]]
        )
    )
    print(
        obj.minimumTeachings(
            n=3,
            languages=[[2], [1, 3], [1, 2], [3]],
            friendships=[[1, 4], [1, 2], [3, 4], [2, 3]],
        )
    )
