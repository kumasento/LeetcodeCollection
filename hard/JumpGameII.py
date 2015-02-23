
class Solution:
    def jump_dynamic_programming(self, A):
        len_of_A = len(A)
        minimum_jump = [0] * len_of_A
        for idx in reversed(xrange(len_of_A-1)):
            max_jump = A[idx]
            if idx + max_jump >= len_of_A - 1:
                max_jump = len_of_A - idx - 1
            best_jump_choice = minimum_jump[idx+1]
            for i in xrange(1, max_jump):
                best_jump_choice = min(best_jump_choice, minimum_jump[idx+i+1])
            minimum_jump[idx] = 1 + best_jump_choice
        return minimum_jump[0]
    def jump(self, A):
        max_total_range = 0
        max_current_range = 0
        max_jump_steps = 0
        for idx in xrange(len(A)):
            if idx > max_current_range:
                max_current_range = max_total_range
                max_jump_steps += 1
            max_total_range = max(max_total_range, idx + A[idx])
        return max_jump_steps


sol = Solution()
print sol.jump([2,1])
print sol.jump([2,3,1,1,4])
