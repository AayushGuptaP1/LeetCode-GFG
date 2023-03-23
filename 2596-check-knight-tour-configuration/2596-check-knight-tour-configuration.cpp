class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(grid[row][col] == count)
                count++;
            
            int kRow[8] = {-1,-2,-2,-1,1,2,2,1};
            int kCol[8] = {-2,-1,1,2,2,1,-1,-2};
            
            for(int i=0;i<8;++i)
            {
                int dRow = row + kRow[i];
                int dCol = col + kCol[i];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && grid[dRow][dCol]==count)
                    q.push({dRow,dCol});
            }
        }
        return (count== m*n);
        
    }
};