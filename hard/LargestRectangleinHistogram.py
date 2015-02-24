
class Solution:
    def largestRectangleArea(self, height):
        idx, max_area = 0, 0
        stack = []
        height.append(0)
        len_of_stack, len_of_height = len(stack), len(height)
        while idx < len_of_height:
            print idx, height[idx], stack, max_area
            len_of_stack = len(stack)
            if len_of_stack == 0 or height[stack[len_of_stack-1]] <= height[idx]:
                stack.append(idx)
                idx += 1
            else:
                left_most_idx = stack.pop()
                len_of_stack = len(stack)
                width_of_area = idx
                if len_of_stack != 0:
                    width_of_area = idx - stack[len_of_stack-1] - 1
                max_area = max(width_of_area * height[left_most_idx], max_area)
        return max_area

sol = Solution()
print sol.largestRectangleArea([2,1,5,6,2,3])
print sol.largestRectangleArea([2,1,2])
