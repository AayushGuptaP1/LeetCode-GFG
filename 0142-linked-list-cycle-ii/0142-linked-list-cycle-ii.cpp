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
    ListNode *detectCycle(ListNode *head) 
    {
        
//         ListNode *fast = head, *slow = head;
//         ListNode *meet = NULL;
        
//          while(fast && fast->next)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
            
//             if(slow == fast)
//             break;
//         }
        
//         if(fast == NULL)
//         return NULL;
//         slow = head;
//         while(fast != slow)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         return fast;
       if(head == NULL || head->next == NULL)
             return NULL;
        ListNode *fast = head, *slow = head;
        
         do
        {
            slow = slow->next;
             fast = fast->next;
             if(fast->next)
                 fast = fast->next;
         }
         while(slow != fast && fast->next != NULL);
             if(fast->next == NULL)
                 return NULL;
         slow = head;
         while(slow != fast)
         {
             slow = slow->next;
             fast = fast->next;
         }
         return slow;
    }
};