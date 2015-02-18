
def majorityElement(num):
    ## Moore Voting 
    if len(num) <= 0:
        return None

    candidate = num[0]
    counter = 1
    for i in num[1:]:
        if counter == 0:
            candidate = i
            counter = 1
        elif i != candidate:
            counter -= 1
        else:
            counter += 1
    return candidate
       
