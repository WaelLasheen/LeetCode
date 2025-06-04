class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends==1:
            return word

        n = len(word)- numFriends+1
        res= word[:n]
        for i in range(1,len(word)):
            if res < word[i:i+n]:
                res =word[i:i+n]
        
        return res