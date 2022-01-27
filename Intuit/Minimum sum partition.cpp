// Question Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    // basically i am using subset sum variation here,
	    // i first kept target as half of sum, and then checked if there are subsets of size n with target j, and then while traversing from backside, the first element which is true(i.e) it is present in subset then it is obvious that total sum - j is also present
	    
	    int sum = 0;
	    for(int i=0; i<n; i++)
	        sum += arr[i];
	    int target = sum/2;
	    bool dp[n+1][target+1];
	    for(int i=0; i<=n; i++) {
	        dp[i][0] = true;
	    }
	    for(int j=1; j<=target; j++) {
	        dp[0][j] = false;
	    }
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=target; j++) {
	            if(arr[i-1]<=j) {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            } else {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    for(int j=target; j>=0; j--) {
	        if(dp[n][j]) {
	            return ((sum-j)-j);
	        }
	    }
	    return sum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends