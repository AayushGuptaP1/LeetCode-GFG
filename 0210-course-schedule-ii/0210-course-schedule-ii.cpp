class Solution {

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> topSort;
        vector<vector<int>>graph(numCourses);
        vector<int>dep(numCourses);
        queue<int> q;
        
        
        for(auto &u : prerequisites)
        {
            graph[u[1]].push_back(u[0]);
            dep[u[0]]++;            
        }
        
        for(int i=0;i<numCourses;++i)
        {
            if(dep[i]==0)
            {
                q.push(i);
                
            }
                
        }
        
        while(q.empty()==false)
        {
            int temp = q.front();
            q.pop();
            topSort.push_back(temp);
            
            for(int i=0;i<graph[temp].size();++i)
            {
                --dep[graph[temp][i]];
                if(dep[graph[temp][i]]==0)
                {
                    q.push(graph[temp][i]);
                    
                }
                    
            }
        }
        if(topSort.size()==numCourses)
            return topSort; 
        else
        return {};
        
            
            
        
        
        
            
    }
};