# -*- coding: utf-8 -*-
# @Author: Seb Blanchet
# @Date:   2019-06-04 18:48:37
# @Last Modified by:   Seb Blanchet
# @Last Modified time: 2019-06-05 12:46:22




class Solution(object):
    
    # Returns index of x in arr if present, else -1 
    def binarySearch(self, arr, l, r, x): 
      
        # Check base case 
        if r >= l: 
      
            mid = l + (r - l)/2
      
            # If element is present at the middle itself 
            if arr[mid] == x: 
                return mid 
              
            # If element is smaller than mid, then it  
            # can only be present in left subarray 
            elif arr[mid] > x: 
                return self.binarySearch(arr, l, mid-1, x) 
      
            # Else the element can only be present  
            # in right subarray 
            else: 
                return self.binarySearch(arr, mid + 1, r, x) 
      
        else: 
            # Element is not present in the array 
            return False

'''
Runtime: 52 ms, faster than 64.01% of Python online submissions for Search a 2D Matrix.
Memory Usage: 13.6 MB, less than 73.95% of Python online submissions for Search a 2D Matrix.
'''

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        # Found flag
        found = False
        
        # Convert matrix to array
        arr =[]

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                arr.append(matrix[r][c])

        return self.binarySearch(arr, 0, len(arr), target)





if __name__ == '__main__':
    matrix = [
        [1,   3,  5,  7],
        [10, 11, 16, 20],
        [23, 30, 34, 50]
    ]

    target = 3
    print Solution().searchMatrix(matrix, target)