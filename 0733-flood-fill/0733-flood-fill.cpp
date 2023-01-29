class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        int source = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row-1>=0 && row-1<m && image[row-1][col] == source && image[row-1][col] != color)
            {
                image[row-1][col] = color;
                q.push({row-1,col});
            }
            if(row+1>=0 && row+1<m && image[row+1][col] == source && image[row+1][col] != color)
            {
                image[row+1][col] = color;
                q.push({row+1,col});
            }
            if(col-1>=0 && col-1<n && image[row][col-1] == source && image[row][col-1] != color)
            {
                image[row][col-1] = color;
                q.push({row,col-1});
            }
            if(col+1>=0 && col+1<n && image[row][col+1] == source && image[row][col+1] != color)
            {
                image[row][col+1] = color;
                q.push({row,col+1});
            }  
        }
        return image;
    }
};