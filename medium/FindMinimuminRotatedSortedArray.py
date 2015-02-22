
class Solution:
    def findMin(self, num):
        l, r = 0, len(num) - 1
        while l < r and num[l] > num[r]:
            mid = (l + r) / 2
            if num[mid] < num[r]:
                r = mid
            else:
                l = mid + 1
        return num[l]

sol = Solution()
print sol.findMin([4,5,6,7,0,1,2])
