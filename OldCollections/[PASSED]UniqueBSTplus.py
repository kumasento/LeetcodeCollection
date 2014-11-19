
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTreesWithNumber(self, begin, end):
        if end < begin: 
            return [ None ]
        if end == begin:
            return [ TreeNode(begin) ]

        result = []
        for i in range(begin, end+1):
            left_res  = self.generateTreesWithNumber(begin, i-1)
            right_res = self.generateTreesWithNumber(i+1, end)
            for l in left_res:
                for r in right_res:
                    root = TreeNode(i)
                    root.left = l
                    root.right = r
                    result.append(root)
                
        return result
    def generateTrees(self, n):
        return self.generateTreesWithNumber(1, n)



if __name__ == '__main__':
    sol = Solution()
    for i in range(1, 4):
        print i
        root_list = sol.generateTrees(i)

        for root in root_list:
            bfs_queue = [ root ]
            while len(bfs_queue) > 0:
                r = bfs_queue[0]
                del bfs_queue[0]
                if r.left != None:
                    bfs_queue.append(r.left)
                if r.right != None:
                    bfs_queue.append(r.right)
                print r.val,

            print ""
