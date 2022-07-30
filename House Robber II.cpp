class Solution {
public:
    int helper(vector<int> &nums, int p1,int p2, bool f){
        int dp[101],n=nums.size();
        dp[0]=p1,dp[1]=p2;
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        if(f==true) return dp[n-1];
        return dp[n-2];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(helper(nums,nums[0],nums[0],false),helper(nums,0,nums[1],true));
    }
}''