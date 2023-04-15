class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp; 
        priority_queue<pair<int,char>> pq;
        string res = "";
        
        for(auto &c : s)
            mp[c]++;
        
        for(auto &x : mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty())
        {
            int length = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            
            while(length--)
            {
                res += c;
            }
        }
        return res;
        
        
    }
};