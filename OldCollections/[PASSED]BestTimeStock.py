class Solution:
    def maxProfit(self, prices):
        if len(prices) <= 1:
            return 0
        sum = 0
        for idx,p in enumerate(prices[1:]):
            d = prices[idx+1] - prices[idx]
            if d >= 0:
                sum += d
        return sum

if __name__ == '__main__':
    #Here are some test instances:
    sol = Solution()
    print sol.maxProfit([])
    print sol.maxProfit([0])
    print sol.maxProfit([1,2])
    print sol.maxProfit([2,1])
    print sol.maxProfit([2,3,1])

