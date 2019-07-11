class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        cur = 0
        idx = 0

        if len(A) == 1:
            return map(int, (str(A[0] + K)))

        # while K or carry:
        for i in range(len(A) - 1, -1, -1):
            cur += A[i]
            cur += (K%10)
            A[i] = (cur % 10)
            K /= 10
            cur /= 10

        print cur, K

        if cur:
            A.insert(0, map(int, (str(cur + K))))

        return A

    def addToArrayForm2(self, A, K):
        '''
        Runtime: 328 ms, faster than 35.98% of
         Python online submissions for Add to Array-Form of Integer.
    Memory Usage: 12.2 MB, less than 24.22% of Python online submissions 
    for Add to Array-Form of Integer.

    O(n^)
        '''
        a=int(''.join(str(i) for i in A))

        res = list(str(a + K))
        ans = []

        for el in res:
            ans.append(int(el))

        return ans


if __name__ == '__main__':
    A = [1,2,0,0]
    K = 34
    print Solution().addToArrayForm(A,K)

    A = [2,7,4]
    K = 181
    # print Solution().addToArrayForm(A,K)

    A = [2,1,5]
    K = 806
    print Solution().addToArrayForm(A,K)

    A = [9,3]
    K = 636
    print Solution().addToArrayForm(A,K)