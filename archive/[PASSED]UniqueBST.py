class Solution:
    def numTrees(self, n):
        if n <= 1: 
            return 1
        f = [1,1]
        for i in range(2, n+1):
            f.append(0)
            for j in range(0, i):
                f[i] += f[j] * f[i-j-1]
        return f[n]

if __name__ == '__main__':
    sol = Solution()
    for i in range(1, 10):
        print i,
        print sol.numTrees(i)


