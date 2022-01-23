// Question Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int len, int nums[]){
        int sum = 0;
        for(int i=0; i<len; i++)
            sum += nums[i];
        if(sum==0)
            return true;
        if(sum&1)
            return false;
        sum = sum/2;
        // int len = nums.size();
        bool dp[len+1][sum+1];
        for(int i=0; i<=len; i++)
            dp[i][0] = true;
        for(int j=1;j<=sum;j++)
            dp[0][j] = false;
        for(int i=1; i<=len; i++) {
            for(int j=1; j<=sum; j++) {
                if(nums[i-1]<=j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends