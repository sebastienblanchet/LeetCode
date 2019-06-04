# 169. Majority Element
# Easy
# Given an array of size n, find the majority element. 
# You may assume that the array is non-empty and the majority element
#  always exist in the array.
#  Success
# Details
# Runtime: 136 ms, faster than 73.02% of Python online submissions for Majority Element.
# Memory Usage: 13.4 MB, less than 56.88% of Python online submissions for Majority Element.


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        n = len(nums)
        ans = 0
        numsset = list(set(nums))

        # Generate dictionary
        d = {el:nums.count(el) for el in numsset}

        key = max(d, key =d.get)

        if d[key] >= (n/2):
            ans = key
            
        return ans

if __name__ == '__main__':
    temp = [2,2,1,1,1,2,2]
    print Solution().majorityElement(temp)
    temp = [3,3,4]
    print Solution().majorityElement(temp)