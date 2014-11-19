
import sys

class Solution:
    # @return a tuple, (index1, index2)
    def biSearch(self, tuple_num, val):
        #assume that entered num is not null
        l = 0
        r = len(tuple_num)-1
        while l <= r:
            mid = l + (r-l)/2
            if tuple_num[mid][0] == val:
                return mid
            elif tuple_num[mid][0] < val:
                l = mid + 1
            else:
                r = mid - 1
        return -1
        
    def twoSum(self, num, target):

        tuple_num = [(j, i) for i, j in enumerate(num)]
        tuple_num = sorted(tuple_num)
        for i in range(len(tuple_num)):
            val = tuple_num[i][0]
            idx = self.biSearch(tuple_num[i+1:], target-val)
            if idx >= 0:
                idx = i + 1 + idx
                return (tuple_num[i][1]+1, tuple_num[idx][1]+1)
        

if __name__ == '__main__':
    if len(sys.argv[1:]) == 0:
        print "Error"
        exit(1)

    num = map(int, sys.argv[1:-1])
    val = int(sys.argv[-1])

    print "#num=" + str(sys.argv[1:-1])
    print "#val=" + sys.argv[-1]

    sol = Solution()
    print sol.twoSum(num, val)


