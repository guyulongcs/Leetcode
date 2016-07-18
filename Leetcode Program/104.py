class Solution(object):
    def maxDepth(self, root):

        leftDepth = 0
        rightDepth = 0
        if root == None:
            return 0

        if root.left != None:
            leftDepth = self.maxDepth(root.left)

        if root.right != None:
            rightDepth = self.maxDepth(root.right)

        maxDepthRes = leftDepth
        if maxDepthRes < rightDepth:
            maxDepthRes = rightDepth

        maxDepthRes = maxDepthRes + 1
        return maxDepthRes

