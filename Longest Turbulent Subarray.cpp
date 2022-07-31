class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int dp[n+1],dp2[n+1];
        memset(dp,0,sizeof(dp));
         memset(dp2,0,sizeof(dp2));
        for(int i=0;i<n-1;i++){
            if(i%2){
                if(arr[i]<arr[i+1]) dp[i+1]=1+dp[i];
                else dp[i+1]=0;
            }
            else{
                if(arr[i]>arr[i+1]) dp[i+1]=1+dp[i];
                else dp[i+1]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            if(i%2){
                if(arr[i]>arr[i+1]) dp2[i+1]=1+dp2[i];
                else dp2[i+1]=0;
            }
            else{
                if(arr[i]<arr[i+1]) dp2[i+1]=1+dp2[i];
                else dp2[i+1]=0;
            }
        }
        int ans=0;
        for(int x:dp ){
            // cout << x<<endl;
            ans=max(x,ans);
        }
        for(int x:dp2){
            // cout << x<<endl;
            ans=max(ans,x);
        }
        return ans+1;
        
        
    }
};