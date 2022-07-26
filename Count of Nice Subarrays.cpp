class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        int cnt = 0;
        
        int i = 0;
        int j = 0;
        while(j<n)
        {
            if((nums[j++]&1)==1)cnt++;            
            
            
            while(cnt>k)if((nums[i++]&1)==1)cnt--;      
           
            if(cnt==k)
            {
                int left = 0, right = 0;
              
                while(j<n && (nums[j]%2)==0)j++,right++;
                while(i<n && (nums[i]%2)==0)i++,left++;
                ans+= ((left+1) * (right+1));
            }
        }
        
        return ans;
        
        
    }
};