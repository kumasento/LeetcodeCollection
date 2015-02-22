
class Solution:
    def search(self, A, target):
        l, r = 0, len(A)-1
        while l <= r:
            m = (l+r) / 2
            if A[m] == target:
                return m
            if A[m] < A[r]:
                if target <= A[r] and target > A[m]:
                    l = m + 1
                else:
                    r = m - 1
            else:
                if target >= A[l] and target < A[m]:
                    r = m - 1
                else:
                    l = m + 1
        return -1

sol = Solution()
print sol.search([4,5,6,7,0,1,2], 0)
print sol.search([4,5,6,7,0,1,2], 1)
print sol.search([4,5,6,7,0,1,2], 9)
print sol.search([4,5,6,7,0,1,2], 2)
