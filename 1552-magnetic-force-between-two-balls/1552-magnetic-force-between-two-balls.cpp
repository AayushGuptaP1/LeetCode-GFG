class Solution {
public:
    bool isPossible(const vector<int>&position,int n, int m,int limit)
    {
        int balls =1;
        int pos = position[0];

        for(int i=1;i<n;i++)
        {
            if(position[i]- pos >= limit)
            {
                balls++;
                pos = position[i];
            }
            if(balls==m)
            return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1, high = position[n-1]- position[0];
        int res = -1;

       while(low<=high)
       {
           int mid = (low+high)/2;

           if(isPossible(position,n,m,mid))
           {
               res = mid;
               low = mid+1;
           }
           else
           high = mid-1;
           
       }
       return res;
    }
};