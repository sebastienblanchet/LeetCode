class Solution(object):

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        K = 2

        # Sort list, timsort, nlogn
        nums.sort()

        # Init results
        ans = []

        self.findKSum(nums, target, K, [], ans)

        return ans
    
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        K = 4

        # Sort list, timsort, nlogn
        nums.sort()

        # Init results
        ans = []

        self.findKSum(nums, target, K, [], ans)

        return ans


    def findKSum(self, nums, target, K, temp, ans):
        # Base cae
        if (len(nums) < K) or (K < 2):
            return

        # 2Sum case
        if K == 2:
            # Init pointers
            l = 0
            r = len(nums) - 1

            # Traverse through array
            while (l < r):
                sumlr = nums[l] + nums[r]
                # Match exist, add 
                if sumlr == target:
                    ans.append(temp + [nums[l], nums[r]])

                    # Move pointers
                    l +=1
                    r -=1

                    # Deal with duplicates
                    while (l < r) and (nums[l] == nums[l-1]):
                        l +=1

                    while (r > l) and (nums[r] == nums[r+1]):
                        r -=1
                
                # if less, increase value of l (move inward)
                elif sumlr < target:
                    l +=1

                # decrease value of r
                else:
                    r -=1

        # Not 2 sum, use recursion
        else:
            return


if __name__ == '__main__':
    nums = [-1, 0, 3, 4, 5]
    target = 3
    print Solution().twoSum(nums, target)