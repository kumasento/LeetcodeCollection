
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def preorderTraversal(root):
    if root == None:
        return []
    preorder_stack = [ root ]
    result = []
    while len(preorder_stack):
        tmp = preorder_stack[-1]
        result.append(tmp.val)
        del preorder_stack[-1]
        if tmp.right != None:
            preorder_stack.append(tmp.right)
        if tmp.left != None:
            preorder_stack.append(tmp.left)

    return result

def inorderTraversal(root):
    if root == None:
        return []
    in_stack = [ root ]
    vis = {}
    res = []
    while len(in_stack) != 0:
        tmp = in_stack[-1]
        if tmp.left != None and not vis.has_key(tmp.left):
            in_stack.append(tmp.left)
        else:
            res.append(tmp.val)
            del in_stack[-1]
            vis[tmp] = True
            if tmp.right != None and not vis.has_key(tmp.right):
                in_stack.append(tmp.right)

    return res


if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    print "PreOrder: " + str(preorderTraversal(root))
    print "InOrder:  " + str(inorderTraversal(root))
