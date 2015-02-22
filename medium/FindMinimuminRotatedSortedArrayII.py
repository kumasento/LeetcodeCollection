
class Solution:
    def findMin(self, num):
        l, r = 0, len(num)-1
        min_val = num[0]
        while l < r-1:
            mid = (l+r) / 2
            if num[mid] > num[l]:
                min_val = min(min_val, num[l])
                l = mid+1
            elif num[mid] < num[l]:
                min_val = min(min_val, num[mid])
                r = mid-1
            else:
                l += 1
        min_val = min(min_val, num[l])
        min_val = min(min_val, num[r])
        return min_val

sol = Solution()
print sol.findMin([3,1,2,3,3,3])
