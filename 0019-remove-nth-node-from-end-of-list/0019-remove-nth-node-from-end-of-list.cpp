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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *first = head, *second = head;
        ListNode *temp;
        
        while(n--)
        {
            first = first->next;
        }
        
        if(first == NULL)
        {
            temp = head->next;
            delete head;
            return temp;
        }
        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        temp = second->next;
        second->next = temp->next;
        delete temp;
        return head;
    }
};