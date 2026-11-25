class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        
        sets = {}

        for i in strs:
            a = str(sorted(i))

            if a in sets:
                sets[a].append(i)
            else :
                sets[a] = [i]

        return list(sets.values())