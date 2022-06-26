class Solution {
public:
    bool isSafe(int x,int y,vector<vector<bool>>& visited){
        return (x<visited.size() && y < visited[0].size() && !visited[x][y]);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<int> col{0,1,0,-1};
        vector<int> row{-1,0,1,0};
        queue<pair<int,int>> q1;
        q1.push(make_pair(sr,sc));
        int old=image[sr][sc];
        int n=image[0].size();
        vector<vector<bool>> visited(image.size(),vector<bool>(n,false));
        visited[sr][sc]=true;
        while(!q1.empty()){
            pair<int,int> curr=q1.front();
            q1.pop();
            image[curr.first][curr.second]=newColor;
            for(int i=0;i<4;i++){
                int x= curr.first + row[i];
                int y= curr.second +col[i];
                if(isSafe(x,y,visited) && image[x][y]==old){
                    q1.push(make_pair(x,y));
                    visited[x][y]=true;
                }
            }
        }
        return image;
    }
};
