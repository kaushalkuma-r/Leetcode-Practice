class Solution {
public:
     void helper(int i, int j , vector<vector<int>> &heights, vector<vector<bool>> & visited, vector<pair<int,int>> &points){
        visited[i][j]=true;
        int m=heights.size(), n=heights[0].size();
        for(auto point : points){
            int x=point.first+i, y=point.second+j;
            if(x>=0 && y>=0 && x<m && y<n){
                if(visited[x][y]==false && heights[x][y] >= heights[i][j]){
                    helper(x,y,heights,visited,points);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> ans;
         vector<pair<int, int>> points = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> atlantic(m,vector<bool>(n,false)) , pacific(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            helper(i,0,heights,pacific,points);
            helper(i,n-1,heights,atlantic,points);
        }
        for(int i=0;i<n;i++){
            helper(0,i,heights,pacific,points);
            helper(m-1,i,heights,atlantic,points);
        }
         for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({ i, j });
        
        
        return ans;
    }
};