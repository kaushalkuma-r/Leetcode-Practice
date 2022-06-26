class Solution {
public:
    int dfs(vector<vector<int>> & grid, int x,int y){
        int n= grid.size();
        int m=grid[0].size();
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1){
           return 0; 
        }
        grid[x][y]=2;
        return(1+dfs(grid,x,y-1)+dfs(grid,x-1,y)+dfs(grid,x,y+1)+dfs(grid,x+1,y));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};