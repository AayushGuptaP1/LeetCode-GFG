class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int count = 0;
        int n = strs.size();
        int size = strs[0].length();
        
        for(int i=0;i<size;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};