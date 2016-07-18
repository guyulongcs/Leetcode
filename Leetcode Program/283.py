
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i=0
        j=0
        n = len(nums)
        for i in range(0,n):
            if(nums[i] != 0):
                nums[j] = nums[i]
                j = j + 1
                
        for k in range(j,n):
            nums[k] = 0
