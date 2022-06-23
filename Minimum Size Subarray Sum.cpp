//Sliding Window Solution
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans= INT_MAX, n = nums.size(), sum=0, left=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-left+1 );
                sum-=nums[left];
                left++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;

    }
};