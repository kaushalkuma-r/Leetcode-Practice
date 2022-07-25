class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
          int n=pairs.size();
        if(n==1) return 1;
        sort(pairs.begin(),pairs.end());
        int dp[n];
        for(int i=0;i<n;i++) dp[i]=1;
        int mx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] < pairs[i][0]) dp[i]=dp[j]+1;  
            }     
            mx=max(mx,dp[i]);
        }
       
        return mx;
    }
};