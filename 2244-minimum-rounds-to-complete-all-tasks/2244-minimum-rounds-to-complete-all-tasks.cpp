class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int,int>mp;
        int count = 0;
        
        for(int &n : tasks)
            mp[n]++;
        
        for(auto &x : mp)
        {   
            if(x.second ==1)
                return -1;
            while(x.second%3 !=0)
            {
                ++count;
                x.second -= 2;
            }
            count += x.second/3;      
                
        }
        return count;
    }
};