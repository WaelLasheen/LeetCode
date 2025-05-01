class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        arr = sentence.split()
        l = len(searchWord)
        for i ,s in enumerate(arr):
            if searchWord == s[0:l]:
                return i+1
        
        return -1