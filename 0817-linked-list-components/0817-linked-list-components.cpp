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
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        unordered_set<int> st(begin(nums),end(nums));
        ListNode *temp = head;
        int count = 0;
        
        while(temp != nullptr)
        {
            if(st.find(temp->val) != st.end())
            {
                count++;
                while(temp && st.find(temp->val) != st.end())
                {
                    temp = temp->next;                    
                }                    
            }
            else
            temp = temp->next;               
        }
        return count;          
    }
};