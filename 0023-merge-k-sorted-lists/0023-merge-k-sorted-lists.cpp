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
    ListNode* mergeTwoLists(ListNode* head1, ListNode *head2)
    {
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        ListNode* first=NULL;
    if(head1 && head2)
    {
       
        ListNode* last;
        if(head1->val<head2->val)
        {
            first = head1;
            last = head1;
            head1 = head1->next;
            last->next = NULL;
            
        }
        else
        {
            first = head2;
            last = head2;
            head2 = head2->next;
            last->next = NULL;
        }
        while(head1 && head2)
        {
            if(head1->val<head2->val)
            {
                last->next = head1;
                head1 = head1->next;
            }
            else
            {
                last->next = head2;
                
                head2 = head2->next;
                
            }  
            last = last->next;           
        }
        if(head1 != NULL)
        last->next = head1;
        if(head2!= NULL)
        last->next = head2;
        
    }
        
    return first;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())return nullptr;
        while(lists.size()>1)
        {
            lists[1] = mergeTwoLists(lists[0],lists[1]);
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};