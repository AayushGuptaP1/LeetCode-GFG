class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        q.push({sr,sc});
        visited[sr][sc] = true;
        
        while(q.empty() == false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row-1>=0 && row-1<m && image[row-1][col]==image[sr][sc] && visited[row-1][col] == false)
            {
                image[row-1][col] = color;
                visited[row-1][col] = true;
                q.push({row-1,col});
            }
            if(row+1>=0 && row+1<m && image[row+1][col]==image[sr][sc] && visited[row+1][col] == false)
            {
                image[row+1][col] = color;
                visited[row+1][col] = true;
                q.push({row+1,col});
            }
            if(col-1>=0 && col-1<n && image[row][col-1]==image[sr][sc] && visited[row][col-1] == false)
            {
                image[row][col-1] = color;
                visited[row][col-1] = true;
                q.push({row,col-1});
            }
            if(col+1>=0 && col+1<n && image[row][col+1]==image[sr][sc] && visited[row][col+1] == false)
            {
                image[row][col+1] = color;
                visited[row][col+1] = true;
                q.push({row,col+1});
            }
        }
        image[sr][sc] = color;
        return image;
    }
};