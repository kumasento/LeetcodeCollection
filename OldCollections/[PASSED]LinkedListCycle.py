import sys

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @question in LeetCode
def hasCycle(head):
    fast = slow = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
        if fast == slow:
            return True
    return False
# corresponding questions
def printLinkedList(head):
    if hasCycle(head):
        print "has cycle, return"
        return None
    p = head
    while p != None:
        print "%3d ->" % p.val,
        p = p.next
    print "end"
def lengthOfCycle_regular(head):    
    fast = slow = head
    while fast != None and fast.next != None:
        fast = fast.next.next
        slow = slow.next
        if fast == slow: #first meet
            break
    if fast == None: 
        print "Error: no cycle"
        return -1

    fast = fast.next.next
    slow = slow.next
    move_time = 1
    while fast != slow:
        fast = fast.next.next
        slow = slow.next
        move_time += 1
    return move_time 

def lengthOfCycle_nofast(head):
    if not hasCycle(head):
        print "Error: no cycle"
        return -1
    fast = slow = head
    fast = fast.next.next
    slow = slow.next
    while fast != slow:
        fast = fast.next.next
        slow = slow.next

    length = 1
    slow = slow.next
    while slow != fast:
        slow = slow.next
        length += 1
    return length
def lengthOfCycle_formula(head):
    if hasCycle(head) == False:
        print "Error: no cycle"
        return -1
    fast = slow = head
    fast = fast.next.next
    slow = slow.next
    length = 1
    while fast != slow:
        fast = fast.next.next
        slow = slow.next
        length += 1
    return length

if __name__ == '__main__':

    node_num = 10
    if len(sys.argv[1:]) > 0:
        node_num = int(sys.argv[1])

    head = ListNode(0)
    tmp = head
    for i in range(1,node_num):
        tmp.next = ListNode(i)
        tmp = tmp.next
        
        #print hasCycle(head)
    
    printLinkedList(head)
    rear = tmp
    for i in range(node_num):
        p = head
        for j in range(i):
            p = p.next
        rear.next = p

        print "connected to point: %d" % p.val
        print "\t[hasCycle] \t\tcheck: " + str(hasCycle(head))
        print "\t[lengthOfCycle] \t(regular)check: " + str(lengthOfCycle_regular(head))
        print "\t[lengthOfCycle] \t(nofast) check: " + str(lengthOfCycle_nofast(head))
        print "\t[lengthOfCycle] \t(formula)check: " + str(lengthOfCycle_formula(head))
        
        rear.next = None
     
