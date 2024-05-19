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
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode *front = head->next, *back = head;
        
        while(back && front)
        {
            back->next = new ListNode(gcd(back->val,front->val),front);
            back = front;
            front = front->next;
        }
        return head;        
    }
};