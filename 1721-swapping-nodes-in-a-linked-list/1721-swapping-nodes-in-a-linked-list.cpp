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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *first,*second = head,*temp = head;
        
        
        while(temp!= NULL)
        {
            second = second->next;
            if(--k == 0)
            {
                first = temp;
                second = head;
            }
            temp = temp->next;
            
            
                
        }
        
        swap(first->val,second->val);
        return head;
        
        
    }
};