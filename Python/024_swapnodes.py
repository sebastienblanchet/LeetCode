# 24. Swap Nodes in Pairs
# Medium
# Given a linked list, swap every two adjacent nodes and return its head.
# You may not modify the values in the list's nodes, only nodes itself may be changed.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def printList(list):
    inc = 0
    while (list):
        temp = list.val
        if not inc:
            print temp,
            inc += 1
        else:
            print "-> {}".format(temp),
        list = list.next

    print ""


def genLL(list):
    head = ListNode(list.pop(0))
    cur = head
    while (list):
        temp = ListNode(list.pop(0))
        cur.next = temp
        cur = temp

    return head


def listEqual(l1, l2):

    if listLen(l1) != listLen(l2):
        return False

    while l1 and l2:

        if l1.val != l2.val:
            return False

        l1 = l1.next
        l2 = l2.next

    return True


def listLen(list):
    len = 0

    while (list):
        len += 1
        list = list.next

    return len


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        last = self
        last.next = head

        # https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C%2B%2B-Python-Ruby
        while last.next and last.next.next:
            
            a = last.next
            b = a.next

            last.next, b.next, a.next = b, a, b.next
            
            last = a

        return self.next

def main(rng, ans, k):

    ll = genLL(rng)
    ansl = genLL(ans)
    res = Solution().swapPairs(ll)
    printList(res)

    if not listEqual(res, ansl):
        printList(ansl)
        print "FAIL"


if __name__ == '__main__':

    rng = range(1, 5)
    ans = [2,1, 4,3]
    main(rng, ans, 2)
