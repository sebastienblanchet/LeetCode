# 54. Spiral Matrix
# Medium
# Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        ans = []

        if not matrix:
            return ans

        r = len(matrix)
        c = len(matrix[0])

        # directions
        nSteps = [c, r-1]
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        iDir = 0
        ir = 0
        ic = -1
        
        while (nSteps[iDir%2]):
            for i in range(nSteps[iDir%2]):
                ir += dirs[iDir][0]
                ic += dirs[iDir][1]
                ans.extend(matrix[ir][ic])

            # nSteps[iDir%2] -=1

            # next direction
            iDir += 1
            iDir %= 4

        return ans

if __name__ == '__main__':
    mtrx = [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
    print Solution().spiralOrder(mtrx)