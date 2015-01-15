
def searchInsert(A, target):
    length = len(A)
    if length == 0:
        return None
    l = 0
    r = length-1
    while l <= r:
        mid = l + (r-l)/2
        val = A[mid]
        if val == target:
            return mid
        elif val < target:
            l = mid + 1
        else:
            r = mid - 1
    return l

def main():
    A, target = ([1,3,5,6], 5)
    print searchInsert(A, target)
    A, target = ([1,3,5,6], 2)
    print searchInsert(A, target)
    A, target = ([1,3,5,6], 7)
    print searchInsert(A, target)
    A, target = ([1,3,5,6], 0)
    print searchInsert(A, target)


if __name__ == '__main__':
    main()
