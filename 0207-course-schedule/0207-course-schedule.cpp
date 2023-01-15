class Solution {
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>graph(numCourses);
        vector<int> inDegree(numCourses,0);
        queue<int>q;
        
        for(auto &e : prerequisites)
        {
            graph[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
        }   
        
        int count = 0;
        
        for(int i=0;i<numCourses;++i)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
                ++count;                
            }                               
        }
        
        while(q.empty()==false)
        {
            int temp = q.front();
            q.pop();
            
            for(int i=0;i<graph[temp].size();++i)
            {
                inDegree[graph[temp][i]]--;
                if(inDegree[graph[temp][i]]==0)
                {
                    q.push(graph[temp][i]);
                    ++count;
                }                     
            }
        }
          return count==numCourses;     
        
    }
};