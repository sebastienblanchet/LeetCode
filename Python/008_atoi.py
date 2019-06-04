'''
8. String to Integer (atoi)
Medium
'''

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MIN = -2147483648
        INT_MAX = 2147483648
        if not str or str[0].isalpha():
            return 0
            
        str = list(str)
        ans = 0
        
        neg = False
        
        if '-' in str:
           neg = True 


           

        while str:

            temp = str.pop(0)
            print temp 

            if temp.isdigit():
                ans *= 10
                ans += int(temp)
                
        if neg:
            ans *= -1
            
        # check overflow
        if ans < INT_MIN:
            return INT_MIN

        if ans > INT_MAX:
            return INT_MAX

        
        return ans



if __name__ == '__main__':
    sol = Solution()
    
    # print sol.myAtoi('1234')
    # print sol.myAtoi('1234 with text')
    print sol.myAtoi('text -1234')
    # print sol.myAtoi('-1234')
