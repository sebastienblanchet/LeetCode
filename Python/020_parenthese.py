'''
20. Valid Parentheses
Easy

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.
'''

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        n = len(s)

        d = {
            '(':')', 
            '{':'}',
            '[':']'
        }

        # Base case, no pairs
        if n % 2:
            return False

        for char in s:
            # opening bracket
            if char in ("(", "[", "{"):
                stack.append(char)
            
            # closing must match
            elif stack:
                if not (char == d[stack.pop()]):
                    return False 
            else:
                return False
            
        if stack:
            return False
        else:
            return True



if __name__ == '__main__':
     
    tests = ["(((", "()", "()[]{}", "(]", "([)]", "{[]}"]
    anss = [False, True, True, False, False, True]
    soln = Solution()

    for ans, test in zip(anss, tests):
        if ans is soln.isValid(test):
            print "PASS {}".format(test)
        else:
            print "FAIL {}".format(test)

