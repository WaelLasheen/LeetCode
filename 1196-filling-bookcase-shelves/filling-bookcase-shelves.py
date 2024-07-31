class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        cache={}
        def helper(i):
            if i== len(books):
                return 0
            if i in cache:
                return cache[i]
            curr_wid=shelfWidth
            max_h=0
            cache[i]=float("inf")
            for j in range(i,len(books)):
                w,h = books[j]
                if curr_wid < w:
                    break
                curr_wid -=w
                max_h=max(max_h ,h)
                cache[i]=min(cache[i] , helper(j+1)+max_h)

            return cache[i]
            
        return helper(0)