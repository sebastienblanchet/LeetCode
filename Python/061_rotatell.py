# 61. Rotate List
# Medium

# Given a linked list, rotate the list to the right by k places,
#  where k is non-negative.

# Definition for singly-linked list.


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
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        n = listLen(head)
        inc = 0

        # Just go to end
        if k > n:
            k = 0

        right = head
        left = head
        cur = left

        # Go to len - kth element and move that to front, get two lists
        while inc < (n - k):
            inc += 1
            right = right.next
            cur = left.next

        cur = cur.next
        cur.next = Non
        # Now go to end of right 
        cur = right

        while cur.next:
            cur = cur.next

        cur.next = left

        return right


def main(rng, ans, k):

    ll = genLL(rng)
    ansl = genLL(ans)
    res = Solution().rotateRight(ll, k)
    printList(res)
    printList(ansl)

    if not listEqual(res, ansl):
        print "FAIL"


if __name__ == '__main__':

    # Input: 1->2->3->4->5->NULL, k = 2
    rng = range(1, 6)
    # Output: 4->5->1->2->3->NULL
    ans = [4, 5, 1, 2, 3]

    main(rng, ans, 2)
