class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>> & graph, vector<int> res, int i, vector<bool> visited){
        int n=graph.size()-1;
        res.push_back(i);
        if(i==n){
            ans.push_back(res);
            return;
        }
        visited[i]=true;
        
        for(auto  x: graph[i]){
            if(visited[x]==false) helper(graph,res,x,visited);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<int> res;
        helper(graph,res,0,visited);
        return ans;
    }
};