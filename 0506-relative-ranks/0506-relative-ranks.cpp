class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        int count = 1;
        vector<string> res(n);
        
        for(int i=0;i<n;++i)
        {
            pq.push({score[i],i});
        }
        
        while(pq.empty() == false)
        {
            auto t = pq.top();
            pq.pop();
            
            if(count == 1)            
                res[t.second] = "Gold Medal";
            
            else if(count == 2)
                res[t.second] = "Silver Medal";
            else if(count == 3)
                res[t.second] = "Bronze Medal";
            else
                res[t.second] = to_string(count);
            count++;
        }
        
        return res;
        
        
        
    }
};