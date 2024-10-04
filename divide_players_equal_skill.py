# 2491. Divide Players Into Teams of Equal Skill

"""
you are given a positive integer array 'skill' of even length 'n' where
'skill[i]' denotes the skill of the i'th player. divide the players into 'n /
2' teams of size '2' such that the total skill of each team is equal. the
chemistry of  team is equal to the product of the skills of the players on
that team. return the sum of the chemistry of all the teams, or return -1 if
there is no way to divide the players into teams such that the total skill of
each team is equal
"""


class Solution(object):
    def dividePlayers(self, skill):
        """
        :type skill: List[int]
        :rtype: int
        """
        skill.sort()
        ans, team = 0, skill[0] + skill[-1]
        for i in range(len(skill) // 2):
            if skill[i] + skill[-i - 1] == team:
                ans += skill[i] * skill[-i - 1]
            else:
                return -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.dividePlayers(skill=[3, 2, 5, 1, 3, 4]))
    print(obj.dividePlayers(skill=[3, 4]))
    print(obj.dividePlayers(skill=[1, 1, 2, 3]))
