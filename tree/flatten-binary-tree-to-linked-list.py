# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        while root is not None:
            root = self.__shift_right_node(root)
            root.left = None
            root = root.right
    
    def __shift_right_node(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        if root.left is None:
            return root
        if root.right is None:
            root.right = root.left
            return root
        
        right_node: TreeNode = root.right
        root.right = root.left
        
        tempnode: TreeNode = root.right
        while tempnode.right is not None:
            tempnode = tempnode.right
        tempnode.right = right_node
        
        return root
