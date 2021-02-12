# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def __len__(self):
        return len(self.coordinate_row)
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ls1 = [l1.val]
        while(l1.next != None):
            l1 = l1.next
            ls1.append(l1.val)
        ls2 = [l2.val]
        while(l2.next != None):
            l2 = l2.next
            ls2.append(l2.val)
        if len(ls1) != len(ls2):
            if len(ls1) > len(ls2):
                ls2 = ls2[:len(ls2)] + [0] * (len(ls1) - len(ls2))
                print(ls2)
            else:
                ls1 = ls1[:len(ls1)] + [0] * (len(ls2) - len(ls1))
        print(ls1, ls2)
        flag = False
        output = [] 
        for i in range(max(len(ls1),len(ls2))):
            if (flag == True):
                output.append((ls1[i] + ls2[i] + 1)%10)
            else:
                output.append((ls1[i] + ls2[i])%10)
            if (ls1[i] + ls2[i])/10 >= 1:
                flag = True
            elif flag == True and (ls1[i] + ls2[i] + 1)/10 >= 1:
                flag = True
            else:
                flag = False
        if flag == True:
            output.append(1)
        node = ListNode(output[0])
        node_tmp = node
        for i in range(1,len(output)):
            node_tmp.next = ListNode(output[i])
            node_tmp = node_tmp.next
        return node