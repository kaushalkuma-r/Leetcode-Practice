class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0,j=arr.size()-k;
        while(i<j){
            int mid=(i+j)/2;
            if(x-arr[mid] > arr[mid+k]-x) i=mid+1;
            else j=mid;
            
        }
        vector<int> ans;
        for(int ii=0;ii<k;ii++){
            ans.push_back(arr[ii+i]);
        }
        return ans;
    }
};