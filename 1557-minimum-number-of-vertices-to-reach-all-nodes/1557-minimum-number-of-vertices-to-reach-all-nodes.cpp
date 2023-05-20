class Solution { 

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> dependencies(n,0);        
      
        vector<bool> visited(n);
        vector<int> res;
        
        
        for(auto &x : edges)
        
            
            dependencies[x[1]]++;
        
        
        for(int i=0; i<n;++i)
        {
            if(dependencies[i] == 0)
               res.push_back(i);
        }
        
       
        return res;
        
        
    }
};