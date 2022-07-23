class Solution {
public:
    int helper(string &text, string &text2,int m , int n, vector<vector<int>> & dp){
        if(n==0|| m==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(text[m-1]==text2[n-1]){
            return dp[m][n]=helper(text,text2,m-1,n-1,dp)+1;
        }
        else{
            return dp[m][n]=max(helper(text,text2,m-1,n,dp),helper(text,text2,m,n-1,dp));
        }
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(text1,text2,m,n,dp);
    }
};