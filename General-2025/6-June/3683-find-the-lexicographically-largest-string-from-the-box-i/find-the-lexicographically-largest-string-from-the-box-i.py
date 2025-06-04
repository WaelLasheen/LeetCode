class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends==1:
            return word

        n = len(word)- numFriends+1
        res= word[:n]
        for i in range(1,len(word)):
            for j in range(min(len(res),len(word)-i)):
                if res[j] < word[i+j]:
                    res =word[i:i+n]
                    break
                elif res[j] > word[i+j]:
                    break
        
        return res