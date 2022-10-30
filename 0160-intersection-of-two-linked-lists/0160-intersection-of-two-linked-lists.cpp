/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
       
        ListNode *dummy1 = headA, *dummy2 = headB;
        
        while(dummy1 != dummy2)
        {
            if(dummy1)
                dummy1 = dummy1->next;
            else
                dummy1 = headB;
            if(dummy2)
                dummy2 = dummy2->next;
            else
                dummy2 = headA;
        }
        return dummy1;
    }
};