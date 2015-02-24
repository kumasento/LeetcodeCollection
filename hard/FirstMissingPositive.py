
class Solution:
    def firstMissingPositive(self, A):
        """ Do this job by swapping
            The number of swap operations should be no more than N
            For each time of swap,
            at least on element will be fixed to one postion"""
        len_of_A = len(A)
        idx = 0
        while idx < len_of_A:
            move_to_pos = A[idx] - 1
            if move_to_pos == idx or move_to_pos < 0 or move_to_pos >= len_of_A or A[move_to_pos] == A[idx]:
                idx += 1
            else:
                tmp = A[move_to_pos]
                A[move_to_pos] = A[idx]
                A[idx] = tmp
        for idx, x in enumerate(A):
            if x-1 != idx:
                return idx + 1
        return len_of_A

sol = Solution()
print sol.firstMissingPositive([3,4,-1,1])
print sol.firstMissingPositive([1,2,0])
print sol.firstMissingPositive([2])
print sol.firstMissingPositive([-1,-2,-3])
