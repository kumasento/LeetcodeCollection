class Solution:
    def singleNumber(self, A):
        ans = 0
        for i in A:
            ans ^= i
            print ans
        return ans

if __name__ == '__main__':
    A = [1,2,1,3,3,4,2]
    sol = Solution()
    print sol.singleNumber(A)
