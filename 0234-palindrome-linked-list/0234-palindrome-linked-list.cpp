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
    bool isPalindrome(ListNode* head) 
    {
        ListNode *fast = head, *slow = head;
        ListNode *prev = NULL, *curr = slow->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow->next = prev;
            prev = slow;
            slow = curr;
            curr = curr->next;            
        }
        slow = fast==NULL? slow : slow->next;
        
        fast = prev;
        
        while(slow != NULL)
        {
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};