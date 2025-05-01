class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        res=0
        for i in range(0,len(words),1):
            for j in range(i+1,len(words),1):
                l=len(words[i])
                if words[i] == words[j][-l:] and words[i] == words[j][:l]:
                    res +=1
        
        return res