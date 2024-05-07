/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int doubleLL(ListNode* head)
    {
        if(head == nullptr)
            return 0;
        head->val = head->val*2 +  doubleLL(head->next);
        int carry = head->val/10;
        head->val %= 10;
        return carry;
    }
public:
    ListNode* doubleIt(ListNode* head) 
    {
        int res = doubleLL(head);
        if(res)
        {
            return new ListNode(res,head);
        }
        return head;
    }
};