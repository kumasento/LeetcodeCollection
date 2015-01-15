
def maxSubArray(A):
    length = len(A)
    if length == 0:
        return 0
    if length == 1:
        return A[0]
    mid = length / 2
    #devide into 2 parts
    left_A = A[0:mid]               #left
    right_A = A[mid+1:length-1]     #right
    
    maxleft = maxSubArray(left_A)
    maxright = maxSubArray(right_A)
    maxsum = max(maxleft, maxright)
    
    maxmid = 0
    midsum = 0
    for val in  
    

def main():
    A = [−2,1,−3,4,−1,2,1,−5,4]
    maxSubArray(A)
    pass

if __name__ == '__main__':
    main()
