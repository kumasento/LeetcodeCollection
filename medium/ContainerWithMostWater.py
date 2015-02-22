
class Solution:
    def maxArea(self, height):
        len_of_height = len(height)
        if len_of_height <= 0:
            return 0
        max_of_all, l_ptr, r_ptr = 0, 0, len_of_height-1
        while l_ptr != r_ptr:
            max_of_all = max(max_of_all,
                             min(height[l_ptr], height[r_ptr])
                             * (r_ptr-l_ptr))
            if height[l_ptr] >= height[r_ptr]:
                r_ptr -= 1
            else:
                l_ptr += 1
        return max_of_all

sol = Solution()
print sol.maxArea([1,1])
print sol.maxArea([3,5,2,1,3])

