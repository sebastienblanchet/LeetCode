'''
97. Interleaving String
Hard

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

'''

class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        s = list(s1 + s2)
        s3 = list(s3)

        if len(s) != len(s3):
            return False

        while s3:

            char = s3.pop()
            print "s3 {}".format(s3)
            print char
            print "s  {}".format(s)
            print "\n"
            
            if char in s:
                s.remove(char)
            else:
                return False

        return True
        

def main():

    soln = Solution()

    s1 = "abc"
    s2 = "def"
    s3 = "abcdeff"
    print soln.isInterleave(s1, s2, s3)

    s1 = "aabcc"
    s2 = "dbbca"
    s3 = "aadbbcbcac"
    # print soln.isInterleave(s1, s2, s3)

    s1 = "aabcc"
    s2 = "dbbca"
    s3 = "aadbbbaccc"
    # print soln.isInterleave(s1, s2, s3)


if __name__ == '__main__':
    main()