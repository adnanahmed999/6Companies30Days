// Question Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s) {
        // Your code here
        int start = 0;
        int end = 0;
        long long sum = 0;
        while(end<n) {
            if(sum==s) {
                break;
            } else if(sum>s) {
                sum -= arr[start];
                start++;
                if(start>end) end = start;
            } else if(sum<s) {
                sum += arr[end];
                end++;
            }
        }
        while(start<n && sum!=s) {
            sum -= arr[start];
            start++;
        }
        vector<int> ans;
        if(sum!=s) {
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(start+1);
        ans.push_back(end);
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends