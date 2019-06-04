class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        carry = 0

        # while K or carry:
        for i in range(len(A) - 1, -1, -1):
            cur = A[i] + (K % 10)
            A[i] = (cur % 10) + carry
            carry = cur / 10

            if A[i] >= 10:
                A[i] %= 10
                carry = 1

            K /= 10
            print K

        if carry:
            A.insert(0, 1)

        return A

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

    A = [0]
    K = 23
    print Solution().addToArrayForm(A,K)