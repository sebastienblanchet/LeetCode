'''
45. Jump Game II
Hard

Given an array of non-negative integers,
 you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at 
that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

'''

class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        Success
Details
Runtime: 80 ms, faster than 59.48% of Python online submissions for Jump Game II.
Memory Usage: 13.3 MB, less than 55.59% of Python online submissions for Jump Game II.
Next challenges: 
        """
        n = len(nums)

        # Base case
        if n <= 1: return 0

        left = 0
        right = nums[0]
        count = 1


        while right < n-1:

            count += 1
            jump = max(i + nums[i] for i in range(left, right + 1))
            left, right = right, jump

        return count



if __name__ == '__main__':
    
    print Solution().jump([2,3,1,1,4])