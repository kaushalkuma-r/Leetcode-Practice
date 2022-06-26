class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size(),n=grid[0].size(),count =0;
       queue<pair<int,int>> q1;
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]=='1'){
                   count++;
                   q1.push({i,j});
               
               while(!q1.empty()){
                   pair p=q1.front();
                   q1.pop();
                   int x=p.first , y= p.second;
                   if(grid[x][y]=='0') continue;
                   else{
                       grid[x][y]='0';
                    for(auto dir : dirs) { 
                        int a = x + dir[0];
                        int b = y + dir[1];
                        if(a>=0 && a<m && b>=0 && b<n)
                            q1.push({a,b});
                    }
                   }
               }
               
          }
           }
             
       }
        
      return count;
    }
};