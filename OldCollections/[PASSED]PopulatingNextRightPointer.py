import os
import sys

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right= None
        self.next = None

def connect(root):
    if root == None:
        return None
    if root.left != None and root.right != None:
        root.left.next = root.right
        root.right = None
    if root.right != None and root.next != None:
        root.right.next = root.next.left

    connect(root.left)
    connect(root.right)
    
def main():
    pass
if __name__ == '__main__':
    main()
