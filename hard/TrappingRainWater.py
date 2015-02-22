
class Solution:
    def trap_two_array(self, A):
        length = len(A)
        if length == 0:
            return 0
        dp_left_most = range(length)
        dp_right_most = range(length)

        dp_left_most[0] = 0
        dp_right_most[length-1] = 0
        for idx in xrange(1,length):
            dp_left_most[idx] = max(dp_left_most[idx-1], A[idx-1])
        for idx in reversed(xrange(length-1)):
            dp_right_most[idx] = max(dp_right_most[idx+1], A[idx+1])
        sum_all = 0
        for idx in xrange(length):
            trapped = min(dp_left_most[idx], dp_right_most[idx]) - A[idx]
            if trapped > 0:
                sum_all += trapped
        return sum_all
    def trap_two_pointer(self, A):
        length = len(A)
        if length == 0:
            return 0
        sum_all, l_ptr, r_ptr = 0, 0, length-1
        while l_ptr != r_ptr:
            if A[l_ptr] <= A[r_ptr]:
                l_tmp_ptr = l_ptr + 1
                while l_tmp_ptr != r_ptr and A[l_tmp_ptr] <= A[l_ptr]:
                    sum_all += A[l_ptr] - A[l_tmp_ptr]
                    l_tmp_ptr += 1
                l_ptr = l_tmp_ptr
            else:
                r_tmp_ptr = r_ptr - 1
                while r_tmp_ptr != l_ptr and A[r_tmp_ptr] <= A[r_ptr]:
                    sum_all += A[r_ptr] - A[r_tmp_ptr]
                    r_tmp_ptr -= 1
                r_ptr = r_tmp_ptr
        return sum_all

sol = Solution()
print sol.trap_two_pointer([0,1,0,2,1,0,1,3,2,1,2,1])
