class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        l = Counter(s1.split() + s2.split())

        return [s for s,n in l.items() if n==1]

        