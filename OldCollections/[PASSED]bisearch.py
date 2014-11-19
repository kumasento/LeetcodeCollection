
from sys import *

def biSearch(num, val):
    l = 0
    r = len(num)-1
    while l <= r:
        print "%d %d" % (l, r)
        mid = l+(r-l)/2
        if num[mid] == val:
            return mid
        elif num[mid] < val:
            l = mid + 1
        else:
            r = mid - 1

    return -1
     
if __name__ == '__main__':
    if len(argv[1:]) == 0:
        print "Error: Wrong Parameter Number"
        exit(1)

    val = int(argv[1])
    num = range(1,101) 
    print "search value %d in list [1..100]" % val
    print "#result="+str(biSearch(num, val))
