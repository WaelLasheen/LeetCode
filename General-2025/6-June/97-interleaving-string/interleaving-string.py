class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if(len(s3) != len(s1) + len(s2)):
            return False

        n,m=len(s1) ,len(s2)
        dp= [[False]*(m+1) for x in range(n+1)]
        dp[n][m]=True

        for i in range(n,-1,-1):
            for j in range(m,-1,-1):
                if(i<n and s1[i]==s3[i+j] and dp[i+1][j]):
                    dp[i][j]=True
                if(j<m and s2[j]==s3[i+j] and dp[i][j+1]):
                    dp[i][j]=True
        
        return dp[0][0]
