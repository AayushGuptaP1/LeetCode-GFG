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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        int firstIndex = -1, lastIndex = -1, index = 0;
        ListNode* ahead = head->next, *tail = head;
        vector<int> res= {INT_MAX,INT_MIN};
        
        while(ahead->next != nullptr)
        {
            if((ahead->val > tail->val && ahead->val > ahead->next->val) || (ahead->val < tail->val && ahead->val < ahead->next->val))
            {
                if(lastIndex != -1)
                    res[0] = min(res[0],index-lastIndex);
                if(firstIndex == -1)
                {
                    firstIndex = index;
                }
                lastIndex = index;
            }
            tail = ahead;
            ahead = ahead->next;  
            index++;
        }
        res[1] = lastIndex-firstIndex;
        if(firstIndex == lastIndex)
            return {-1,-1};
        return res;
        
    }
};