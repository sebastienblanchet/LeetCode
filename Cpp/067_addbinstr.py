
class Solution(object):
    '''
Success
Details
Runtime: 40 ms, faster than 15.22% of Python online submissions for Add Binary.
Memory Usage: 11.8 MB, less than 49.09% of Python online submissions for Add Binary.
'''

    def addBinaryBrute(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        # add leading zeros
        na = len(a)
        nb = len(b)

        if na != nb:
            # Add leading zeros
            if na > nb:
                b = ''.join(('0'*(na-nb), b))
            else:
                a = ''.join(('0'*(nb-na), a))

        n = max(na, nb)

        ans = ''

        carry = 0

        for i in range(n-1, -1, -1):

            cur = int(a[i]) + int(b[i])

            if cur == 2 and carry:
                ans = ''.join(('1', ans))
                carry = 1

            elif cur == 1 and carry or cur == 2:
                ans = ''.join(('0', ans))
                carry = 1

            elif cur == 0 and carry:
                ans = ''.join(('1', ans))
                carry = 0

            elif cur == 1:
                ans = ''.join(('1', ans))

            else:
                ans = ''.join(('0', ans))

        if carry:
            ans = ''.join(('1', ans))

        return ans

        '''
        Success
Details
Runtime: 20 ms, faster than 95.46% of Python online submissions for Add Binary.
Memory Usage: 11.8 MB, less than 35.05% of Python online submissions for Add Binary.
        '''
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ans = ''
        carry = 0
        i = len(a) - 1
        j = len(b) - 1

        while i >= 0 or j >= 0 or carry:

            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1

            temp = str(carry % 2)
            ans = ''.join((temp, ans))
            carry /= 2

        return ans


if __name__ == '__main__':
    print Solution().addBinary('11', '1')
    print Solution().addBinary('1010', '1011')
