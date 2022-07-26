class Solution {
public:
    void helper(vector<vector<int>> & graph, int i, vector<bool> &visited){
        
    
        visited[i]=true;
        
        for(auto  x: graph[i]){
            if(visited[x]==false) helper(graph,x,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        helper(rooms,0,visited);
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};