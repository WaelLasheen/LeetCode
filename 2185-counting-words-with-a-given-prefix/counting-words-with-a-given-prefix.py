class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        l = len(pref)
        res=0
        for i in words:
            if i[:l] == pref:
                res +=1
        
        return res