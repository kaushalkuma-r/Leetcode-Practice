class Solution {
public:
    int helper(vector<int>&nums1,vector<int>&nums2, int m,int n,vector<vector<int>> &dp){
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(nums1[m-1]==nums2[n-1]){
             helper(nums1,nums2,m,n-1,dp);
            helper(nums1,nums2,m-1,n,dp);
            return dp[m][n]=1+helper(nums1,nums2,m-1,n-1,dp);
        }
        else {
            
            helper(nums1,nums2,m,n-1,dp);
            helper(nums1,nums2,m-1,n,dp);
            return dp[m][n]=0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        helper(nums1,nums2,nums1.size(),nums2.size(),dp);
        int max=-1;
        for(int i=0; i<=nums1.size(); i++)
        {
            for(int j=0; j<=nums2.size(); j++)
            {
                if(dp[i][j] > max){ max = dp[i][j];}
            }
        }
        return max;
    }
};