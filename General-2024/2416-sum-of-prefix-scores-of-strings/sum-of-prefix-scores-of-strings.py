from collections import defaultdict

class Solution:
    def sumPrefixScores(self, words):
        freq = defaultdict(int)

        for word in words:
            for i in range(1, len(word) + 1):
                prefix = word[:i]
                freq[prefix] += 1

        result = []
        for word in words:
            score = 0
            for i in range(1, len(word) + 1):
                prefix = word[:i]
                score += freq[prefix]
            result.append(score)

        return result
