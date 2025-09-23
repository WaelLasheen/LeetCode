class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        arr1 = version1.split('.')
        arr2 = version2.split('.')
        s = max(len(version1),len(version2))
        arr1 +=['0']*(s-len(arr1))
        arr2 +=['0']*(s-len(arr2))
        for i in range(0,s,1):
            if(int(arr1[i]) > int(arr2[i])):
                return 1
            if(int(arr1[i]) < int(arr2[i])):
                return -1
        
        return 0
        