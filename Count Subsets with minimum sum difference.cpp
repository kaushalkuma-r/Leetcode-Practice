

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0; 
    cin >> n;
    vector<int> bq; 
    while(n--){
        int a;
        cin >>a;
        sum+=a;
        bq.push_back(a);
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=sum;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(bq[i-1]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i-1][j-bq[i-1]];
        }
    }
    int diff=INT_MAX,in=0;
    for (int j = sum / 2; j >= 0; j--) {
    
        if (dp[n][j] !=0) {
            if(diff< sum - 2 * j) in=j;
            
        }
    }
    return dp[n][in];
}