# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
        
class Solution:
    def preorder(self, root: Node) -> List[int]:
        return self.__preorder(root)
    
    def __preorder(self, rootnode: Node) -> List[int]:
        if rootnode is None:
            return []
        
        result: List[int] = [rootnode.val]
            
        for i in range(len(rootnode.children)):
            result += self.__preorder(rootnode.children[i])
        
        return result
