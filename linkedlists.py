class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    tot1 = 0
    tot2 = 0
    i = 0
    j = 0
    n1 = l1
    n2 = l2
    while True:
        tot1 += n1.val * (10^i)
        print(n1.val * (10^i))
        if n1.next == None:
            break
        else:
            n1 = n1.next
            i += 1
    while True:
        tot2 += n2.val * (10^j)
        print(n2.val * (10^j))
        if n2.next == None:
            break
        else:
            n2 = n2.next
            j += 1
    print(tot1)
    print(tot2)