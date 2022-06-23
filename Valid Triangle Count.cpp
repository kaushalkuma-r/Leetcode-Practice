class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int count = 0, len = nums.size(), wanted;
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                wanted = nums[i] + nums[j];
                int index = binarySearch(wanted, j + 1, len, nums);
                if (index != -1) {
                    count += index - 1 - j;
                }
            }
        }
        return count;
    }
        int binarySearch(int target, int start, int &len, vector<int> &nums) {
        int l = start, r = len, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};


// class Solution {
// public:
//     int helper( vector<int> nums, int left, int right, int target){
//         while(right>=left && right <nums.size()){
//             int mid = (left+right)/2;
//             if(nums[mid]>=target) right= mid-1;
//             else left=mid+1;
//         }
//         return left;
//     }
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int count=0;
//         if(nums.size()<3) return 0;
//         for(int i=0;i<nums.size()-2;i++){
//             int k=i+2;
//             for(int j=i+1;j<nums.size(); j++){
//                 k=helper(nums, k , nums.size()-1,nums[i]+nums[j]);
//                 count +=k-j-1;
//             }
//         }
//         if(count>0) return count;
//         return 0;
//     }
// };