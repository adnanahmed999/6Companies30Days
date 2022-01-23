// Question Link: https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A, int n) {
	    //Write your code here
	    vector<vector<int>> dp(n,vector<int>(n,0));
	    for(int g=0; g<n; g++) {
	        for(int i=0,j=g; j<n; i++,j++) {
	            if(g==0) {
	                dp[i][j] = A[i];
	            } else if(g==1) {
	                dp[i][j] = max(A[i],A[j]);
	            } else {
	                int val1 = dp[i+2][j];
	                int val2 = dp[i+1][j-1];
	                int val3 = dp[i][j-2];
	                int selectI = A[i] + min(val1,val2);
	                int selectJ = A[j] + min(val2,val3);
	                dp[i][j] = max(selectI,selectJ);
	            }
	        }
	    }
	    return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends