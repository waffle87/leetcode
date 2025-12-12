# 3433. Count Mentions Per User

"""
you are given an integer 'numberOfUsers' representing the total number of
users and an array 'events' of size 'n x 3'. each 'events[i]' can be either
of the following types: message event indicates that a set of users was
mentioned in a message at 'timestamp' offline even indicates that the user
'id_i' has become offline at 'timestamp_i' for 60 time units. the user will
automatically be online again at time 'timestamp_i + 60'. return an array
'mentions' that represents the number of mentions the user with id 'i' has
across all 'MESSAGE' events. all users are initially online, and if a user
goes offline or comes back online, their status change is processed before
handling any message event that occurs at the same timestamp
"""


class Solution(object):
    def countMentions(self, numberOfUsers, events):
        """
        :type numberOfUsers: int
        :type events: List[List[str]]
        :rtype: List[int]
        """
        mentions = [0] * numberOfUsers
        online = [1] * numberOfUsers
        users = range(numberOfUsers)
        events.sort(key=lambda x: (int(x[1]), x[0] == "MESSAGE"))
        for action, stamp, mentioned in events:
            if action == "MESSAGE":
                if mentioned == "ALL":
                    for user in users:
                        mentions[user] += 1
                elif mentioned == "HERE":
                    for user in users:
                        if online[user] <= int(stamp):
                            mentions[user] += 1
                else:
                    for id in mentioned.replace("id", "").split(" "):
                        mentions[int(id)] += 1
            else:
                online[int(mentioned)] = int(stamp) + 60
        return mentions


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countMentions(
            numberOfUsers=2,
            events=[
                ["MESSAGE", "10", "id1 id0"],
                ["OFFLINE", "11", "0"],
                ["MESSAGE", "71", "HERE"],
            ],
        )
    )
    print(
        obj.countMentions(
            numberOfUsers=2,
            events=[
                ["MESSAGE", "10", "id1 id0"],
                ["OFFLINE", "11", "0"],
                ["MESSAGE", "12", "ALL"],
            ],
        )
    )
    print(
        obj.countMentions(
            numberOfUsers=2, events=[["OFFLINE", "10", "0"], ["MESSAGE", "12", "HERE"]]
        )
    )
