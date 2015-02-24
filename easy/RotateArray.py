class Solution:
    def rotate(self, nums, k):
        len_of_nums = len(nums);
        ans = [0] * len_of_nums
        for idx, num in enumerate(nums):
            ans[(idx+k)%len_of_nums] = num
        return ans

sol = Solution()
print sol.rotate([1,2], 1)
print sol.rotate([1,2,3,4,5,6,7],3)
