class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size(), water = 0;
        
        vector<int>lMax(n),rMax(n);
        
        lMax[0] = height[0];
        rMax[n-1] = height[n-1];
        
        for(int i=1;i<n;i++)
        {
            lMax[i] = max(lMax[i-1],height[i]);
        }
        
        for(int i=n-2;i>0;i--)
        {
           rMax[i] = max(rMax[i+1],height[i]);                
        }
        
        for(int i=1;i<n;i++)
        {
            water+= min(rMax[i],lMax[i])-height[i];
        }
        return water;
    }
};