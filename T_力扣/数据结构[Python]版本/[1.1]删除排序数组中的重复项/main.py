class Solution:
    def removeDuplicates(self, nums) :
        for i in range(len(nums)-1 , 0 , -1):
            if nums[i] == nums[i-1]:
                del nums[i]
        return len(nums)
