def longestSubstring(s: str) -> int:
    if s == "":
        return 0
    start = 0
    end = 0
    maxLength = 0
    uniqueCharacter = set()
    
    while end < len(s):
        if s[end] not in uniqueCharacter:
            uniqueCharacter.add(s[end])
            end += 1
            maxLength = max(maxLength, len(uniqueCharacter))
        else:
            uniqueCharacter.remove(s[start])
            start += 1
    return maxLength

#should output 3, as "abc" is the longest substring that occurs
print(longestSubstring("abcabcbb"))
