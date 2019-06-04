# 41. First Missing Positive
# Hard

# Runtime: 24 ms, faster than 68.91% of Python online submissions for First Missing Positive.
# Memory Usage: 11.9 MB, less than 11.42% of Python online submissions for First Missing Positive.
# Next challenges: 
# Given an unsorted integer array, find the smallest missing positive integer.

class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 1
        nums = list(set(nums))
        nums.sort()
        print nums
        
        for el in nums:
            if el <= ans and el > 0:
                ans += 1
        
        return ans

if __name__ == '__main__':
    test = [3,17,7,16,16,8,-4,5,-4,3,-2,18,34,5,1,-7,3,3,27,8,23,3,-3,2,27,8,15,7,-6,15,23,-6,3,2,5,23,21,3,2]
    res = Solution().firstMissingPositive(test)
    print res