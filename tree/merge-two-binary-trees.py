# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def mergeTrees(self, tree1: TreeNode, tree2: TreeNode) -> TreeNode:
        return self.merge(tree1, tree2)
    
    def merge(self, tree1: TreeNode, tree2: TreeNode) -> TreeNode:
        if tree1 is None:
            return tree2
        if tree2 is None:
            return tree1
        
        leftnode: TreeNode = self.merge(tree1.left, tree2.left)
        currnode: TreeNode = TreeNode(tree1.val + tree2.val)
        rightnode: TreeNode = self.merge(tree1.right, tree2.right)

        currnode.left = leftnode
        currnode.right = rightnode
        
        return currnode
